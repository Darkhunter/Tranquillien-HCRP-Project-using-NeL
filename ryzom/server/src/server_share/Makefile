#############################################################################
# Simple make file for compiling GAME SHARE

#############################################################################
# Setting up the compiler settings...

# Global variables
include ../../../Variables.mk

# The flags for the C++ compiler
CXXFLAGS     = $(FLAGS_CMN) $(FLAGS_DBG_$(DBG)) \
		-I/usr/include/libxml2 \
		-I/usr/include/mysql \
		-I$(NEL_INCLUDE) \
		-I$(RYZOM_PATH)/common/src \
		-I./ \
		-I./character_structure \
		-I./egs_sheets \
		-I./entity_structure \
		-I./game_item_manager

# The flags for the linker
LDFLAGS      = 	$(LD_FLAGS_CMN) -L$(RYZOM_PATH)/install/$(DIR_DBG_$(DBG))/lib \
		-llibmysqlclient \
		-lnelnet \
		-lnelgeorges \
		-lnelpacs \
		-L/usr/lib \
		-L/usr/X11R6/lib \
		-lnelmisc \
		-lxml2 \
		-lstlport \
		-lpthread \
		-lld

#############################################################################
# The bit that changes each time we cut paste and hack this file :o)

# The list of targets to build
TARGETS		= libserver_share.a
DSP_TARGET	= server_share.vcproj

# The default build rule
all:			check-deps $(TARGETS)


#libgame_share.so: $(OBJS)
#	$(CXX) -o $@ $(OBJS) -shared $(LDFLAGS)

libserver_share.a: $(OBJS)
	ar r libserver_share.a $(OBJS)

#############################################################################
# Rules

include ../../../Rules.mk
