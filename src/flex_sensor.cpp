#include "flex_sensor.hpp"

int FlexSensor::getAngle() {
    angle = ((getResistance() - calibrateValue) / range) * 90.0f;
    return angle;
}