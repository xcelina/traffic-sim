SRC_FILES = $(wildcard src/*.c) $(wildcard src/sim/*.c)
INCLUDE_DIRS = -Iinclude
GCC = gcc
CFLAGS = -lm

ifndef NOGUI
	CFLAGS += `pkg-config --cflags --libs sdl2`
	SRC_FILES += $(wildcard src/gui/*.c)
else
	CFLAGS += -D NOGUI
endif

default: a.out

nogui:
	$(MAKE) $(MAKEFLAGS) NOGUI=1 a.out

a.out: $(SRC_FILES)
	$(GCC) $(INCLUDE_DIRS) $(SRC_FILES) $(CFLAGS)

clear:
	rm a.out