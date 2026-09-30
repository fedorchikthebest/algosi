export module BetterBubbleSortClass;
import BaseArrClass;

export template <typename T> class BetterBubbleSort : public ArrSort<T> {
public:
  using ArrSort<T>::ArrSort;
  using ArrSort<T>::get_arr;
  void sort() {
    T z;
    bool swap = true;
    while (swap) {
      swap = false;
      for (int i = 0; i < this->arr.size() - 1; i++)
        if (this->arr.at(i) > this->arr.at(i + 1)) {
          z = this->arr.at(i + 1);
          this->arr.at(i + 1) = this->arr.at(i);
          this->arr.at(i) = z;
          swap = true;
        }
    }
  }
};
