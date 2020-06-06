# Simple Calculator (Example) App

This is an example of a GTK+3 application designed to function as a simple Calculator.

## Prerequisites

- GTK+ v3 installed on system.
- gtkmm v3 installed on system.
- C++ Compiler (modern).
- GNU Make v3.82 or higher.

## Tested System Setup

- macOS Catalina (`10.15.4`)
- Homebrew: [https://brew.sh/](https://brew.sh/)
- GTK+3 install: `3.24.18` (macOS Homebrew)
- gtkmm3 install: `3.24.2` (macOS Homebrew)
- GCC install: `9.3.0_1` (macOS Homebrew)
- GNU Make (`gmake`) install: `4.3` (macOS Homebrew)

## Build

Currently this only supports macOS.

To build the application defined in the `src/` directory, use the following `bash` commands:

```bash
cd <REPO_PATH_LOCAL>/build/macos/;
make;
```

The above should build an executable file named `calculator_simple` that can be run (see below).

## Run

After following the build instructions:

```bash
# ASSUMED: cd <REPO_PATH_LOCAL>/build/macos/;
./calculator_simple;
```

## Functionality

That **Run** procedure should pop-open a small Application Window with the appearance of a simple Calculator.

*Stay tuned...*

## Executable Info

- Name: `calculator_simple` (defined in `Makefile`)
- Size: `??? kiB`
