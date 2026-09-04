#include "telegen/ui/HydraulicPumpEditorWidget.hpp"

namespace telegen::ui {
    HydraulicPumpEditorWidget::HydraulicPumpEditorWidget(std::shared_ptr<HydraulicPump> pump)
        : GeneratorEditorWidget(pump),
        pump_(std::move(pump)),
        min_pressure_str_(pump_ ? std::to_string(pump_->get_min_pressure()) : "0.0"),
        max_pressure_str_(pump_ ? std::to_string(pump_->get_max_pressure()) : "0.0") {}
     
    ftxui::Component HydraulicPumpEditorWidget::get_custom_fields_components() {
        return ftxui::Container::Vertical({
            ftxui::Input(&min_pressure_str_, "Min Druck (bar)"),
            ftxui::Input(&max_pressure_str_, "Max Druck (bar)"),
        });       
    }

    void HydraulicPumpEditorWidget::save_custom_fields() {
        if (!pump_) {return;}
         
        try {
            pump_->set_min_pressure(std::stod(min_pressure_str_));
            pump_->set_max_pressure(std::stod(max_pressure_str_));
        }catch(const std::invalid_argument&){
            //Errorhandeling of unallowed number format
        }catch(const std::out_of_range&) {
            //Errorhandeling of to big numbers
        }
    }
}