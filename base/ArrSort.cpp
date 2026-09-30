module;

#include <vector>

export module BaseArrClass;

export template <typename T> class ArrSort {
protected:
  std::vector<T> arr;

public:
  ArrSort(std::vector<T> a) {
    if (a.size() <= 0)
      throw std::length_error("size <= 0");
    arr = a;    
  }
  std::vector<T> get_arr() const { return arr; }
  virtual void sort() = 0;  
};
