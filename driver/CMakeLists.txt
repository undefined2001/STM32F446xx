# Set the name of the driver library
set(LIBRARY_NAME hardware)

# Collect all source files in the driver/src directory
file(
    GLOB_RECURSE SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
)

message(STATUS "Driver Src Files: ${SRCS}")

# Create a static library for the driver
add_library(${LIBRARY_NAME} STATIC ${SRCS})

# Define the STM32F446xx macro for this library
target_compile_definitions(${LIBRARY_NAME} PUBLIC STM32F446xx)

# Add include directories for the driver
target_include_directories(${LIBRARY_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/driver/inc
    ${CMAKE_SOURCE_DIR}/driver/cmsis
)
