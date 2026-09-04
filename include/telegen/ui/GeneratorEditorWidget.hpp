#pragma once
#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>
#include <memory>
#include <string>
#include "telegen/TelemetryGenerator.hpp"

namespace telegen::ui {
    class GeneratorEditorWidget {
    public:
        explicit GeneratorEditorWidget(std::shared_ptr<TelemetryGenerator> generator);
        virtual ~GeneratorEditorWidget() = default;

        
        /* Creates the build formular component*/
        ftxui::Component get_component();

        virtual void save();

    protected:
        virtual ftxui::Component get_custom_fields_components();
        virtual void save_custom_fields();

        std::shared_ptr<TelemetryGenerator> generator_;
        std::string name_input_;

    };
}