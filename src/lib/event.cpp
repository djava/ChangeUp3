#include "lib/event.h"

namespace lib {
    std::vector<event> event::allEvents {};

    event::event(const std::function<bool(void)>& triggerFunction,
                 const std::function<void(void)>& effectFunction,
                 const std::string& nickname = "")
        : triggerFunction{triggerFunction}, effectFunction{effectFunction}, nickname{nickname}
    {
        allEvents.push_back(*this);
    }

    event::~event() {
        auto thisIndex = std::find(allEvents.begin(), allEvents.end(), *this);

        allEvents.erase(thisIndex);
    }

    event::event(const event& other)
        : triggerFunction{other.triggerFunction},
          effectFunction{other.effectFunction},
          nickname{other.nickname} {}

    bool event::operator==(const event& b) {
        return this == &b;
    }

    void event::taskTriggerFunction() {
        for (auto& i: allEvents) {
            if (i.triggerFunction()) {
                i.effectFunction();
            }
        }
    }
}