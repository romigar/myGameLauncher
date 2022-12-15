project(game)

# ------------------------------------------------------------------------------

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Core Network Sql REQUIRED)

# ------------------------------------------------------------------------------

aux_source_directory(. SRCS)
file(GLOB_RECURSE OTHER_FILES "./*.h*")

add_library(${PROJECT_NAME} STATIC
    ${SRCS}
    ${OTHER_FILES}
    )

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../world
        )

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt5::Core
    Qt5::Network
    world
    )

add_dependencies(${PROJECT_NAME} world)


