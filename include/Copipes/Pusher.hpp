#pragma once

#include "Sink.hpp"
#include <array>

namespace Copipes {

/*template <typename DataType, size_t OUTPUTS = 1>
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
    template <size_t INDEX>
    void SetOutput(Sink<DataType>& sink)
    {
        this->sink[INDEX] = &sink;
    }
};*/

template <typename InputType, typename... OutputTypes>
class Pusher
{
    std::tuple<Sink<OutputTypes>*...> sinks;

    template<int N, typename... Ts> using NthTypeOf =
            typename std::tuple_element<N, std::tuple<Ts...>>::type;

protected:
    void Push(InputType data, std::function<void()> onDone)
    {
        // TODO
        //sink->Push(std::move(data), std::move(onDone));
    }
public:
    template <size_t index>
    void SetOutput(Sink<NthTypeOf<index, OutputTypes...>>& sink)
    {
        std::get<index>(sinks) = &sink;
    }
};

/*
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
};*/

}