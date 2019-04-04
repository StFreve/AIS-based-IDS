include ../template.mk

LDLIBS +=-lids -lais
LIBS += $(LIB_DIR)/libids.a $(LIB_DIR)/libais.a

EXECUTABLE = $(BIN_DIR)/server

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