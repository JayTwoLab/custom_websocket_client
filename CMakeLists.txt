cmake_minimum_required(VERSION 3.10)
project(ix_websocket_example)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find IXWebSocket package
# Must be installed on the system or have its path provided via vcpkg, etc.
# Pre-installation of https://github.com/machinezone/IXWebSocket is required.
find_package(ixwebsocket REQUIRED)

# Create executable
add_executable(ws_client 
    main.cpp 
    custom_websocket_client.cpp
)

# Header paths and library linking
target_include_directories(ws_client PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ws_client PRIVATE ixwebsocket::ixwebsocket) # Link IXWebSocket library. 

# Link system libraries (Threads, SSL, etc. may be required on Linux)
find_package(Threads REQUIRED)
target_link_libraries(ws_client PRIVATE Threads::Threads)

if(UNIX AND NOT APPLE)
    target_link_libraries(ws_client PRIVATE ssl crypto)
endif()
