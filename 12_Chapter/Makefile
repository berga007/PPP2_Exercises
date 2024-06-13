# The following script was based on
# Compiling Programs with Makefiles from the url:
# https://www.fltk.org/doc-1.3/basics.html#basics_makefile

TARGET = sec_12_3
CODEDIRS = GUI

CXX      = $(shell fltk-config --cxx)
DEBUG    = -g
CXXFLAGS = $(shell fltk-config --use-gl --use-images --cxxflags ) -I.
LDFLAGS  = $(shell fltk-config --use-gl --use-images --ldflags )
LDSTATIC = $(shell fltk-config --use-gl --use-images --ldstaticflags )
LINK     = $(CXX)

# for-style iteration (foreach) and regular expression completions (wildcard)
SRCS = $(foreach D, $(CODEDIRS), $(wildcard $(D)/*.cpp))
# SRCS = sec_12_3.cpp

# regular expression replacement
OBJS = $(patsubst %.c, %.o, $(SRCS)) sec_12_3.cpp
 
.SUFFIXES: .o .cpp
 
all: $(TARGET)

$(TARGET): $(OBJS)
		$(LINK) -o $(TARGET) $(OBJS) $(LDSTATIC)

%.o: %.cpp
		$(CXX) $(CXXFLAGS) $(DEBUG) -c $@ $<
 
clean: $(TARGET) $(OBJS)
		rm -f *.o 2> /dev/null
		rm -f $(TARGET) 2> /dev/null