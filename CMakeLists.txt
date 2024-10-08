cmake_minimum_required(VERSION 3.20)

# Project Name and Version
project(stm32f446xx VERSION 1.0.0 LANGUAGES C CXX ASM)

# Include the toolchain file
include(${CMAKE_SOURCE_DIR}/arm-none-eabi.cmake)

# Set target name for the firmware
set(TARGET firmware)

# Set the linker script
set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/STM32F446RETX_FLASH.ld)

# Collect all source files from the src directory
file(GLOB_RECURSE SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
)

# Check if any source files were found, error out if none
if(NOT SRCS)
    message(FATAL_ERROR "No source files found in the src directory!")
endif()

# Debug message to display source files collected
message(STATUS "Collected Source Files: ${SRCS}")

# Add subdirectory for the driver (must happen before linking)
add_subdirectory(driver)

# Create the main executable target for the firmware
add_executable(${TARGET} ${SRCS})

# Set target compile options
target_compile_options(${TARGET} PRIVATE
    -mcpu=cortex-m4
    -mthumb
    -mfloat-abi=soft
    -ffunction-sections
    -fdata-sections
    -Os 
    -Og 
    -g3
    -ggdb
)

# Set linker options
target_link_options(${TARGET} PRIVATE
    -T${LINKER_SCRIPT}
    -Wl,--gc-sections
    -Wl,--print-memory-usage
    -Wl,-Map=${TARGET}.map
    --specs=nano.specs
    -lc
    -lstdc++
)

# Link the driver library (hardware) to the firmware target
target_link_libraries(${TARGET} PRIVATE hardware)

# Post-build steps to generate .bin file from the .elf file
add_custom_command(TARGET ${TARGET} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -Obinary ${TARGET}.elf ${TARGET}.bin
)

# Optional custom target to flash the firmware using st-flash
add_custom_target(flash
    COMMAND st-flash write ${TARGET}.bin 0x08000000
    COMMAND st-flash reset
)
