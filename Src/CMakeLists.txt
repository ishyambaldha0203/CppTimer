################################################################
# SOURCE
################################################################
### The main CMake file does not know nor care where the sources are.
target_sources(${CPP_TIMER_TARGET_NAME}
    PRIVATE
        # Src
        ${CMAKE_CURRENT_LIST_DIR}/main.cpp

        # Src/Internal
        ${CMAKE_CURRENT_LIST_DIR}/Internal/ObjectFactory.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Internal/Program.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Internal/Timer.cpp
)
