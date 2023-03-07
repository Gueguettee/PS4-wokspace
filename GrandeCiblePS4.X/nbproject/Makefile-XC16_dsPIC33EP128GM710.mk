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
	${MAKE}  -f nbproject/Makefile-XC16_dsPIC33EP128GM710.mk ${DISTDIR}/GrandeCiblePS4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33EP128GM710
MP_LINKER_FILE_OPTION=,--script=p33EP128GM710.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/adc.o: src/adc.c  .generated_files/flags/XC16_dsPIC33EP128GM710/2292a320e2173795fc256d61b640f3dce1e0a113 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/adc.o.d 
	@${RM} ${OBJECTDIR}/src/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/adc.c  -o ${OBJECTDIR}/src/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/adc.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/gpio.o: src/gpio.c  .generated_files/flags/XC16_dsPIC33EP128GM710/80d7a1e9360326a18eef16d84bac63198a6e0f5 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/gpio.o.d 
	@${RM} ${OBJECTDIR}/src/gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/gpio.c  -o ${OBJECTDIR}/src/gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/gpio.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/pwm.o: src/pwm.c  .generated_files/flags/XC16_dsPIC33EP128GM710/9a2f90ee0877045b293cdf2afda6b5f611579926 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/pwm.o.d 
	@${RM} ${OBJECTDIR}/src/pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/pwm.c  -o ${OBJECTDIR}/src/pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/pwm.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/sysTick.o: src/sysTick.c  .generated_files/flags/XC16_dsPIC33EP128GM710/52561ebc75c5125ff56827cda813fcadf9cfac31 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/sysTick.o.d 
	@${RM} ${OBJECTDIR}/src/sysTick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/sysTick.c  -o ${OBJECTDIR}/src/sysTick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/sysTick.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/timer.o: src/timer.c  .generated_files/flags/XC16_dsPIC33EP128GM710/90244514f7be883322c3512c07d087638cec06b9 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/timer.o.d 
	@${RM} ${OBJECTDIR}/src/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/timer.c  -o ${OBJECTDIR}/src/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/timer.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/uart.o: src/uart.c  .generated_files/flags/XC16_dsPIC33EP128GM710/41fe09e59843de41c490d28e2a0e288d96f062e6 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/uart.o.d 
	@${RM} ${OBJECTDIR}/src/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/uart.c  -o ${OBJECTDIR}/src/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/uart.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/xbee.o: src/xbee.c  .generated_files/flags/XC16_dsPIC33EP128GM710/f7a05271eb8e01e55a6d0d42a7739c7fe408aa98 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/xbee.o.d 
	@${RM} ${OBJECTDIR}/src/xbee.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/xbee.c  -o ${OBJECTDIR}/src/xbee.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/xbee.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/configurationBit.o: src/configurationBit.c  .generated_files/flags/XC16_dsPIC33EP128GM710/f9ccff56886916b1f51315146a64af541729b1e2 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/configurationBit.o.d 
	@${RM} ${OBJECTDIR}/src/configurationBit.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/configurationBit.c  -o ${OBJECTDIR}/src/configurationBit.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/configurationBit.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/main.o: src/main.c  .generated_files/flags/XC16_dsPIC33EP128GM710/85e6a9ac1bdda6e98d9731133c5f63efe5118468 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/main.c  -o ${OBJECTDIR}/src/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/main.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/i2c.o: src/i2c.c  .generated_files/flags/XC16_dsPIC33EP128GM710/d9f77545ccbade07f38472ad8130cc2bccac6c53 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/i2c.o.d 
	@${RM} ${OBJECTDIR}/src/i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/i2c.c  -o ${OBJECTDIR}/src/i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/i2c.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/spi.o: src/spi.c  .generated_files/flags/XC16_dsPIC33EP128GM710/cdda04e9194908b89de4e5e97ba90699a9879158 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/spi.o.d 
	@${RM} ${OBJECTDIR}/src/spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/spi.c  -o ${OBJECTDIR}/src/spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/spi.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/clock.o: src/clock.c  .generated_files/flags/XC16_dsPIC33EP128GM710/9649b10431b85d75e2d4e0d8d01ffeed24e95be .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/clock.o.d 
	@${RM} ${OBJECTDIR}/src/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/clock.c  -o ${OBJECTDIR}/src/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/clock.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/can.o: src/can.c  .generated_files/flags/XC16_dsPIC33EP128GM710/90e713b4ffb378fb1fc303b8b858a928d31022a0 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/can.o.d 
	@${RM} ${OBJECTDIR}/src/can.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/can.c  -o ${OBJECTDIR}/src/can.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/can.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/rtc.o: src/rtc.c  .generated_files/flags/XC16_dsPIC33EP128GM710/ce094a8591c6c8bfe0176dd973de6ae813b8ad15 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/rtc.o.d 
	@${RM} ${OBJECTDIR}/src/rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/rtc.c  -o ${OBJECTDIR}/src/rtc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/rtc.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/src/adc.o: src/adc.c  .generated_files/flags/XC16_dsPIC33EP128GM710/2cbee15049a4788ae40709d771a15c110f946aa9 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/adc.o.d 
	@${RM} ${OBJECTDIR}/src/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/adc.c  -o ${OBJECTDIR}/src/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/adc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/gpio.o: src/gpio.c  .generated_files/flags/XC16_dsPIC33EP128GM710/5ac198fb4e74a83cb6a82cbb3067e8da4265d287 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/gpio.o.d 
	@${RM} ${OBJECTDIR}/src/gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/gpio.c  -o ${OBJECTDIR}/src/gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/gpio.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/pwm.o: src/pwm.c  .generated_files/flags/XC16_dsPIC33EP128GM710/4154a8d359c14fdc70d96f40338ebd6cd04cca23 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/pwm.o.d 
	@${RM} ${OBJECTDIR}/src/pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/pwm.c  -o ${OBJECTDIR}/src/pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/pwm.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/sysTick.o: src/sysTick.c  .generated_files/flags/XC16_dsPIC33EP128GM710/d7828bb99636ddc330d91875f0d8266d020ff8fa .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/sysTick.o.d 
	@${RM} ${OBJECTDIR}/src/sysTick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/sysTick.c  -o ${OBJECTDIR}/src/sysTick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/sysTick.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/timer.o: src/timer.c  .generated_files/flags/XC16_dsPIC33EP128GM710/4206d2afd6c1c724bdadda69c788843d3857b551 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/timer.o.d 
	@${RM} ${OBJECTDIR}/src/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/timer.c  -o ${OBJECTDIR}/src/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/timer.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/uart.o: src/uart.c  .generated_files/flags/XC16_dsPIC33EP128GM710/fbb832f11f162f2c052934f6c7a68dc2d03a6b76 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/uart.o.d 
	@${RM} ${OBJECTDIR}/src/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/uart.c  -o ${OBJECTDIR}/src/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/uart.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/xbee.o: src/xbee.c  .generated_files/flags/XC16_dsPIC33EP128GM710/df423948a17ce8e8a5725c9cc4c667ab8902f20d .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/xbee.o.d 
	@${RM} ${OBJECTDIR}/src/xbee.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/xbee.c  -o ${OBJECTDIR}/src/xbee.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/xbee.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/configurationBit.o: src/configurationBit.c  .generated_files/flags/XC16_dsPIC33EP128GM710/8f4c3041db2472e46f107f60712bd4314a1d1c78 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/configurationBit.o.d 
	@${RM} ${OBJECTDIR}/src/configurationBit.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/configurationBit.c  -o ${OBJECTDIR}/src/configurationBit.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/configurationBit.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/main.o: src/main.c  .generated_files/flags/XC16_dsPIC33EP128GM710/4e5fef64ae33e3634f94b59d3055f4a3323f086d .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/main.c  -o ${OBJECTDIR}/src/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/i2c.o: src/i2c.c  .generated_files/flags/XC16_dsPIC33EP128GM710/e063ecd03ee0947716869213f15c22cb9b3c3f13 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/i2c.o.d 
	@${RM} ${OBJECTDIR}/src/i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/i2c.c  -o ${OBJECTDIR}/src/i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/i2c.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/spi.o: src/spi.c  .generated_files/flags/XC16_dsPIC33EP128GM710/a6a595a6b16b76b2754691163a432c712ef9ec15 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/spi.o.d 
	@${RM} ${OBJECTDIR}/src/spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/spi.c  -o ${OBJECTDIR}/src/spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/spi.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/clock.o: src/clock.c  .generated_files/flags/XC16_dsPIC33EP128GM710/7e5e9d5ee941e77f250d86d0bcd3d5f06e90efec .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/clock.o.d 
	@${RM} ${OBJECTDIR}/src/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/clock.c  -o ${OBJECTDIR}/src/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/clock.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/can.o: src/can.c  .generated_files/flags/XC16_dsPIC33EP128GM710/5a82f08083d4029c97a9aa333c40012847304a2c .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/can.o.d 
	@${RM} ${OBJECTDIR}/src/can.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/can.c  -o ${OBJECTDIR}/src/can.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/can.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/rtc.o: src/rtc.c  .generated_files/flags/XC16_dsPIC33EP128GM710/d6fb7eb5cf04257dd86a3240b5998956bef4729b .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/rtc.o.d 
	@${RM} ${OBJECTDIR}/src/rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/rtc.c  -o ${OBJECTDIR}/src/rtc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/rtc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
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
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/GrandeCiblePS4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)      -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/GrandeCiblePS4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/GrandeCiblePS4.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
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

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
