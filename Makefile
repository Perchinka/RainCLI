BUILD_DIR := build
BIN := $(BUILD_DIR)/bin/cli-rain

.PHONY: all build run clean rebuild

all: build

build:
	@mkdir -p $(BUILD_DIR)
	@cmake -S . -B $(BUILD_DIR) > /dev/null
	@cmake --build $(BUILD_DIR) -- -s 

run: build
	@$(BIN)

clean:
	@rm -rf $(BUILD_DIR)

rebuild: clean all

