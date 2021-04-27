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
QUANTITY_TYPE(1, 2, -3, 0, QVoltage)

constexpr QVoltage volt(1.0); // SI base unit
constexpr QVoltage millivolt = 0.001 * volt;

inline namespace literals {
constexpr QVoltage operator"" _v(long double x) {
  return QVoltage(x);
}
constexpr QVoltage operator"" _mV(long double x) {
  return static_cast<double>(x) * millivolt;
}
constexpr QVoltage operator"" _v(unsigned long long int x) {
  return QVoltage(static_cast<double>(x));
}
constexpr QVoltage operator"" _mV(unsigned long long int x) {
  return static_cast<double>(x) * millivolt;
}
} // namespace literals
} // namespace okapi
