#include "arena.h"
#include "linear_allocator.h"
#include "test.h"
#include <string>
#include <vector>

#if defined(_MSC_VER) && defined(_DEBUG)
#include <crtdbg.h>
#endif

int main(int argc, char* argv[]) {
#if defined(_MSC_VER) && defined(_DEBUG)
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    int n = argc > 1 ? std::stoi(argv[1]) : 1000000;

    {
        std::vector<int> v;
        test("Standard", v, n, false);
    }
    {
        std::vector<int> v;
        test("Standard", v, n, true);
    }

    Arena arena(4ULL * n * sizeof(int) + 1024);
    {
        std::vector<int, LinearAllocator<int>> v{LinearAllocator<int>(arena)};
        test("Linear", v, n, false);
    }
    std::cout << "Arena used (batch): " << arena.used() << " bytes\n";

    arena.reset(); // Только после уничтожения первого вектора
    {
        std::vector<int, LinearAllocator<int>> v{LinearAllocator<int>(arena)};
        test("Linear", v, n, true);
    }
    std::cout << "Arena used (alternate): " << arena.used() << " bytes\n";
}
