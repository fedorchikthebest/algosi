module;
#include <vector>
export module OnePhaseMergeSortClass;
import BaseArrClass;

export template <typename T> class OnePhaseMergeSort : public ArrSort<T> {
public:
  using ArrSort<T>::ArrSort;
  using ArrSort<T>::get_arr;

  void sort() {
    std::vector<T> buf = this->arr;
    std::vector<T> *src = &this->arr;
    std::vector<T> *dst = &buf;
    int mid, right;
    int i, j, k;

    for (int step = 1; step < this->arr.size(); step *= 2) {
      for (int left = 0; left < this->arr.size(); left += step * 2) {
        mid = this->arr.size(), right = this->arr.size();
        if (left + step * 2 < this->arr.size()) {
          mid = left + step;
          right = left + step * 2;
        } else if (left + step < this->arr.size())
          mid = left + step;

        i = left, j = mid, k = left;
        while (i < mid && j < right) {
          if (src->at(i) <= src->at(j))
            dst->at(k++) = src->at(i++);
          else
            dst->at(k++) = src->at(j++);
        }
        while (i < mid)
          dst->at(k++) = src->at(i++);
        while (j < right)
          dst->at(k++) = src->at(j++);
      }
      std::swap(src, dst);
    }

    if (src != &this->arr)
      this->arr = *src;
  }
};
