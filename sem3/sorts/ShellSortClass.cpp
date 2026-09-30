export module ShellSortClass;
import BaseArrClass;

export template <typename T> class ShellSort : public ArrSort<T> {
public:
  using ArrSort<T>::ArrSort;
  using ArrSort<T>::get_arr;
  void sort() {
    T z;
    for (int step = this->arr.size() / 2; step > 0; step /= 2) {
      for (int i = step; i < this->arr.size(); i++) {
        z = this->arr.at(i);
        for (int j = i - step; j >= 0; j-=step) {
          if (this->arr.at(j) <= z)
            break;
          this->arr.at(j + step) = this->arr.at(j);
          this->arr.at(j) = z;          
        }
      }
    }
  }
};
