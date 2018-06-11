AutomatedMakefile = am
CC = g++
CXXFLAGS = -Wno-deprecated-declarations -g -O0

PROJECT_PATH = $(CURRENT_DIR)
GUI_PATH = $(DRIVE_LETTER)/TDM-GCC-64/x86_64-w64-mingw32

INC_DIRS = -I./1310/CSC1310 -I./1310/GUI -I$(GUI_PATH)/include -I$(GUI_PATH)/lib/gcc510TDM_x64_dll/mswu
LIB_DIRS = -L./1310/CSC1310 -L./1310/GUI -L$(GUI_PATH)/lib/gcc510TDM_x64_dll
LDFLAGS = -Wl,-Bstatic
LIBS = $(LDFLAGS) -lCSC1310 -lrandom -lGUI 


COMPILE = $(CC) $(CXXFLAGS) $(INC_DIRS) -c 
LINK = $(CC) $(CXXFLAGS) $(LIB_DIRS)

FILES = Password.o PasswordDriver.o
EXECUTABLE = Lab03.exe

all: Lab03

Lab03: 	$(FILES)
			$(LINK) $(FILES) $(LIBS) -o $(EXECUTABLE)

Password.o:		
			$(COMPILE) Password.cpp
PasswordDriver.o:		
			$(COMPILE) PasswordDriver.cpp