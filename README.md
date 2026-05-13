# custom_websocket_client

## 소개
`custom_websocket_client`는 [IXWebSocket](https://github.com/machinezone/IXWebSocket) 라이브러리를 기반으로 제작된 C++ 웹소켓 클라이언트 예제입니다. 간단한 코드로 웹소켓 서버와의 연결, 메시지 송수신, 쓰레드 안전 송신 등을 구현할 수 있습니다.

## 주요 기능
- 웹소켓 서버 연결 및 해제
- 텍스트/바이너리 메시지 송수신
- 쓰레드 안전한 메시지 전송
- 연결 상태 및 오류 출력

## 빌드 방법
1. **IXWebSocket 라이브러리 설치**
	- vcpkg, 소스 빌드 등으로 [IXWebSocket](https://github.com/machinezone/IXWebSocket)을 설치하세요.
2. **CMake 빌드**
	```bash
	mkdir build
	cd build
	cmake ..
	cmake --build .
	```

## 실행 방법
빌드 후 생성된 실행 파일(`ws_client`)을 사용합니다.

```bash
./ws_client
```

프로그램 실행 후 메시지를 입력하면 서버로 전송되며, 서버로부터 수신된 메시지는 콘솔에 출력됩니다. 종료하려면 `exit`을 입력하세요.

## 의존성
- [IXWebSocket](https://github.com/machinezone/IXWebSocket)
- C++17 이상
- CMake 3.10 이상
- (Linux) OpenSSL, pthread 등

## 라이선스
MIT License (LICENSE 파일 참고)