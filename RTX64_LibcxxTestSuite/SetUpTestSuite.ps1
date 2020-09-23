# This path will work as long as the steps in Libcxx Test Suite Steps.docx are followed EXACTLY
cd "C:\RTX64_LibcxxTestSuite\"
$currentDir = ("{0}{1}" -f (Get-Item -Path ".\").FullName,'\')



# Env Variable used in Props file
if (-not (Test-Path env:LibCXXTestDir))
{
    "LibCXXTestDir Does not exist setting the Environment up..."
    [Environment]::SetEnvironmentVariable('LibCXXTestDir', $currentDir, 'User')
}

#brute force some environments to allow us to construct an SLN
C:\"Program Files (x86)\Microsoft Visual Studio"\2019\Professional\VC\Auxiliary\Build\vcvarsall.bat x64 10.0.18362.0


$CPPVersion = "c++11"
$VSPlatform = "v141"
$msvc = "msvc"
$RTTI = "runtimetypeinfo"
$projects = Get-ChildItem -recurse -filter *.cpp -name

"Initiating Project Creation Loop"
$solutionDir = ""
$solutionName = ""
$unsupported = ""
$breakout = 0;

for ($i = 0; $i -lt $projects.length; $i++) 
{
    # find out is this version of CPP is Unsupported and skip if it is not. 
    $unsupported = Select-String -Path $projects[$i] -Pattern 'UNSUPPORTED:'
    foreach( $item in $unsupported)
    {
        if($item.ToString().Contains($CPPVersion))
        {  
          $breakout = 1
          break
        }

        if($item.ToString().Contains($msvc))
        {  
          $breakout = 1
          break
        }

        if($item.ToString().Contains($VSPlatform))
        {  
          $breakout = 1
          break
        }

        if($item.ToString().Contains($RTTI))
        {  
          $breakout = 1
          break
        }
    }
    if($breakout -eq 1)
    {
        $breakout = 0
         continue
    }

    $unsupported = $null
    $breakout = 0
     # find out is this version of CPP is Required and skip if it is not. 
    $unsupported = Select-String -Path $projects[$i] -Pattern 'REQUIRES:'
    if($unsupported -ne $null)
    {
        foreach( $item in $unsupported)
        { 
            if(-not $item.ToString().Contains("c++"))
            {
                $breakout = 1
                break
            }
            if($item.ToString().Contains($CPPVersion))
            {  
              $breakout = 1
              break
            }
        }
        if($breakout -ne 1)
        {
             continue
        }
        $breakout = 0
    }

     $unsupported = $null
 
    # find out is this version of CPP is XFAIL and skip if it is not. 
    #TODO: This is actually means expected failure.  We could modify this later to have the scripts expect a failure.
    $unsupported = Select-String -Path $projects[$i] -Pattern 'XFAIL:'
    foreach( $item in $unsupported)
    {
        if($item.ToString().Contains($CPPVersion))
        {  
          $breakout = 1
          break
        }
    }
    if($breakout -eq 1)
    {
        $breakout = 0
         continue
    }


    $thisDir = Split-Path $projects[$i]

    # Ignore the experimental folder
    if ($thisDir -match "experimental")
    {
        continue
    }

    $thisName = Split-Path -Path $projects[$i] -Leaf 

    #construct vcxproj file
    $newProject = [io.path]::ChangeExtension($thisName, ".vcxproj")
    
    "Creating new Project $thisDir\$newProject"

    #Copy vcxproj File
    Copy-Item -Path .\Template.vcxproj -Destination "$thisDir\$newProject"
    
    #Construct hFile
    $newHeaderFile = [io.path]::ChangeExtension($thisName, ".h")
    
    #copy templated Header File over
    Copy-Item -Path .\Template.h -Destination "$thisDir\$newHeaderFile"

    #Let's get the contents of the VCXProj and do a text replace
    [xml]$project = Get-Content -Path "$thisDir\$newProject"
    
    #change the .cpp and .h file
    for ($j = 0; $j -lt $project.project.ItemGroup.length; $j++) {

        if ($project.project.ItemGroup[$j].ClCompile -NE $null)
        {
            $project.project.ItemGroup[$j].ClCompile.Include = $thisName.ToString()
        }

        if ($project.project.ItemGroup[$j].ClInclude.Include -NE $null)
        {
            $project.project.ItemGroup[$j].ClInclude.Include = $newHeaderFile
        }

    }

    #change the rootnamespace
    for ($j = 0; $j -lt $project.project.PropertyGroup.length; $j++) {
         if ($project.project.PropertyGroup[$j].Label -eq "Globals")
         {
            $project.project.PropertyGroup[$j].RootNamespace = [io.path]::GetFileNameWithoutExtension($thisName)
         }
    }
    $project.save("$currentDir\$thisDir\$newProject")


    #edit HeaderFile to Help Label Test
    $replacementValue = [io.path]::GetFileNameWithoutExtension($thisName)
    $headerFile = Get-Content -Path "$thisDir\$newHeaderFile"

    [System.IO.File]::WriteAllText(
        "$currentDir\$thisDir\$newHeaderFile",
        ([System.IO.File]::ReadAllText("$currentDir\$thisDir\$newHeaderFile") -replace "Template", $replacementValue)
        )


}#end of primary for loop