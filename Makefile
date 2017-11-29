# redmake-0.1 Individual Project Makefile

# Build Options
LIBRARY_NAME          = arete
COMMON_COMPILER_FLAGS = -g -Wall -Wextra
C_COMPILER_FLAGS      = -std=c11
CPP_COMPILER_FLAGS    = -std=c++11
INCLUDE_DIRECTORIES   =
LINKER_FLAGS          =
REDMAKE_DEPENDENCIES  =
LINK_TYPE             = dynamic

##################
## Call redmake ##
##################

MAKE = make
REDMAKE_DIRECTORY = ../redmake/Makefile
COMMAND = $(MAKE) -f $(REDMAKE_DIRECTORY) -C . $@ LIBRARY_NAME="$(LIBRARY_NAME)" COMMON_COMPILER_FLAGS="$(COMMON_COMPILER_FLAGS)" C_COMPILER_FLAGS="$(C_COMPILER_FLAGS)" CPP_COMPILER_FLAGS="$(CPP_COMPILER_FLAGS)" INCLUDE_DIRECTORIES="$(INCLUDE_DIRECTORIES)" LINKER_FLAGS="$(LINKER_FLAGS)" REDMAKE_DEPENDENCIES="$(REDMAKE_DEPENDENCIES)" LINK_TYPE="$(LINK_TYPE)"

all:
	$(COMMAND)
clean:
	$(COMMAND)
