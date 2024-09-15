#pragma once

#include <cstdint>
#include <vector>

namespace AODV {


enum PacketType {
    RREQ = 1,  // Route Request
    RREP = 2,  // Route Reply
    RERR = 3,  // Route Error
    HELLO = 4  // Hello packet
};


struct RREQPacket {
    uint8_t type;       // Loại packet (RREQ)
    uint8_t hopCount;   // Số lần nhảy
    uint32_t rreqID;    // ID yêu cầu định tuyến
    uint32_t destIP;    // Địa chỉ IP đích
    uint32_t destSeq;   // Số thứ tự đích
    uint32_t srcIP;     // Địa chỉ IP nguồn
    uint32_t srcSeq;    // Số thứ tự nguồn

    RREQPacket() : type(RREQ), hopCount(0), rreqID(0), destIP(0), destSeq(0), srcIP(0), srcSeq(0) {}
};


struct RREPPacket {
    uint8_t type;       // Loại packet (RREP)
    uint8_t hopCount;   // Số lần nhảy
    uint32_t destIP;    // Địa chỉ IP đích
    uint32_t destSeq;   // Số thứ tự đích
    uint32_t srcIP;     // Địa chỉ IP nguồn
    uint32_t lifetime;  // Thời gian sống của đường dẫn

    RREPPacket() : type(RREP), hopCount(0), destIP(0), destSeq(0), srcIP(0), lifetime(0) {}
};


struct RERRPacket {
    uint8_t type;       // Loại packet (RERR)
    std::vector<uint32_t> unreachableDestIP;  // Danh sách các IP đích không thể truy cập
    std::vector<uint32_t> unreachableDestSeq; // Danh sách số thứ tự đích không thể truy cập

    RERRPacket() : type(RERR) {}
};

// Định nghĩa một packet Hello (có thể tùy chỉnh theo yêu cầu)
struct HelloPacket {
    uint8_t type;       // Loại packet (HELLO)
    uint32_t srcIP;     // Địa chỉ IP nguồn
    uint32_t lifetime;  // Thời gian sống của đường dẫn

    HelloPacket() : type(HELLO), srcIP(0), lifetime(0) {}
};

} // namespace AODV
