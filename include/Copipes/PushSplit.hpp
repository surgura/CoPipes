#pragma once

#include "Pusher.hpp"
#include "Sink.hpp"

namespace Copipes {

template<typename Dependent, std::size_t Index>
using DependOn = Dependent;

template<typename T, std::size_t N, typename Indices = std::make_index_sequence<N>>
struct repeat;

template<typename T, std::size_t N, std::size_t... Indices>
struct repeat<T, N, std::index_sequence<Indices...>> {
    using type = std::tuple<DependOn<T, Indices>...>;
};

template<typename DataType, std::size_t OUTPUTS, typename Indices = std::make_index_sequence<OUTPUTS>>
class PushSplit;

template<typename DataType, std::size_t OUTPUTS, std::size_t... Indices>
struct PushSplit<DataType, OUTPUTS, std::index_sequence<Indices...>> : public Pusher<DependOn<DataType, Indices>...>, public Sink<DataType>
{
    //using type = std::tuple<DependOn<T, Indices>...>;
public:
    void Push(DataType data, std::function<void()> onDone) override
    {
        //Pusher<DataType, OUTPUTS>::Push(std::move(data), std::move(onDone));
        // TODO
    }
};

}