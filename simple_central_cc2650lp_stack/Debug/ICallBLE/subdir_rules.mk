################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
ICallBLE/ble_dispatch.obj: C:/ti/ble_sdk_2_02_02_25/src/icall/stack/ble_dispatch.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" --cmd_file="C:/ti/ble_sdk_2_02_02_25/ble_examples/examples/cc2650lp/simple_central/ccs/stack/../../iar/stack/build_config.opt" --cmd_file="C:/ti/ble_sdk_2_02_02_25/src/config/build_components.opt"  -mv7M3 --code_state=16 -me -O4 --opt_for_speed=0 --include_path="E:/git/EVRS_TX_PROTOTYPE/simple_central_cc2650lp_stack" --include_path="C:/ti/ble_sdk_2_02_02_25/src/examples/simple_central/cc26xx/stack" --include_path="C:/ti/ble_sdk_2_02_02_25/src/common/cc26xx" --include_path="C:/ti/ble_sdk_2_02_02_25/src/components/hal/src/target/_common" --include_path="C:/ti/ble_sdk_2_02_02_25/src/components/hal/src/target" --include_path="C:/ti/ble_sdk_2_02_02_25/src/components/hal/src/target/_common/cc26xx" --include_path="C:/ti/ble_sdk_2_02_02_25/src/components/hal/src/inc" --include_path="C:/ti/ble_sdk_2_02_02_25/src/components/osal/src/inc" --include_path="C:/ti/ble_sdk_2_02_02_25/src/components/services/src/nv/cc26xx" --include_path="C:/ti/ble_sdk_2_02_02_25/src/components/services/src/nv" --include_path="C:/ti/ble_sdk_2_02_02_25/src/components/services/src/saddr" --include_path="C:/ti/ble_sdk_2_02_02_25/src/components/icall/src/inc" --include_path="C:/ti/ble_sdk_2_02_02_25/src/inc" --include_path="C:/ti/ble_sdk_2_02_02_25/src/controller/cc26xx/inc" --include_path="C:/ti/ble_sdk_2_02_02_25/src/rom" --include_path="C:/ti/ble_sdk_2_02_02_25/src/components/services/src/aes/cc26xx" --include_path="C:/ti/ble_sdk_2_02_02_25/src/components/npi/src" --include_path="C:/ti/ble_sdk_2_02_02_25/src/common/cc26xx/npi/stack" --include_path="C:/ti/ble_sdk_2_02_02_25/src/inc" --include_path="C:/ti/ble_sdk_2_02_02_25/src/icall/inc" --include_path="C:/ti/ble_sdk_2_02_02_25/src/profiles/roles" --include_path="C:/ti/tirtos_cc13xx_cc26xx_2_21_01_08/products/cc26xxware_2_24_03_17272" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --define=USE_ICALL --define=FLASH_ROM_BUILD --define=POWER_SAVING --define=OSAL_SNV=1 --define=INCLUDE_AES_DECRYPT --define=xPM_DISABLE_PWRDOWN --define=xTESTMODES --define=xTEST_BLEBOARD --define=OSAL_CBTIMER_NUM_TASKS=1 --define=EXT_HAL_ASSERT --define=xDEBUG_GPIO --define=xDEBUG_ENC --define=xDEBUG_SW_TRACE --define=NEAR_FUNC= --define=DATA= --define=CC26XXWARE --define=CC26XX -g --c99 --diag_suppress=48 --diag_suppress=16004 --diag_warning=225 --diag_warning=2 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="ICallBLE/ble_dispatch.d_raw" --obj_directory="ICallBLE" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


