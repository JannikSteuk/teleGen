#include "telegen/HydraulicPump.hpp"
#include <stdexcept>
#include <chrono>

HydraulicPump::HydraulicPump(uint32_t id, std::string name, double intial_pressure_bar, double target_pressure_bar) : TelemetryGenerator(id, std::move(name)) {

    if (intial_pressure_bar < 0.0 || target_pressure_bar < 0.0) {
        throw std::invalid_argument("Pressure values are not allowed to be negative!");
    }

    if (intial_pressure_bar > target_pressure_bar) {
        throw std::invalid_argument("The initial pressure value must be smaller than the target pressure!");
    }

    this->current_pressure_bar = intial_pressure_bar;
    this->target_pressure_bar = target_pressure_bar;
}

/*
* Generates the next value based on the calculations of the generator via a TelemetryPacket
*/
TelemetryPacket HydraulicPump::generate_next() {
    double delta = (target_pressure_bar - current_pressure_bar) * 0.1;
    current_pressure_bar += delta;

    auto now = std::chrono::high_resolution_clock::now().time_since_epoch();
    uint64_t timestamp = std::chrono::duration_cast<std::chrono::nanoseconds>(now).count();

    return TelemetryPacket{ id, timestamp, current_pressure_bar};
}


/*
    Sets the parameter based on the given key as string, idk if it should stay this way, for now its fine
*/
void HydraulicPump::set_parameter(const std::string& key, double value) {
    if (key == "target_pressure_bar") {
        target_pressure_bar = value;
    }
}