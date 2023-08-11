# CMSIS Build CMakeLists generated on 2023-08-11T22:11:30

cmake_minimum_required(VERSION 3.22)

# Target options

set(TARGET Cyclocomputer-F407)
set(CPU Cortex-M4)
set(PRJ_DIR "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG")
set(OUT_DIR "D:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/out/Cyclocomputer-F407/Target_1")
set(INT_DIR "D:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/tmp/Cyclocomputer-F407/Target_1")
set(FPU SP_FPU)
set(SECURE Non-secure)
set(BYTE_ORDER Little-endian)
set(DEBUG on)
set(AS_FLAGS_GLOBAL "-masm=auto")
set(CC_FLAGS_GLOBAL "-fno-rtti -funsigned-char -fshort-enums -fshort-wchar -ffunction-sections -std=c11 -w")
set(CXX_FLAGS_GLOBAL "-fno-rtti -funsigned-char -fshort-enums -fshort-wchar -ffunction-sections -std=c11 -w")
set(LD_FLAGS_GLOBAL "--map --load_addr_map_info --xref --callgraph --symbols --info sizes --info totals --info unused --info veneers --list --strict --summary_stderr --info summarysizes")
set(LD_SCRIPT "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/Cyclocomputer-F407_Target_1.sct")

set(DEFINES
  STM32F407xx
  USE_STDPERIPH_DRIVER
  STM32F40_41xxx
)

set(INC_PATHS
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/Driver"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/Peripherals"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/System"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/User"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/Peripherals/0.96_OLED_IIC"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/Peripherals/LED"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/Peripherals/MPU6050"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/Peripherals/W25Q64"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/Peripherals/2.4_TFT_SPI"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/Peripherals/Key"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/FreeRTOS/include"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/FreeRTOS/portable/GCC/ARM_CM4F"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/FreeRTOS"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/CMSIS"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver"
  "C:/Users/Wendo/AppData/Local/Arm/Packs/Keil/STM32F4xx_DFP/2.17.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include"
)

set(AS_ARM_SRC_FILES
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/CMSIS/startup_stm32f40xx.s"
)

set(CC_SRC_FILES
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/CMSIS/system_stm32f4xx.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/Driver/SPI.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/FreeRTOS/croutine.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/FreeRTOS/event_groups.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/FreeRTOS/list.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/FreeRTOS/portable/GCC/ARM_CM4F/port.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/FreeRTOS/portable/MemMang/heap_4.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/FreeRTOS/queue.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/FreeRTOS/stream_buffer.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/FreeRTOS/tasks.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/FreeRTOS/timers.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/Peripherals/2.4_TFT_SPI/2.4TFT.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/Peripherals/2.4_TFT_SPI/test.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/misc.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_adc.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_can.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_cec.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_crc.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_cryp.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_cryp_aes.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_cryp_des.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_cryp_tdes.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_dac.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_dbgmcu.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_dcmi.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_dfsdm.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_dma.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_dma2d.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_dsi.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_exti.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_flash.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_flash_ramfunc.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_fmpi2c.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_fsmc.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_gpio.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_hash.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_hash_md5.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_hash_sha1.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_i2c.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_iwdg.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_lptim.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_ltdc.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_pwr.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_qspi.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_rcc.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_rng.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_rtc.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_sai.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_sdio.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_spdifrx.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_spi.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_syscfg.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_tim.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_usart.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/STM32F4xx_StdPeriph_Driver/stm32f4xx_wwdg.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/System/Delay.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/System/sys.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/User/main.c"
  "d:/OneDrive - email.szu.edu.cn/Codes/VS Code/Cyclocomputer-F407VG/User/stm32f4xx_it.c"
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
set_target_properties(${TARGET} PROPERTIES PREFIX "" SUFFIX ".axf" OUTPUT_NAME "Cyclocomputer-F407")
set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUT_DIR} LINK_DEPENDS ${LD_SCRIPT})
target_include_directories(${TARGET} PUBLIC ${INC_PATHS})
