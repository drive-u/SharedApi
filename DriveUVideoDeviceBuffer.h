#pragma once

#include "Types.h"
#include <memory>

namespace EncoderApi {
// all video format is AV_PIX_FMT_YUV420P
class DriveUVideoDeviceBuffer
{
public:
    DriveUVideoDeviceBuffer(){}
    DriveUVideoDeviceBuffer(unsigned size);
    virtual ~DriveUVideoDeviceBuffer(){}
    virtual unsigned size() const = 0;
    virtual unsigned long long buffer() = 0;
    virtual void encoderApiMemcpyFromHost(EncoderApi::PointerLengthReleaser buffer, unsigned offset = 0) = 0;
    virtual void encoderApiMemcpyToHost(EncoderApi::PointerLengthReleaser buffer) = 0;
    virtual void memset(unsigned char value = 0) = 0;
};
typedef std::shared_ptr<DriveUVideoDeviceBuffer> DriveUVideoDeviceBufferPtr;
}
