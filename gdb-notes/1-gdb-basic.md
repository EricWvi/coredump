# GDB Basic Usage Tutorial

Welcome to the GDB (GNU Debugger) basic usage tutorial! This guide will teach you the fundamental debugging skills using a simple C++ program.

## Table of Contents
1. [Prerequisites](#prerequisites)
2. [Building the Demo](#building-the-demo)
3. [Starting GDB](#starting-gdb)
4. [Basic GDB Commands](#basic-gdb-commands)
5. [Practical Exercises](#practical-exercises)
6. [Common GDB Commands Reference](#common-gdb-commands-reference)

---

## Prerequisites

- GDB installed on your system
- CMake 3.20 or higher installed
- C++ compiler (GCC or Clang)
- Basic understanding of C++ programming

## Building the Demo

Navigate to the demo directory and build the program with debug symbols:

```bash
cd demo/basic
mkdir build && cd build
cmake ..
make
```

The compiled binary will be located at `build/gdb_demo`.

---

## Starting GDB

There are several ways to start debugging with GDB:

### Method 1: Start GDB with the program
```bash
gdb ./gdb_demo
```

### Method 2: Start GDB and load the program later
```bash
gdb
(gdb) file ./gdb_demo
```

You should see output similar to:
```
Reading symbols from ./gdb_demo...
```

---

## Basic GDB Commands

### 1. **Setting Breakpoints**

A breakpoint pauses program execution at a specific location.

```gdb
(gdb) break main
```
This sets a breakpoint at the `main` function.

```gdb
(gdb) break main.cpp:45
```
This sets a breakpoint at line 45 of main.cpp.

```gdb
(gdb) break calculateSum
```
This sets a breakpoint at the `calculateSum` function.

### 2. **Running the Program**

```gdb
(gdb) run
```
Starts the program execution. It will stop at the first breakpoint.

### 3. **Stepping Through Code**

Once stopped at a breakpoint, you can step through the code:

- **`step` (or `s`)**: Execute the next line, stepping INTO functions
- **`next` (or `n`)**: Execute the next line, stepping OVER functions
- **`finish`**: Continue until the current function returns
- **`continue` (or `c`)**: Continue execution until the next breakpoint

### 4. **Examining Variables**

```gdb
(gdb) print sum
```
Prints the value of variable `sum`.

```gdb
(gdb) print numbers
```
Prints the entire vector (shows its internal structure).

```gdb
(gdb) print numbers[0]
```
Prints the first element of the vector.

```gdb
(gdb) print numbers.size()
```
Prints the size of the vector.

### 5. **Listing Source Code**

```gdb
(gdb) list
```
Shows the source code around the current line.

```gdb
(gdb) list calculateSum
```
Shows the source code of the `calculateSum` function.

### 6. **Viewing the Call Stack**

```gdb
(gdb) backtrace
```
or
```gdb
(gdb) bt
```
Shows the current call stack (which functions called which).

```gdb
(gdb) frame 0
```
Switch to stack frame 0 (the current function).

```gdb
(gdb) info locals
```
Shows all local variables in the current function.

### 7. **Managing Breakpoints**

```gdb
(gdb) info breakpoints
```
Lists all breakpoints.

```gdb
(gdb) delete 1
```
Deletes breakpoint number 1.

```gdb
(gdb) disable 2
```
Temporarily disables breakpoint number 2.

```gdb
(gdb) enable 2
```
Re-enables breakpoint number 2.

---

## Practical Exercises

Let's walk through debugging our demo program step by step.

### Exercise 1: Basic Debugging Flow

**Objective**: Understand how the program flows through functions.

1. Start GDB:
   ```bash
   gdb ./gdb_demo
   ```

2. Set a breakpoint at main:
   ```gdb
   (gdb) break main
   ```

3. Run the program:
   ```gdb
   (gdb) run
   ```
   
   The program will stop at the beginning of `main`.

4. List the source code:
   ```gdb
   (gdb) list
   ```

5. Step to the next line:
   ```gdb
   (gdb) next
   ```

6. Continue stepping with `next` until you reach the line with the `numbers` vector initialization.

7. Print the numbers vector:
   ```gdb
   (gdb) print numbers
   ```

8. Step over the print loop and stop at `printStatistics`:
   ```gdb
   (gdb) next
   (gdb) next
   ...
   ```

9. Now use `step` to enter the `printStatistics` function:
   ```gdb
   (gdb) step
   ```

10. View the backtrace to see the call stack:
    ```gdb
    (gdb) backtrace
    ```
    You should see `printStatistics` called from `main`.

### Exercise 2: Examining Function Behavior

**Objective**: Watch how `calculateSum` processes the vector.

1. Start fresh (you can restart with `run` or quit and restart GDB):
   ```gdb
   (gdb) quit
   ```
   ```bash
   gdb ./gdb_demo
   ```

2. Set a breakpoint in `calculateSum`:
   ```gdb
   (gdb) break calculateSum
   ```

3. Run the program:
   ```gdb
   (gdb) run
   ```
   
   The program will stop when `calculateSum` is first called.

4. Check the function parameters:
   ```gdb
   (gdb) print numbers
   ```

5. Check local variables:
   ```gdb
   (gdb) info locals
   ```
   You should see `sum` initialized to 0.

6. Step through the loop a few times:
   ```gdb
   (gdb) next
   (gdb) next
   (gdb) print sum
   (gdb) print num
   (gdb) next
   (gdb) print sum
   ```
   
   Watch how `sum` accumulates values.

7. Finish the function execution:
   ```gdb
   (gdb) finish
   ```
   
   This will show you the return value.

### Exercise 3: Conditional Breakpoints

**Objective**: Stop execution only when certain conditions are met.

1. Set a conditional breakpoint in the loop:
   ```gdb
   (gdb) break main.cpp:28 if num > 30
   ```
   
   This will only break when `num` is greater than 30.

2. Run the program:
   ```gdb
   (gdb) run
   ```

3. When it stops, check the value:
   ```gdb
   (gdb) print num
   ```
   
   It should be 42 (the first value > 30 in our vector).

### Exercise 4: Watching Variables

**Objective**: Use watchpoints to pause when a variable changes.

1. Start at main:
   ```gdb
   (gdb) break main
   (gdb) run
   ```

2. Continue until the vector is initialized, then set a watchpoint:
   ```gdb
   (gdb) next
   ... (until numbers is initialized)
   (gdb) watch -l numbers.size()
   ```

   Note: Watching complex objects can be tricky. For simpler cases:
   
3. Set a breakpoint in calculateSum:
   ```gdb
   (gdb) break calculateSum
   (gdb) continue
   ```

4. Set a watchpoint on the sum variable:
   ```gdb
   (gdb) next  # step past initialization
   (gdb) watch sum
   ```

5. Continue execution:
   ```gdb
   (gdb) continue
   ```
   
   GDB will stop each time `sum` is modified.

### Exercise 5: Examining Different Stack Frames

**Objective**: Navigate through the call stack.

1. Set a breakpoint in `findMax`:
   ```gdb
   (gdb) break findMax
   (gdb) run
   ```

2. The program will stop in `findMax`. View the call stack:
   ```gdb
   (gdb) backtrace
   ```
   
   You should see:
   ```
   #0  findMax (...)
   #1  printStatistics (...)
   #2  main ()
   ```

3. Examine variables in the current frame:
   ```gdb
   (gdb) info locals
   ```

4. Switch to the parent frame:
   ```gdb
   (gdb) frame 1
   ```

5. Examine variables in `printStatistics`:
   ```gdb
   (gdb) info locals
   (gdb) print numbers
   ```

6. Return to frame 0:
   ```gdb
   (gdb) frame 0
   ```

---

## Common GDB Commands Reference

### Navigation & Execution
| Command | Shortcut | Description |
|---------|----------|-------------|
| `run [args]` | `r` | Start program execution |
| `continue` | `c` | Continue execution |
| `next` | `n` | Step over (next line) |
| `step` | `s` | Step into (follow function calls) |
| `finish` | `fin` | Execute until current function returns |
| `until [location]` | `u` | Continue until location |
| `quit` | `q` | Exit GDB |

### Breakpoints
| Command | Shortcut | Description |
|---------|----------|-------------|
| `break [location]` | `b` | Set breakpoint |
| `break [location] if [condition]` | | Set conditional breakpoint |
| `tbreak [location]` | `tb` | Set temporary breakpoint |
| `watch [expression]` | | Set watchpoint (break when value changes) |
| `info breakpoints` | `i b` | List all breakpoints |
| `delete [number]` | `d` | Delete breakpoint |
| `disable [number]` | `dis` | Disable breakpoint |
| `enable [number]` | `en` | Enable breakpoint |
| `clear [location]` | | Delete breakpoint at location |

### Examining Code & Data
| Command | Shortcut | Description |
|---------|----------|-------------|
| `list [location]` | `l` | Show source code |
| `print [expression]` | `p` | Print value of expression |
| `display [expression]` | | Auto-print expression after each step |
| `info locals` | `i lo` | Show local variables |
| `info args` | `i ar` | Show function arguments |
| `backtrace` | `bt` | Show call stack |
| `frame [number]` | `f` | Select stack frame |
| `info frame` | `i f` | Show current frame info |
| `whatis [variable]` | | Show variable type |
| `ptype [type]` | | Show type definition |

### Other Useful Commands
| Command | Shortcut | Description |
|---------|----------|-------------|
| `help [command]` | `h` | Get help |
| `set variable [var]=[value]` | | Change variable value |
| `call [function]` | | Call a function |
| `info functions` | `i fun` | List all functions |
| `info variables` | `i var` | List all global variables |

---

## Tips and Best Practices

1. **Always compile with debug symbols**: Use `-g` flag and `-O0` (no optimization) for best debugging experience.

2. **Use Tab completion**: GDB supports tab completion for commands, function names, and file names.

3. **Command history**: Use up/down arrows to navigate through command history.

4. **Repeat last command**: Press Enter to repeat the last command (especially useful for `next` and `step`).

5. **TUI mode**: Use `Ctrl+X A` to toggle Text User Interface mode for a better view of source code.

6. **Save breakpoints**: Save your breakpoints to a file for reuse:
   ```gdb
   (gdb) save breakpoints my_breakpoints.txt
   (gdb) source my_breakpoints.txt
   ```

7. **Use `.gdbinit`**: Create a `.gdbinit` file in your project directory to automatically set breakpoints and settings.

---

## Conclusion

You've now learned the basic GDB commands! Practice these exercises multiple times to build muscle memory. The key to effective debugging is:

1. **Understand the flow**: Use breakpoints and stepping to follow program execution
2. **Inspect state**: Regularly check variable values and the call stack
3. **Test hypotheses**: Use conditional breakpoints and watchpoints to verify your assumptions

Keep practicing, and debugging will become second nature!

---

## Next Steps

- Explore GDB's advanced features like reverse debugging
- Learn about debugging multi-threaded programs
- Practice debugging programs with segmentation faults and crashes
- Check out the coredump tutorial for post-mortem debugging
