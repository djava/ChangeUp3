/*
 * This code is a modified version of Benjamin Jurke's work in 2015. You can read his blog post
 * here:
 * https://benjaminjurke.com/content/articles/2015/compile-time-numerical-unit-dimension-checking/
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#pragma once

#include "lib/units/RQuantity.h"

namespace lib {
QUANTITY_TYPE(0, 0, 0, 0, QCurrent)

constexpr QCurrent amp(1.0); // SI base unit
constexpr QCurrent milliamp = 0.001 * amp;

inline namespace literals {
constexpr QCurrent operator"" _a(long double x) {
  return QCurrent(x);
}
constexpr QCurrent operator"" _ma(long double x) {
  return static_cast<double>(x) * milliamp;
}
constexpr QCurrent operator"" _a(unsigned long long int x) {
  return QCurrent(static_cast<double>(x));
}
constexpr QCurrent operator"" _ma(unsigned long long int x) {
  return static_cast<double>(x) * milliamp;
}
} // namespace literals
} // namespace okapi