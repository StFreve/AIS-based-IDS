ROOT_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
DIR_NAME := $(notdir $(shell pwd))
LIB_DIR = $(ROOT_DIR)/lib
OBJ_DIR = $(ROOT_DIR)/obj/$(DIR_NAME)
BIN_DIR = $(ROOT_DIR)/bin
SRC_DIR = $(shell pwd)
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
DEP_FILES = $(LIBS) $(OBJ_FILES)

CC = g++
AR = ar
INCLUDES = -I$(ROOT_DIR)
LIBS =
LDLIBS =
CFLAGS = -c -Wall -std=c++11 $(INCLUDES)
LDFLAGS = -static -L$(LIB_DIR) $(LDLIBS)
ARFLAGS = rvs