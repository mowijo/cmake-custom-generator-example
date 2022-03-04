cmake_minimum_required (VERSION 3.16.3)
project ( list-and-destination-variable-name )

set ( EXECUTABLE_NAME list-and-destination-variable-name)



function(add_speakers )
    set(list_var "${ARGN}")
    set(I 0)
    foreach(loop_var IN LISTS list_var)
        if( ${I} EQUAL 0 )
            set(SRC_LIST ${loop_var})
        else()
            get_filename_component(SPEAKER_CLASS_NAME_INSIDE_MACRO ${loop_var} NAME_WE)
            set( GENERATED_SPEAKER_CPP ${CMAKE_CURRENT_BINARY_DIR}/speakers_generated_during_build/${SPEAKER_CLASS_NAME_INSIDE_MACRO}.cpp)
            set( BOBBEL ${BOBBEL} ${GENERATED_SPEAKER_CPP})
            add_custom_command(
                OUTPUT
                    ${GENERATED_SPEAKER_CPP}
                COMMAND
                    ${CMAKE_CURRENT_SOURCE_DIR}/../tools/speakerGenerator.sh
                    ARGS
                        ${CMAKE_CURRENT_SOURCE_DIR}/${loop_var}
                        ${CMAKE_CURRENT_BINARY_DIR}/speakers_generated_during_build/
                DEPENDS
                    ${CMAKE_CURRENT_SOURCE_DIR}/${loop_var}
            )
        endif()
        MATH(EXPR I "${I}+1")
    endforeach()
    set(${SRC_LIST} ${BOBBEL} PARENT_SCOPE)

endfunction()


set( SPEAKER_DEFS
 ../Hercule.speak
 ../LongFeng.speak
 ../CaptainKirk.speak
)

add_speakers( FOO ${SPEAKER_DEFS} )

add_executable(${EXECUTABLE_NAME} main.cpp ${FOO})

target_include_directories (${EXECUTABLE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/)
