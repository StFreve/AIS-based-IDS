NAME = Server

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

EXECUTABLE=$(BIN_DIR)/server

LIBS += $(LIB_DIR)/libIDS.a $(LIB_DIR)/libAIS.a
LDLIBS +=-lIDS -lAIS
INCLUDES += -I$(DIR)/

all: $(SRC_FILES) $(EXECUTABLE)
	
$(EXECUTABLE): $(DEP_FILES)
	mkdir -p $(BIN_DIR)
	$(CC) $(OBJ_FILES) $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	echo $<
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_FILES) $(EXECUTABLE)