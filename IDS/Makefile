include ../Makefile.tmpl

LIB_PATH = $(LIB_DIR)/libids.a
LIBS += $(LIB_DIR)/libais.a

all: $(SRC_FILES) $(LIB_PATH)
	
$(LIB_PATH): $(DEP_FILES) 
	mkdir -p $(LIB_DIR)
	$(AR) $(ARFLAGS) $@ $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_FILES) $(LIB_PATH)