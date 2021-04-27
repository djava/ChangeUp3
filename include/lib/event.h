#pragma once
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

    namespace eventTriggerFactory {
        template <typename C, typename F, typename B, typename = std::enable_if_t<std::is_invocable_v<F>>>
        auto funcCmp(F&& func, B&& val) {
            C cmp{}; 
            return [func = std::forward<F>(func), val = std::forward<B>(val), cmp{std::move(cmp)}] {
                return cmp(func(), val);
            };
        }
    }
}