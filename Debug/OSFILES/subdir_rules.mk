################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
OSFILES/%.obj: ../OSFILES/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/home/satish/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/satish/workspace_v9/EmbeddedSystemsPractice" --include_path="/home/satish/workspace_v9/EmbeddedSystemsPractice/DATA_CONST" --include_path="/home/satish/workspace_v9/EmbeddedSystemsPractice/Diagnostics" --include_path="/home/satish/workspace_v9/EmbeddedSystemsPractice/driver_libraries" --include_path="/home/satish/workspace_v9/EmbeddedSystemsPractice/INCLUDE" --include_path="/home/satish/workspace_v9/EmbeddedSystemsPractice/OSFILES" --include_path="/home/satish/workspace_v9/EmbeddedSystemsPractice/SOURCE" --include_path="/home/satish/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="OSFILES/$(basename $(<F)).d_raw" --obj_directory="OSFILES" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '


