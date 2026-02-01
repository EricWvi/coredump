cmake_minimum_required(VERSION 3.20)
project(crash_demo)

# Enable C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Build with debug symbols and no optimization for better debugging
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_BUILD_TYPE Debug)

# Build the shared library
add_library(crash SHARED
    libcrash.cpp
    libcrash.h
)

# Build the main executable
add_executable(crash_demo
    main.cpp
)

# Link the executable with the shared library
target_link_libraries(crash_demo PRIVATE crash)

# Install targets (optional, for demonstration)
install(TARGETS crash_demo crash
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
)
