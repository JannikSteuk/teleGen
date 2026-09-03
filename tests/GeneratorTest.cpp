#include <gtest/gtest.h>
#include "telegen/HydraulicPump.hpp"
#include "telegen/GeneratorManager.hpp"

TEST(HydraulicPumpTest, PressureApproachesTarget) {
    HydraulicPump pump(1, "TestPump", 0.0, 100.0);

    auto p1 = pump.generate_next();
    auto p2 = pump.generate_next();

    EXPECT_GT(p2.value, p1.value);
    EXPECT_LE(p2.value, 100.0);
}

TEST(HydraulicPumpTest, ThrowsOnInvalidPressureValues) {
    // Negativer Druck
    EXPECT_THROW(
        HydraulicPump(1, "PumpNegative", -5.0, 100.0),
        std::invalid_argument
    );

    // Initial pressure higher than target pressure
    EXPECT_THROW(
        HydraulicPump(1, "PumpInvalidTarget", 150.0, 100.0),
        std::invalid_argument
    );
}

TEST(GeneratorManagerTest, AddsAndRemovesGenerators) {
    GeneratorManager manager;
    EXPECT_EQ(manager.get_generators().size(), 0);

    manager.add_hydraulic_pump("Pumpe 1", 0.0, 50.0);
    EXPECT_EQ(manager.get_generators().size(), 1);

    manager.remove_generator(0);
    EXPECT_EQ(manager.get_generators().size(), 0);
}