#include <iostream>
#include <boost/asio.hpp>
#include <chrono>
#include <thread>

using boost::asio::ip::udp;

#pragma pack(push, 1)
enum class PacketType : uint8_t { MOVE = 0x01, PING = 0xFF };
struct MovePacket {
    PacketType type;
    uint32_t   playerId;
    float      x, y;
};
#pragma pack(pop)

int main() {
    try {
        boost::asio::io_context ctx;
        udp::socket sock(ctx, udp::endpoint(udp::v4(), 0));
        // docker-compose에 지정된 서버 IP와 포트
        udp::endpoint server_ep(boost::asio::ip::make_address("172.20.0.10"), 9000);

        MovePacket pkt{ PacketType::MOVE, 999, 10.0f, 20.0f };
        std::cout << "[Client] Sending move packets to server...\n";

        while (true) {
            sock.send_to(boost::asio::buffer(&pkt, sizeof(pkt)), server_ep);
            std::this_thread::sleep_for(std::chrono::milliseconds(16)); // 약 60 FPS
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}