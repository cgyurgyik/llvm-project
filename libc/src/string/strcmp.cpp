//===-- Implementation of strcmp ------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/string/strcmp.h"

#include "src/__support/common.h"

namespace __llvm_libc {

char *LLVM_LIBC_ENTRYPOINT(strcmp)(char *l, const char *r) {
  while (*l) {
    if (*l != *r) break;
    ++l;
    ++r;
  }
  return *(const unsigned char*)l - *(const unsigned char*)r;
}

} // namespace __llvm_libc