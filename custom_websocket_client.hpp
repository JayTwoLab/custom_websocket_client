#pragma once

#include <ixwebsocket/IXWebSocket.h>
#include <string>

class custom_websocket_client {
public:
    custom_websocket_client();
    void set_url(const std::string& url);
    ~custom_websocket_client();

    // Service control
    void start();
    void stop();

    // Thread-safe sending from external threads
    void send_message(const std::string& text);

    // Check connection status
    bool isReady() const;

private:
    void setup_callback();

    std::string _url;
    ix::WebSocket _web_socket;
};

