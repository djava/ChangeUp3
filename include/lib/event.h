#pragma once
#include <algorithm>
#include <type_traits>
#include <utility>
#include <vector>
#include <functional>
#include "lib/memberBind.h"
#include "lib/APIWrappers.h"

namespace lib {
    class event {
    private:
        static std::vector<event> allEvents;
        inline static unsigned long long globalIdCounter = 0;
        
        std::function<bool(void)> triggerFunction;
        std::function<void(void)> effectFunction;
        unsigned long long id;

        static void taskTriggerFunction();
        static lib::task eventTriggerTask;

    public:
        std::string nickname;

        event(const std::function<bool(void)>& triggerFunction,
              const std::function<void(void)>& effectFunction,
              const std::string& nickname = "");

        ~event();

        event(const event& other);

        bool operator==(const event& b);

        std::function<void(void)> trigger = effectFunction;

        void remove();

    };

    namespace triggers {
        using less = std::less<>;
        using greater = std::greater<>;
        using less_equal = std::less_equal<>;
        using greater_equal = std::greater_equal<>;
        using equal = std::equal_to<>;
        using not_equal = std::not_equal_to<>;

        /** cmpTrigger: Returns a function that returns true when the comparison condition is met
         *  
         *  Template Params:
         *  C is the only template parameter passed, and it should be one of the std::functional
         *  comparison types (as are aliased above). It can, be any type with operator(a, b) defined,
         *  but it's meant to be one of the comparison types. The returned function from cmpTrigger
         *  will be true when C's operator(a, b) returns true.
         *
         * Params:
         * A and B are both either functions or variables that will be compared in C's operator(a,b).
         * Either A or B or both or neither can be functions, since the std::enable_if's allow for
         * the compiler to correctly deduce which overload to use under each circumstance.
         *
         * Returns:
         * cmpTrigger returns a function that returns the result of C's operator(a, b), with a or b
         * or both or neither being called, depending on what they are.
         **/

        template <typename C, typename A, typename B,
                  typename std::enable_if_t<std::is_invocable_v<A> && std::is_invocable_v<B>>* = nullptr>
        auto cmpTrigger(A&& a, B&& b) {
            return [a = std::forward<A>(a), b = std::forward<B>(b), cmp{C {}}] { return cmp(a(), b()); };
        }
        
        template <typename C, typename A, typename B,
                  typename std::enable_if_t<std::is_invocable_v<A> && !std::is_invocable_v<B>>* = nullptr>
        auto cmpTrigger(A&& a, B&& b) {
            return [a = std::forward<A>(a), b = std::forward<B>(b), cmp{C {}}] { return cmp(a(), b); };
        }

        template <typename C, typename A, typename B,
                  typename std::enable_if_t<!std::is_invocable_v<A> && std::is_invocable_v<B>>* = nullptr>
        auto cmpTrigger(A&& a, B&& b) {
            return [a = std::forward<A>(a), b = std::forward<B>(b), cmp{C {}}] { return cmp(a, b()); };
        }
        
        template <typename C, typename A, typename B,
                  typename std::enable_if_t<!std::is_invocable_v<A> && !std::is_invocable_v<B>>* = nullptr>
        auto cmpTrigger(A&& a, B&& b) {
            return [a = std::forward<A>(a), b = std::forward<B>(b), cmp{C {}}] { return cmp(a, b); };
        }

        // Returns a function that returns true when a() in in the range [upper, lower] (inclusive),
        // according to A::operator<(B) and A::operator>(B)
        template <typename A, typename B,
                  typename std::enable_if_t<std::is_invocable_v<A>>* = nullptr>
        auto rangeTrigger(A&& a, B&& lower, B&& upper) {
            return [a = std::forward<A>(a), lower = std::forward<B>(lower), upper = std::forward<B>(upper)]
                    { auto& val = a(); return val <= upper && val >= lower; };
        }

        // Returns a function that returns true if a in in the range [upper, lower] (inclusive),
        // according to A::operator<(B) and A::operator>(B)
        template <typename A, typename B,
                  typename std::enable_if_t<!std::is_invocable_v<A>>* = nullptr>
        auto rangeTrigger(A&& a, B&& lower, B&& upper) {
            return [a = std::forward<A>(a), lower = std::forward<B>(lower), upper = std::forward<B>(upper)]
                    { return a <= upper && a >= lower; };
        }
        
        // Returns a function that returns true when a() is equal to B
        template <bool B, typename A,
                  typename std::enable_if_t<std::is_invocable_v<A>>* = nullptr>
        auto boolTrigger(A&& a) {
            return [a = std::forward<A>(a), b = std::forward<bool>(B)] { return a() == b; };
        }

        // Returns a function that returns true when a is equal to B
        template <bool B, typename A,
                  typename std::enable_if_t<!std::is_invocable_v<A>>* = nullptr>
        auto boolTrigger(A&& a) {
            return [a = std::forward<A>(a), b = std::forward<bool>(B)] { return a == b; };
        }

        inline namespace filters {
            template <typename A, typename = std::enable_if_t<std::is_invocable_v<A>>*>
            auto risingEdgeFilter(A&& a) {
                return [a = std::forward<A>(a)]{ 
                    static bool on = false;
                    bool oldOn = on; on = a();
                    return on && !oldOn;
                };
            }
            
            template <typename A, typename = std::enable_if_t<std::is_invocable_v<A>>>
            auto fallingEdgeFilter(A&& a) {
                return [a = std::forward<A>(a)]{ 
                    static bool on = false;
                    bool oldOn = on; on = a();
                    return !on && oldOn;
                };
            }
        }
    } // namespace triggerFactory
} // namespace lib