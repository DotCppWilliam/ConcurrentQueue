#include "concurrent_queue_impl.h"
#include <iostream>
#include <thread>

using namespace std;

int main()
{
    ConcurrentQueue<int> conqueue;
    bool exit = false;
    
    std::thread t1([&]{
        for (int i = 0; i < 50; i++)
            conqueue.Enqueue(i);
        cout << "t1 insert done!\n";
    });

    std::thread t2([&]{
        int ret = 0;
        while (conqueue.TryDequeue(ret))
            cout << "t2: " << ret << "\n";
        exit = true;
    });
    
    t1.join();
    t2.join();

    while (!exit);
    return 0;
}