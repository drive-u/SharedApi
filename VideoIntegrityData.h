#pragma once
#include <stdint.h>

namespace VideoIntegrity
{
    static const uint8_t VIDEO_INTEGRITY_VERSION = 0x01;
    
    enum class VCLMessageType : uint8_t {
        STREAMER_PARTIAL_MESSAGE,
        NODE_PARTIAL_MESSAGE,
        STREAMER_FULL_MESSAGE,
        NODE_FULL_MESSAGE,
    };

    struct VideoIntegrityData {
        uint8_t VideoIntegrityMessageVersion = VIDEO_INTEGRITY_VERSION;
        VCLMessageType videoIntegrityMessageType;
        uint64_t customerTimestamp;
        uint64_t streamerGrabTime;
        uint64_t captureTimestampStreamer; 
        uint64_t nodePlayedTime; 
        uint64_t streamerReturnTime;
        uint64_t encodedFrameCrc;
        uint64_t CRCBeforeDecoding;
        uint64_t lastValidCanvasIndex;
        uint64_t lastControlOk;
        uint64_t lastTimestampControl;
        uint64_t customerField1;
        uint64_t customerField2;
        uint32_t lastValidQp;
        uint32_t cameraFrameIndex;
        uint32_t canvasIndex;
        uint32_t nodeError;
        uint8_t  VIN[32];
        uint8_t  uuid[32];
        uint8_t  NIN[32];
        uint8_t  nodeUuid[32];
        uint8_t  grabCameraIndex;
    }__attribute__((__packed__));

 std::ostream &operator<<(std::ostream &out, VCLMessageType type) {
    switch(type) {
#define CASE(a) case VCLMessageType::a: out<<#a; return out
        CASE(STREAMER_PARTIAL_MESSAGE);
        CASE(NODE_PARTIAL_MESSAGE);
        CASE(STREAMER_FULL_MESSAGE);
        CASE(NODE_FULL_MESSAGE);
#undef CASE
    }

    return out<<"type("<<static_cast<unsigned>(type)<<")";
    }
    std::ostream &operator<<( std::ostream &out, VideoIntegrityData d ) {
        return out <<
           "VideoIntegrityMessageVersion: " << static_cast<unsigned>(d.VideoIntegrityMessageVersion) << ", " <<
           "videoIntegrityMessageType: " << d.videoIntegrityMessageType << ", " <<
           "customerTimestamp: " << d.customerTimestamp << ", " <<
           "streamerGrabTime: " << d.streamerGrabTime << ", " <<
           "captureTimestampStreamer: " << d.captureTimestampStreamer << ", " <<
           "nodePlayedTime: " << d.nodePlayedTime << ", " <<
           "streamerReturnTime: " << d.streamerReturnTime << ", " <<
           "canvasIndex: " << d.canvasIndex;
    }
}