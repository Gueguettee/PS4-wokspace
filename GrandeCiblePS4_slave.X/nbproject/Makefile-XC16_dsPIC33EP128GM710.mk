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
	${MAKE}  -f nbproject/Makefile-XC16_dsPIC33EP128GM710.mk ${DISTDIR}/GrandeCiblePS4_slave.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33EP128GM710
MP_LINKER_FILE_OPTION=,--script=p33EP128GM710.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/adc.o: src/adc.c  .generated_files/flags/XC16_dsPIC33EP128GM710/3e343c2b8dcbe50f5d6c0d19bcb47672e7349652 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/adc.o.d 
	@${RM} ${OBJECTDIR}/src/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/adc.c  -o ${OBJECTDIR}/src/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/adc.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/gpio.o: src/gpio.c  .generated_files/flags/XC16_dsPIC33EP128GM710/6d5b47a718d9357a1c0c62c7878208b5e3b3db2 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/gpio.o.d 
	@${RM} ${OBJECTDIR}/src/gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/gpio.c  -o ${OBJECTDIR}/src/gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/gpio.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/pwm.o: src/pwm.c  .generated_files/flags/XC16_dsPIC33EP128GM710/85fdbf2bbe2d40d775fe9621dde6a36490304b3a .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/pwm.o.d 
	@${RM} ${OBJECTDIR}/src/pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/pwm.c  -o ${OBJECTDIR}/src/pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/pwm.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/sysTick.o: src/sysTick.c  .generated_files/flags/XC16_dsPIC33EP128GM710/ce073a076d3c2fbd80399425d445ebbd255b930e .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/sysTick.o.d 
	@${RM} ${OBJECTDIR}/src/sysTick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/sysTick.c  -o ${OBJECTDIR}/src/sysTick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/sysTick.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/timer.o: src/timer.c  .generated_files/flags/XC16_dsPIC33EP128GM710/3b2c4794948cebcf41667d4865b55149759a22b5 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/timer.o.d 
	@${RM} ${OBJECTDIR}/src/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/timer.c  -o ${OBJECTDIR}/src/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/timer.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/uart.o: src/uart.c  .generated_files/flags/XC16_dsPIC33EP128GM710/b7c5512ab518f06edeae11788ae225085e19478a .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/uart.o.d 
	@${RM} ${OBJECTDIR}/src/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/uart.c  -o ${OBJECTDIR}/src/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/uart.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/xbee.o: src/xbee.c  .generated_files/flags/XC16_dsPIC33EP128GM710/6f804163f5a172bd495134b4e2cc9c87b175256 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/xbee.o.d 
	@${RM} ${OBJECTDIR}/src/xbee.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/xbee.c  -o ${OBJECTDIR}/src/xbee.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/xbee.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/configurationBit.o: src/configurationBit.c  .generated_files/flags/XC16_dsPIC33EP128GM710/c9c992bde83fb4abd76769ed517b11ef93a37007 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/configurationBit.o.d 
	@${RM} ${OBJECTDIR}/src/configurationBit.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/configurationBit.c  -o ${OBJECTDIR}/src/configurationBit.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/configurationBit.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/main.o: src/main.c  .generated_files/flags/XC16_dsPIC33EP128GM710/410bbf4bfb33e9527f617a20df0b8b75b62060b0 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/main.c  -o ${OBJECTDIR}/src/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/main.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/i2c.o: src/i2c.c  .generated_files/flags/XC16_dsPIC33EP128GM710/b1e5406df81cce6b3806ac4b63fc3a73cede209e .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/i2c.o.d 
	@${RM} ${OBJECTDIR}/src/i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/i2c.c  -o ${OBJECTDIR}/src/i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/i2c.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/spi.o: src/spi.c  .generated_files/flags/XC16_dsPIC33EP128GM710/14635451b9ecf0b5f6f7316e957230ba2894c6bf .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/spi.o.d 
	@${RM} ${OBJECTDIR}/src/spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/spi.c  -o ${OBJECTDIR}/src/spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/spi.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/clock.o: src/clock.c  .generated_files/flags/XC16_dsPIC33EP128GM710/c9edad6d963648f79a23f29204d963d6192b1a6d .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/clock.o.d 
	@${RM} ${OBJECTDIR}/src/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/clock.c  -o ${OBJECTDIR}/src/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/clock.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/can.o: src/can.c  .generated_files/flags/XC16_dsPIC33EP128GM710/75a9d834c6ad716ec6c99bbd1f6c71ac45a19872 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/can.o.d 
	@${RM} ${OBJECTDIR}/src/can.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/can.c  -o ${OBJECTDIR}/src/can.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/can.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/rtc.o: src/rtc.c  .generated_files/flags/XC16_dsPIC33EP128GM710/a200ef021406f65724d7f8398b1fadb8bc8b5384 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/rtc.o.d 
	@${RM} ${OBJECTDIR}/src/rtc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/rtc.c  -o ${OBJECTDIR}/src/rtc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/rtc.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/src/adc.o: src/adc.c  .generated_files/flags/XC16_dsPIC33EP128GM710/f79f068f70d00622160e5f281a5e9c1341332766 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/adc.o.d 
	@${RM} ${OBJECTDIR}/src/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/adc.c  -o ${OBJECTDIR}/src/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/adc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/gpio.o: src/gpio.c  .generated_files/flags/XC16_dsPIC33EP128GM710/2f201076b6d4cbc119d4819ec0c23c94d1330206 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/gpio.o.d 
	@${RM} ${OBJECTDIR}/src/gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/gpio.c  -o ${OBJECTDIR}/src/gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/gpio.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/pwm.o: src/pwm.c  .generated_files/flags/XC16_dsPIC33EP128GM710/ca94e157151ea17d6ced0b07960a18889c4ef3e2 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/pwm.o.d 
	@${RM} ${OBJECTDIR}/src/pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/pwm.c  -o ${OBJECTDIR}/src/pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/pwm.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/sysTick.o: src/sysTick.c  .generated_files/flags/XC16_dsPIC33EP128GM710/34bad5529cb812092f7f0eeeabef54404a402925 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/sysTick.o.d 
	@${RM} ${OBJECTDIR}/src/sysTick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/sysTick.c  -o ${OBJECTDIR}/src/sysTick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/sysTick.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/timer.o: src/timer.c  .generated_files/flags/XC16_dsPIC33EP128GM710/7a313678e895551c6113e26d8021ce55d315c1a8 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/timer.o.d 
	@${RM} ${OBJECTDIR}/src/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/timer.c  -o ${OBJECTDIR}/src/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/timer.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/uart.o: src/uart.c  .generated_files/flags/XC16_dsPIC33EP128GM710/ea677556ea683ff248adf78a1f167121a6270ae4 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/uart.o.d 
	@${RM} ${OBJECTDIR}/src/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/uart.c  -o ${OBJECTDIR}/src/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/uart.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/xbee.o: src/xbee.c  .generated_files/flags/XC16_dsPIC33EP128GM710/7c5a84c978759dceb2f062860f270c7061539143 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/xbee.o.d 
	@${RM} ${OBJECTDIR}/src/xbee.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/xbee.c  -o ${OBJECTDIR}/src/xbee.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/xbee.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/configurationBit.o: src/configurationBit.c  .generated_files/flags/XC16_dsPIC33EP128GM710/54cf345c22c1ac9e4a354a90f0ec628bc6069c43 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/configurationBit.o.d 
	@${RM} ${OBJECTDIR}/src/configurationBit.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/configurationBit.c  -o ${OBJECTDIR}/src/configurationBit.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/configurationBit.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/main.o: src/main.c  .generated_files/flags/XC16_dsPIC33EP128GM710/d07e03781d694ab60b926785486ec3f0abb4d030 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/main.c  -o ${OBJECTDIR}/src/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/i2c.o: src/i2c.c  .generated_files/flags/XC16_dsPIC33EP128GM710/3fc8f2aa7573283a39d338c0fd8a0cdb04f902ba .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/i2c.o.d 
	@${RM} ${OBJECTDIR}/src/i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/i2c.c  -o ${OBJECTDIR}/src/i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/i2c.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/spi.o: src/spi.c  .generated_files/flags/XC16_dsPIC33EP128GM710/aa48669faf6034ddeaf23b401c56905f75a1143 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/spi.o.d 
	@${RM} ${OBJECTDIR}/src/spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/spi.c  -o ${OBJECTDIR}/src/spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/spi.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/clock.o: src/clock.c  .generated_files/flags/XC16_dsPIC33EP128GM710/323d07ab63fcdb4bccfc9b711fa6ce3e368e8cee .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/clock.o.d 
	@${RM} ${OBJECTDIR}/src/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/clock.c  -o ${OBJECTDIR}/src/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/clock.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/can.o: src/can.c  .generated_files/flags/XC16_dsPIC33EP128GM710/11b8818e5b215dc7cbf4cc1ecef40ccaee8056b3 .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/can.o.d 
	@${RM} ${OBJECTDIR}/src/can.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/can.c  -o ${OBJECTDIR}/src/can.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/can.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"src" -I"header" -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/rtc.o: src/rtc.c  .generated_files/flags/XC16_dsPIC33EP128GM710/8e150f11f3ff15e2e79c1bc024096d32abe3bdeb .generated_files/flags/XC16_dsPIC33EP128GM710/24e18da1c422b499c691c65d8515f474e43e977d
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
${DISTDIR}/GrandeCiblePS4_slave.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/GrandeCiblePS4_slave.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/GrandeCiblePS4_slave.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/GrandeCiblePS4_slave.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_XC16_dsPIC33EP128GM710=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
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
