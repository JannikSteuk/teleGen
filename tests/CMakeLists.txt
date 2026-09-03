# Aktiviert CTest (Das Test-System von CMake)
enable_testing()

# Erzeuge die Test-Anwendung
add_executable(telegen_tests GeneratorTest.cpp)

# Verlinke unsere Logik und GoogleTest
target_link_libraries(telegen_tests
    PRIVATE
        telegen_core
        GTest::gtest_main
)

# Registriere die Tests automatisch
include(GoogleTest)
gtest_discover_tests(telegen_tests)
