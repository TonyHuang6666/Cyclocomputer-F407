# CMSIS Build CMakeLists generated on 2023-08-09T21:56:42

cmake_minimum_required(VERSION 3.22)

# Target options

set(TARGET Cyclocomputer)
set(CPU Cortex-M3)
set(PRJ_DIR "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer")
set(OUT_DIR "D:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/out/Cyclocomputer/Target_1")
set(INT_DIR "D:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/tmp/Cyclocomputer/Target_1")
set(FPU NO_FPU)
set(SECURE Non-secure)
set(BYTE_ORDER Little-endian)
set(OPTIMIZE none)
set(DEBUG on)
set(AS_FLAGS_GLOBAL "-masm=auto")
set(CC_FLAGS_GLOBAL "-fno-rtti -funsigned-char -fshort-enums -fshort-wchar -ffunction-sections -std=c11 -w")
set(CXX_FLAGS_GLOBAL "-fno-rtti -funsigned-char -fshort-enums -fshort-wchar -ffunction-sections -std=c11 -w")
set(LD_FLAGS_GLOBAL "--map --load_addr_map_info --xref --callgraph --symbols --info sizes --info totals --info unused --info veneers --list --strict --summary_stderr --info summarysizes")
set(LD_SCRIPT "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Cyclocomputer_Target_1.sct")

set(DEFINES
  STM32F10X_MD
  USE_STDPERIPH_DRIVER
)

set(INC_PATHS
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Driver"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Library"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Peripherals"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Start"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/System"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/User"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Peripherals/0.96_OLED_IIC"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Peripherals/LED"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Peripherals/MPU6050"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Peripherals/W25Q64"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Peripherals/2.4_TFT_SPI"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Peripherals/Key"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/FreeRTOS/include"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/FreeRTOS/portable/RVDS/ARM_CM3"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/FreeRTOS"
  "C:/Users/Wendo/AppData/Local/Arm/Packs/Keil/STM32F1xx_DFP/2.4.1/Device/Include"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Peripherals/Through_Beam_Sensor"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Peripherals/DC Motor"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Peripherals/Rotary Encoder"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Peripherals/Servo Motor"
)

set(AS_ARM_SRC_FILES
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Start/startup_stm32f10x_md.s"
)

set(CC_SRC_FILES
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Driver/ADC.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Driver/DMA.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Driver/IIC.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Driver/Input_Capture.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Driver/PWM.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Driver/SPI.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Driver/Serial.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Driver/Timer.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Driver/Timer_External_Clock.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/FreeRTOS/croutine.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/FreeRTOS/event_groups.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/FreeRTOS/list.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/FreeRTOS/portable/MemMang/heap_4.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/FreeRTOS/portable/RVDS/ARM_CM3/port.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/FreeRTOS/queue.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/FreeRTOS/stream_buffer.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/FreeRTOS/tasks.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/FreeRTOS/timers.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Library/misc.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Library/stm32f10x_adc.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Library/stm32f10x_bkp.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Library/stm32f10x_can.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Library/stm32f10x_cec.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Library/stm32f10x_crc.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Library/stm32f10x_dac.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Library/stm32f10x_dbgmcu.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Library/stm32f10x_dma.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Library/stm32f10x_exti.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Library/stm32f10x_flash.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Library/stm32f10x_fsmc.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Library/stm32f10x_gpio.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Library/stm32f10x_i2c.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Library/stm32f10x_iwdg.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Library/stm32f10x_pwr.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Library/stm32f10x_rcc.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Library/stm32f10x_rtc.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Library/stm32f10x_sdio.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Library/stm32f10x_spi.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Library/stm32f10x_tim.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Library/stm32f10x_usart.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Library/stm32f10x_wwdg.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Peripherals/0.96_OLED_IIC/0.96_OLED_IIC.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Peripherals/2.4_TFT_SPI/2.4TFT.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Peripherals/2.4_TFT_SPI/test.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Peripherals/DC Motor/DC_Motor.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Peripherals/Key/Key.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Peripherals/MPU6050/MPU6050.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Peripherals/Rotary Encoder/Rotary_Encoder.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Peripherals/Servo Motor/Servo_Motor.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Peripherals/Through_Beam_Sensor/Through_Beam_Sensor.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Peripherals/W25Q64/W25Q64.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Start/core_cm3.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/Start/system_stm32f10x.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/System/Delay.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/System/sys.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/User/main.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer/User/stm32f10x_it.c"
)

# Toolchain config map

set(REGISTERED_TOOLCHAIN_ROOT "c:/Users/Wendo/.vcpkg/artifacts/fd3d78d7/compilers.arm.armclang/6.20.0/bin")
set(REGISTERED_TOOLCHAIN_VERSION "6.20.0")
set(TOOLCHAIN_VERSION_MIN "6.20.0")
include ("C:/Users/Wendo/.vcpkg/artifacts/fd3d78d7/tools.open.cmsis.pack.cmsis.toolbox/2.0.0/etc/AC6.6.18.0.cmake")
include ("C:/Users/Wendo/.vcpkg/artifacts/fd3d78d7/tools.open.cmsis.pack.cmsis.toolbox/2.0.0/etc/CMSIS-Build-Utils.cmake")

# Setup project

project(${TARGET} LANGUAGES AS_ARM C)

cbuild_get_running_toolchain(TOOLCHAIN_ROOT TOOLCHAIN_VERSION C)

# Global Flags

set(CMAKE_AS_ARM_FLAGS "${AS_ARM_CPU} ${AS_ARM_BYTE_ORDER} ${AS_ARM_DEFINES} ${AS_ARM_OPTIONS_FLAGS} ${AS_ARM_FLAGS} ${AS_FLAGS_GLOBAL}")
cbuild_get_system_includes(CC_SYS_INC_PATHS_LIST CC_SYS_INC_PATHS)
set(CMAKE_C_FLAGS "${CC_CPU} ${CC_BYTE_ORDER} ${CC_DEFINES} ${CC_SECURE} ${CC_OPTIONS_FLAGS} ${CC_FLAGS} ${CC_FLAGS_GLOBAL} ${CC_SYS_INC_PATHS}")
set(CMAKE_C_LINK_FLAGS "${LD_CPU} ${_LS}\"${LD_SCRIPT}\" ${LD_SECURE} ${LD_FLAGS_GLOBAL} ${LD_OPTIONS_FLAGS} ${LD_FLAGS}")

# Local Flags

foreach(SRC ${AS_ARM_SRC_FILES})
  set_source_files_properties(${SRC} PROPERTIES LANGUAGE AS_ARM)
endforeach()

# Compilation Database

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_custom_target(database COMMAND ${CMAKE_COMMAND} -E copy_if_different "${INT_DIR}/compile_commands.json" "${OUT_DIR}")

# Setup Target

add_executable(${TARGET} ${AS_ARM_SRC_FILES} ${CC_SRC_FILES})
set_target_properties(${TARGET} PROPERTIES PREFIX "" SUFFIX ".axf" OUTPUT_NAME "Cyclocomputer")
set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUT_DIR} LINK_DEPENDS ${LD_SCRIPT})
target_include_directories(${TARGET} PUBLIC ${INC_PATHS})
