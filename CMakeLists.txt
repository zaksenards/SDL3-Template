project(SDLTemplate)
cmake_minimum_required(VERSION 3.0.5)

SET(SDL3_PATH C:/SDL3)
SET(SDL3_LIB_PATH C:/SDL3/lib/x64)
SET(SDL3_INCLUDE_PATH C:/SDL3/include)

add_executable(SDLTemplate template.cpp)
target_compile_definitions(SDLTemplate PRIVATE SDL_MAIN_HANDLED)
target_include_directories(SDLTemplate PUBLIC ${SDL3_INCLUDE_PATH})
target_link_directories(SDLTemplate PUBLIC ${SDL3_LIB_PATH})
target_link_libraries(SDLTemplate SDL3.lib)

add_custom_command(
    TARGET SDLTemplate POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory 
    ${CMAKE_SOURCE_DIR}/bin
)

add_custom_command(
    TARGET SDLTemplate POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:SDLTemplate>
        ${CMAKE_SOURCE_DIR}/bin/SDLTemplate.exe
)

add_custom_command(
    TARGET SDLTemplate POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${SDL3_LIB_PATH}/SDL3.dll
        ${CMAKE_SOURCE_DIR}/bin/SDL3.dll
)
