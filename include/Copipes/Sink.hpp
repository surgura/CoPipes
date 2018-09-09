#pragma once

#include <functional>

namespace Copipes {

template <typename DataType>
class Sink
{
public:
    virtual void Push(DataType data, std::function<void()> onDone) = 0;
};

}