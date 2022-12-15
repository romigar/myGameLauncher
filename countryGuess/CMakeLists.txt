cmake_minimum_required(VERSION 3.1)

project(countryGuess LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

add_executable(${PROJECT_NAME} "main.cpp" "qml.qrc")

file(GLOB_RECURSE OTHER_FILES "./*.h*")

add_subdirectory(world)
add_subdirectory(game)
add_subdirectory(tests)

target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME} PUBLIC Qt5::Core Qt5::Quick world game)
add_dependencies(${PROJECT_NAME} world game)

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/world
        ${CMAKE_CURRENT_SOURCE_DIR}/game
        )
