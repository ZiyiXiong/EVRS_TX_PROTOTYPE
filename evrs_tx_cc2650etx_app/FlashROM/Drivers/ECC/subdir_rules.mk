################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Drivers/ECC/ECCROMCC26XX.obj: C:/ti/ble_sdk_2_02_02_25/src/common/cc26xx/ecc/ECCROMCC26XX.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" --cmd_file="C:/ti/ble_sdk_2_02_02_25/examples/cc2650lp/simple_peripheral/ccs/app/../../iar/stack/../../../../../src/config/build_components.opt" --cmd_file="C:/ti/ble_sdk_2_02_02_25/examples/cc2650lp/simple_peripheral/ccs/app/../../iar/stack/build_config.opt" --cmd_file="C:/ti/ble_sdk_2_02_02_25/examples/cc2650lp/simple_peripheral/ccs/app/../../iar/stack/../../ccs/config/ccs_compiler_defines.bcfg"  -mv7M3 --code_state=16 -me -O4 --opt_for_speed=0 --include_path="E:/workbench/git/EVRS_BLE_Firmware/evrs_tx_cc2650etx_app/src" --include_path="E:/workbench/git/EVRS_BLE_Firmware/evrs_tx_cc2650etx_app/drv" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --include_path="C:/ti/ble_sdk_2_02_02_25/src/inc" --include_path="C:/ti/ble_sdk_2_02_02_25/src/icall/inc" --include_path="C:/ti/ble_sdk_2_02_02_25/src/profiles/roles/cc26xx" --include_path="C:/ti/ble_sdk_2_02_02_25/src/profiles/roles" --include_path="C:/ti/ble_sdk_2_02_02_25/src/profiles/dev_info" --include_path="C:/ti/ble_sdk_2_02_02_25/src/common/cc26xx" --include_path="C:/ti/ble_sdk_2_02_02_25/src/components/heapmgr" --include_path="C:/ti/ble_sdk_2_02_02_25/src/controller/cc26xx/inc" --include_path="C:/ti/ble_sdk_2_02_02_25/src/components/hal/src/target/_common" --include_path="C:/ti/ble_sdk_2_02_02_25/src/target" --include_path="C:/ti/ble_sdk_2_02_02_25/src/components/hal/src/target/_common/cc26xx" --include_path="C:/ti/ble_sdk_2_02_02_25/src/components/hal/src/inc" --include_path="C:/ti/ble_sdk_2_02_02_25/src/components/osal/src/inc" --include_path="C:/ti/ble_sdk_2_02_02_25/src/components/services/src/sdata" --include_path="C:/ti/ble_sdk_2_02_02_25/src/components/services/src/saddr" --include_path="C:/ti/ble_sdk_2_02_02_25/src/components/icall/src/inc" --include_path="C:/ti/ble_sdk_2_02_02_25/src/inc" --include_path="C:/ti/ble_sdk_2_02_02_25/src/rom" --include_path="C:/ti/tirtos_cc13xx_cc26xx_2_21_01_08/products/cc26xxware_2_24_03_17272" --define=BOARD_DISPLAY_EXCLUDE_LCD --define=xBOARD_DISPLAY_EXCLUDE_UART --define=CC2650_LAUNCHXL --define=CC26XX --define=xDisplay_DISABLE_ALL --define=GAPROLE_TASK_STACK_SIZE=540 --define=HEAPMGR_SIZE=0 --define=ICALL_MAX_NUM_ENTITIES=6 --define=ICALL_MAX_NUM_TASKS=3 --define=POWER_MEASURE --define=POWER_SAVING --define=USE_ICALL --define=xdc_runtime_Assert_DISABLE_ALL --define=xdc_runtime_Log_DISABLE_ALL -g --c99 --gcc --diag_suppress=48 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="Drivers/ECC/ECCROMCC26XX.d_raw" --obj_directory="Drivers/ECC" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


