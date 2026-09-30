LIBS_FLAGS = -I/usr/local/include -L/usr/local/lib -lCatch2 -lCatch2Main
BASE_FLAGS = -std=c++20 -x c++-module --precompile

all:
	clang++ $(BASE_FLAGS) ../base/ArrSort.cpp -o ArrSort.pcm
	clang++ $(BASE_FLAGS) -fmodule-file=BaseArrClass=ArrSort.pcm  BubbleSort.cpp -o BubbleSort.pcm
	clang++ -std=c++20 $(LIBS_FLAGS) -fmodule-file=BaseArrClass=ArrSort.pcm -fmodule-file=BubbleSortClass=BubbleSort.pcm  test.cpp
