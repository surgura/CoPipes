#pragma once

#include "Source.hpp"

namespace Copipes {

template <typename DataType>
class Puller
{
    Source<DataType>* source;
protected:
    void Pull(std::function<void(bool closed, DataType data)> onDone)
    {
        source->Pull(std::move(onDone));
    }
public:
    void SetInput(Source<DataType>& source)
    {
        this->source = &source;
    }
};

}