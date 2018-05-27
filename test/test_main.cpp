#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "wrap-hwlib.hpp"
#include "strain_gauge.hpp"

TEST_CASE( "Example Test Case" ) {
    REQUIRE(10 == 10);
}

TEST_CASE( "Test 12-bit ADC value to voltage to resistance conversion" ) {
	hwlib::test::pin_adc input = {1032, 293, 192, 3964};
	StrainGauge strainGauge(input);
	REQUIRE(strainGauge.getResistance() == 260.70481242);
	REQUIRE(strainGauge.getResistance() == 74.01793608);
	REQUIRE(strainGauge.getResistance() == 48.50322091);
	REQUIRE(strainGauge.getResistance() == 1001.38941518);
	
	// ad = 1032
	// v = 1032/4095*3.3 = 0.83164835165
	// a = 3.19
	// r = v/(a/1000) = 0.83164835165/(3.19*1000) = 260.70481242947
}

TEST_CASE( "Test resistance to force conversion" ) {
	hwlib::test::pin_adc input = {1032, 293, 192, 3964};
	StrainGauge strainGauge(input);
	REQUIRE(strainGauge.getForce() == 260.70481242);
	REQUIRE(strainGauge.getForce() == 74.01793608);
	REQUIRE(strainGauge.getForce() == 48.50322091);
	REQUIRE(strainGauge.getForce() == 1001.38941518);
}