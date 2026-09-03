#pragma once

#include "telegen/TelemetryGenerator.hpp"
#include <vector>
#include <memory>


class GeneratorManager{
    private:
        std::vector<std::unique_ptr<TelemetryGenerator>> generators;
        uint32_t next_id = 1;
    
    public: 
        GeneratorManager() = default;

        void add_hydraulic_pump(const std::string& name, double initial_pressure, double target_pressure);
        void remove_generator(size_t index);

        const std::vector<std::unique_ptr<TelemetryGenerator>>& get_generators() const;
};