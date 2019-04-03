NAME = IDS

CC = g++
AR = ar
INCLUDES =
LIBS =
LDLIBS =
CFLAGS = -c -Wall -std=c++11 $(INCLUDES)
LDFLAGS = -static -L$(LIB_DIR) $(LDLIBS)
ARFLAGS = rvs

DIR=..
LIB_DIR = $(DIR)/lib
OBJ_DIR = $(DIR)/obj/$(NAME)
BIN_DIR = $(DIR)/bin
SRC_DIR = $(DIR)/$(NAME)
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
DEP_FILES = $(LIBS) $(OBJ_FILES)

LIB_PATH = $(LIB_DIR)/lib$(NAME).a
LIBS += $(LIB_DIR)/libAIS.a
INCLUDES += -I$(DIR)/

all: $(SRC_FILES) $(LIB_PATH)
	
$(LIB_PATH): $(DEP_FILES) 
	mkdir -p $(LIB_DIR)
	$(AR) $(ARFLAGS) $@ $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_FILES) $(LIB_PATH)