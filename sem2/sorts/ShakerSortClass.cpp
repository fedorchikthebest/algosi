export module ShakerSortClass;
import BaseArrClass;

export template <typename T> class ShakerSort : public ArrSort<T> {
public:
  using ArrSort<T>::ArrSort;
  using ArrSort<T>::get_arr;
  void sort() {
    int left = 0, right = this->arr.size() - 1;
    bool swapped = true;
	T z;
    while (swapped) {
      swapped = false;
      for (int i = left; i < right; i++)
        if (this->arr.at(i) > this->arr.at(i + 1)) {
          z = this->arr.at(i + 1);
          this->arr.at(i + 1) = this->arr.at(i);
          this->arr.at(i) = z;
          swapped = true;
        }
      right--;
      for (int i = right; i > left; i--)
        if (this->arr.at(i) < this->arr.at(i - 1)) {
          z = this->arr.at(i - 1);
          this->arr.at(i - 1) = this->arr.at(i);
          this->arr.at(i) = z;
          swapped = true;
        }
      left++;
    }
  }
};
