################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
driver_libraries/%.obj: ../driver_libraries/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/home/satish/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/satish/workspace_v9/embssystems_practice" --include_path="/home/satish/workspace_v9/embssystems_practice/Diagnostics" --include_path="/home/satish/workspace_v9/embssystems_practice/driver_libraries" --include_path="/home/satish/workspace_v9/embssystems_practice/DATA_CONST" --include_path="/home/satish/workspace_v9/embssystems_practice/INCLUDE" --include_path="/home/satish/workspace_v9/embssystems_practice/OSFILES" --include_path="/home/satish/workspace_v9/embssystems_practice/SOURCE" --include_path="/home/satish/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="driver_libraries/$(basename $(<F)).d_raw" --obj_directory="driver_libraries" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '


