#ifndef __ENCODER_TYPES_H__
#define __ENCODER_TYPES_H__

#include <functional>

namespace EncoderApi
{

struct PointerLengthReleaser
{
    void * buffer;
    unsigned length;
    std::function<void()>  releaser;
};

struct FrameRateFraction
{
    unsigned numerator;
    unsigned denominator;
};

enum class Codec : uint8_t {
    H264,
    H265,
    CEIL
};

enum class FrameType
{
   PFRAME,
   PFRAME_WITH_INVALIDATIONS,
   IDR,
   SPSPPSIDR,
};
struct EncodedFrameMetadata
{
   FrameType frameType;
   uint32_t averageQP;
   uint64_t timestamp;
   uint64_t frameIndex;
   uint64_t lastValidFrame; //0 if frameType != PFRAME_WITH_INVALIDATIONS else last valid frame
   Codec codec;
};


}

#endif // __ENCODER_TYPES_H__
