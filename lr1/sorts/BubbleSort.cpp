export module BubbleSortClass;
import BaseArrClass;

export template <typename T> class BubbleSort : public ArrSort<T> {
public:
  using ArrSort<T>::ArrSort;
  using ArrSort<T>::get_arr;
  void sort() {
    T z;
    for (int _ = 0; _ < this->arr.size(); _++) {
      for (int i = 0; i < this->arr.size() - 1; i++)
        if (this->arr.at(i) > this->arr.at(i + 1)) {
          z = this->arr.at(i + 1);
          this->arr.at(i + 1) = this->arr.at(i);
          this->arr.at(i) = z;
        }
    }
  }
};
