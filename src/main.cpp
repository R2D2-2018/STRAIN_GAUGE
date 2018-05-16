#include "wrap-hwlib.hpp"

#include "strain-gauge.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);
    hwlib::cout << "Hello world!\r" << hwlib::endl;

    StrainGauge strainGauge = StrainGauge();
    hwlib::cout << strainGauge.readSensor() << "\r" << hwlib::endl;
    hwlib::cout << (int) strainGauge.filterReadings() << "\r" << hwlib::endl;
    hwlib::cout << (int) strainGauge.convertVoltageToResistance(4.3) << "\r" << hwlib::endl;
    hwlib::cout << (int) strainGauge.convertResistanceToX(2.64) << "\r" << hwlib::endl;
    
    return 0;
}
