#pragma once
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <memory>
#include <vector>
#include <string>

#include "telegen/GeneratorManager.hpp"
#include "telegen/ui/GeneratorEditorWidget.hpp"

namespace telegen::ui {
    class DashboardApp {
        public:
            //Dependency Injection happening here !
            explicit DashboardApp(GeneratorManager& manager) : manager_(manager) {}
            void run();

        private:
            GeneratorManager& manager_;
    };
}