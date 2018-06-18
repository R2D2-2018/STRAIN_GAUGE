/**
 * @file      flex_sensor.cpp
 * @brief     Flex Sensor functionality
 * @author    Joost van Lingen
 * @license   See LICENSE
 */

#include "flex_sensor.hpp"

int FlexSensor::getAngle() {
    angle = ((getResistance() - calibrateValue) / range) * 90.0f;
    return angle;
}