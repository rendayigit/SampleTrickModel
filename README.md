# SampleTrickModel

This is a sample simulation model created to run on [NASA's Trick simulator](https://github.com/nasa/trick). This repository also contains unit tests and coverage infrastructure.

## Usage

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
