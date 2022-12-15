project(tests)

# ------------------------------------------------------------------------------

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Core Network Sql REQUIRED)

add_executable(${PROJECT_NAME} "test-distance.cpp" )

# ------------------------------------------------------------------------------

aux_source_directory(. SRCS)
file(GLOB_RECURSE OTHER_FILES "./*.h*")

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../game
        ${CMAKE_CURRENT_SOURCE_DIR}/../world
        )

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt5::Core
    Qt5::Network
    game
    world
    )

add_dependencies(${PROJECT_NAME} world game)

# ------------------------------------------------------------------------------

add_executable(test-liste "test-liste.cpp" )
aux_source_directory(. SRCS)
file(GLOB_RECURSE OTHER_FILES "./*.h*")
target_include_directories(test-liste PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../game
        ${CMAKE_CURRENT_SOURCE_DIR}/../world
        )
target_link_libraries(test-liste PUBLIC
    Qt5::Core
    Qt5::Network
    game
    world
    )
add_dependencies(${PROJECT_NAME} world game)

# ------------------------------------------------------------------------------




