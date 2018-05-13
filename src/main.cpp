#include "wrap-hwlib.hpp"

#include "strain-gauge.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);
    hwlib::cout << "Hello world!" << hwlib::endl;

    StrainGauge strainGauge = StrainGauge();
    hwlib::cout << strainGauge.readSensor() << hwlib::endl;
    hwlib::cout << (int) strainGauge.filterReadings() << hwlib::endl;
    hwlib::cout << (int) strainGauge.convertVoltageToResistance(4.3) << hwlib::endl;
    hwlib::cout << (int) strainGauge.convertResistanceToX(2.64) << hwlib::endl;
    
    return 0;
}
