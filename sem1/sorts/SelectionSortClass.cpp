export module SelectionSortClass;
import BaseArrClass;

export template <typename T> class SelectionSort : public ArrSort<T> {
public:
  using ArrSort<T>::ArrSort;
  using ArrSort<T>::get_arr;
  void sort() {
    T *min = nullptr;
    T z;
    for (int min_pos = 0; min_pos < this->arr.size() - 1; min_pos++) {
      min = &this->arr.at(min_pos);      
      for (int i = min_pos; i < this->arr.size(); i++) {
        if (this->arr.at(i) < *min)
          min = &this->arr.at(i)                 ;
      }
      z = *min;
      *min = this->arr.at(min_pos);
      this->arr.at(min_pos) = z;
    }
  }
};
