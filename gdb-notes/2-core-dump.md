# Core Dump Demo

This demo teaches you how to analyze core dumps using GDB. The program intentionally crashes in different ways to help you practice debugging crashed programs.

## What is a Core Dump?

A core dump is a file containing the memory image of a process at the time it crashed. It's like a "snapshot" of the program's state when something went wrong, allowing you to debug the crash after it happened.

## Project Structure

- `main.cpp` - Main program that triggers different crash scenarios
- `libcrash.cpp` / `libcrash.h` - Shared library containing functions that crash
- `CMakeLists.txt` - Build configuration

## Building the Demo

```bash
# Create build directory
mkdir build
cd build

# Configure and build
cmake ..
make

# The executable will be at: ./crash_demo
# The shared library will be at: ./libcrash.so
```

## Enabling Core Dumps

Before running the demo, you need to enable core dumps on your system:

```bash
# Check current core dump limit
ulimit -c

# Enable unlimited core dumps
ulimit -c unlimited

# Configure core dump file pattern (optional)
# This makes core dumps easier to find
sudo sysctl -w kernel.core_pattern=core.%e.%p
```

## Running the Demo

### Option 1: Interactive Mode

```bash
./crash_demo
```

Select a crash scenario from the menu:
1. NULL pointer dereference
2. Array out of bounds
3. Buffer overflow / Stack corruption

### Option 2: Command Line

```bash
# Directly trigger a specific crash scenario
./crash_demo 1  # NULL pointer dereference
./crash_demo 2  # Array out of bounds
./crash_demo 3  # Buffer overflow
```

## Analyzing the Core Dump

After the program crashes, you'll have a core dump file (usually named `core` or `core.crash_demo.<pid>`).

### Load the Core Dump in GDB

```bash
gdb ./crash_demo core
```

Or specify the core file explicitly:

```bash
gdb ./crash_demo core.crash_demo.12345
```

### Essential GDB Commands for Core Dump Analysis

Once GDB loads the core dump:

```gdb
# See where the crash occurred
(gdb) bt
# or
(gdb) backtrace

# See the full backtrace with all frames
(gdb) bt full

# Switch to a specific frame to inspect variables
(gdb) frame 2

# Examine variables in the current frame
(gdb) info locals
(gdb) print variableName

# See the source code around the crash
(gdb) list

# Examine the arguments passed to the current function
(gdb) info args

# Inspect memory at an address
(gdb) x/16x 0x12345678

# See all threads (if multi-threaded)
(gdb) info threads

# Navigate through the call stack
(gdb) up      # Move up one frame
(gdb) down    # Move down one frame
```

## Expected Crash Scenarios

### Scenario 1: NULL Pointer Dereference

**Call Stack:**
```
main() → processUserData() → formatUsername() → strcpy()
```

**What to look for:**
- The `name` parameter is NULL in `formatUsername()`
- `strcpy()` attempts to dereference a NULL pointer
- Stack trace shows the function call chain

**GDB Investigation:**
```gdb
(gdb) bt
(gdb) frame 1          # Go to formatUsername
(gdb) print name       # Should be 0x0 (NULL)
```

### Scenario 2: Array Out of Bounds

**Call Stack:**
```
main() → calculateScore() → processScores() → calculateBonus()
```

**What to look for:**
- The `index` value is out of bounds (e.g., 10 for a 5-element array)
- Access to `scores[10]` causes undefined behavior
- May crash immediately or corrupt memory

**GDB Investigation:**
```gdb
(gdb) bt
(gdb) frame 1          # Go to calculateBonus
(gdb) print index      # Should be 10
(gdb) print scores     # Array only has 5 elements
```

### Scenario 3: Buffer Overflow / Stack Corruption

**Call Stack:**
```
main() → validateConfig() → strcpy()
```

**What to look for:**
- `strcpy()` writes beyond the buffer boundaries
- Stack corruption may cause unpredictable crashes
- Local variables and return addresses may be overwritten

**GDB Investigation:**
```gdb
(gdb) bt
(gdb) frame 1          # Go to validateConfig
(gdb) info locals      # See local variables
(gdb) x/32x $rsp       # Examine stack memory
```

## Learning Objectives

After completing this demo, you should be able to:

1. ✅ Enable core dumps on a Linux system
2. ✅ Generate a core dump from a crashing program
3. ✅ Load a core dump in GDB
4. ✅ Identify the exact line where the crash occurred
5. ✅ Examine the call stack (backtrace) to understand the function call chain
6. ✅ Inspect variables and memory at the time of the crash
7. ✅ Navigate between stack frames to gather context
8. ✅ Identify common crash causes (NULL pointers, buffer overflows, array bounds)

## Tips

- **Always build with debug symbols (`-g`)** - Without them, you won't see source code or variable names
- **Disable optimizations (`-O0`)** - Optimizations can make debugging confusing
- **Use `bt full`** - Shows more detail than just `bt`
- **Check the actual values** - Don't assume, verify with `print` and `x` commands
- **Understand the call chain** - The crash location is often a symptom; the bug may be earlier in the call chain

## Next Steps

After mastering core dump analysis, explore:
- Multi-threaded crashes (`info threads`, `thread apply all bt`)
- Memory corruption debugging with Valgrind
- Address Sanitizer (AddressSanitizer) for real-time crash detection
- Reverse debugging with `gdb --reverse`

## Common Issues

**Core dump not generated?**
```bash
# Check and set core dump limit
ulimit -c unlimited

# Check where core dumps go
cat /proc/sys/kernel/core_pattern

# If it shows |/usr/share/apport/apport..., core dumps are being handled by apport
# To disable apport temporarily:
sudo systemctl stop apport
```

**Can't find the core file?**
```bash
# Find recent core dumps
find . -name "core*" -type f -mmin -5

# Or search the entire system
sudo find / -name "core*" -type f -mmin -5 2>/dev/null
```

**GDB shows "no debugging symbols"?**
- Make sure you built with `-g` flag
- Make sure you're loading the same binary that crashed
- Check that the shared library also has debug symbols
