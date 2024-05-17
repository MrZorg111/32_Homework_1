cmake_minimum_required(VERSION 3.21)

add_executable("32_Homework_1" main.cpp ${MY_INCLUDE_DIR}/function.h)
target_include_directories("32_Homework_1" PUBLIC ${MY_INCLUDE_DIR})
target_link_libraries("32_Homework_1" PRIVATE nlohmann_json::nlohmann_json)