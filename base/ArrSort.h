#pragma once
#include <vector>

template <typename T> class ArrSort {
protected:
  std::vector<T> arr;
  
public:
  ArrSort(std::vector<T> a);
  void sort();
  std::vector<T> get_arr() const;
};
