export module ExchangeSortClass;
import BaseArrClass;

export template <typename T> class ExchangeSort : public ArrSort<T> {
public:
  using ArrSort<T>::ArrSort;
  using ArrSort<T>::get_arr;
  void sort() {
    T *min = nullptr;
    T z;
    for (int i = 0; i < this->arr.size() - 1; i++) {    
      for (int j = i + 1; j < this->arr.size(); j++) {
        if (this->arr.at(j) < this->arr.at(i)) {
          z = this->arr.at(i);
          this->arr.at(i) = this->arr.at(j);
		  this->arr.at(j) = z;
		}          
      }
    }
  }
};
