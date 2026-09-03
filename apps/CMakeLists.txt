add_executable(telegen_app main.cpp)

target_link_libraries(telegen_app
    PRIVATE
        telegen_core
        ftxui::screen
        ftxui::dom
        ftxui::component
)
