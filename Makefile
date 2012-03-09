program_NAME := BadassHeroes

program_CXX_SRCS := $(wildcard *.cpp)
OBJ_DIR := .obj
program_CXX_OBJS  := $(patsubst %,$(OBJ_DIR)/%,${program_CXX_SRCS:.cpp=.o})

program_INCLUDE_DIRS :=

program_LIBRARIES := GL glfw SDL SDL_image

CPPFLAGS += $(foreach includedir,$(program_INCLUDE_DIRS),-I$(includedir))

LDFLAGS += $(foreach librarydir,$(program_LIBRARY_DIRS),-L$(librarydir))

LDFLAGS += $(foreach library,$(program_LIBRARIES),-l$(library))

$(OBJ_DIR)/%.o:%.cpp
	$(CC) -c -o $@ $<

$(program_NAME): $(program_CXX_OBJS)
	$(LINK.cc) $(program_CXX_OBJS) -o bin/$(program_NAME)

clean:
	@- $(RM) bin/$(program_NAME)
	@- $(RM) $(program_CXX_OBJS)