module;
#include <vector>
export module TwoPhaseMergeSortClass;
import BaseArrClass;

export template <typename T> class TwoPhaseMergeSort: public ArrSort<T> {
public:
  using ArrSort<T>::ArrSort;
  using ArrSort<T>::get_arr;
  
  void sort() {
    std::vector<T> tmp = this->arr;
	int right, mid, z, o, v, pos, pos1, pos2;
    for (int step = 1; step <= tmp.size(); step *= 2) {
      for (int left = 0; left < tmp.size(); left += step * 2) {
        mid = tmp.size();
        right = tmp.size();
        if (left + step * 2 < tmp.size()) {
          mid = left + step;
          right = left + step * 2;
        } else if (left + step < tmp.size())
          mid = left + step;
        z = left;
        o = mid;
        v = left;
        while (z < mid && o < right)
          tmp.at(v++) = (this->arr.at(z) <= this->arr.at(o))
                            ? this->arr.at(z++)
                            : this->arr.at(o++);
        while (z < mid)
          tmp.at(v++) = this->arr.at(z++);
        while (o < right)
          tmp.at(v++) = this->arr.at(o++);       
      }
	  std::swap(this->arr, tmp);     
    }
  }
};
