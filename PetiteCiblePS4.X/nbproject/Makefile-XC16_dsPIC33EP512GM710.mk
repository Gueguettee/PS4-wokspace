#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-XC16_dsPIC33EP512GM710.mk)" "nbproject/Makefile-local-XC16_dsPIC33EP512GM710.mk"
include nbproject/Makefile-local-XC16_dsPIC33EP512GM710.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=XC16_dsPIC33EP512GM710
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/PetiteCiblePS4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/PetiteCiblePS4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=src/gpio.c src/sysTick.c src/configurationBit.c src/clock.c src/adc.c src/xbee.c src/uart.c src/timer.c src/spi.c src/i2c.c src/pwm.c src/mainRemote.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/gpio.o ${OBJECTDIR}/src/sysTick.o ${OBJECTDIR}/src/configurationBit.o ${OBJECTDIR}/src/clock.o ${OBJECTDIR}/src/adc.o ${OBJECTDIR}/src/xbee.o ${OBJECTDIR}/src/uart.o ${OBJECTDIR}/src/timer.o ${OBJECTDIR}/src/spi.o ${OBJECTDIR}/src/i2c.o ${OBJECTDIR}/src/pwm.o ${OBJECTDIR}/src/mainRemote.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/gpio.o.d ${OBJECTDIR}/src/sysTick.o.d ${OBJECTDIR}/src/configurationBit.o.d ${OBJECTDIR}/src/clock.o.d ${OBJECTDIR}/src/adc.o.d ${OBJECTDIR}/src/xbee.o.d ${OBJECTDIR}/src/uart.o.d ${OBJECTDIR}/src/timer.o.d ${OBJECTDIR}/src/spi.o.d ${OBJECTDIR}/src/i2c.o.d ${OBJECTDIR}/src/pwm.o.d ${OBJECTDIR}/src/mainRemote.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/gpio.o ${OBJECTDIR}/src/sysTick.o ${OBJECTDIR}/src/configurationBit.o ${OBJECTDIR}/src/clock.o ${OBJECTDIR}/src/adc.o ${OBJECTDIR}/src/xbee.o ${OBJECTDIR}/src/uart.o ${OBJECTDIR}/src/timer.o ${OBJECTDIR}/src/spi.o ${OBJECTDIR}/src/i2c.o ${OBJECTDIR}/src/pwm.o ${OBJECTDIR}/src/mainRemote.o

# Source Files
SOURCEFILES=src/gpio.c src/sysTick.c src/configurationBit.c src/clock.c src/adc.c src/xbee.c src/uart.c src/timer.c src/spi.c src/i2c.c src/pwm.c src/mainRemote.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-XC16_dsPIC33EP512GM710.mk ${DISTDIR}/PetiteCiblePS4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33EP512GM710
MP_LINKER_FILE_OPTION=,--script=p33EP512GM710.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/gpio.o: src/gpio.c  .generated_files/flags/XC16_dsPIC33EP512GM710/1733e021b9f133167d366b078a6a2d133c9a9e3d .generated_files/flags/XC16_dsPIC33EP512GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/gpio.o.d 
	@${RM} ${OBJECTDIR}/src/gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/gpio.c  -o ${OBJECTDIR}/src/gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/gpio.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/sysTick.o: src/sysTick.c  .generated_files/flags/XC16_dsPIC33EP512GM710/8d3af7802334f6d9bd1f247b914db1fe783bc071 .generated_files/flags/XC16_dsPIC33EP512GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/sysTick.o.d 
	@${RM} ${OBJECTDIR}/src/sysTick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/sysTick.c  -o ${OBJECTDIR}/src/sysTick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/sysTick.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/configurationBit.o: src/configurationBit.c  .generated_files/flags/XC16_dsPIC33EP512GM710/510f22e26501494d208e8a675759a72bfa5e09a6 .generated_files/flags/XC16_dsPIC33EP512GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/configurationBit.o.d 
	@${RM} ${OBJECTDIR}/src/configurationBit.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/configurationBit.c  -o ${OBJECTDIR}/src/configurationBit.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/configurationBit.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/clock.o: src/clock.c  .generated_files/flags/XC16_dsPIC33EP512GM710/375d5f0bd7466ae939578847c3b718d5f38e4b54 .generated_files/flags/XC16_dsPIC33EP512GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/clock.o.d 
	@${RM} ${OBJECTDIR}/src/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/clock.c  -o ${OBJECTDIR}/src/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/clock.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/adc.o: src/adc.c  .generated_files/flags/XC16_dsPIC33EP512GM710/afd51b5b455bf2efa66fa221bc82cabdb6862c4b .generated_files/flags/XC16_dsPIC33EP512GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/adc.o.d 
	@${RM} ${OBJECTDIR}/src/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/adc.c  -o ${OBJECTDIR}/src/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/adc.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/xbee.o: src/xbee.c  .generated_files/flags/XC16_dsPIC33EP512GM710/47b99dbf27bf1d542067db967541f387e77a36f5 .generated_files/flags/XC16_dsPIC33EP512GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/xbee.o.d 
	@${RM} ${OBJECTDIR}/src/xbee.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/xbee.c  -o ${OBJECTDIR}/src/xbee.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/xbee.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/uart.o: src/uart.c  .generated_files/flags/XC16_dsPIC33EP512GM710/b2c972b3c7280031d482ba2a3cdbb3c5aeb3e91c .generated_files/flags/XC16_dsPIC33EP512GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/uart.o.d 
	@${RM} ${OBJECTDIR}/src/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/uart.c  -o ${OBJECTDIR}/src/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/uart.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/timer.o: src/timer.c  .generated_files/flags/XC16_dsPIC33EP512GM710/237ed52e0358b3cd48f049cc4e999cbae4e0edb1 .generated_files/flags/XC16_dsPIC33EP512GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/timer.o.d 
	@${RM} ${OBJECTDIR}/src/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/timer.c  -o ${OBJECTDIR}/src/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/timer.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/spi.o: src/spi.c  .generated_files/flags/XC16_dsPIC33EP512GM710/2ea59328af971d019e9297bba91b6690b12a4bc6 .generated_files/flags/XC16_dsPIC33EP512GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/spi.o.d 
	@${RM} ${OBJECTDIR}/src/spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/spi.c  -o ${OBJECTDIR}/src/spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/spi.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/i2c.o: src/i2c.c  .generated_files/flags/XC16_dsPIC33EP512GM710/104982126c0b5b49fe9a74de5275fc521501d99f .generated_files/flags/XC16_dsPIC33EP512GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/i2c.o.d 
	@${RM} ${OBJECTDIR}/src/i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/i2c.c  -o ${OBJECTDIR}/src/i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/i2c.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/pwm.o: src/pwm.c  .generated_files/flags/XC16_dsPIC33EP512GM710/c9b350984062157df031f321176e1406b420002d .generated_files/flags/XC16_dsPIC33EP512GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/pwm.o.d 
	@${RM} ${OBJECTDIR}/src/pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/pwm.c  -o ${OBJECTDIR}/src/pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/pwm.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/mainRemote.o: src/mainRemote.c  .generated_files/flags/XC16_dsPIC33EP512GM710/117446b56214af9b2ab7f9534efdc528b3ad551e .generated_files/flags/XC16_dsPIC33EP512GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/mainRemote.o.d 
	@${RM} ${OBJECTDIR}/src/mainRemote.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/mainRemote.c  -o ${OBJECTDIR}/src/mainRemote.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/mainRemote.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/src/gpio.o: src/gpio.c  .generated_files/flags/XC16_dsPIC33EP512GM710/23af5f5f00f8ca987d941f788deed7be9bcfb403 .generated_files/flags/XC16_dsPIC33EP512GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/gpio.o.d 
	@${RM} ${OBJECTDIR}/src/gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/gpio.c  -o ${OBJECTDIR}/src/gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/gpio.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/sysTick.o: src/sysTick.c  .generated_files/flags/XC16_dsPIC33EP512GM710/d3ba49284aa5399f9f8785de9a34c95c018d1074 .generated_files/flags/XC16_dsPIC33EP512GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/sysTick.o.d 
	@${RM} ${OBJECTDIR}/src/sysTick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/sysTick.c  -o ${OBJECTDIR}/src/sysTick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/sysTick.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/configurationBit.o: src/configurationBit.c  .generated_files/flags/XC16_dsPIC33EP512GM710/b139bf36346a95afe9e2eb1941fc5941ecae5029 .generated_files/flags/XC16_dsPIC33EP512GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/configurationBit.o.d 
	@${RM} ${OBJECTDIR}/src/configurationBit.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/configurationBit.c  -o ${OBJECTDIR}/src/configurationBit.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/configurationBit.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/clock.o: src/clock.c  .generated_files/flags/XC16_dsPIC33EP512GM710/20de63279780478365f3468eba21f1ec626527e0 .generated_files/flags/XC16_dsPIC33EP512GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/clock.o.d 
	@${RM} ${OBJECTDIR}/src/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/clock.c  -o ${OBJECTDIR}/src/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/clock.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/adc.o: src/adc.c  .generated_files/flags/XC16_dsPIC33EP512GM710/3f69c495979313e77535e7f35170a8bd6125ca43 .generated_files/flags/XC16_dsPIC33EP512GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/adc.o.d 
	@${RM} ${OBJECTDIR}/src/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/adc.c  -o ${OBJECTDIR}/src/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/adc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/xbee.o: src/xbee.c  .generated_files/flags/XC16_dsPIC33EP512GM710/7d8fe37b7611bad92e2a8425e505ef24a176576a .generated_files/flags/XC16_dsPIC33EP512GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/xbee.o.d 
	@${RM} ${OBJECTDIR}/src/xbee.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/xbee.c  -o ${OBJECTDIR}/src/xbee.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/xbee.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/uart.o: src/uart.c  .generated_files/flags/XC16_dsPIC33EP512GM710/5b4dbaafcc0c63b213cbba2eeed432ea16494670 .generated_files/flags/XC16_dsPIC33EP512GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/uart.o.d 
	@${RM} ${OBJECTDIR}/src/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/uart.c  -o ${OBJECTDIR}/src/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/uart.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/timer.o: src/timer.c  .generated_files/flags/XC16_dsPIC33EP512GM710/d119c0340b5fa01655100817f0ac2ff043d88433 .generated_files/flags/XC16_dsPIC33EP512GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/timer.o.d 
	@${RM} ${OBJECTDIR}/src/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/timer.c  -o ${OBJECTDIR}/src/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/timer.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/spi.o: src/spi.c  .generated_files/flags/XC16_dsPIC33EP512GM710/46cce84de4888ef9e846b0b689d0136b57033f39 .generated_files/flags/XC16_dsPIC33EP512GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/spi.o.d 
	@${RM} ${OBJECTDIR}/src/spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/spi.c  -o ${OBJECTDIR}/src/spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/spi.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/i2c.o: src/i2c.c  .generated_files/flags/XC16_dsPIC33EP512GM710/42a82aa0955d9555a79a4d46d5d642f7ee8a77c3 .generated_files/flags/XC16_dsPIC33EP512GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/i2c.o.d 
	@${RM} ${OBJECTDIR}/src/i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/i2c.c  -o ${OBJECTDIR}/src/i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/i2c.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/pwm.o: src/pwm.c  .generated_files/flags/XC16_dsPIC33EP512GM710/e1497c158ceb781011bc978a8a19d158272a5b1b .generated_files/flags/XC16_dsPIC33EP512GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/pwm.o.d 
	@${RM} ${OBJECTDIR}/src/pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/pwm.c  -o ${OBJECTDIR}/src/pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/pwm.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/mainRemote.o: src/mainRemote.c  .generated_files/flags/XC16_dsPIC33EP512GM710/56babb27e83e7228d7f595aec73dad0ebbca787a .generated_files/flags/XC16_dsPIC33EP512GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/mainRemote.o.d 
	@${RM} ${OBJECTDIR}/src/mainRemote.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/mainRemote.c  -o ${OBJECTDIR}/src/mainRemote.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/mainRemote.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/PetiteCiblePS4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/PetiteCiblePS4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/PetiteCiblePS4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/PetiteCiblePS4.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/PetiteCiblePS4.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
