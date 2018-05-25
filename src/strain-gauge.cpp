/**
 * @file
 * @brief     This is the implementation file of the StrainGauge class
 * @author    Willem de Groot, 1710045
 * @license   See LICENSE
 */

#include "strain-gauge.hpp"

int StrainGauge::readSensor() {
    return input.get();
}

void StrainGauge::filterReadings() {
    int total = 0;
    /// The number of readings to take the average from.
    int readings = 0;
    for (int i = 0; i < readings; ++i) {
        total += readSensor();
    }
    averagReading = total / readings;
}

void StrainGauge::convertVoltageToResistance() {
    /// Calculate voltage from sensor reading first.
    convertReadingToVoltage();
    resistance = voltage/current;
}

void StrainGauge::convertResistanceToNewton() {
    /// Calibration is required to determine newtonFactor.
    newton = newtonFactor * resistance;
}

void StrainGauge::calibrate() {
    /// Calibrate to determine how much force corresponds to how much strain.
}

double StrainGauge::getResistance() {
    /// Recalculate the resistance to make sure it's up to date before returning it.
    convertVoltageToResistance();
    return resistance;
}

double StrainGauge::getNewton() {
    /// Update Newton before returning it.
    convertResistanceToNewton();
    return newton;
}

void StrainGauge::convertReadingToVoltage() {
    // 1023 = max reading
    // 5 = max voltage
    filterReadings();
    voltage = averagReading / 1023 * 5;
}