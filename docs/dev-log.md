# Development Log

## 2026-02-01: Core Dump Teaching Demo Implementation

### Summary
Implemented a complete core dump debugging tutorial project in `demo/crash/` with multiple crash scenarios, shared library integration, and comprehensive documentation.

### Changes

#### Demo Project (`demo/crash/`)

**Library Implementation (`libcrash.cpp`, `libcrash.h`)**
- Created a shared library with three distinct crash scenarios:
  1. **NULL Pointer Dereference**: Multi-level call chain (`processUserData() → formatUsername() → strcpy()`) demonstrating NULL pointer crashes
  2. **Array Out of Bounds**: Function chain (`calculateScore() → processScores() → calculateBonus()`) accessing invalid array indices
  3. **Buffer Overflow**: Stack corruption via `strcpy()` in `validateConfig()` triggering stack smashing detection

- Each scenario uses 2-3 function call levels to demonstrate realistic call stack analysis without overwhelming complexity
- Functions are well-commented with `// CRASH:` markers indicating crash points

**Main Program (`main.cpp`)**
- Interactive menu-driven interface for selecting crash scenarios
- Command-line argument support for direct crash triggering (e.g., `./crash_demo 1`)
- Clear user feedback and scenario descriptions

**Build Configuration (`CMakeLists.txt`)**
- Configured to build shared library (`libcrash.so`) and executable (`crash_demo`)
- Enabled debug symbols (`-g`) and disabled optimizations (`-O0`) for optimal debugging
- Proper linking between executable and shared library

#### Documentation (`demo/crash/README.md`)

Comprehensive tutorial covering:

1. **Core Dump Fundamentals**: What core dumps are and why they're useful
2. **System Configuration**: How to enable core dumps (`ulimit -c unlimited`, `kernel.core_pattern`)
3. **Build Instructions**: Step-by-step CMake build process
4. **Usage Guide**: Both interactive and command-line modes
5. **GDB Analysis Workflow**: 
   - Loading core dumps in GDB
   - Essential commands (`bt`, `bt full`, `frame`, `print`, `info locals`, etc.)
   - Navigation techniques (`up`, `down`, `frame N`)
6. **Scenario Walkthroughs**: Detailed analysis guides for each crash type with expected call stacks
7. **Learning Objectives**: Clear goals for students (8 specific skills)
8. **Troubleshooting**: Common issues and solutions (core dump location, apport handling, debug symbols)
9. **Next Steps**: Advanced topics for further learning

### Design Decisions

- **Simplicity First**: All source files are concise (< 100 lines each) for quick comprehension
- **Realistic Complexity**: Used function call chains (2-3 levels) to demonstrate real-world debugging scenarios
- **Multiple Crash Types**: Covered the most common crash categories students will encounter
- **Shared Library Architecture**: Demonstrates debugging across library boundaries, a common real-world scenario
- **Educational Focus**: Extensive inline comments and clear variable names for self-guided learning
- **Progressive Learning**: README structured from basic concepts to advanced techniques

### Testing

✅ **Build Verification**: Successfully compiled with CMake
✅ **Crash Scenario 1** (NULL pointer): Generates core dump, GDB shows correct call stack and NULL value
✅ **Crash Scenario 3** (Buffer overflow): Triggers stack smashing detection, generates analyzable core dump
✅ **Core Dump Analysis**: Verified GDB can load core dumps and display full backtraces with source locations

### Status
✅ TODO "coredump teaching example" - **COMPLETED**

---

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
