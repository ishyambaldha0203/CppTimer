# CppTimer
C++ Timer: A versatile timer class with callback function support.

## High-Level Design
- The SOLID principles are strictly followed, with DRY, KISS, and YAGNI as supporting principles.
- Each class has an interface that defines its responsibilities.
- Class declarations are in separate .hpp files, while class definitions are in .cpp files.
- All components are unit testable.
- An abstract factory is used to create class instances.
- **CMake is used as the build system.**
- **C++17 is used for development.** 

## Brief of Project Components
- **Timer Class:** The Timer class is a versatile and easy-to-use utility for scheduling tasks to run after a delay or at regular intervals. It provides a simple interface for loading a configuration, starting the timer, and stopping it.
- **Program class:** Is being used to demo all the timer functionalities.

## Directory Structure
```
CppTimer/
├── Build
│   ├── CmakeModules
│   └── DefaultCmakeSettings.cmake
├── CMakeLists.txt
├── CppTimer.Tests
│   ├── CMakeLists.txt
│   └── Src
├── Include
│   ├── CommonConfig.hpp
│   ├── Exceptions
│   ├── Interfaces
│   └── Internal
├── LICENSE
├── README.md
└── Src
    ├── CMakeLists.txt
    ├── Internal
    └── main.cpp

```

## Building the Application
**NOTE: These instructions assume that you are using the command prompt to build the application.**

1. Using cmake version `3.19.0` to build the application.
2. Using C++ version `C++17`. It is configurable from the `DefaultCmakeSettings.cmake` file.
3. Open the command prompt and navigate to the `CppTimer` directory ($cd CppTimer).
4. Create a new directory named `build` by entering `mkdir build`, then navigate to the `build` directory ($cd build).
5. Run the `cmake` command by entering ($cmake ..).
6. Compile the application by entering the `make` command. To speed up compilation, you can use the `-j` option followed by the number of cores you want to use, for example, ($make -j4).
7. If compilation is successful, an executable file named `timer_demo_application` will be created in the `./bin/exec` directory. You can verify this by entering `ls bin/exe/timer_demo_application`.

## Running the Application
**NOTE:** The following instructions are based on the assumption that you are using the command prompt to execute the application.

1. Execute the application by typing `./timer_demo_application` in your command prompt.
2. To explore the functionalities of the timer, refer to the `Program.cpp` file. This file contains a sample code demonstrating how to use the timer class.

## Limitations

1. Currently, the timer is stateless and only supports two operations: Start and Stop.

## Future Enhancements

1. **Logging Module:** Plan to incorporate a logging module that will record events in a log file. This will facilitate easier debugging and analysis.
2. **Stateful Timer:** Aim to develop a stateful timer with extended functionalities such as Start, Pause, Resume, and Stop.

# Known Issue/Bug
Not any at the moment.
