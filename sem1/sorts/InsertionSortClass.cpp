export module InsertionSortClass;
import BaseArrClass;

export template <typename T> class InsertionSort : public ArrSort<T> {
public:
  using ArrSort<T>::ArrSort;
  using ArrSort<T>::get_arr;
  void sort() {
    T z;
    for (int i = 1; i < this->arr.size(); i++) {
      z = this->arr.at(i);
      for (int j = i - 1; j >= 0; j--){
        if (this->arr.at(j) <= z)
          break;
        this->arr.at(j + 1) = this->arr.at(j);
		this->arr.at(j) = z;
      }      
    }    
  }
};
