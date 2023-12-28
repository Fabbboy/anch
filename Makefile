# TOOLS
CC=gcc
CPP=g++
FLEX=flex
TARGET_EXEC:=anch
MKDIR_P:=mkdir -p

# GLOBAL
BUILD_DIR:=./build
SRC_DIRS:=./src

# PATHS
SRCS:=$(shell find $(SRC_DIRS) -name '*.c' -or -name '*.cpp')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS:=$(OBJS:.o=.d)
INC_DIRS:=$(shell find $(SRC_DIRS) -type d)
CFLEX_INPUT:=$(shell find $(SRC_DIRS) -name '*.l')
FLEX_OUT:=$(SRC_DIRS)/lexer/lex.yy.c
FLEX_OBJ:=$(BUILD_DIR)/$(SRC_DIRS)/lexer/lex.yy.c.o

# FLAGS
INC_FLAGS:=$(addprefix -I,$(INC_DIRS))
CPPFLAGS:=$(INC_FLAGS) -MMD -MP
CFLAGS:=-Wall -Wextra  -pedantic -g
LDFLAGS:=-lm
CPP_FLAGS:=-std=c++17 $(CFLAGS)


all: clean prepare cflex $(TARGET_EXEC)

$(TARGET_EXEC): $(OBJS) $(FLEX_OBJ) 
	$(CPP) $^ -o $@ $(LDFLAGS)
# C
$(BUILD_DIR)/%.c.o: %.c  | cflex
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@	

# C++
$(BUILD_DIR)/%.cpp.o: %.cpp  | cflex
	$(MKDIR_P) $(dir $@)
	$(CPP) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(FLEX_OUT): $(CFLEX_INPUT)
	$(FLEX) -o $(FLEX_OUT) $(CFLEX_INPUT)

$(FLEX_OBJ): $(FLEX_OUT)  # Ensure the flex object file is built from flex output
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

cflex: $(FLEX_OUT)

clean:
	$(RM) -r $(BUILD_DIR)
	$(RM) $(TARGET_EXEC)
	$(RM) $(FLEX_OUT)

prepare:
	mkdir -p $(BUILD_DIR)

run:
	./$(TARGET_EXEC)

.PHONY: clean prepare cflex
-include $(DEPS)