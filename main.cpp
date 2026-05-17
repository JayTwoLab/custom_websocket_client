#include "custom_websocket_client.hpp"
#include <iostream>
#include <string>

int main() {
    custom_websocket_client client;

    std::string server_url = "ws://localhost:8080"; // wss:// (WebSocket Secure) protocol is also supported.
    client.set_url(server_url); 

    client.start(); // Start the WebSocket client

    std::cout << "--- Enter message to send (type 'exit' to quit) ---" << std::endl;

    std::string user_input;
    user_input = "hello world"; // Initial test message

    while (true) {
        // if (!std::getline(std::cin, user_input)) break;
        // if (user_input == "exit") break;

        if (!user_input.empty()) {
            if (client.isReady()) {
                std::cout << "[SEND] " << user_input << std::endl;
                client.send_message(user_input);
                // Send messages in a thread-safe manner. Can be called from external threads.
            } else {
                std::cerr << "[Warning] Connection is not open. Message will be sent when connection is established." << std::endl;
            } 
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Brief wait to prevent CPU overuse
    }

    client.stop(); // Stop the WebSocket client
    return 0;
}