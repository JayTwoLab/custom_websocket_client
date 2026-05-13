#include "custom_websocket_client.hpp"
#include <ixwebsocket/IXNetSystem.h>
#include <iostream>

custom_websocket_client::custom_websocket_client() {
    ix::initNetSystem();
    setup_callback();
}
void custom_websocket_client::set_url(const std::string& url) {
    _url = url;
    _web_socket.setUrl(_url);
}

custom_websocket_client::~custom_websocket_client() {
    stop();
    ix::uninitNetSystem();
}

void custom_websocket_client::setup_callback() {
    _web_socket.setOnMessageCallback([this](const ix::WebSocketMessagePtr& msg) {
        switch (msg->type) {
            case ix::WebSocketMessageType::Message:
                if (msg->binary) {
                    std::cout << "\n[수신] Binary message size: " << msg->str.size() << " bytes" << std::endl;
                } else {
                    std::cout << "\n[수신] Text message: " << msg->str << std::endl;
                }
                break;

            case ix::WebSocketMessageType::Open:
                std::cout << "[상태] Connection opened" << std::endl;
                break;

            case ix::WebSocketMessageType::Close:
                std::cout << "[상태] Connection closed. Code: " << msg->closeInfo.code 
                          << ", Reason: " << msg->closeInfo.reason << std::endl;
                break;

            case ix::WebSocketMessageType::Error:
                std::cerr << "[오류] Error: " << msg->errorInfo.reason << std::endl;
                break;

            case ix::WebSocketMessageType::Ping:
                // 서버로부터 수신된 Ping (자동 응답됨)
                break;

            case ix::WebSocketMessageType::Pong:
                // 클라이언트 Ping에 대한 서버의 응답 수신
                break;

            case ix::WebSocketMessageType::Fragment:
                // 파편화된 메시지 수신 시 처리
                break;
        }
    });
}

void custom_websocket_client::start() {
    _web_socket.start();
}

void custom_websocket_client::stop() {
    _web_socket.stop();
}

void custom_websocket_client::send_message(const std::string& text) {
    if (_web_socket.getReadyState() == ix::ReadyState::Open) {
        _web_socket.send(text);
        std::cout << "[송신] " << text << std::endl;
    } else {
        std::cerr << "[경고] Cannot send. Connection is not open." << std::endl;
    }
}

bool custom_websocket_client::isReady() const {
    return _web_socket.getReadyState() == ix::ReadyState::Open;
}   
