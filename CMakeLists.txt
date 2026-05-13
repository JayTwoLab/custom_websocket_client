cmake_minimum_required(VERSION 3.10)
project(ix_websocket_example)

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# IXWebSocket 패키지 찾기
# 시스템에 설치되어 있거나 vcpkg 등을 통해 경로가 잡혀있어야 합니다.
# https://github.com/machinezone/IXWebSocket 의 사전 설치 필요함. 
find_package(ixwebsocket REQUIRED)

# 실행 파일 생성
add_executable(ws_client 
    main.cpp 
    custom_websocket_client.cpp
)

# 헤더 경로 및 라이브러리 링크
target_include_directories(ws_client PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ws_client PRIVATE ixwebsocket::ixwebsocket) # IXWebSocket 라이브러리 링크. 

# 시스템 라이브러리 링크 (Linux의 경우 Threads, SSL 등 필요)
find_package(Threads REQUIRED)
target_link_libraries(ws_client PRIVATE Threads::Threads)

if(UNIX AND NOT APPLE)
    target_link_libraries(ws_client PRIVATE ssl crypto)
endif()
