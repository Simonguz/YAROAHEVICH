CXX = g++
CXXFLAGS = -std=c++17 -O2 -g

lab5: main.cpp arena.cpp arena.h linear_allocator.h test.h
	$(CXX) $(CXXFLAGS) main.cpp arena.cpp -o lab5

leak:
	$(CXX) -std=c++17 -O1 -g -fsanitize=address -fno-omit-frame-pointer -DDEMO_LEAK main.cpp arena.cpp -o lab5_leak

clean:
	rm -f lab5 lab5_leak
