#pragma once
#include <cstddef>

class Arena {
    char* buffer;
    size_t capacity, offset = 0;

public:
    Arena(size_t bytes);
    ~Arena();

    void* allocate(size_t bytes, size_t alignment);
    void reset();
    size_t used() const;
};
