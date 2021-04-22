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
QUANTITY_TYPE(0, 0, 0, 0, QPercent)

constexpr QPercent percent(1.0); // SI base unit
constexpr QPercent proportion = 0.01 * percent;

inline namespace literals {
constexpr QPercent operator"" _pct(long double x) {
  return QPercent(x);
}
constexpr QPercent operator"" _ppt(long double x) {
  return static_cast<double>(x) * proportion;
}
constexpr QPercent operator"" _pct(unsigned long long int x) {
  return QPercent(static_cast<double>(x));
}
constexpr QPercent operator"" _ppt(unsigned long long int x) {
  return static_cast<double>(x) * proportion;
}

} // namespace literals
} // namespace okapi