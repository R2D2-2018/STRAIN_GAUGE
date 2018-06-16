/**
 * @file      strain_gauge.hpp
 * @brief     Strain Gauge class
 * @author    Joost van Lingen
 * @license   See LICENSE
 */

#ifndef STRAIN_GAUGE_HPP
#define STRAIN_GAUGE_HPP
#include "wrap-hwlib.hpp"

class StrainGauge {
  private:
    const int maxVoltage = 3300;        ///< Voltage when no resistance is applied
    const int adcSize = 4095;           ///< Range of the ADC on the used Arduino Due pin
    const int pullDownResistor = 46000; ///< Used pulldown resistor on the sensor
    int resistance = 0;                 ///< Stores the current resistance measured
    int rawData[5] = {0, 0, 0, 0, 0};   ///< Stores the raw measurements to be filtered

    /**
     * @brief Median filter
     *
     * This function returns the median value from five in an array placed integers.
     *
     * The integers are sorted from lowest to highest before returning the middle
     * value (median).
     *
     * @param inputData: an array of five integers to be filtered
     * @return Median of the given data as integer
     */
    int medianFilter(int inputData[5]);

    /**
     * @brief Update the resistance measurement
     *
     * The current resistance is calculated from the ADC input and stored in the
     * resistance variable (int).
     *
     * The function measures five times over a course of ~500us after which a median
     * filter is applied. The resistance is calculated by first calculating the
     * input voltage by comparing the measurement by the range of the ADC. This value
     * is then compared to the maximum voltage. Finally, the outcome is multiplied by
     * the value of the used pulldown resistor.
     */
    void update();

  protected:
    hwlib::adc &inputPin;   ///< Stores the address of the ADC pin connected to the sensor
    int calibrateValue = 0; ///< Stores the value to calibrate the sensor to

  public:
    /**
     * @brief StrainGauge constructor
     *
     * Costructor for StrainGauge.
     *
     * @param inputPin stores the address of the ADC pin the sensor is connected to
     */
    explicit StrainGauge(hwlib::adc &inputPin) : inputPin(inputPin) {
    }
    /**
     * @brief Returns the current measured resistance
     *
     * This function calls the update() function before returning the resistance.
     *
     * @return Current resistance in ohms as integer
     */
    int getResistance();
    /**
     * @brief Calibrate the sensor to a 0 point
     *
     * This function can be called to set the current measured resistance as a
     * 0 point. This way the resistance can easily be compared to a set point.
     */
    void calibrate();
};

#endif // STRAIN_GAUGE_HPP