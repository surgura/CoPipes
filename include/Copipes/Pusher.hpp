#pragma once

#include "Sink.hpp"
#include <array>

namespace Copipes {

template <typename... OutputTypes>
class Pusher
{
    std::tuple<Sink<OutputTypes>*...> sinks;

    template<int N, typename... Ts> using NthTypeOf =
            typename std::tuple_element<N, std::tuple<Ts...>>::type;

protected:
    template <size_t index>
    void Push(NthTypeOf<index, OutputTypes...> data, std::function<void()> onDone)
    {
        std::get<index>(sinks)->Push(std::move(data), std::move(onDone));
    }
public:
    template <size_t index>
    void SetOutput(Sink<NthTypeOf<index, OutputTypes...>>& sink)
    {
        std::get<index>(sinks) = &sink;
    }
};

template <typename OutputType>
class Pusher<OutputType>
{
    Sink<OutputType>* sink;

protected:
    void Push(OutputType data, std::function<void()> onDone)
    {
        sink->Push(std::move(data), std::move(onDone));
    }
public:
    void SetOutput(Sink<OutputType>& sink)
    {
        this->sink = &sink;
    }
};

}