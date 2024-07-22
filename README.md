# SampleTrickModel

This is a sample simulation model created to run on [NASA's Trick simulator](https://github.com/nasa/trick). This repository also contains unit tests and coverage infrastructure.

## Usage

### Install Nasa Trick

1. Follow [this guide](https://nasa.github.io/trick/documentation/install_guide/Install-Guide) to install Nasa Trick.
1. Make sure to install trick under `${HOME}`
1. Make sure to add `${HOME}/trick/bin` to the `PATH` environment variable.
1. Make sure to create a permanent envirtonment variable with the value of `${HOME}/trick` named `TRICK_HOME`.

### Install GNU compilers

``` bash
sudo apt install build-essential                                    # Install GNU compilers.
```

### Install clangd language server

``` bash
sudo apt install clangd                                             # Install clangd language server.
```

### Install GTest for unit testing

``` bash
cd /tmp/
git clone https://github.com/google/googletest.git -b v1.14.0       # Clone project from github to a specific release.
cd googletest                                                       # Main directory of the cloned repository.
mkdir build                                                         # Create a directory to hold the build output.
cd build                                                            # Change current dir to build dir.
cmake ..                                                            # Generate native build scripts for GoogleTest.
make                                                                # Compile gtest
sudo make install                                                   # Install in /usr/local/ by default
rm -rf /tmp/googletest/                                             # Remove temporarily create files.
```

### Install Gcovr for code coverage

``` bash
cd ~
sudo apt install python3-pip                                        # Install python package manager.
pip install gcovr                                                   # Install gcovr code coverage tool.
```

### Install GDB for debugging

``` bash
sudo apt install gdb                                                # Install GNU GDB debugger.
```

### Install clang-tidy for static code analysis

``` bash
sudo apt install clang-tidy                                         # Install clang-tidy.
```

### Use the scripts under `scripts/`

- `build.sh`: Build the unit tests.
- `clean.sh`: Clean the unit tests.
- `coverage.sh`: Generate unit test code coverage.
- `run.sh`: Run the unit tests without code coverage.

### Install zmq for TCP Communication

``` bash
sudo apt install cppzmq-dev                                         # Install cppzmq-dev
sudo apt install libczmq-dev                                        # Install libczmq-dev
```
