#pragma once
#include <chrono>
#include <iostream>

// Два сценария: добавить всё и удалить, либо чередовать добавление с удалением.
template <class V>
void test(const char* name, V& v, int n, bool alternate) {
    auto start = std::chrono::steady_clock::now();

    if (alternate) {
        for (int i = 0; i < n; ++i) {
            v.push_back(i);
            v.pop_back();
        }
    } else {
        for (int i = 0; i < n; ++i) v.push_back(i);
        for (int i = 0; i < n; ++i) v.pop_back();
    }

    auto end = std::chrono::steady_clock::now();
    std::cout << name << (alternate ? " alternate: " : " batch: ")
              << std::chrono::duration<double, std::milli>(end - start).count()
              << " ms\n";
}
