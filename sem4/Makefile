LIBS_FLAGS := -I/usr/local/include -L/usr/local/lib -lCatch2Main -lCatch2
BASE_FLAGS := -std=c++20 -x c++-module --precompile
CXX := clang++
SORT_PCMS   := $(patsubst sorts/%.cpp,modules/%.pcm,$(wildcard sorts/*.cpp))

.PHONY: all

all: modules/ArrSort.pcm $(SORT_PCMS)
	clang++ -std=c++20 -fprebuilt-module-path=modules/ -fmodule-file=BaseArrClass=modules/ArrSort.pcm test.cpp $(LIBS_FLAGS) -o tests

modules/ArrSort.pcm: ../base/ArrSort.cpp
	clang++ $(BASE_FLAGS) ../base/ArrSort.cpp -o modules/ArrSort.pcm

modules/%.pcm: sorts/%.cpp
	$(CXX) $(BASE_FLAGS) -fmodule-file=BaseArrClass=modules/ArrSort.pcm $< -o $@
