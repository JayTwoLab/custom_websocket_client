#pragma once

#include <ixwebsocket/IXWebSocket.h>
#include <string>

class custom_websocket_client {
public:
    custom_websocket_client();
    void set_url(const std::string& url);
    ~custom_websocket_client();

    // 서비스 제어
    void start();
    void stop();

    // 외부 쓰레드 안전 송신
    void send_message(const std::string& text);

private:
    void setup_callback();

    std::string _url;
    ix::WebSocket _web_socket;
};

