# GTK+ v3 Examples (C++ Language)

This is a repository of C++ (C++11 and C++2a) examples of using GTK+ v3 to build Graphical User Interfaces for system applications using the `gtkmm` library for C++ bindings.

You can use `gtk`'s C bindings instead of `gtkmm`, but to write more modern code in C++ style we decided to use `gtkmm`.

For more testing purposes, we're also building with GCC 9 using the C++2a standard ("C++20") and testing out the latest language features with the GUI apps shown here.

Once you've followed the build-and-setup section, you should go to the [test_install](test_install/README.md) documentation and follow those instructions to verify that everything is setup correctly.

## Build and Setup

Follow the setup instructions for your system before trying to build, modify, or run any of the provided example subprojects in this repository.

### macOS Catalina (10.15.x)

Note that with macOS Catalina (10.15.x), Apple changed the default shell for the system and user accounts to be `zsh` instead of `bash`. You shouldn't need to change it to run anything here, but I built everything using `bash` instead of `zsh`, so for reference here's how I updated my config:

```zsh
chsh -s /bin/bash;
touch ~/.bash_profile;
touch ~/.bashrc;
echo "source ~/.bashrc" >> ~/.bash_profile;
```

And then you can use either `~/.bashrc` or `~/.bash_profile` to put your shell preferences in. As configured, it's preferable to put everything in `~/.bashrc` since that'll be `source`-ed (read: "imported") by the `~/.bash_profile` file. I do this typically just to try and keep things more comparable to Linux systems that I use and work with, since they tend to only use a `~/.bashrc` config file and don't have the `~/.bash_profile` version. Most (if not all) of the configs are compatible between macOS and Linux, so putting everything into `~/.bashrc` this way can make the config more portable and reusable.

Again, the above is optional, but it's what I did, so there may be `bash`-specific commands referenced, and if you're using `zsh` you may get errors that I didn't. So please just be aware of that so that you don't get stuck or post a config-specific issue. If you'd like to request `zsh` support for this repo, please create an Enhancement issue on GitHub.

For the rest of the setup, the steps we'll follow are:

1. Install Homebrew, to make library installations consistent and (relatively) config-proof.
1. Use Homebrew to install the GTK+ v3 library and its dependencies.
1. Download and install a macOS compatible D Language Compiler.
1. Download the `gtkd` source code.
1. Build and install `gtkd`.

This process, all together, should take about 30-60 minutes with downloads and depending on your system specs.

1. [Homebrew](https://brew.sh/) install:
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
```
1. C++ Compiler installation (we're using GCC 9.3.x from Homebrew):
```bash
bre install gcc;
```
1. Homebrew install GTK+ v3 to macOS system:
```bash
brew install gtk+3;
brew install gtkmm3;  # C++ bindings, to do modern C++ (instead of C) development.
```
1. Go to the [test_install README](test_install/README.md) and confirm that the application builds and runs.

## Examples

### test_install

Simple example to confirm that the installation of prerequisites was successful.

See the [test_install README](test_install/README.md) for more info.
