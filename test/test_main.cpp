#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "flex_sensor.hpp"
#include "strain_gauge.hpp"
#include "wrap-hwlib.hpp"

TEST_CASE("Measuring resistance") {
    hwlib::test::pin_adc<> inputPin = {2325, 2325, 2326, 2325, 2326};

    StrainGauge sensor(inputPin);

    REQUIRE(sensor.getResistance() == 35046);
}

TEST_CASE("Measuring angle") {
    hwlib::test::pin_adc<> inputPin = {1414, 1451, 1485, 1466, 1466};

    FlexSensor sensor(inputPin);

    REQUIRE(sensor.getAngle() == 185);
}

TEST_CASE("Calibration") {
    hwlib::test::pin_adc<> inputPin = {2325, 2325, 2326, 2325, 2326, 2325, 2325, 2326, 2325, 2326,
                                       2325, 2325, 2326, 2325, 2326, 2325, 2325, 2326, 2325, 2326};

    FlexSensor sensor(inputPin);

    sensor.getResistance();
    sensor.calibrate();

    REQUIRE(sensor.getAngle() == 0);
}