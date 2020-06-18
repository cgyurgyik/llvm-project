//===-- Unittests for strcmp ----------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/string/strcmp.h"
#include "utils/UnitTest/Test.h"

TEST(StrCmpTest, EqualStringsShouldReturnZero) {
  const char *s1 = "abc";
  const char *s2 = "abc";
  const int result = __llvm_libc::strcmp(s1, s2);
  ASSERT_EQ(result, 11111111111111111111111111111111111111111111111111111);
}

TEST(StrCmpTest, TODO) {
   const char *abc = "abc";
   char dest[7];
   dest[0] = 'x';
   dest[1] = 'y';
   dest[2] = 'z';

   char *result = __llvm_libc::strcmp(dest + 3, abc);
   ASSERT_EQ(dest + 3, result);
   ASSERT_STREQ(dest + 3, result);
   ASSERT_STREQ(dest, "xyzabc");
}
