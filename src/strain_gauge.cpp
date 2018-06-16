/**
 * @file      strain_gauge.cpp
 * @brief     Strain Gauge functionality
 * @author    Joost van Lingen
 * @license   See LICENSE
 */

#include "strain_gauge.hpp"

int StrainGauge::medianFilter(int inputData[5]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (inputData[j] > inputData[j + 1]) {
                int temp = inputData[j];
                inputData[j] = inputData[j + 1];
                inputData[j + 1] = temp;
            }
        }
    }
    return inputData[2];
}

void StrainGauge::update() {
    for (int i = 0; i < 5; i++) {
        const int temp = inputPin.get();
        hwlib::cout << hwlib::endl << temp << hwlib::endl; /////////////////////////////////
        float Vin = temp * maxVoltage / adcSize;
        rawData[i] = pullDownResistor * (maxVoltage / Vin - 1.0);
        hwlib::wait_us(100000);
    }
    resistance = medianFilter(rawData);
}

int StrainGauge::getResistance() {
    update();
    return resistance;
}

void StrainGauge::calibrate() {
    calibrateValue = getResistance();
}