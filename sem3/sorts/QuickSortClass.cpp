export module QuickSortClass;
import BaseArrClass;

export template <typename T> class QuickSort : public ArrSort<T> {
public:
  using ArrSort<T>::ArrSort;
  using ArrSort<T>::get_arr;
		void sort() { recursive_qsort(&this->arr.at(0), &this->arr.at(this->arr.size() - 1)); }  

private:
  void recursive_qsort(T *begin, T *end) {
    if (begin >= end)
      return;    
    T opora = *end, z;    
    T *min_end = begin;
    for (T *i = begin; i < end; i++) {
      if (*i <= opora) {
        z = *min_end;
        *min_end = *i;
        *i = z;
        min_end++;
      }
    }
    *end = *min_end;
	*min_end = opora;
    recursive_qsort(begin, min_end - 1);
	recursive_qsort(min_end, end);
  }    
};
