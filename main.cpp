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
    user_input = "hello world"; // 테스트용 초기 메시지

    while (true) {
        // if (!std::getline(std::cin, user_input)) break;
        // if (user_input == "exit") break;

        if (!user_input.empty()) {
            if (client.isReady()) {
                std::cout << "[송신] " << user_input << std::endl;
                client.send_message(user_input);
                // 쓰레드 세이프하게 메시지 송신. 외부 쓰레드에서 호출해도 됨.
            } else {
                std::cerr << "[경고] Connection is not open. Message will be sent when connection is established." << std::endl;
            } 
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // CPU 과부하 방지 위해 잠시 대기
    }

    client.stop(); // 웹소켓 클라이언트 종료
    return 0;
}