#include "trackingWheels.h"

namespace trackingWheels {
    void resetPositions() {
        for (auto& i: allRotationSensors) {
            i.resetPosition();
        }
    }

    void resetPositions(const std::vector<trackingWheels>& wheels...) {
        for (auto& i: wheels) {
            wheelEnumToRotationSensor.at(i).resetPosition();
        }
    }

    void resetPositions(std::vector<vex::rotation>& sensors) {
        for (auto& i: sensors){
            i.resetPosition();
        }
    }
    
    void resetPositions(vex::rotation& sensor) {
      sensor.resetPosition();
    }

    void resetPositions(const trackingWheels& wheel) {
      wheelEnumToRotationSensor.at(wheel).resetPosition();
    }

    double getPosition(const trackingWheels& wheel) {
        return wheelEnumToRotationSensor.at(wheel).position(vex::deg);
    }

    double getPosition(vex::rotation& sensor) {
        return sensor.position(vex::deg);
    }


    double getAvgPosition(void) {
        double total = 0;
        for (auto& i: allRotationSensors) {
            total += i.position(vex::deg);
        }

        return total / allRotationSensors.size();
    }

    double getAvgPosition(const std::vector<trackingWheels>& wheels...) {
        const int numOfWheels = wheels.size();

        double total = 0;
        for (auto& i: wheels) {
            total += wheelEnumToRotationSensor.at(i).position(vex::deg);
        }

        return total / numOfWheels;
    }

    double getAvgPosition(std::vector<vex::rotation>& sensors) {
        const int numOfSensors = sensors.size();

        double total = 0;
        for (auto& i: sensors) {
            total += i.position(vex::deg);
        }
        
        return total / numOfSensors;
    }
}