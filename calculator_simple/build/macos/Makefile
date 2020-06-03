# gtk_examples_v3_cpp/calculator_simple
# macOS Build Script
# GNU Make 4.3 (Tested)
#
# References:
# - https://www.rapidtables.com/code/linux/gcc/gcc-o.html
#
# Author:
# Tommy Vegetables (leafyrabbet)
# leafyrabbet@gmail.com
# 
# Copyright:
# TenonGarden Productions (c) 2020

.RECIPEPREFIX = +  # Note: This replaces the `\t` (TAB) character


EXE_NAME_BASE ?= calculator_simple
BINTAG ?=  # _`date +D%Y.%m.%d_T%H.%M.%S_Z%z`

SRC_DIR := ../../src

GCC := gcc-9
CC_STD = c++2a  # C++20
COMPILER := $(GCC) --std=$(CC_STD)
FLG_GDB_DEBUG ?=  # -ggdb3
FLG_OPTIMIZED ?= -O0
FLAGS = -Wall \
         -Wextra \
         -Werror \
         -pedantic \
         $(FLG_OPTIMIZED) \
         $(FLG_GDB_DEBUG)

COMPILER_WITH_FLAGS := $(COMPILER) $(FLAGS)

LIB_GTKMM = gtkmm-3.0
LIB_GLIB = glib-2.0
LIB_CAIRO = cairomm-1.0
LIB_PANGO = pangomm-1.4
PKG_CONFIG_LIBS := $(LIB_GTKMM) $(LIB_GLIB) $(LIB_CAIRO) $(LIB_PANGO)
OTHER_LIBS := -lstdc++
LIBS := $(OTHER_LIBS) `pkg-config --cflags --libs $(PKG_CONFIG_LIBS)`

.DELETE_ON_ERROR:

.PHONY: all
all:
+ $(COMPILER_WITH_FLAGS) \
   -o $(EXE_NAME_BASE)$(BINTAG) \
   $(SRC_DIR)/app_window.cpp \
   $(SRC_DIR)/logic_calculator.cpp \
   $(SRC_DIR)/main.cpp \
   $(LIBS)
+ chmod +x $(EXE_NAME_BASE)$(BINTAG)

.PHONY: clean
clean:
+ rm ./$(EXE_NAME_BASE)
