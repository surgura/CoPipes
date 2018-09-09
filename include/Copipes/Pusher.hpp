#pragma once

#include "Sink.hpp"

namespace Copipes {

template <typename DataType>
class Pusher
{
    Sink<DataType>* sink;
protected:
    void Push(DataType data, std::function<void()> onDone)
    {
        sink->Push(std::move(data), std::move(onDone));
    }
public:
    void SetOutput(Sink<DataType>& sink)
    {
        this->sink = &sink;
    }
};

}