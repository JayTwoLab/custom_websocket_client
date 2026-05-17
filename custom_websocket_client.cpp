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
                    std::cout << "\n[RECEIVED] Binary message size: " << msg->str.size() << " bytes" << std::endl;
                } else {
                    std::cout << "\n[RECEIVED] Text message: " << msg->str << std::endl;
                }
                break;

            case ix::WebSocketMessageType::Open:
                std::cout << "[STATUS] Connection opened" << std::endl;
                break;

            case ix::WebSocketMessageType::Close:
                std::cout << "[STATUS] Connection closed. Code: " << msg->closeInfo.code 
                          << ", Reason: " << msg->closeInfo.reason << std::endl;
                break;

            case ix::WebSocketMessageType::Error:
                std::cerr << "[ERROR] Error: " << msg->errorInfo.reason << std::endl;
                break;

            case ix::WebSocketMessageType::Ping:
                // Ping received from server (automatically responded)
                break;

            case ix::WebSocketMessageType::Pong:
                // Received server's response to client's Ping (Pong)
                break;

            case ix::WebSocketMessageType::Fragment:
                // Handle reception of fragmented messages
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
        std::cout << "[SENT] " << text << std::endl;
    } else {
        std::cerr << "[WARNING] Cannot send. Connection is not open." << std::endl;
    }
}

bool custom_websocket_client::isReady() const {
    return _web_socket.getReadyState() == ix::ReadyState::Open;
}   
