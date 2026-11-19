#pragma once
#include "arena.h"

// Аллокатор для std::vector.
template <class T>
struct LinearAllocator {
    using value_type = T;
    Arena* arena;

    LinearAllocator(Arena& a) : arena(&a) {}

    T* allocate(size_t n) {
        return static_cast<T*>(arena->allocate(n * sizeof(T), alignof(T)));
    }

    void deallocate(T*, size_t) {} // Отдельные блоки не освобождаем
};
