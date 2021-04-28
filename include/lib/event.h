#pragma once
#include <algorithm>
#include <type_traits>
#include <utility>
#include <vector>
#include <functional>

namespace lib {
    class event {
    private:
        static std::vector<event> allEvents;
        static unsigned long long globalIdCounter;
        
        std::function<bool(void)> triggerFunction;
        std::function<void(void)> effectFunction;
        unsigned long long id;
    
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

        static void taskTriggerFunction();
    };

    namespace triggers {
        using less = std::less<>;
        using greater = std::greater<>;
        using less_equal = std::less_equal<>;
        using greater_equal = std::greater_equal<>;
        using equal = std::equal_to<>;
        using not_equal = std::not_equal_to<>;

        #define memberBind(obj, func) std::bind(&decltype(obj)::func, &obj)
        #define memberBindArgs(obj, func, ...) std::bind(&decltype(obj)::func, &obj, __VA_ARGS__)

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

        template <typename A, typename B,
                  typename std::enable_if_t<std::is_invocable_v<A>>* = nullptr>
        auto rangeTrigger(A&& a, B&& lower, B&& upper) {
            return [a = std::forward<A>(a), lower = std::forward<B>(lower), upper = std::forward<B>(upper)]
                    { return a() <= upper && a() >= lower; };
        }

        template <typename A, typename B,
                  typename std::enable_if_t<!std::is_invocable_v<A>>* = nullptr>
        auto rangeTrigger(A&& a, B&& lower, B&& upper) {
            return [a = std::forward<A>(a), lower = std::forward<B>(lower), upper = std::forward<B>(upper)]
                    { return a <= upper && a >= lower; };
        }
        
        template <bool B, typename A,
                  typename std::enable_if_t<std::is_invocable_v<A>>* = nullptr>
        auto boolTrigger(A&& a) {
            return [a = std::forward<A>(a), b = std::forward<bool>(B)] { return a() == b; };
        }

        template <bool B, typename A,
                  typename std::enable_if_t<!std::is_invocable_v<A>>* = nullptr>
        auto boolTrigger(A&& a) {
            return [a = std::forward<A>(a), b = std::forward<bool>(B)] { return a == b; };
        }

        inline namespace filters {
            template <typename A, typename std::enable_if_t<std::is_invocable_v<A>>* = nullptr>
            auto risingEdgeFilter(A&& a) {
                return [a = std::forward<A>(a)]{ 
                    static bool on = false;
                    bool oldOn = on; on = a();
                    return on && !oldOn;
                };
            }
            
            template <typename A, typename std::enable_if_t<std::is_invocable_v<A>>* = nullptr>
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