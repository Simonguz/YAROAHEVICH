#include "arena.h"
#include <memory>
#include <new>

Arena::Arena(size_t bytes) : buffer(new char[bytes]), capacity(bytes) {}

Arena::~Arena() {
    //delete[] buffer; 
}

void* Arena::allocate(size_t bytes, size_t alignment) {
    void* ptr = buffer + offset;
    size_t space = capacity - offset;
    if (!std::align(alignment, bytes, ptr, space))
        throw std::bad_alloc();
    offset = capacity - space + bytes;
    return ptr;
}

void Arena::reset() { offset = 0; }
size_t Arena::used() const { return offset; }
