# coredump

A comprehensive tutorial project for learning GDB debugging and coredump analysis.

## Requirements

- **CMake**: Version 3.20 or higher
  - Check version: `cmake --version`
  - Install from: https://cmake.org/download/
- **GDB**: GNU Debugger
  - Check version: `gdb --version`
  - Install: `apt-get install gdb` (Ubuntu/Debian) or `yum install gdb` (RHEL/CentOS)
- **C++ Compiler**: GCC or Clang with C++11 support
- **vcpkg** (optional): For dependency management
  - Install from: https://vcpkg.io/en/getting-started.html

## Project Structure

- `demo/basic/` - Basic GDB usage demonstration
- `demo/crash/` - Coredump analysis demonstration (coming soon)
- `gdb-notes/` - Step-by-step tutorials and teaching materials
- `docs/` - Development documentation

## Getting Started

### Basic GDB Tutorial

1. Build the demo:
   ```bash
   cd demo/basic
   mkdir build && cd build
   cmake ..
   make
   ```

2. Follow the tutorial:
   - Read [gdb-notes/1-gdb-basic.md](gdb-notes/1-gdb-basic.md) for comprehensive step-by-step instructions

3. Start debugging:
   ```bash
   gdb ./gdb_demo
   ```

## License

MIT
