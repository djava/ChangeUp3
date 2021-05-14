#pragma once
#include <functional>

/** This is a method to effectively overload macro functions by number of arguments.
 *  The way it works is that the arguments to memberBind are placed in front of the list
 *  of macros with corresponding number of arguments to "bump" it so that the correct
 *  one ends up in the NAME argument of __GET_MEMBERBIND_MACRO
 */

#define __GET_MEMBERBIND_MACRO(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, NAME, ...) NAME
#define memberBind(obj, func, ...) \
        __GET_MEMBERBIND_MACRO(__VA_ARGS__, __memberBind10, __memberBind9, \
                               __memberBind8, __memberBind7, __memberBind6, \
                               __memberBind5, __memberBind4, __memberBind3, \
                               __memberBind2, __memberBind1, __memberbind0)(obj, func, __VA_ARGS__)

#define __memberBind0(obj, func) \
                std::bind(&decltype(obj)::func, &obj)

#define __memberBind1(obj, func, arg1) \
                std::bind(&decltype(obj)::func, &obj, arg1)

#define __memberBind2(obj, func, arg1, arg2) \
                std::bind(&decltype(obj)::func, &obj, arg1, arg2)

#define __memberBind3(obj, func, arg1, arg2, arg3) \
                std::bind(&decltype(obj)::func, &obj, arg1, arg2, arg3)

#define __memberBind4(obj, func, arg1, arg2, arg3, arg4) \
                std::bind(&decltype(obj)::func, &obj, arg1, arg2, arg3, arg4)

#define __memberBind5(obj, func, arg1, arg2, arg3, arg4, arg5) \
                std::bind(&decltype(obj)::func, &obj, arg1, arg2, arg3, arg4, arg5)

#define __memberBind6(obj, func, arg1, arg2, arg3, arg4, arg5, arg6) \
                std::bind(&decltype(obj)::func, &obj, arg1, arg2, arg3, arg4, arg5, arg6)

#define __memberBind7(obj, func, arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
                std::bind(&decltype(obj)::func, &obj, arg1, arg2, arg3, arg4, arg5, arg6, arg7)

#define __memberBind8(obj, func, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
                std::bind(&decltype(obj)::func, &obj, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)

#define __memberBind9(obj, func, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) \
                std::bind(&decltype(obj)::func, &obj, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9)

#define __memberBind10(obj, func, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) \
                std::bind(&decltype(obj)::func, &obj, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10)
