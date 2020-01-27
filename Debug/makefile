################################################################################
# Automatically-generated file. Do not edit!
################################################################################

CG_TOOL_ROOT := /home/satish/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.obj" \
"./tm4c123gh6pm_startup_ccs.obj" \
"./DATA_CONST/constdata_gpioconfig.obj" \
"./OSFILES/os.obj" \
"./SOURCE/exception_handlers.obj" \
"./SOURCE/sys_init.obj" \
"./driver_libraries/i2c.obj" \
"./driver_libraries/pwm_timer_lib.obj" \
"../tm4c123gh6pm.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := rm -rf
RMDIR := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include DATA_CONST/subdir_vars.mk
-include OSFILES/subdir_vars.mk
-include SOURCE/subdir_vars.mk
-include driver_libraries/subdir_vars.mk
-include subdir_rules.mk
-include DATA_CONST/subdir_rules.mk
-include OSFILES/subdir_rules.mk
-include SOURCE/subdir_rules.mk
-include driver_libraries/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
embssystems_practice.out \

EXE_OUTPUTS__QUOTED += \
"embssystems_practice.out" \

BIN_OUTPUTS += \
embssystems_practice.hex \

BIN_OUTPUTS__QUOTED += \
"embssystems_practice.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "embssystems_practice.out"

# Tool invocations
embssystems_practice.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: ARM Linker'
	"/home/satish/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"embssystems_practice.map" --heap_size=0 --stack_size=512 -i"/home/satish/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/lib" -i"/home/satish/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="embssystems_practice_linkInfo.xml" --rom_model -o "embssystems_practice.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

embssystems_practice.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: ARM Hex Utility'
	"/home/satish/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/bin/armhex"  -o "embssystems_practice.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "main.obj" "tm4c123gh6pm_startup_ccs.obj" "DATA_CONST/constdata_gpioconfig.obj" "OSFILES/os.obj" "SOURCE/exception_handlers.obj" "SOURCE/sys_init.obj" "driver_libraries/i2c.obj" "driver_libraries/pwm_timer_lib.obj" 
	-$(RM) "main.d" "tm4c123gh6pm_startup_ccs.d" "DATA_CONST/constdata_gpioconfig.d" "OSFILES/os.d" "SOURCE/exception_handlers.d" "SOURCE/sys_init.d" "driver_libraries/i2c.d" "driver_libraries/pwm_timer_lib.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

