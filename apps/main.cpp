#include <iostream>
#include "telegen/GeneratorManager.hpp"

int main() {
    GeneratorManager manager;
    manager.add_hydraulic_pump("Haupt-Hydraulik", 10.0, 150.0);
    manager.add_hydraulic_pump("Kühlkreis-Pumpe", 2.0, 45.0);

    std::cout << "=== TeleGen Backend Simulator ===\n\n";

    // Simuliere 5 Zeitschritte
    for (int step = 1; step <= 5; ++step) {
        std::cout << "--- Schritt " << step << " ---\n";
        for (const auto& gen : manager.get_generators()) {
            auto packet = gen->generate_next();
            std::cout << "  [" << gen->get_id() << "] " << gen->get_name()
                      << " | Druck: " << packet.value << " bar"
                      << " | Timestamp: " << packet.timestamp_ns << " ns\n";
        }
    }

    return 0;
}