#pragma once
#include <functional>

#define memberBind(obj, func) std::bind(&decltype(obj)::func, &obj)
#define memberBindArgs(obj, func, ...) std::bind(&decltype(obj)::func, &obj, __VA_ARGS__)