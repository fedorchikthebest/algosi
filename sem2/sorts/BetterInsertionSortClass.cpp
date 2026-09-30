export module BetterInsertionSortClass;
import BaseArrClass;

export template <typename T> class BetterInsertionSort : public ArrSort<T> {
public:
  using ArrSort<T>::ArrSort;
  using ArrSort<T>::get_arr;
  void sort() {
    T z;
	T *insert_pos;
    for (int i = 1; i < this->arr.size(); i++) {
      z = this->arr.at(i);
      insert_pos = binnary_search(&this->arr.at(0), &this->arr.at(i), z);
      for (T *j = &this->arr.at(i); j > insert_pos; j--)
        *j = *(j - 1);
	  *insert_pos = z;
    }
  }

private:
  T *binnary_search(T *begin, T *end, T value) {
    int mid;    
    while (begin < end) {
      mid = (end - begin) / 2;
      if (begin[mid] <= value)
        begin = &begin[mid] + 1;
      else
        end = &begin[mid];
    }
    return begin;    
  }    
};
