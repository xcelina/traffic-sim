SRC_FILES = $(wildcard src/*.c) $(wildcard src/**/*.c)

default: $(SRC_FILES)
	gcc -Iinclude $(SRC_FILES) -lm