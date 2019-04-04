include ../template.mk

LIB_PATH = $(LIB_DIR)/libais.a

all: $(SRC_FILES) $(LIB_PATH)

$(LIB_PATH): $(OBJ_FILES) 
	mkdir -p $(LIB_DIR)
	$(AR) $(ARFLAGS) $@ $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_FILES) $(LIB_PATH)