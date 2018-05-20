#ifndef STRAIN_GAUGE_HPP
#define STRAIN_GAUGE_HPP
#include "wrap-hwlib.hpp"

class StrainGauge {
private:
    double voltage; // V
    double current; // mA
    double resistance; // Ohm
    double newton;
    double newtonFactor;
    double averagReading;
    hwlib::pin_in & input;

    /**
     * @brief Read the voltage from strain gauge
     * 
     * We measure the change in resistance of the strain gauge by observing the change in voltage.
     * 
     * @return The measured amount of voltage
     */
    int readSensor();
    
    /**
     * @brief Filter several readings to get a more reliable impression
     * 
     * Take several readings and calculate the average to eliminate spikes
     * 
     * @return Average over several sensor readings
     */
    void filterReadings();

    /**
     * @brief Convert the measured current to resistance
     * 
     * Convert measured current to resistance by dividing voltage by current,
     * following the formula U = I * R -> R = U / I.
     * 
     * @param[in] voltage The measured voltage through the strain gauge
     * @return resistance calculated by dividing voltage by current
     */
    void convertVoltageToResistance();

    /**
     * @brief Convert the resistance to a desired unit.
     * 
     * This function will convert the resistance to a currently unspecified unit.
     * This is done by multiplying the resistance by a value that will be specified during calibration.
     * 
     * @param[in] resistance The resistance calculated from the current and measured voltage
     * @return What will the function return
     */
    void convertResistanceToNewton();

    void convertReadingToVoltage();

public:
    StrainGauge(hwlib::pin_in & input):
        voltage(0.0),
        current(7.14),
        resistance(350.0),
        newton(0.0),
        input(input)
    {}

    /**
     * @brief Calibrate the strain gauge.
     * 
     * Calibrate the strain gauge to determine which sensor value corresponds to which amount of strain.
     * 
     */
    void calibrate();

    double getResistance();

    double getNewton();
};

#endif // STRAIN_GAUGE_HPP