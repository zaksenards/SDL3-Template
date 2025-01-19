project(Lifez)
cmake_minimum_required(VERSION 3.0.5)

SET(SDL3_PATH C:/SDL3)
SET(SDL3_LIB_PATH C:/SDL3/lib/x64)
SET(SDL3_INCLUDE_PATH C:/SDL3/include)

add_executable(Lifez main.cpp)
target_compile_definitions(Lifez PRIVATE SDL_MAIN_HANDLED)
target_include_directories(Lifez PUBLIC ${SDL3_INCLUDE_PATH})
target_link_directories(Lifez PUBLIC ${SDL3_LIB_PATH})
target_link_libraries(Lifez SDL3.lib)

add_custom_command(
    TARGET Lifez POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory 
    ${CMAKE_SOURCE_DIR}/bin
)

add_custom_command(
    TARGET Lifez POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:Lifez>
        ${CMAKE_SOURCE_DIR}/bin/Lifez.exe
)

add_custom_command(
    TARGET Lifez POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${SDL3_LIB_PATH}/SDL3.dll
        ${CMAKE_SOURCE_DIR}/bin/SDL3.dll
)
