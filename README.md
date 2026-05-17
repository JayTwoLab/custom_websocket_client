# custom_websocket_client

> [Korean](README.ko.md)

## Introduction
`custom_websocket_client` is a C++ WebSocket client example based on the [IXWebSocket](https://github.com/machinezone/IXWebSocket) library. This project demonstrates how to implement connections with a WebSocket server, send and receive messages, and ensure thread-safe transmissions with simple code.

## Key Features
- Connect and disconnect from WebSocket servers
- Send and receive text/binary messages
- Thread-safe message transmission
- Connection status and error reporting

## Build Instructions
1. **Install IXWebSocket Library**
	- Install [IXWebSocket](https://github.com/machinezone/IXWebSocket) using vcpkg, source build, or other methods.
2. **CMake Build**
	```bash
	mkdir build
	cd build
	cmake ..
	cmake --build .
	```

## Usage
Run the generated executable (`ws_client`) after building.

```bash
./ws_client
```

After starting the program, enter a message to send it to the server. Messages received from the server will be displayed in the console. Type `exit` to terminate the program.

## Dependencies
- [IXWebSocket](https://github.com/machinezone/IXWebSocket)
- C++17 or later
- CMake 3.10 or later
- (Linux) OpenSSL, pthread, etc.

## License
MIT License (see LICENSE file)