#include "Copipes/Copipes.hpp"
#include <thread>
#include <boost/asio.hpp>
#include <iostream>

namespace cp = Copipes;
namespace asio = boost::asio;

class IntMaker : public cp::Pusher<int>
{
    asio::io_context& io;
    std::thread worker;

    void MakeInt()
    {
        while(true)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            bool ready  = false;
            io.post([this, &ready]() {
                Push(15, [this, &ready]() {
                    ready = true;
                });
            });
            while(!ready) {}
        }
    }
public:
    IntMaker(asio::io_context& io) : io(io) {}
    void Start()
    {
        worker = {[this]() {
            MakeInt();
        }};
    }
};

class IntShower : public cp::Sink<int>
{
public:
    void Push(int data, std::function<void()> onDone) override
    {
        std::cout << data << std::endl;
        onDone();
    }
};

int main()
{
    asio::io_context io;
    auto guard = boost::asio::make_work_guard(io);

    IntShower intShower;

    IntMaker intMaker(io);
    intMaker.SetOutput(intShower);
    intMaker.Start();

    io.run();

    return 0;
}