#pragma once

#include "telegen/TelemetryGenerator.hpp"

class HydraulicPump : public TelemetryGenerator {
    private:
        double target_pressure_bar;
        double current_pressure_bar;

    public:
        HydraulicPump(uint32_t id, std::string name, double initial_pressure = 0.0, double target_pressure = 0.0);

        TelemetryPacket generate_next() override;
        void set_parameter(const std::string& key, double value) override;
};