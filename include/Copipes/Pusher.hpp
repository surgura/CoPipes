#pragma once

#include "Sink.hpp"
#include <array>

namespace Copipes {

template <typename DataType, size_t OUTPUTS = 1>
class Pusher
{
    std::array<Sink<DataType>*, OUTPUTS> sinks;
protected:
    void Push(DataType data, std::function<void()> onDone)
    {
     //   sink->Push(std::move(data), std::move(onDone));
     // TODO
    }
public:
    template <typename INDEX>
    void SetOutput(Sink<DataType>& sink)
    {
        this->sink[INDEX] = &sink;
    }
};

template <typename DataType>
class Pusher<DataType, 1>
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