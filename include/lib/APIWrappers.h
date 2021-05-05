#pragma once
#include "lib/HAL/APIHeader.h"
#include "lib/memberBind.h"
#include "lib/units/units.h"
#include "pros/rtos.h"
#include <type_traits>

namespace lib {
    inline void delay(QTime time) {
        #ifdef IS_PROS
            pros::delay(static_cast<int>(time.convert(millisecond)));
        #else
            vex::wait(time.convert(millisecond), vex::msec);
        #endif
    }

    class task {
    private:
        #ifdef IS_PROS
        pros::Task apiTask;
        #else
        vex::Task apiTask;
        #endif

        std::string name;

    public:
        typedef int taskPriority;
        #ifdef IS_PROS
            constexpr static taskPriority normalPriority = TASK_PRIORITY_DEFAULT;
        #else
            constexpr static taskPriority normalPriority = vex::task::taskPriorityNormal;
        #endif

        template <class F, typename std::enable_if_t<std::is_invocable_v<F>>* = nullptr>
        task(F&& function, const taskPriority& priority, const std::string& name = "")
        : apiTask{
        #ifdef IS_PROS
            pros::Task(function, priority, TASK_STACK_DEPTH_DEFAULT, name.c_str())
        #elif defined(IS_VEXCODE)
            vex::Task([](void* parameters) {
                std::unique_ptr<std::function<void()>> ptr{static_cast<std::function<void()>*>(parameters)};
                (*ptr)();
            },
            new std::function<void()>(std::forward<F>(function)), priority)
        #endif
        }, name{name} {}

        template <class F, typename std::enable_if_t<std::is_invocable_v<F>>* = nullptr>
        task(F&& function, const std::string& name = "")
        : apiTask{
        #ifdef IS_PROS
            pros::Task(function, name.c_str())
        #elif defined(IS_VEXCODE)
            vex::Task([](void* parameters) {
                std::unique_ptr<std::function<void()>> ptr{static_cast<std::function<void()>*>(parameters)};
                (*ptr)();
            },
            new std::function<void()>(std::forward<F>(function)))
        #endif
        }, name{name} {}

        inline void setPriority(taskPriority priority) { apiTask.set_priority(priority); }
        inline void resume() { apiTask.resume(); }
        inline void suspend() { apiTask.suspend(); }
        
        inline taskPriority getPriority() {
            #ifdef IS_PROS
            return apiTask.get_priority();
            #else
            return apiTask.priority();
            #endif
        }

        inline void remove() {
            #ifdef IS_PROS
            apiTask.remove();
            #else
            apiTask.stop();
            #endif
        };
    };
}