#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/arquivos/ex01.o \
	${OBJECTDIR}/arquivos/ex02.o \
	${OBJECTDIR}/arquivos/ex03.o \
	${OBJECTDIR}/arquivos/ex04.o \
	${OBJECTDIR}/exemplos/ex01.o \
	${OBJECTDIR}/exemplos/ex02.o \
	${OBJECTDIR}/exemplos/ex03.o \
	${OBJECTDIR}/exemplos/ex04.o \
	${OBJECTDIR}/exemplos/ex05.o \
	${OBJECTDIR}/exemplos/ex06.o \
	${OBJECTDIR}/exemplos/ex07.o \
	${OBJECTDIR}/exemplos/ex08.o \
	${OBJECTDIR}/exemplos/ex10.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/archiver

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/archiver: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/archiver ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/arquivos/ex01.o: arquivos/ex01.c
	${MKDIR} -p ${OBJECTDIR}/arquivos
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/arquivos/ex01.o arquivos/ex01.c

${OBJECTDIR}/arquivos/ex02.o: arquivos/ex02.c
	${MKDIR} -p ${OBJECTDIR}/arquivos
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/arquivos/ex02.o arquivos/ex02.c

${OBJECTDIR}/arquivos/ex03.o: arquivos/ex03.c
	${MKDIR} -p ${OBJECTDIR}/arquivos
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/arquivos/ex03.o arquivos/ex03.c

${OBJECTDIR}/arquivos/ex04.o: arquivos/ex04.c
	${MKDIR} -p ${OBJECTDIR}/arquivos
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/arquivos/ex04.o arquivos/ex04.c

${OBJECTDIR}/exemplos/ex01.o: exemplos/ex01.c
	${MKDIR} -p ${OBJECTDIR}/exemplos
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exemplos/ex01.o exemplos/ex01.c

${OBJECTDIR}/exemplos/ex02.o: exemplos/ex02.c
	${MKDIR} -p ${OBJECTDIR}/exemplos
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exemplos/ex02.o exemplos/ex02.c

${OBJECTDIR}/exemplos/ex03.o: exemplos/ex03.c
	${MKDIR} -p ${OBJECTDIR}/exemplos
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exemplos/ex03.o exemplos/ex03.c

${OBJECTDIR}/exemplos/ex04.o: exemplos/ex04.c
	${MKDIR} -p ${OBJECTDIR}/exemplos
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exemplos/ex04.o exemplos/ex04.c

${OBJECTDIR}/exemplos/ex05.o: exemplos/ex05.c
	${MKDIR} -p ${OBJECTDIR}/exemplos
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exemplos/ex05.o exemplos/ex05.c

${OBJECTDIR}/exemplos/ex06.o: exemplos/ex06.c
	${MKDIR} -p ${OBJECTDIR}/exemplos
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exemplos/ex06.o exemplos/ex06.c

${OBJECTDIR}/exemplos/ex07.o: exemplos/ex07.c
	${MKDIR} -p ${OBJECTDIR}/exemplos
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exemplos/ex07.o exemplos/ex07.c

${OBJECTDIR}/exemplos/ex08.o: exemplos/ex08.c
	${MKDIR} -p ${OBJECTDIR}/exemplos
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exemplos/ex08.o exemplos/ex08.c

${OBJECTDIR}/exemplos/ex10.o: exemplos/ex10.c
	${MKDIR} -p ${OBJECTDIR}/exemplos
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exemplos/ex10.o exemplos/ex10.c

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
