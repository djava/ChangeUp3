#include "lib/event.h"
#include "lib/APIWrappers.h"
#include "main.h"

namespace lib {
    std::vector<event> event::allEvents {};

    lib::task event::eventTriggerTask = lib::task(taskTriggerFunction,
                                                  lib::task::normalPriority + 1,
                                                  "Event Triggers");

    event::event(const std::function<bool(void)>& triggerFunction,
                 const std::function<void(void)>& effectFunction,
                 const std::string& nickname)
        : triggerFunction{triggerFunction}, effectFunction{effectFunction},
          nickname{nickname}, id{globalIdCounter++}
    {
        allEvents.push_back(*this);
    }

    // If no trigger function is provided, the effect funtion will run
    // every cycle automically.  []{ return true; } is used as the trigger.
    event::event(const std::function<void(void)>& effectFunction,
                 const std::string& nickname)
        : triggerFunction{[]{ return true; }}, effectFunction{effectFunction},
          nickname{nickname}, id{globalIdCounter++}
    {
        allEvents.push_back(*this);
    }

    // The else function will run if triggerFunction returns false
    event::event(const std::function<bool(void)>& triggerFunction,
                 const std::function<void(void)>& effectFunction,
                 const std::function<void(void)>& elseFunction,
                 const std::string& nickname)
        : triggerFunction{triggerFunction}, effectFunction{effectFunction},
          elseFunction{elseFunction}, nickname{nickname}, id{globalIdCounter++}
    {
        hasElse = true;
        allEvents.push_back(*this);
    }


    event::event(const event& other)
        : triggerFunction{other.triggerFunction}, effectFunction{other.effectFunction},
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
        while (true) {
            for (auto& i: allEvents) {
                if (i.triggerFunction()) {
                    i.effectFunction();
                } else if (i.hasElse) {
                    i.elseFunction();
                }
            }
            lib::delay(20_ms);
        }
    }
}