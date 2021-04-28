#pragma once
#include <algorithm>
#include <type_traits>
#include <vector>
#include <functional>

namespace lib {
    class event {
    private:
        static std::vector<event> allEvents;
        
        std::function<bool(void)> triggerFunction;
        std::function<void(void)> effectFunction;
    
    public:
        std::string nickname;

        event(const std::function<bool(void)>& triggerFunction,
              const std::function<void(void)>& effectFunction,
              const std::string& nickname);

        ~event();

        event(const event& other);

        bool operator==(const event& b);

        std::function<void(void)> trigger = effectFunction;

        static void taskTriggerFunction();
    };

    namespace triggerFactory {
        using less = std::less<>;
        using greater = std::greater<>;
        using less_equal = std::less_equal<>;
        using greater_equal = std::greater_equal<>;
        using equal = std::equal_to<>;
        using not_equal = std::not_equal_to<>;

        #define memberBind(obj, func) std::bind(&decltype(obj)::func, &obj)

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

    } // namespace triggerFactory
} // namespace lib