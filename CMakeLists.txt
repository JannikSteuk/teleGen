# 1. Initialisierung
cmake_minimum_required(VERSION 3.20)
project(TeleGen VERSION 0.1.0 LANGUAGES CXX)

# 2. Setting C++ standarts
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 3. Das Download-Werkzeug von CMake aktivieren
include(FetchContent)

# 4. FTXUI (Terminal UI) aus dem Internet laden
FetchContent_Declare(
  ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
  GIT_TAG        main
)
FetchContent_MakeAvailable(ftxui)

# 5. GoogleTest (Test Framework) aus dem Internet laden
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 6. Unsere Kern-Logik als Bibliothek definieren 
add_library(telegen_core
    src/HydraulicPump.cpp
    src/GeneratorManager.cpp
    src/DashboardApp.cpp
    src/GeneratorEditorWidget.cpp        
    src/HydraulicPumpEditorWidget.cpp    
)
target_include_directories(telegen_core PUBLIC include)

target_link_libraries(telegen_core 
  PUBLIC 
    ftxui::screen
    ftxui::dom 
    ftxui::component)

# 7. Die Unterordner einbinden
add_subdirectory(apps)
add_subdirectory(tests)
