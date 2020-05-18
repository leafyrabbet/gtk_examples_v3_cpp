# test_install App

This is an example app to confirm that GTK+3 and gtkmm are installed, as well as a valid C++ compiler.

You should have been directed here as the first to run after cloning out this repository, to confirm that your system is ready for development with GTK+ v3.x.y (GTK+3).

## Prerequisites

- GTK+ v3 installed on system.
- gtkmm v3 installed on system.
- C++ Compiler (modern).
- GNU Make v3.82 or higher.

## Tested System Setup

- macOS Catalina (10.15.4)
- Homebrew: [https://brew.sh/](https://brew.sh/)
- GTK+3 install: 3.24.18 (macOS Homebrew)
- gtkmm3 install: 3.24.2 (macOS Homebrew)
- GCC install: 9.3.0_1 (macOS Homebrew)
- GNU Make (`gmake`) install: 4.3 (macOS Homebrew)

## Build

Currently this only supports macOS.

To build the application defined in the `src/` directory, use the following `bash` commands:

```bash
cd <REPO_PATH>/build/macos/;
make;
```

The above should build an executable file named `test_install` that can be run (see below).

## Run

After following the build instructions:

```bash
# ASSUMED: cd <REPO_PATH>/build/macos/;
./test_install;
```

That above command should pop-open a small Application Window with a few widgets in it.

If that succeeds, then your system is all set to run through the other examples.

If you get an error or some issue with any of the above commands, you'll need to re-review the prerequisites and confirm that your system is configured correctly.

## Executable Info

- Name: `test_install` (defined in `Makefile`)
- Size: `20.15 kiB`
