#include "telegen/ui/GeneratorEditorWidget.hpp"

namespace telegen::ui {
    GeneratorEditorWidget::GeneratorEditorWidget(std::shared_ptr<TelemetryGenerator> generator)
        : generator_(std::move(generator)), 
        name_input_(generator_ ? generator->get_name() : " ") {}

    ftxui::Component GeneratorEditorWidget::get_component() {
        auto base_form = ftxui::Container::Vertical({
           ftxui::Input(&name_input_, "Generator Name"), 
        });

        auto custom_fields = get_custom_fields_components();
        if(custom_fields) {
            base_form->Add(custom_fields);
        }

        return base_form;
    }

    void GeneratorEditorWidget::save() {
        if(generator_) {
            generator_->set_name(name_input_);
        }
        save_custom_fields();
    }

    void GeneratorEditorWidget::save_custom_fields() {
        // Base class has no implemented function cause there are no custom fields ...
    }
}
