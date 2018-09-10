#pragma once

#include "Pusher.hpp"
#include "Sink.hpp"

namespace Copipes {

template <typename DataType, size_t OUTPUTS>
class PushSplit : public Pusher<DataType, OUTPUTS>, public Sink<DataType>
{
public:
    void Push(DataType data, std::function<void()> onDone) override
    {
        Pusher<DataType, OUTPUTS>::Push(std::move(data), std::move(onDone));
    }
};

}