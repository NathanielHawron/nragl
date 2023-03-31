C ?= emcc

BIN ?= bin/debug
SRC ?= src
INCLUDE ?= -I include -I vendor/freeglut/include

RES = $(BIN)/index.html
MAIN = $(SRC)/main.c

EXPORTED_RUNTIME_METHODS ?= "['ccall']"
TEMPLATE ?= templates/debug.html

compile:

build: compile
	$(C) $(MAIN) -o $(RES) --shell-file $(TEMPLATE) -s NO_EXIT_RUNTIME=1 -s "EXPORTED_RUNTIME_METHODS=$(EXPORTED_RUNTIME_METHODS)"