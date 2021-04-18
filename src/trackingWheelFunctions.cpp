#include "trackingWheels.h"

namespace trackingWheels {
    void resetPositions() {
        for (auto& i: allRotationSensors) {
            i.resetPosition();
        }
    }

    void resetPositions(const trackingWheels& wheels...) {
        for (auto& i: {wheels...}) {
            wheelEnumToRotationSensors[i].resetPosition();
        }
    }

    void resetPositions(const vex::rotation& sensors...) {
        for (auto& i: {sensors...}) {
            i.resetPosition();
        }
    }

    double getPosition(const trackingWheels& wheel) {
        return wheelEnumToRotationSensors[i].position(vex::deg);
    }

    double getPosition(const vex::rotation& sensor) {
        return sensor.position(vex::deg);
    }

    double getAvgPosition(void) {
        double total = 0;
        for (auto& i: allRotationSensors) {
            total += i.position(vex::deg);
        }

        return total / allRotationSensors.size();
    }

    double getAvgPosition(const trackingWheels& wheels...) {
        constexpr int numOfWheels = sizeof...(wheels);

        double total = 0;
        for (auto& i: {wheels...}) {
            total += wheelEnumToRotationSensor[i].position(vex::deg);
        }

        return total / numOfWheels;
    }

    double getAvgPosition(const vex::rotation& sensors...) {
        constexpr int numOfSensors = sizeof...(sensors);

        double total = 0;
        for (auto& i: {sensors...}) {
            total += i.position(vex::deg);
        }
        
        return total / numOfSensors;
    }
}