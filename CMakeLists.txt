cmake_minimum_required(VERSION 3.26.4)

project(sfml-snake VERSION 1.0.1)

# clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# SFML config
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_DOC OFF CACHE BOOL "" FORCE)
set(SFML_INSTALL_PKGCONFIG_FILES OFF CACHE BOOL "" FORCE)
add_subdirectory(ext/SFML)

add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/button.cpp
    src/states.cpp
    src/menustate.cpp
    src/gamestate.cpp
    src/level.cpp
    src/snake.cpp
    src/food_spawner.cpp
    src/game.cpp)

#Copy resource folder to build directory
add_custom_target(copy_resources ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${PROJECT_SOURCE_DIR}/res
    ${PROJECT_BINARY_DIR}/res
    COMMENT "Copying resources into build directory")

add_dependencies(${PROJECT_NAME} 
    copy_resources)

target_link_libraries(${PROJECT_NAME}
    sfml-window
    sfml-graphics)

