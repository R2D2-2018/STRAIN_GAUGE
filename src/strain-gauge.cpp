/**
 * @file
 * @brief     This is the implementation file of the StrainGauge class
 * @author    Willem de Groot, 1710045
 * @license   See LICENSE
 */

#include "strain-gauge.hpp"

int StrainGauge::readSensor() {
    /// This is a random value right now, it does not read a value from an actual strain gauge yet.
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
    /// U = I * R, so R = U / I
    /// Chosen value for now.
    // double current = 0.1;
    convertReadingToVoltage();
    resistance = voltage/current;
}

void StrainGauge::convertResistanceToNewton() {
    /// A random factor, whatever it needs to be to convert the resistance to Newton.
    /// Calibration is required to determine this number.
    newton = newtonFactor * resistance;
}

void StrainGauge::calibrate() {

}

double StrainGauge::getResistance() {
    convertVoltageToResistance();
    return resistance;
}

double StrainGauge::getNewton() {
    convertResistanceToNewton();
    return newton;
}

void StrainGauge::convertReadingToVoltage() {
    // 1023 = max reading
    // 5 = max voltage
    voltage = averagReading / 1023 * 5;
}