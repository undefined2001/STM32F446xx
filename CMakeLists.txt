cmake_minimum_required(VERSION 3.5)

# Include the arm-none-eabi toolchain file
include(${CMAKE_SOURCE_DIR}/arm-none-eabi.cmake)

# Define the project name and languages
project(STM32F446xx VERSION 1.0.0 LANGUAGES ASM C CXX)

# Print the list of source files for debugging purposes
message(STATUS "Source files: ${SRCS}")

add_subdirectory(driver)

# Add the executable target
add_executable(${TARGET} ${SRCS})

# Include CMSIS directory
target_include_directories(${TARGET} PUBLIC ${CMAKE_SOURCE_DIR}/driver/cmsis ${CMAKE_SOURCE_DIR}/driver/inc)

target_link_libraries(${TARGET} hardware)

target_compile_definitions(${TARGET} PUBLIC STM32F446xx)

target_compile_options(${TARGET} PUBLIC
    $<$<CONFIG:Debug>:-g -ggdb>
    $<$<CONFIG:Release>:-Os>
)


target_link_options(${TARGET} PUBLIC 
    -T${LINKER_SCRIPT}
    -Wl,--start-group
    -Wl,--gc-sections
    -Wl,--print-memory-usage
    -Wl,-Map=${TARGET}.map
    -Wl,--end-group
    --specs=nano.specs
    -lc
    -lm
    -lstdc++
)

add_custom_command(TARGET ${TARGET} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -Obinary ${TARGET}.elf ${TARGET}.bin
)

add_custom_target(flash
    COMMAND st-flash write ${TARGET}.bin 0x08000000
    COMMAND st-flash reset
)