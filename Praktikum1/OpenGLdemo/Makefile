#
# file....: Makefile for OpenGLdemo
# desc....: supports the build process for the following targets
#
#      LINUX_X86 : Linux      (Ubuntu 10.04 or similar with gl and glut development libs)
#      MAC       : MAC OS X   (Apple with gl and glut development libs - similar to linux)
#      QNX_X86   : QNX 6.4.1  (VirtualBox standard installation with disabled Photon)
#      QNX_SH4   : QNX 6.3.2  (Harmann/Becker D1 sh4 target)
#
# usage...: make QNX_X86|QNX_SH4|LINUX_X86|MAC
#

## defaulttarget
TARGETS = LINUX_X86 QNX_X86 #QNX_SH4

# Makefile global settings: 

HOSTPLATFORM		=$(shell uname)
ifneq ($(HOSTPLATFORM), Darwin)
CPUS				= $(shell cat /proc/cpuinfo  | grep MHz | wc -l)
else
CPUS				= 2
TARGETS				= MAC
endif
PARALLELPROC		= $(shell echo ${CPUS}*2 | bc)

PROJECT_ROOT  		= $(shell pwd)

PROG          		= OpenGLdemo
DEBUGFLAGS    		= -g
COMMON_INCLUDES		= 
CFLAGS 				= -Wall -DDEBUG_MODE

BINDIR	= $(PROJECT_ROOT)/bin/$(TARGET)

## internal vars
PROJECT_ROOT  = $(shell pwd)
VALID_TARGET  = 0

## target specific environments
ifeq ($(TARGET), LINUX_X86) 
	VALID_TARGET=1
	CC 			= g++
	LD 			= g++
	LIBS		= -lGL -lglut -lfreetype
	CFLAGS 		= $(DEBUGFLAGS)
	LDFLAGS		= $(DEBUGFLAGS)
	INCLUDES	= -I/usr/include/freetype2
	TARGETOBJS	= $(BINDIR)/CGraphicsDriverGLUT.o
endif # LINUX_X86

ifeq ($(TARGET), MAC) 
	VALID_TARGET=1
	CC 			= g++
	LD 			= g++
	LIBS		= -framework GLUT -framework OpenGL
	CFLAGS 		= $(DEBUGFLAGS) -DGLUT_STROKE_CHAR
	LDFLAGS		= $(DEBUGFLAGS)
	TARGETOBJS	= $(BINDIR)/CGraphicsDriverGLUT.o
endif # MAC

ifeq ($(TARGET), QNX_SH4) 
 	VALID_TARGET=1
	QNX_VERSION=650
	QNX_ROOT=/opt/qnx$(QNX_VERSION)
	QNX_TARGET=$(QNX_ROOT)/target/qnx6
	QNX_HOST=$(QNX_ROOT)/host/linux/x86

	CC 				= $(QNX_HOST)/usr/bin/qcc
	LD 				= $(QNX_HOST)/usr/bin/qcc
	CFLAGS 			= -V2.95.3,gcc_ntoshle -DGFX $(DEBUGFLAGS)
	LDFLAGS 		= -Vgcc_ntoshle $(DEBUGFLAGS)
	LIBDIR			= -Llib/qnx632
	LIBS			= -lGLES_CM -lgf -lgfx-gf -lfreetype
	INCLUDES		= -I$(PROJECT_ROOT)/include/qnx632 \
					-I$(PROJECT_ROOT)/include/qnx632/nvidia \
					-I$(PROJECT_ROOT)/include/qnx632/nvidia/GLES \
					-I$(PROJECT_ROOT)/include/qnx632/nvidia/gf 
	TARGETOBJS		= $(BINDIR)/CGraphicsDriverGFX.o
endif # QNX_SH4

ifeq ($(TARGET), QNX_X86)
	VALID_TARGET=1
	QNX_VERSION=650
	QNX_ROOT=/opt/qnx$(QNX_VERSION)
	QNXBIN=$(QNXROOT)/host/linux/x86/usr/bin
	QNX_ROOT=/opt/qnx$(QNX_VERSION)
	QNX_TARGET=$(QNX_ROOT)/target/qnx6
	QNX_HOST=$(QNX_ROOT)/host/linux/x86

	CC 			= $(QNX_HOST)/usr/bin/QCC
	LD 			= $(QNX_HOST)/usr/bin/QCC
	LIBS		= -lgf -lGLES_CM lib/qnx641/libfreetype.a -lz 
	CFLAGS 		= -Vgcc_ntox86 -Wall -DEGL  $(DEBUGFLAGS)
	LDFLAGS		= $(DEBUGFLAGS) $(BUILDTYPE)
	LIBDIR		= -Llib/qnx641
	INCLUDES	= -I$(PROJECT_ROOT)/include/qnx641
	TARGETOBJS  = $(BINDIR)/CGraphicsDriverEGL.o
endif #QNX_X86

## object files
OBJS = $(BINDIR)/main.o \
	$(BINDIR)/AGraphicsDriver.o \
	$(BINDIR)/CFTRender.o \
	$(BINDIR)/CHMIGUIImage.o \
	$(BINDIR)/CHMIGUIImageDesc.o \
	$(TARGETOBJS)

## make rules start here

## 
# All Targets
all: 
	@echo 
	@echo "Now perform build for most platforms ..."
	@echo 
	@for i in $(TARGETS); do \
	echo "   ... build target $$i"; \
	(make $$i > /dev/null); done
	@echo
	@echo "Finished build for most platforms"
	
LINUX_%:
	@make -j$(PARALLELPROC) $(PROG) TARGET=$@

QNX_%:
	@make -j$(PARALLELPROC) $(PROG) TARGET=$@
	
MAC:
	@make -j$(PARALLELPROC) $(PROG) TARGET=$@
	

$(PROG): $(OBJS)
	@echo 
	@echo " INFO    >> now linking $(PROG)"
	$(LD) $(LDFLAGS) $(LIBDIR) -o $(BINDIR)/$(PROG) $(OBJS) $(LIBS)
	@echo 
	@echo " INFO    >> build finished"
	
check:
	@echo 
	@echo " INFO   >> checking environment"
	@if [ "$(VALID_TARGET)" -ne 1 ] ; then \
		echo " ERROR   >> no variable TARGET defined!"; \
		exit 1; \
	fi
	@echo " INFO   >> environment is setup for target [$(TARGET)]"
	@echo " INFO   >> using compiler [$(CC)]"
	@echo " INFO   >> using linker   [$(LD)]"
	@echo ""

$(BINDIR)/%.o: %.cpp
	@mkdir -p $(BINDIR)
	$(CC) ${CFLAGS} $(BUILDTYPE) $(INCLUDES) -c -o $@ $<

clean: 
	@echo " INFO    >> now cleaning up"
	rm -rf  $(PROJECT_ROOT)/bin

# EOF
