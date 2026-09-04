#pragma once
#include "telegen/ui/GeneratorEditorWidget.hpp"
#include "telegen/HydraulicPump.hpp"

namespace telegen::ui {
    class HydraulicPumpEditorWidget : public GeneratorEditorWidget {
        public:
            explicit HydraulicPumpEditorWidget(std::shared_ptr<HydraulicPump> pump);
        
        protected:
            ftxui::Component get_custom_fields_components() override;
            void save_custom_fields() override;

        private:
            std::shared_ptr<HydraulicPump> pump_;
            std::string min_pressure_str_;
            std::string max_pressure_str_;
    };
}