/**
 * @file
 * @brief     This is the implementation file of the StrainGauge class
 * @author    Willem de Groot, 1710045
 * @license   See LICENSE
 */

#include "strain_gauge.hpp"

int StrainGauge::StrainGauge::readSensor() {
    return input.get();
}

void StrainGauge::StrainGauge::convertVoltageToResistance() {
    ///< Calculate voltage from sensor reading first.
    convertReadingToVoltage();
    ///< 1000 to convert from uA to mA
    resistance = 1000 * voltage / current;
}

void StrainGauge::StrainGauge::convertResistanceToForce() {
    ///< Calibration is required to determine newtonFactor.
    convertVoltageToResistance();
    force = newtonFactor * resistance;
}

void StrainGauge::StrainGauge::calibrate(int appliedForce) {
    ///< Calibrate to determine how much force corresponds to how much strain.
    int startValue = readSensor();
    hwlib::cout << "Apply force" << hwlib::endl;
    while (readSensor() > startValue - 10 && readSensor() < startValue + 10)
        ;
    hwlib::cout << "Starting calibration..." << hwlib::endl;
    auto start = hwlib::now_us();
}

int StrainGauge::StrainGauge::getResistance() {
    ///< Recalculate the resistance to make sure it's up to date before returning it.
    convertVoltageToResistance();
    return resistance;
}

int StrainGauge::StrainGauge::getDeltaResistance() {
    convertVoltageToResistance();
    return resistance - defaultResistance;
}

int StrainGauge::StrainGauge::getForce() {
    ///< Update Newton before returning it.
    convertResistanceToForce();
    return force;
}

void StrainGauge::StrainGauge::convertReadingToVoltage() {
    ///< 4095 = max reading of 12-bit ADC
    ///< 3300 = max voltage in mV (3.3V)
    voltage = 3300 * readSensor() / 4095;
}
