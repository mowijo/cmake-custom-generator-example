cmake_minimum_required (VERSION 3.16.3)
project ( as-a-macro )

set ( EXECUTABLE_NAME as-a-macro )



macro( add_speaker FILENAME )

    get_filename_component(SPEAKER_CLASS_NAME_INSIDE_MACRO ${FILENAME} NAME_WE)
    set( GENERATED_SPEAKER_CPP ${CMAKE_CURRENT_BINARY_DIR}/speakers_generated_during_build/${SPEAKER_CLASS_NAME_INSIDE_MACRO}.cpp)
    set( SPEAKER_SRCS ${SPEAKER_SRCS} ${GENERATED_SPEAKER_CPP})
    add_custom_command(
        OUTPUT
            ${GENERATED_SPEAKER_CPP}
        COMMAND
            ${CMAKE_CURRENT_SOURCE_DIR}/../tools/speakerGenerator.sh
            ARGS
                ${CMAKE_CURRENT_SOURCE_DIR}/${FILENAME}
                ${CMAKE_CURRENT_BINARY_DIR}/speakers_generated_during_build/
        DEPENDS
            ${CMAKE_CURRENT_SOURCE_DIR}/${FILENAME}
    )
endmacro()

add_speaker("../Hercule.speak")
add_speaker("../LongFeng.speak")


add_executable(${EXECUTABLE_NAME} main.cpp ${SPEAKER_SRCS})

target_include_directories (${EXECUTABLE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/)
