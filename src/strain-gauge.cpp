/**
 * @file
 * @brief     This is the implementation file of the StrainGauge class
 * @author    Willem de Groot, 1710045
 * @license   See LICENSE
 */

#include "strain-gauge.hpp"

int StrainGauge::readSensor() {
    /// This is a random value right now, it does not read a value from an actual strain gauge yet.
    return 738479;
}

double StrainGauge::filterReadings() {
    int total = 0;
    /// The number of readings to take the average from.
    int readings = 0;
    for (int i = 0; i < readings; ++i) {
        total += readSensor();
    }
    return (double) total / readings;
}

double StrainGauge::convertVoltageToResistance(double voltage) {
    /// U = I * R, so R = U / I
    /// Chosen value for now.
    double current = 0.1;
    return voltage/current;
}

double StrainGauge::convertResistanceToX(double resistance) {
    /// A random factor, whatever it needs to be to convert the resistance to any desired unit.
    /// Calibration is required to determine this number.
    double factor = 3.45;
    return factor * resistance;
}

void StrainGauge::calibrate() {

}