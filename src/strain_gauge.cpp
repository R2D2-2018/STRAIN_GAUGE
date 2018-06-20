/**
 * @file      strain_gauge.cpp
 * @brief     Strain Gauge functionality
 * @author    Joost van Lingen
 * @license   See LICENSE
 */

#include "strain_gauge.hpp"

int StrainGauge::medianFilter(std::array<int, 5> inputData) {
    for (uint16_t i = 0; i < (inputData.size() - 1); i++) {
        for (uint16_t j = 0; j < (inputData.size() - 1); j++) {
            if (inputData[j] > inputData[j + 1]) {
                int temp = inputData[j];
                inputData[j] = inputData[j + 1];
                inputData[j + 1] = temp;
            }
        }
    }
    if (inputData.size() % 2 == 0) {
        return ((inputData[inputData.size() / 2 - 1]) + (inputData[inputData.size() / 2])) / 2;
    } else {
        return inputData[(int)inputData.size() / 2];
    }
}

void StrainGauge::update() {
    for (uint16_t i = 0; i < 5; i++) {
        const int temp = inputPin.get();
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