BUILD_DIR := build
BIN := $(BUILD_DIR)/bin/cli-rain

.PHONY: all build run clean test rebuild

all: build

build:
	@mkdir -p $(BUILD_DIR)
	@cmake -S . -B $(BUILD_DIR) > /dev/null
	@cmake --build $(BUILD_DIR) -- -s 

test: build
	@echo "Running unit tests..."
	@cd $(BUILD_DIR) && ctest --output-on-failure

run: build
	@$(BIN)

clean:
	@rm -rf $(BUILD_DIR)

rebuild: clean all

