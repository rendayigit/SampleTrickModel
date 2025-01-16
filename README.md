# SampleTrickModel

[![Ubuntu CI](https://github.com/rendayigit/SampleTrickModel/actions/workflows/Unit%20Tests.yml/badge.svg)](https://github.com/rendayigit/SampleTrickModel/actions/workflows/Unit%20Tests.yml)

This is a sample simulation model created to run on [NASA's Trick simulator](https://github.com/nasa/trick). This repository also contains unit tests and code coverage infrastructure.

## Usage

### Install Nasa Trick

1. Follow [this guide](https://nasa.github.io/trick/documentation/install_guide/Install-Guide) to install Nasa Trick.
1. Make sure to install trick under `${HOME}`
1. Make sure to add `${HOME}/trick/bin` to the `PATH` environment variable.
1. Make sure to create a permanent envirtonment variable with the value of `${HOME}/trick` named `TRICK_HOME`.

### Install Other Dependencies

```bash
cd ~
sudo apt install python3            # Install python.
sudo apt install python3-pip        # Install python package manager.
sudo apt install build-essential    # Install GNU compilers.
pip install gcovr                   # Install gcovr code coverage tool.
sudo apt install gdb                # Install GNU GDB debugger.
sudo apt install libgtest-dev       # Install gtest unit testing framework.
sudo apt install clangd             # Install clangd language server.
sudo apt install clang-format       # Install clang-format.
```

### Use the scripts under `scripts/`

- `build.sh`: Build the unit tests.
- `clean.sh`: Clean the unit tests.
- `coverage.sh`: Generate unit test code coverage.
- `run.sh`: Run the unit tests without code coverage.

## Services

| Service | Description |
|----------|----------|
| [Data Flow](models/common/dataFlow.hpp) | A variable type that allows the flow of data between models. |
| [Model Event](models/common/modelEvent.hpp) | A service that allows the creation of events that can be triggered by the simulator. |

## Models

| Model | Description |
|----------|----------|
| [Root](models/root/root.hpp) | The Root of all models. This model is a container of all other models. |
| [ModelWithEvents](models/modelWithEvents/modelWithEvents.hpp) | A sample trick model to demonstrate events. |
| [ModelX](models/modelX/modelX.hpp) and [ModelY](models/modelY/modelY.hpp) | Sample trick models created to demonstrate inter model communication between ModelX and ModelY. |
| [ModelDummy](models/modelDummy/modelDummy.hpp) | A sample trick model that only showcases minimal sim features. |
| [Math](models/math/math.hpp) | A model that doesn't really do much. It is only created to showcase unit test coverage analysis. |
