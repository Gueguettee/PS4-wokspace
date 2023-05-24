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
ifeq "$(wildcard nbproject/Makefile-local-XC16_dsPIC33EP128GM710.mk)" "nbproject/Makefile-local-XC16_dsPIC33EP128GM710.mk"
include nbproject/Makefile-local-XC16_dsPIC33EP128GM710.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=XC16_dsPIC33EP128GM710
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/GrandeCiblePS4_slave.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/GrandeCiblePS4_slave.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=src/adc.c src/gpio.c src/pwm.c src/sysTick.c src/timer.c src/uart.c src/xbee.c src/configurationBit.c src/i2c.c src/spi.c src/clock.c src/can.c src/rtc.c src/mainSlave.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/adc.o ${OBJECTDIR}/src/gpio.o ${OBJECTDIR}/src/pwm.o ${OBJECTDIR}/src/sysTick.o ${OBJECTDIR}/src/timer.o ${OBJECTDIR}/src/uart.o ${OBJECTDIR}/src/xbee.o ${OBJECTDIR}/src/configurationBit.o ${OBJECTDIR}/src/i2c.o ${OBJECTDIR}/src/spi.o ${OBJECTDIR}/src/clock.o ${OBJECTDIR}/src/can.o ${OBJECTDIR}/src/rtc.o ${OBJECTDIR}/src/mainSlave.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/adc.o.d ${OBJECTDIR}/src/gpio.o.d ${OBJECTDIR}/src/pwm.o.d ${OBJECTDIR}/src/sysTick.o.d ${OBJECTDIR}/src/timer.o.d ${OBJECTDIR}/src/uart.o.d ${OBJECTDIR}/src/xbee.o.d ${OBJECTDIR}/src/configurationBit.o.d ${OBJECTDIR}/src/i2c.o.d ${OBJECTDIR}/src/spi.o.d ${OBJECTDIR}/src/clock.o.d ${OBJECTDIR}/src/can.o.d ${OBJECTDIR}/src/rtc.o.d ${OBJECTDIR}/src/mainSlave.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/adc.o ${OBJECTDIR}/src/gpio.o ${OBJECTDIR}/src/pwm.o ${OBJECTDIR}/src/sysTick.o ${OBJECTDIR}/src/timer.o ${OBJECTDIR}/src/uart.o ${OBJECTDIR}/src/xbee.o ${OBJECTDIR}/src/configurationBit.o ${OBJECTDIR}/src/i2c.o ${OBJECTDIR}/src/spi.o ${OBJECTDIR}/src/clock.o ${OBJECTDIR}/src/can.o ${OBJECTDIR}/src/rtc.o ${OBJECTDIR}/src/mainSlave.o

# Source Files
SOURCEFILES=src/adc.c src/gpio.c src/pwm.c src/sysTick.c src/timer.c src/uart.c src/xbee.c src/configurationBit.c src/i2c.c src/spi.c src/clock.c src/can.c src/rtc.c src/mainSlave.c



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
	${MAKE}  -f nbproject/Makefile-XC16_dsPIC33EP128GM710.mk ${DISTDIR}/GrandeCiblePS4_slave.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33EP128GM710
MP_LINKER_FILE_OPTION=,--script=p33EP128GM710.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/adc.o: src/adc.c  .generated_files/flags/XC16_dsPIC33EP128GM710/61b09c4d0920603bbe9599088872fb49e2ee02c4 .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/adc.o.d 
	@${RM} ${OBJECTDIR}/src/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/adc.c  -o ${OBJECTDIR}/src/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/adc.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/gpio.o: src/gpio.c  .generated_files/flags/XC16_dsPIC33EP128GM710/a80c625594fd4067e09bd34ed429b0338aeed966 .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/gpio.o.d 
	@${RM} ${OBJECTDIR}/src/gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/gpio.c  -o ${OBJECTDIR}/src/gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/gpio.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/pwm.o: src/pwm.c  .generated_files/flags/XC16_dsPIC33EP128GM710/aa849bebd601e61df46d244ee377dd9b26d4fb67 .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/pwm.o.d 
	@${RM} ${OBJECTDIR}/src/pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/pwm.c  -o ${OBJECTDIR}/src/pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/pwm.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/sysTick.o: src/sysTick.c  .generated_files/flags/XC16_dsPIC33EP128GM710/8319891c9d7cf602a062350a1839100b7f4b0e59 .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/sysTick.o.d 
	@${RM} ${OBJECTDIR}/src/sysTick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/sysTick.c  -o ${OBJECTDIR}/src/sysTick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/sysTick.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/timer.o: src/timer.c  .generated_files/flags/XC16_dsPIC33EP128GM710/ebe01c5defe3d516f6e46c2722649d738b0ac1a .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/timer.o.d 
	@${RM} ${OBJECTDIR}/src/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/timer.c  -o ${OBJECTDIR}/src/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/timer.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/uart.o: src/uart.c  .generated_files/flags/XC16_dsPIC33EP128GM710/3d59857f99013b7cbad7ed93efa12bf85956ade6 .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/uart.o.d 
	@${RM} ${OBJECTDIR}/src/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/uart.c  -o ${OBJECTDIR}/src/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/uart.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/xbee.o: src/xbee.c  .generated_files/flags/XC16_dsPIC33EP128GM710/cb444d8e8b6553ccfd91b89389ced99658b29e20 .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/xbee.o.d 
	@${RM} ${OBJECTDIR}/src/xbee.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/xbee.c  -o ${OBJECTDIR}/src/xbee.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/xbee.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/configurationBit.o: src/configurationBit.c  .generated_files/flags/XC16_dsPIC33EP128GM710/a605780e16b5c035715c1ab0ede27364b0336b70 .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/configurationBit.o.d 
	@${RM} ${OBJECTDIR}/src/configurationBit.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/configurationBit.c  -o ${OBJECTDIR}/src/configurationBit.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/configurationBit.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/i2c.o: src/i2c.c  .generated_files/flags/XC16_dsPIC33EP128GM710/b086405a7b7ad6e51ab5b15603ed642b1cc125f1 .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/i2c.o.d 
	@${RM} ${OBJECTDIR}/src/i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/i2c.c  -o ${OBJECTDIR}/src/i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/i2c.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/spi.o: src/spi.c  .generated_files/flags/XC16_dsPIC33EP128GM710/699e7b3b1a31f1a2ba4e003745d65cb256100490 .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/spi.o.d 
	@${RM} ${OBJECTDIR}/src/spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/spi.c  -o ${OBJECTDIR}/src/spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/spi.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/clock.o: src/clock.c  .generated_files/flags/XC16_dsPIC33EP128GM710/748b19743b405f986a73f9c5be063255bdf3b31d .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/clock.o.d 
	@${RM} ${OBJECTDIR}/src/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/clock.c  -o ${OBJECTDIR}/src/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/clock.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/can.o: src/can.c  .generated_files/flags/XC16_dsPIC33EP128GM710/834a3272955b2f44d82a4ba4ba61a04f892ca760 .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/can.o.d 
	@${RM} ${OBJECTDIR}/src/can.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/can.c  -o ${OBJECTDIR}/src/can.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/can.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/rtc.o: src/rtc.c  .generated_files/flags/XC16_dsPIC33EP128GM710/c1d970b50a7618b1aa7cf9784430ac81b8a917dd .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/rtc.o.d 
	@${RM} ${OBJECTDIR}/src/rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/rtc.c  -o ${OBJECTDIR}/src/rtc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/rtc.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/mainSlave.o: src/mainSlave.c  .generated_files/flags/XC16_dsPIC33EP128GM710/32d368169ed865620216c56b52f155edf01056bc .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/mainSlave.o.d 
	@${RM} ${OBJECTDIR}/src/mainSlave.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/mainSlave.c  -o ${OBJECTDIR}/src/mainSlave.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/mainSlave.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/src/adc.o: src/adc.c  .generated_files/flags/XC16_dsPIC33EP128GM710/35588b06c41ad4f5e8358990184b0827ead8b35f .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/adc.o.d 
	@${RM} ${OBJECTDIR}/src/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/adc.c  -o ${OBJECTDIR}/src/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/adc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/gpio.o: src/gpio.c  .generated_files/flags/XC16_dsPIC33EP128GM710/71b07cfb4872ae856ee07e394adb4b3375bdab0 .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/gpio.o.d 
	@${RM} ${OBJECTDIR}/src/gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/gpio.c  -o ${OBJECTDIR}/src/gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/gpio.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/pwm.o: src/pwm.c  .generated_files/flags/XC16_dsPIC33EP128GM710/1017a9213436b4e5b8bb51947ad52da5f00b32a8 .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/pwm.o.d 
	@${RM} ${OBJECTDIR}/src/pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/pwm.c  -o ${OBJECTDIR}/src/pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/pwm.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/sysTick.o: src/sysTick.c  .generated_files/flags/XC16_dsPIC33EP128GM710/9dbf940e8c2bbdd6ea1d7ab71134a00addacbf2d .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/sysTick.o.d 
	@${RM} ${OBJECTDIR}/src/sysTick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/sysTick.c  -o ${OBJECTDIR}/src/sysTick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/sysTick.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/timer.o: src/timer.c  .generated_files/flags/XC16_dsPIC33EP128GM710/320dcdef50e92b380a7eaf7855e0b61a38c5291d .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/timer.o.d 
	@${RM} ${OBJECTDIR}/src/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/timer.c  -o ${OBJECTDIR}/src/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/timer.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/uart.o: src/uart.c  .generated_files/flags/XC16_dsPIC33EP128GM710/8860eecb5d980f33500640fb6050500b7361fb04 .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/uart.o.d 
	@${RM} ${OBJECTDIR}/src/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/uart.c  -o ${OBJECTDIR}/src/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/uart.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/xbee.o: src/xbee.c  .generated_files/flags/XC16_dsPIC33EP128GM710/50085fe5a8c31bae134e18443fcd8aeb8ecdf08 .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/xbee.o.d 
	@${RM} ${OBJECTDIR}/src/xbee.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/xbee.c  -o ${OBJECTDIR}/src/xbee.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/xbee.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/configurationBit.o: src/configurationBit.c  .generated_files/flags/XC16_dsPIC33EP128GM710/98a75681e9dae5be40013ee6bf926f1c1d28220c .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/configurationBit.o.d 
	@${RM} ${OBJECTDIR}/src/configurationBit.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/configurationBit.c  -o ${OBJECTDIR}/src/configurationBit.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/configurationBit.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/i2c.o: src/i2c.c  .generated_files/flags/XC16_dsPIC33EP128GM710/7ff5ee42eb00babf0985ec00f74e8fb86c720383 .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/i2c.o.d 
	@${RM} ${OBJECTDIR}/src/i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/i2c.c  -o ${OBJECTDIR}/src/i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/i2c.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/spi.o: src/spi.c  .generated_files/flags/XC16_dsPIC33EP128GM710/c031b3199d996680af23d627ff258f6c0284d930 .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/spi.o.d 
	@${RM} ${OBJECTDIR}/src/spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/spi.c  -o ${OBJECTDIR}/src/spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/spi.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/clock.o: src/clock.c  .generated_files/flags/XC16_dsPIC33EP128GM710/83a901fff7633fcab966cdd0388ca3ff3f162fcb .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/clock.o.d 
	@${RM} ${OBJECTDIR}/src/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/clock.c  -o ${OBJECTDIR}/src/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/clock.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/can.o: src/can.c  .generated_files/flags/XC16_dsPIC33EP128GM710/c27046be5b8d557bd9e3272e3080504f8d248670 .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/can.o.d 
	@${RM} ${OBJECTDIR}/src/can.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/can.c  -o ${OBJECTDIR}/src/can.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/can.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/rtc.o: src/rtc.c  .generated_files/flags/XC16_dsPIC33EP128GM710/a027e9680dcbce574fc59828c393723a7dfae6e6 .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/rtc.o.d 
	@${RM} ${OBJECTDIR}/src/rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/rtc.c  -o ${OBJECTDIR}/src/rtc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/rtc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/mainSlave.o: src/mainSlave.c  .generated_files/flags/XC16_dsPIC33EP128GM710/5a877adfa629c906a50e18df6bb8fd1faf2445b0 .generated_files/flags/XC16_dsPIC33EP128GM710/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/mainSlave.o.d 
	@${RM} ${OBJECTDIR}/src/mainSlave.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/mainSlave.c  -o ${OBJECTDIR}/src/mainSlave.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/mainSlave.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
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
${DISTDIR}/GrandeCiblePS4_slave.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/GrandeCiblePS4_slave.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/GrandeCiblePS4_slave.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/GrandeCiblePS4_slave.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/GrandeCiblePS4_slave.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
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
