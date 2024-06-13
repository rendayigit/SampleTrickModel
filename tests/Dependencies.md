# Install Google Test
``` bash
cd /tmp/
git clone https://github.com/google/googletest.git -b v1.14.0
cd googletest        # Main directory of the cloned repository.
mkdir build          # Create a directory to hold the build output.
cd build
cmake ..             # Generate native build scripts for GoogleTest.
make                 # Compile gtest
sudo make install    # Install in /usr/local/ by default
rm -rf /tmp/googletest/
```

# Install Gcovr
``` bash
sudo apt install python3-pip
pip install gcovr
```

# Install Debugger
``` bash
sudo apt install gdb
```