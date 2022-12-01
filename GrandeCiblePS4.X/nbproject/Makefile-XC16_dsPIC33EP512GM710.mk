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
FINAL_IMAGE=${DISTDIR}/GrandeCiblePS4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/GrandeCiblePS4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=src/adc.c src/gpio.c src/pwm.c src/sysTick.c src/timer.c src/uart.c src/xbee.c src/configurationBit.c src/main.c src/i2c.c src/spi.c src/clock.c src/can.c src/rtc.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/adc.o ${OBJECTDIR}/src/gpio.o ${OBJECTDIR}/src/pwm.o ${OBJECTDIR}/src/sysTick.o ${OBJECTDIR}/src/timer.o ${OBJECTDIR}/src/uart.o ${OBJECTDIR}/src/xbee.o ${OBJECTDIR}/src/configurationBit.o ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/i2c.o ${OBJECTDIR}/src/spi.o ${OBJECTDIR}/src/clock.o ${OBJECTDIR}/src/can.o ${OBJECTDIR}/src/rtc.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/adc.o.d ${OBJECTDIR}/src/gpio.o.d ${OBJECTDIR}/src/pwm.o.d ${OBJECTDIR}/src/sysTick.o.d ${OBJECTDIR}/src/timer.o.d ${OBJECTDIR}/src/uart.o.d ${OBJECTDIR}/src/xbee.o.d ${OBJECTDIR}/src/configurationBit.o.d ${OBJECTDIR}/src/main.o.d ${OBJECTDIR}/src/i2c.o.d ${OBJECTDIR}/src/spi.o.d ${OBJECTDIR}/src/clock.o.d ${OBJECTDIR}/src/can.o.d ${OBJECTDIR}/src/rtc.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/adc.o ${OBJECTDIR}/src/gpio.o ${OBJECTDIR}/src/pwm.o ${OBJECTDIR}/src/sysTick.o ${OBJECTDIR}/src/timer.o ${OBJECTDIR}/src/uart.o ${OBJECTDIR}/src/xbee.o ${OBJECTDIR}/src/configurationBit.o ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/i2c.o ${OBJECTDIR}/src/spi.o ${OBJECTDIR}/src/clock.o ${OBJECTDIR}/src/can.o ${OBJECTDIR}/src/rtc.o

# Source Files
SOURCEFILES=src/adc.c src/gpio.c src/pwm.c src/sysTick.c src/timer.c src/uart.c src/xbee.c src/configurationBit.c src/main.c src/i2c.c src/spi.c src/clock.c src/can.c src/rtc.c



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
	${MAKE}  -f nbproject/Makefile-XC16_dsPIC33EP512GM710.mk ${DISTDIR}/GrandeCiblePS4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33EP128GM710
MP_LINKER_FILE_OPTION=,--script=p33EP128GM710.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/adc.o: src/adc.c  .generated_files/flags/XC16_dsPIC33EP512GM710/d8cf746df5a54cafd982f07bab2fdabdec0ffdff .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/adc.o.d 
	@${RM} ${OBJECTDIR}/src/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/adc.c  -o ${OBJECTDIR}/src/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/adc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/gpio.o: src/gpio.c  .generated_files/flags/XC16_dsPIC33EP512GM710/817270e7678d2e5fb9b14be7c9e52ea96772c67a .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/gpio.o.d 
	@${RM} ${OBJECTDIR}/src/gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/gpio.c  -o ${OBJECTDIR}/src/gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/gpio.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/pwm.o: src/pwm.c  .generated_files/flags/XC16_dsPIC33EP512GM710/cb1a982b53e98b1f82abba8d1f89214a3a1f983b .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/pwm.o.d 
	@${RM} ${OBJECTDIR}/src/pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/pwm.c  -o ${OBJECTDIR}/src/pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/pwm.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/sysTick.o: src/sysTick.c  .generated_files/flags/XC16_dsPIC33EP512GM710/bb5472a74ac27b4a67bc655ff89d89f04c173561 .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/sysTick.o.d 
	@${RM} ${OBJECTDIR}/src/sysTick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/sysTick.c  -o ${OBJECTDIR}/src/sysTick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/sysTick.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/timer.o: src/timer.c  .generated_files/flags/XC16_dsPIC33EP512GM710/fd82ebff9355af7b5fe540ad8053b04b511efa38 .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/timer.o.d 
	@${RM} ${OBJECTDIR}/src/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/timer.c  -o ${OBJECTDIR}/src/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/timer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/uart.o: src/uart.c  .generated_files/flags/XC16_dsPIC33EP512GM710/aba958a381a0c63e253a71373476f7de3b80776d .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/uart.o.d 
	@${RM} ${OBJECTDIR}/src/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/uart.c  -o ${OBJECTDIR}/src/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/uart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/xbee.o: src/xbee.c  .generated_files/flags/XC16_dsPIC33EP512GM710/dfcb9db16564a2165ff19c8e10049f2d9d403e3a .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/xbee.o.d 
	@${RM} ${OBJECTDIR}/src/xbee.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/xbee.c  -o ${OBJECTDIR}/src/xbee.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/xbee.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/configurationBit.o: src/configurationBit.c  .generated_files/flags/XC16_dsPIC33EP512GM710/20bb2215b5153209d42e635bc707296d19307656 .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/configurationBit.o.d 
	@${RM} ${OBJECTDIR}/src/configurationBit.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/configurationBit.c  -o ${OBJECTDIR}/src/configurationBit.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/configurationBit.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/main.o: src/main.c  .generated_files/flags/XC16_dsPIC33EP512GM710/37278c2d4284b97b6f327f1f94e297ffcf6eb4a8 .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/main.c  -o ${OBJECTDIR}/src/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/i2c.o: src/i2c.c  .generated_files/flags/XC16_dsPIC33EP512GM710/87a923fd9551b8a47df804039fbe3cf84bcb5caf .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/i2c.o.d 
	@${RM} ${OBJECTDIR}/src/i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/i2c.c  -o ${OBJECTDIR}/src/i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/i2c.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/spi.o: src/spi.c  .generated_files/flags/XC16_dsPIC33EP512GM710/7f5098df88c5bbd9b47ddad0c9cd6f1655615f1e .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/spi.o.d 
	@${RM} ${OBJECTDIR}/src/spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/spi.c  -o ${OBJECTDIR}/src/spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/spi.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/clock.o: src/clock.c  .generated_files/flags/XC16_dsPIC33EP512GM710/e17f8035b5d253f05936f23c38b640b50d5175c4 .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/clock.o.d 
	@${RM} ${OBJECTDIR}/src/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/clock.c  -o ${OBJECTDIR}/src/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/clock.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/can.o: src/can.c  .generated_files/flags/XC16_dsPIC33EP512GM710/3677c4846f37059541fb9619aadbe14087256c62 .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/can.o.d 
	@${RM} ${OBJECTDIR}/src/can.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/can.c  -o ${OBJECTDIR}/src/can.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/can.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/rtc.o: src/rtc.c  .generated_files/flags/XC16_dsPIC33EP512GM710/2728dcf7a63775513e5d4b1488d4a54951db10f7 .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/rtc.o.d 
	@${RM} ${OBJECTDIR}/src/rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/rtc.c  -o ${OBJECTDIR}/src/rtc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/rtc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/src/adc.o: src/adc.c  .generated_files/flags/XC16_dsPIC33EP512GM710/4c946c4296e8e8c0e21ae86358b05094a84ba8cc .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/adc.o.d 
	@${RM} ${OBJECTDIR}/src/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/adc.c  -o ${OBJECTDIR}/src/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/adc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/gpio.o: src/gpio.c  .generated_files/flags/XC16_dsPIC33EP512GM710/223eb95fd8beb76d455fc0841c7c974c33be9d38 .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/gpio.o.d 
	@${RM} ${OBJECTDIR}/src/gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/gpio.c  -o ${OBJECTDIR}/src/gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/gpio.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/pwm.o: src/pwm.c  .generated_files/flags/XC16_dsPIC33EP512GM710/dd6033522bb2b68e7eb1b24384f02e389fda5b3b .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/pwm.o.d 
	@${RM} ${OBJECTDIR}/src/pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/pwm.c  -o ${OBJECTDIR}/src/pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/pwm.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/sysTick.o: src/sysTick.c  .generated_files/flags/XC16_dsPIC33EP512GM710/19c019876ceddd25fffff98842580cd5f45206e7 .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/sysTick.o.d 
	@${RM} ${OBJECTDIR}/src/sysTick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/sysTick.c  -o ${OBJECTDIR}/src/sysTick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/sysTick.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/timer.o: src/timer.c  .generated_files/flags/XC16_dsPIC33EP512GM710/4c275410a8451d4fa42c161b02dc82123d17ff22 .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/timer.o.d 
	@${RM} ${OBJECTDIR}/src/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/timer.c  -o ${OBJECTDIR}/src/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/timer.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/uart.o: src/uart.c  .generated_files/flags/XC16_dsPIC33EP512GM710/ba4032db11863f7e558bc2ddc4e71ed9d22aef3c .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/uart.o.d 
	@${RM} ${OBJECTDIR}/src/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/uart.c  -o ${OBJECTDIR}/src/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/uart.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/xbee.o: src/xbee.c  .generated_files/flags/XC16_dsPIC33EP512GM710/632adf711e82df21bbbc3d2a776ec04cdd37ca71 .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/xbee.o.d 
	@${RM} ${OBJECTDIR}/src/xbee.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/xbee.c  -o ${OBJECTDIR}/src/xbee.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/xbee.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/configurationBit.o: src/configurationBit.c  .generated_files/flags/XC16_dsPIC33EP512GM710/cdc30159f287998377d128c6663cfcd43a4e36bc .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/configurationBit.o.d 
	@${RM} ${OBJECTDIR}/src/configurationBit.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/configurationBit.c  -o ${OBJECTDIR}/src/configurationBit.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/configurationBit.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/main.o: src/main.c  .generated_files/flags/XC16_dsPIC33EP512GM710/6e38f5c6e002c18b3a81156b32b8aa7b14e98958 .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/main.c  -o ${OBJECTDIR}/src/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/i2c.o: src/i2c.c  .generated_files/flags/XC16_dsPIC33EP512GM710/3b368ba073a8afc2966b4c5c72a31078023ddd09 .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/i2c.o.d 
	@${RM} ${OBJECTDIR}/src/i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/i2c.c  -o ${OBJECTDIR}/src/i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/i2c.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/spi.o: src/spi.c  .generated_files/flags/XC16_dsPIC33EP512GM710/9954b94ecfc14ddb8659e547160724a2d952af90 .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/spi.o.d 
	@${RM} ${OBJECTDIR}/src/spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/spi.c  -o ${OBJECTDIR}/src/spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/spi.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/clock.o: src/clock.c  .generated_files/flags/XC16_dsPIC33EP512GM710/a4a91dc0f39fa5a05ffa675086bfd12845008aa8 .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/clock.o.d 
	@${RM} ${OBJECTDIR}/src/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/clock.c  -o ${OBJECTDIR}/src/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/clock.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/can.o: src/can.c  .generated_files/flags/XC16_dsPIC33EP512GM710/5933b547fb2fa01f7c0ebc8a281331de283f625 .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/can.o.d 
	@${RM} ${OBJECTDIR}/src/can.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/can.c  -o ${OBJECTDIR}/src/can.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/can.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/rtc.o: src/rtc.c  .generated_files/flags/XC16_dsPIC33EP512GM710/25f3ed3949ded784b19370fd08b908bb1221a2e2 .generated_files/flags/XC16_dsPIC33EP512GM710/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/rtc.o.d 
	@${RM} ${OBJECTDIR}/src/rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/rtc.c  -o ${OBJECTDIR}/src/rtc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/rtc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
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
${DISTDIR}/GrandeCiblePS4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/GrandeCiblePS4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/GrandeCiblePS4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/GrandeCiblePS4.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_XC16_dsPIC33EP512GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/GrandeCiblePS4.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}
