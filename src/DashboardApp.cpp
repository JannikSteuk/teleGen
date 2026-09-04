#include "telegen/ui/DashboardApp.hpp"

namespace telegen::ui
{

   void DashboardApp::run() {
        int selected_index = 0;
        std::vector<std::string> generator_names;

        auto refresh_list = [&]() {
            generator_names.clear();
            for(const auto& gen : manager_.get_generators()){
                generator_names.push_back("[" + std::to_string(gen->get_id()) + "] " + gen->get_name());
            }
        };
        refresh_list();

        //Left row for selecting the generator
        auto menu = ftxui::Menu(&generator_names, &selected_index);

        //buttons for crud operations
        auto btn_add = ftxui::Button(" + Add pump", [&] {
            manager_.add_hydraulic_pump("New Pump", 0.0, 100.0);
            refresh_list();
            selected_index = static_cast<int>(generator_names.size()) - 1;
        });

        // bttn for deleting generator
        auto btn_delete = ftxui::Button(" - Löschen ", [&] {
            if (!manager_.get_generators().empty() && selected_index >= 0) {
                auto id = manager_.get_generators()[selected_index]->get_id();
                manager_.remove_generator(id);
                refresh_list();
                if (selected_index >= static_cast<int>(generator_names.size())) {
                    selected_index = std::max(0, static_cast<int>(generator_names.size()) - 1);
                }
            }
        });

        auto left_pane = ftxui::Container::Vertical({
            menu,
            ftxui::Container::Horizontal({btn_add, btn_delete}),
        });

        auto screen = ftxui::ScreenInteractive::TerminalOutput();

        auto main_renderer = ftxui::Renderer(left_pane, [&] {
            return ftxui::hbox({
                ftxui::vbox({
                    ftxui::text(" Registered generators") | ftxui::bold | ftxui::hcenter,
                    ftxui::separator(),
                    menu ->Render() | ftxui::flex,
                    ftxui::separator(),
                    ftxui::hbox({ btn_add->Render(), btn_delete->Render()}),
                }) | ftxui::size(ftxui::WIDTH, ftxui::LESS_THAN, 35) | ftxui::border,

                ftxui::vbox({
                    ftxui::text(" Generator editor") | ftxui::bold | ftxui::hcenter, 
                    ftxui::separator(),
                    ftxui::text(generator_names.empty() ? "No generator selected" : "Editor active for index: " + std::to_string(selected_index)),
                }) | ftxui::flex | ftxui::border,
            });
        });

        screen.Loop(main_renderer);
    }
} // namespace telegen::ui
