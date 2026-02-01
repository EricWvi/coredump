## TODO: coredump teaching example

~~Set up a c++ project in `demo/crash/`. One binary load a `.so` library. Some funcs in the library will crash, and produce coredump. Use a hand of function calls, so that it is not too simple, but avoid complex logic, I want students to understand the project in five minutes. Then teach the students use `gdb` to load coredump and find why the crash happened.~~

✅ **COMPLETED** - See `demo/crash/` for the implementation. The project includes:
- Shared library (`libcrash.so`) with 3 crash scenarios
- Main executable (`crash_demo`) that triggers crashes
- Comprehensive README with GDB tutorial
- Multiple function call levels for realistic debugging practice
- Tested and verified to generate core dumps successfully


