#pragma once

#include <functional>

namespace Copipes {

template <typename DataType>
class Source
{
public:
    virtual void Pull(std::function<void(bool closed, DataType data)> onDone) = 0;
};

}