#include "telegen/GeneratorManager.hpp"
#include "telegen/ui/DashboardApp.hpp"

using namespace telegen;

int main() {
    // 1. Manager instanziieren & Initialdaten anlegen
    GeneratorManager manager;
    manager.add_hydraulic_pump("Haupt-Hydraulik", 10.0, 150.0);
    manager.add_hydraulic_pump("Kühlkreis-Pumpe", 2.0, 45.0);

    // 2. UI-App mit dem Manager initialisieren (Composition Root)
    ui::DashboardApp app(manager);

    // 3. TUI starten
    app.run();

    return 0;
}