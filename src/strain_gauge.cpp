/**
 * @file
 * @brief     This is the implementation file of the StrainGauge class
 * @author    Willem de Groot, 1710045
 * @license   See LICENSE
 */

#include "strain_gauge.hpp"

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
    /// 1000 to convert from uA to mA
    resistance = 1000*voltage/current;
}

void StrainGauge::convertResistanceToForce() {
    /// Calibration is required to determine newtonFactor.
    force = newtonFactor * resistance;
}

void StrainGauge::calibrate() {
    /// Calibrate to determine how much force corresponds to how much strain.
}

double StrainGauge::getResistance() {
    /// Recalculate the resistance to make sure it's up to date before returning it.
    convertVoltageToResistance();
    return resistance;
}

double StrainGauge::getForce() {
    /// Update Newton before returning it.
    convertResistanceToForce();
    return force;
}

void StrainGauge::convertReadingToVoltage() {
    /// 4095 = max reading of 12-bit ADC
    /// 3300 = max voltage in mV (3.3V)
    voltage = 3300*readSensor() / 4095;
}
