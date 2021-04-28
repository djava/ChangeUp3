#include "lib/event.h"

namespace lib {
    std::vector<event> event::allEvents {};

    unsigned long long event::globalIdCounter = 0;

    event::event(const std::function<bool(void)>& triggerFunction,
                 const std::function<void(void)>& effectFunction,
                 const std::string& nickname)
        : triggerFunction{triggerFunction}, effectFunction{effectFunction},
          nickname{nickname}, id{globalIdCounter++}
    {
        allEvents.push_back(*this);
    }

    event::event(const event& other)
        : triggerFunction{other.triggerFunction},
          effectFunction{other.effectFunction},
          nickname{other.nickname}, id{other.id} {}

    event::~event() {
        remove();
    }

    void event::remove() {
        allEvents.erase(std::remove(allEvents.begin(), allEvents.end(), *this));
    }

    bool event::operator==(const event& b) {
        return id == b.id;
    }

    void event::taskTriggerFunction() {
        for (auto& i: allEvents) {
            if (i.triggerFunction()) {
                i.effectFunction();
            }
        }
    }
}