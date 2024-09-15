#include "AODVPacket.h"

namespace AODV {
std::vector<uint8_t> serializeRREQ(const RREQPacket& packet) {
    std::vector<uint8_t> buffer;
    buffer.push_back(packet.type);
    buffer.push_back(packet.hopCount);
    // Thêm các trường khác vào buffer dưới dạng bytes...
    return buffer;
}

RREQPacket deserializeRREQ(const std::vector<uint8_t>& buffer) {
    RREQPacket packet;
    packet.type = buffer[0];
    packet.hopCount = buffer[1];
    // Đọc các trường khác từ buffer...
    return packet;
}



} 
