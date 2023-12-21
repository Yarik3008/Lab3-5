#include <iostream>
#include <chrono>
#include <random>
#include "../../queue/include/MyQueue.h"

auto average_test(size_t size, size_t iterations = 10) {
    int max_random = 10000;
    int min_random = -10000;
    long long average_time_add = 0;
    long long average_time_del = 0;
    for (size_t i = 0; i < iterations; i++) {
        TQueue<int> queue(size);

        std::cout << "#" << i << " Adding" << std::endl;
        for (size_t j = 0; j < size; j++) {
            int c1 = min_random + std::rand() % static_cast<int>(max_random - min_random + 1);

            std::chrono::steady_clock::time_point begin, end;

            begin = std::chrono::steady_clock::now();
            queue.Push(c1);
            end = std::chrono::steady_clock::now();

            auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
            average_time_add += elapsed_ms.count();
            std::cout << i + 1 << '\t' << elapsed_ms.count() << std::endl;
        }
        std::cout << std::endl << "#" << i << " Delliting" << std::endl;
        for (size_t j = 0; j < size; j++) {

            std::chrono::steady_clock::time_point begin, end;

            begin = std::chrono::steady_clock::now();
            queue.Get();
            end = std::chrono::steady_clock::now();

            auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
            average_time_add += elapsed_ms.count();
            std::cout << i + 1 << '\t' << elapsed_ms.count() << std::endl;
        }
    }

    std::cout << "Average time add: " << average_time_add / static_cast<double>(iterations * size) << std::endl;
    std::cout << "Average time del: " << average_time_add / static_cast<double>(iterations * size) << std::endl;

    return;
}

int main(int argc, char** arhv)
{
    auto begin = std::chrono::steady_clock::now();

    average_test(150);

    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "Execution time: " << elapsed_ms.count();

}
