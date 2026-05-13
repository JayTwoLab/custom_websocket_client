#include "custom_websocket_client.hpp"
#include <iostream>
#include <string>

int main() {
    custom_websocket_client client;

    std::string server_url = "ws://localhost:8080"; // wss:// (WebSocket Secure) 프로토콜도 지원됨. 
    client.set_url(server_url); 

    client.start(); // 웹소켓 클라이언트 시작

    std::cout << "--- Enter message to send (type 'exit' to quit) ---" << std::endl;

    std::string user_input;
    while (true) {
        if (!std::getline(std::cin, user_input)) break;
        if (user_input == "exit") break;

        if (!user_input.empty()) {
            // 쓰레드 세이프하게 메시지 송신. 외부 쓰레드에서 호출해도 됨.
            client.send_message(user_input);
        }
    }

    client.stop(); // 웹소켓 클라이언트 종료
    return 0;
}