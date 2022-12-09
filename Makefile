CC=gcc
# TARGET="bin/libenuma.so"
CFLAGS:=-std=gnu18 -g -fPIC -I./ -I$(VULKAN_SDK)/include/vulkan/
LIBS:=-lm -lglfw
FILES:=$(shell find . -type f -name "*.c")

all: 
	mkdir -p bin
	$(CC) $(FILES) $(CFLAGS) $(LIBS) -o  bin/test
	./bin/test