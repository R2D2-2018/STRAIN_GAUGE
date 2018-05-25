#ifndef STRAIN_GAUGE_HPP
#define STRAIN_GAUGE_HPP
#include "wrap-hwlib.hpp"

class StrainGauge {
private:
    double voltage; // V
    double current; // mA
    double resistance; // kOhm
    double newton;
    double newtonFactor;
    double averagReading;
    hwlib::pin_in & input;

    /**
     * @brief Read the voltage from strain gauge
     * 
     * To measure the change in resistance of the strain gauge, this function reads from the analog input.
     * 
     * @return A value with a 10-bit resolution that reaches up to 5V
     */
    int readSensor();
    
    /**
     * @brief Filter several readings to get a more reliable impression
     * 
     * Take several readings and calculate the average to eliminate spikes
     */
    void filterReadings();

    /**
     * @brief Convert the measured voltage to resistance
     * 
     * Convert measured voltage to resistance by dividing voltage by current,
     * following the formula U = I * R -> R = U / I.
     */
    void convertVoltageToResistance();

    /**
     * @brief Convert the resistance to a desired unit.
     * 
     * This function will convert the resistance to a Newton
     * This is done by multiplying the resistance by a value (newtonFactor) that will be determined during calibration.
     */
    void convertResistanceToNewton();

    /**
     * @brief Convert analog input reading to a voltage
     * 
     * This function will the 10-bit sensor reading to a voltage.
     * This is done by dividing the reading by the maximum value and multiplying by the maximum voltage.
     */
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
     */
    void calibrate();

    /**
     * @brief Return resistance
     * 
     * This function returns the current resistance of the strain gauge in kOhm.
     * 
     * @return The resistance in kOhm
     */
    double getResistance();

    /**
     * @brief Return Newton
     * 
     * This function returns the amount of force on the material the strain gauge is attached to in Newton.
     * 
     * @return The force in Newton
     */
    double getNewton();
};

#endif // STRAIN_GAUGE_HPP