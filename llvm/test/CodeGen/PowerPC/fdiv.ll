; NOTE: Assertions have been autogenerated by utils/update_llc_test_checks.py
; RUN: llc -verify-machineinstrs < %s -mtriple=powerpc64le-unknown-linux-gnu -mcpu=pwr8 | FileCheck %s

define dso_local float @foo(float %0, float %1) local_unnamed_addr {
; CHECK-LABEL: foo:
; CHECK:       # %bb.0:
; CHECK-NEXT:    xsresp 3, 2
; CHECK-NEXT:    xsmulsp 0, 1, 3
; CHECK-NEXT:    xsnmsubasp 1, 2, 0
; CHECK-NEXT:    xsmaddasp 0, 3, 1
; CHECK-NEXT:    fmr 1, 0
; CHECK-NEXT:    blr
  %3 = fdiv reassoc arcp nsz float %0, %1
  ret float %3
}
