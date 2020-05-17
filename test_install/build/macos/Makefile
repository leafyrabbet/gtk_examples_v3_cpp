# GNU Make 4.3
# macOS Build Script
#
# Tommy Vegetables (leafyrabbet)
# leafyrabbet@gmail.com
# Copyright (c) 2020, TenonGarden Productions

.RECIPEPREFIX = +

CC_STD = c++2a
GCC := gcc-9 --std=$(CC_STD)
FLAGS = -Wall -Wextra -Werror -pedantic -g

LIB_GTKMM = gtkmm-3.0
LIB_GLIB = glib-2.0
LIBS := `pkg-config $(LIB_GTKMM) $(LIB_GLIB) --cflags --libs` -lstdc++

BINTAG ?=  # `date +D%Y.%m.%d_T%H.%M.%S_Z%z`
EXE_NAME_BASE ?= test_install

SRC_DIR := ../../src

.DELETE_ON_ERROR:

.PHONY: all
all:
+ $(GCC) $(FLAGS) \
    -o $(EXE_NAME_BASE)$(BINTAG) \
    $(SRC_DIR)/main.cpp \
    $(LIBS)
+ chmod +x $(EXE_NAME_BASE)$(BINTAG)

.PHONY: clean
clean:
+ rm ./$(EXE_NAME_BASE)
