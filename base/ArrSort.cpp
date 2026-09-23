#include "ArrSort.h"
#include <stdexcept>
#include <vector>

template <typename T> ArrSort<T>::ArrSort(std::vector<T> a) : arr(a) {
  if (a.size() <= 0)
    throw std::length_error("size <= 0");  
}

template <typename T> std::vector<T> ArrSort<T>::get_arr() const {
  return arr;  
};  
