#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "strain_gauge.hpp"
#include "wrap-hwlib.hpp"

TEST_CASE("Test 12-bit ADC value to voltage to resistance conversion") {
    hwlib::test::pin_adc<> input = {0, 1032, 293, 192, 3964};
    StrainGauge::StrainGauge strainGauge(input);
    REQUIRE(strainGauge.getResistance() == 260);
    REQUIRE(strainGauge.getResistance() == 73);
    REQUIRE(strainGauge.getResistance() == 48);
    REQUIRE(strainGauge.getResistance() == 1001);
}

TEST_CASE("Test resistance to force conversion") {
    hwlib::test::pin_adc<> input2 = {0, 1032, 293, 192, 3964};
    StrainGauge::StrainGauge strainGauge(input2);
    REQUIRE(strainGauge.getForce() == 260);
    REQUIRE(strainGauge.getForce() == 73);
    REQUIRE(strainGauge.getForce() == 48);
    REQUIRE(strainGauge.getForce() == 1001);
}
