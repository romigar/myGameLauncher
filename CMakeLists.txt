cmake_minimum_required(VERSION 3.1)

project(myGame LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

add_executable(${PROJECT_NAME} "main.cpp" "qml.qrc")
target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Quick)

add_subdirectory(countryGuess)

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/countryGuess
        ${CMAKE_CURRENT_SOURCE_DIR}/countryGuess/world
        ${CMAKE_CURRENT_SOURCE_DIR}/countryGuess/game
        )
target_link_libraries(${PROJECT_NAME} PUBLIC Qt5::Core Qt5::Quick world game)
add_dependencies(${PROJECT_NAME} world game)
