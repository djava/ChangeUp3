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
QUANTITY_TYPE(1, -1, -2, 0, QTemperature)

constexpr QTemperature kelvin(1.0); // SI base unit
constexpr QTemperature celsius = kelvin + QTemperature(273.15);
constexpr QTemperature fahrenheit = (celsius * 9.0/5.0) + QTemperature(32.0);

inline namespace literals {
constexpr QTemperature operator"" _degC(long double x) {
  return static_cast<double>(x) * celsius;
}
constexpr QTemperature operator"" _degF(long double x) {
  return static_cast<double>(x) * fahrenheit;
}
constexpr QTemperature operator"" _degC(unsigned long long int x) {
  return static_cast<double>(x) * celsius;
}
constexpr QTemperature operator"" _degF(unsigned long long int x) {
  return static_cast<double>(x) * fahrenheit;
}

} // namespace literals
} // namespace okapi