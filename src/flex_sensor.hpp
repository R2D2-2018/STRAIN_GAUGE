/**
 * @file      flex_sensor.hpp
 * @brief     Flex Sensor class
 * @author    Joost van Lingen
 * @license   See LICENSE
 */

#ifndef FLEX_SENSOR_HPP
#define FLEX_SENSOR_HPP
#include "strain_gauge.hpp"
#include "wrap-hwlib.hpp"

class FlexSensor : public StrainGauge {
  private:
    int angle = 0;        ///< Stores current angle of flex sensor in integer.
    float range = 40'000; ///< Range in ohms from 0 to 90 degrees.

  public:
    /**
     * @brief FlexSensor constructor.
     *
     * Constructor for FlexSensor. Given a hwlib::adc input pin, stored in
     * the StrainGauge class.
     *
     * @param[in] inputPin Storing ADC pin address to read voltage from the sensor.
     */
    explicit FlexSensor(hwlib::adc &inputPin) : StrainGauge(inputPin) {
    }
    /**
     * @brief Return current angle of sensor.
     *
     * This function returns the current angle the sensor is in, compared
     * to the calibrated 0 degree point.
     *
     * The resistance measured by the getResistance() function is subtrackted
     * from the calibrated 0 degree points' resistance. The outcome is
     * devided by the range from 0 to 90 degrees is ohms and multiplied by 90
     * to get the current angle.
     *
     * @return Current angle in degrees in integer.
     */
    int getAngle();
};

#endif // FLEX_SENSOR_HPP
