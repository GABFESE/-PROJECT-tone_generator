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
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/tonos.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/tonos.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=SystemPIC32MX.c 00.c "../../../Contenido del curso/TECLADO/14_Teclado_4X4_tmr/M_Timers.c" Teclado_4X4.c M_LCD_16X2.c delay.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/SystemPIC32MX.o ${OBJECTDIR}/00.o ${OBJECTDIR}/_ext/1834382844/M_Timers.o ${OBJECTDIR}/Teclado_4X4.o ${OBJECTDIR}/M_LCD_16X2.o ${OBJECTDIR}/delay.o
POSSIBLE_DEPFILES=${OBJECTDIR}/SystemPIC32MX.o.d ${OBJECTDIR}/00.o.d ${OBJECTDIR}/_ext/1834382844/M_Timers.o.d ${OBJECTDIR}/Teclado_4X4.o.d ${OBJECTDIR}/M_LCD_16X2.o.d ${OBJECTDIR}/delay.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/SystemPIC32MX.o ${OBJECTDIR}/00.o ${OBJECTDIR}/_ext/1834382844/M_Timers.o ${OBJECTDIR}/Teclado_4X4.o ${OBJECTDIR}/M_LCD_16X2.o ${OBJECTDIR}/delay.o

# Source Files
SOURCEFILES=SystemPIC32MX.c 00.c ../../../Contenido del curso/TECLADO/14_Teclado_4X4_tmr/M_Timers.c Teclado_4X4.c M_LCD_16X2.c delay.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/tonos.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX250F128B
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/SystemPIC32MX.o: SystemPIC32MX.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SystemPIC32MX.o.d 
	@${RM} ${OBJECTDIR}/SystemPIC32MX.o 
	@${FIXDEPS} "${OBJECTDIR}/SystemPIC32MX.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SystemPIC32MX.o.d" -o ${OBJECTDIR}/SystemPIC32MX.o SystemPIC32MX.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/00.o: 00.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/00.o.d 
	@${RM} ${OBJECTDIR}/00.o 
	@${FIXDEPS} "${OBJECTDIR}/00.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/00.o.d" -o ${OBJECTDIR}/00.o 00.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1834382844/M_Timers.o: ../../../Contenido\ del\ curso/TECLADO/14_Teclado_4X4_tmr/M_Timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1834382844" 
	@${RM} ${OBJECTDIR}/_ext/1834382844/M_Timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1834382844/M_Timers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1834382844/M_Timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1834382844/M_Timers.o.d" -o ${OBJECTDIR}/_ext/1834382844/M_Timers.o "../../../Contenido del curso/TECLADO/14_Teclado_4X4_tmr/M_Timers.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Teclado_4X4.o: Teclado_4X4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Teclado_4X4.o.d 
	@${RM} ${OBJECTDIR}/Teclado_4X4.o 
	@${FIXDEPS} "${OBJECTDIR}/Teclado_4X4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Teclado_4X4.o.d" -o ${OBJECTDIR}/Teclado_4X4.o Teclado_4X4.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/M_LCD_16X2.o: M_LCD_16X2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/M_LCD_16X2.o.d 
	@${RM} ${OBJECTDIR}/M_LCD_16X2.o 
	@${FIXDEPS} "${OBJECTDIR}/M_LCD_16X2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/M_LCD_16X2.o.d" -o ${OBJECTDIR}/M_LCD_16X2.o M_LCD_16X2.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/delay.o: delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/delay.o.d 
	@${RM} ${OBJECTDIR}/delay.o 
	@${FIXDEPS} "${OBJECTDIR}/delay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/delay.o.d" -o ${OBJECTDIR}/delay.o delay.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/SystemPIC32MX.o: SystemPIC32MX.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SystemPIC32MX.o.d 
	@${RM} ${OBJECTDIR}/SystemPIC32MX.o 
	@${FIXDEPS} "${OBJECTDIR}/SystemPIC32MX.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SystemPIC32MX.o.d" -o ${OBJECTDIR}/SystemPIC32MX.o SystemPIC32MX.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/00.o: 00.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/00.o.d 
	@${RM} ${OBJECTDIR}/00.o 
	@${FIXDEPS} "${OBJECTDIR}/00.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/00.o.d" -o ${OBJECTDIR}/00.o 00.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1834382844/M_Timers.o: ../../../Contenido\ del\ curso/TECLADO/14_Teclado_4X4_tmr/M_Timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1834382844" 
	@${RM} ${OBJECTDIR}/_ext/1834382844/M_Timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1834382844/M_Timers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1834382844/M_Timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1834382844/M_Timers.o.d" -o ${OBJECTDIR}/_ext/1834382844/M_Timers.o "../../../Contenido del curso/TECLADO/14_Teclado_4X4_tmr/M_Timers.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Teclado_4X4.o: Teclado_4X4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Teclado_4X4.o.d 
	@${RM} ${OBJECTDIR}/Teclado_4X4.o 
	@${FIXDEPS} "${OBJECTDIR}/Teclado_4X4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Teclado_4X4.o.d" -o ${OBJECTDIR}/Teclado_4X4.o Teclado_4X4.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/M_LCD_16X2.o: M_LCD_16X2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/M_LCD_16X2.o.d 
	@${RM} ${OBJECTDIR}/M_LCD_16X2.o 
	@${FIXDEPS} "${OBJECTDIR}/M_LCD_16X2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/M_LCD_16X2.o.d" -o ${OBJECTDIR}/M_LCD_16X2.o M_LCD_16X2.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/delay.o: delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/delay.o.d 
	@${RM} ${OBJECTDIR}/delay.o 
	@${FIXDEPS} "${OBJECTDIR}/delay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/delay.o.d" -o ${OBJECTDIR}/delay.o delay.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/tonos.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/tonos.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/tonos.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/tonos.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/tonos.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
