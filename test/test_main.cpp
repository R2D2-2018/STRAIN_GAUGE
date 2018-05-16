#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

TEST_CASE( "Example Test Case" ) {
    REQUIRE(10 == 10);
}

TEST_CASE( "Test voltage to resistance conversion" ) {
	REQUIRE(convertVoltageToResistance(4.7) == 0.47);
}

TEST_CASE( "Test resistance to X conversion" ) {
	REQUIRE(convertResistanceToX(0.47) == 1.6215);
}