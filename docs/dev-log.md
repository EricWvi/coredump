# Development Log

## 2026-02-01: Migration from Bazel to CMake

### Summary
Migrated the build system from Bazel to CMake with vcpkg support for better portability and wider tooling compatibility.

### Changes

#### Build System Migration
- **Removed**: All Bazel files (BUILD, MODULE.bazel, MODULE.bazel.lock, bazel-* directories)
- **Added**: CMakeLists.txt with debug symbols (-g) and no optimization (-O0) for optimal debugging
- **Updated**: .gitignore to exclude CMake build artifacts instead of Bazel outputs

#### Documentation Updates
- **README.md**: Updated requirements to specify CMake 3.20+, added vcpkg as optional dependency, updated build instructions
- **gdb-notes/1-gdb-basic.md**: Updated all build commands from `bazel build :gdb_demo` to CMake workflow (`mkdir build && cd build && cmake .. && make`)
- **Tutorial exercises**: Updated all binary paths from `bazel-bin/gdb_demo` to `./gdb_demo`

### Rationale
- CMake is more widely adopted and familiar to most C++ developers
- Better integration with vcpkg for future dependency management
- Simpler build configuration for educational purposes
- Cross-platform compatibility

---

## 2026-02-01: GDB Basic Usage Example Implementation

### Summary
Implemented the complete GDB basic usage example project, including a C++ demo and comprehensive teaching materials.

### Changes

#### Demo Project (`demo/basic/`)
- **main.cpp**: Created a simple statistics calculator program with multiple functions:
  - `calculateSum()`: Computes sum of vector elements
  - `calculateAverage()`: Calculates average value
  - `findMax()`: Finds maximum value in vector
  - `printStatistics()`: Displays all statistics
  - `main()`: Entry point with sample data
  
  The program uses a vector of integers {10, 25, 7, 42, 15, 33, 8} and demonstrates function calls, loops, and variable manipulation - perfect for learning GDB basics.

- **CMakeLists.txt**: Configured CMake build with `-g` (debug symbols) and `-O0` (no optimization) flags for optimal debugging experience.

#### Teaching Materials (`gdb-notes/1-gdb-basic.md`)
Comprehensive tutorial covering:

1. **Prerequisites & Setup**: Building the demo with CMake
2. **Basic Commands**: Breakpoints, stepping, examining variables, call stack navigation
3. **5 Practical Exercises**:
   - Exercise 1: Basic debugging flow with `next` and `step`
   - Exercise 2: Examining function behavior and watching accumulation
   - Exercise 3: Using conditional breakpoints
   - Exercise 4: Working with watchpoints
   - Exercise 5: Navigating stack frames
4. **Command Reference**: Comprehensive table of common GDB commands with shortcuts
5. **Tips & Best Practices**: TUI mode, command history, .gdbinit configuration

### Design Decisions
- Kept the program simple (< 70 lines) so students can understand it in ~5 minutes
- Used familiar concepts (statistics on numbers) to minimize cognitive load
- Included a "handful" of functions (4 utility functions + main) to demonstrate call stack without overwhelming complexity
- Structured tutorial progressively from basic to intermediate concepts
- Included both command reference and hands-on exercises for different learning styles

### Status
✅ TODO "gdb basic usage example" - **COMPLETED**
