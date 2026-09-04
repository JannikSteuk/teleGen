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

        //Getter

        double get_min_pressure() {return current_pressure_bar;}
        double get_max_pressure() {return target_pressure_bar;}

        //Setter

        void set_min_pressure(double min_pressure) {this->current_pressure_bar = min_pressure;}
        void set_max_pressure(double max_pressure) {this->target_pressure_bar = max_pressure;}
};