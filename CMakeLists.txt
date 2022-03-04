cmake_minimum_required (VERSION 2.8.11)
project ( talker )

set ( EXECUTABLE_NAME ${CMAKE_PROJECT_NAME})

add_custom_command(
    OUTPUT
        ${CMAKE_CURRENT_BINARY_DIR}/speakers_generated_during_build/Hercule.cpp
    COMMAND
        ${CMAKE_CURRENT_SOURCE_DIR}/tools/speakerGenerator.sh
        ARGS ${CMAKE_CURRENT_SOURCE_DIR}/Hercule.speak ${CMAKE_CURRENT_BINARY_DIR}/speakers_generated_during_build/
    DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/Hercule.speak
)

add_executable(${EXECUTABLE_NAME} main.cpp ${CMAKE_CURRENT_BINARY_DIR}/speakers_generated_during_build/Hercule.cpp)

target_include_directories (${EXECUTABLE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/)
