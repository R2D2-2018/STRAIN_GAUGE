#include "flex_sensor.hpp"
#include "strain_gauge.hpp"
#include "wrap-hwlib.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);

    auto input = hwlib::target::pin_adc(hwlib::target::ad_pins::a1);
    FlexSensor sensor(input);
    sensor.calibrate();

    while (true) {
        hwlib::cout << "R: " << sensor.getResistance() << "\r" << hwlib::endl;
        hwlib::cout << "A: " << sensor.getAngle() << "\r" << hwlib::endl;
        hwlib::wait_ms(500);
    }
    return 0;
}