cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

add_executable(sfml.3.3 main.cpp)

target_include_directories(sfml.3.3 PRIVATE ${SFML_INCLUDE_DIR})
target_compile_features(sfml.3.3 PUBLIC cxx_std_17)
target_compile_definitions(sfml.3.3 PRIVATE SFML_STATIC)

target_link_libraries(sfml.3.3 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})