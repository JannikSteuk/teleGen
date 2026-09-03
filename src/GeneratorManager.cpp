#include "telegen/GeneratorManager.hpp"
#include "telegen/HydraulicPump.hpp"

void GeneratorManager::add_hydraulic_pump(const std::string& name, double inital_pressure_bar, double target_pressure_bar) {
    generators.push_back(
        std::make_unique<HydraulicPump>(next_id++, name, inital_pressure_bar, target_pressure_bar)
    );
}

void GeneratorManager::remove_generator(size_t index) {
    if (index < generators.size()) {
        generators.erase(generators.begin() + index);
    }
}

const std::vector<std::unique_ptr<TelemetryGenerator>>& GeneratorManager::get_generators() const {
    return generators;
}