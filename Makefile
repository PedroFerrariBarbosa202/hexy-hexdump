CC := gcc
AR := ar

CFLAGS := -Wall
CPPFLAGS := -Iinc/hexy -Ishared

LDFLAGS :=

LIB_NAME := libhexy.a
TARGET := hexy

BUILD_DIR := build
LIB_DIR := lib
CMD_DIR := tool

LIB_SRC := \
					 $(LIB_DIR)/hexy.c


# patsubst(patters, replace, text)
# pattern: what to look for
# replace: what to replace with
# text: text to check
LIB_OBJS := $(patsubst $(LIB_DIR)/%.c, \
						$(BUILD_DIR)/%.o, \
						$(LIB_SRC))

CMD_OBJ := $(BUILD_DIR)/hexy.o

LIBRARY := $(BUILD_DIR)/$(LIB_NAME)

.PHONY: all library clean

all: $(TARGET)

# Build the static lib
library: $(LIBRARY)

$(LIBRARY): $(LIB_OBJS) 
	$(AR) rcs $@ $^

# Compile library source file:
$(BUILD_DIR)/%.o: $(LIB_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Compile frontend/tools
$(CMD_OBJ): $(CMD_DIR)/hexy.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Link the executable against the library
$(TARGET): $(CMD_OBJ) $(LIBRARY)
	$(CC) $(CMD_OBJ) $(LIBRARY) $(LDFLAGS) -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)
