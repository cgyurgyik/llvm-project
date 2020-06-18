//===-- Unittests for strcmp ----------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/string/strcmp.h"
#include "utils/UnitTest/Test.h"

TEST(StrCmpTest, EmptyStringsShouldReturnZero) {
  const char *s1 = "";
  const char *s2 = "";
  const int result = __llvm_libc::strcmp(s1, s2);
  ASSERT_EQ(result, 0);
}

TEST(StrCmpTest, EqualStringsShouldReturnZero) {
  const char *s1 = "abc";
  const char *s2 = "abc";
  const int result = __llvm_libc::strcmp(s1, s2);
  ASSERT_EQ(result, 0);
}

TEST(StrCmpTest, ShouldReturnResultOfFirstDifference) {
  const char* s1 = "aaaB42";
  const char* s2 = "aaaC55";
  const int result = __llvm_libc::strcmp(s1, s2);
  // This should return 'C' - 'B', which is equal to -1.
  ASSERT_EQ(result, -1);
}

TEST(StrCmpTest, CapitalizedLetterShouldNotBeEqual) {
  const char* s1 = "abcd";
  const char* s2 = "abCd";
  const int result = __llvm_libc::strcmp(s1, s2);
  // 'c' - 'C' is equal to 32.
  ASSERT_EQ(result, 32);
}

TEST(StrCmpTest, UnequalLengthStringsShouldNotReturnZero) {
  const char* s1 = "abc";
  const char* s2 = "abcd";
  const int result = __llvm_libc::strcmp(s1, s2);
  // '\0' - 'd' is equal to -100.
  ASSERT_EQ(result, -100);
}

TEST(StrCmpTest, OrderingSwapChangesSign) {
  const char* a = "a";
  const char* b = "b";
  int result = __llvm_libc::strcmp(b, a);
  // 'b' - 'a' is equal to 1.
  ASSERT_EQ(result, 1);
    
  result = __llvm_libc::strcmp(a, b);
  // 'a' - 'b' is equal to -1.
  ASSERT_EQ(result, -1);
}
