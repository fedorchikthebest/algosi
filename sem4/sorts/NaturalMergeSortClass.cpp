module;
#include <vector>
#include <iostream>
export module NaturalMergeSortClass;
import BaseArrClass;

export template <typename T> class NaturalMergeSort : public ArrSort<T> {
public:
  using ArrSort<T>::ArrSort;
  using ArrSort<T>::get_arr;
  void sort() {
    std::vector<T> buf(this->arr.size());
	bool merged = true;

    while (merged) {
        int writePos = 0;
        int i = 0;
        merged = false;

        while (i < this->arr.size()) {
            int j1 = i + 1;
            while (j1 < this->arr.size() && this->arr.at(j1 - 1) <= this->arr.at(j1))
                j1++;
            int len1 = j1 - i;

            if (j1 >= this->arr.size()) {
                for (int k = i; k < j1; k++)
                  buf.at(writePos++) = this->arr.at(k);                
                break;
            }

            int j2 = j1 + 1;
            while (j2 < this->arr.size() && this->arr.at(j2 - 1) <= this->arr.at(j2))
                j2++;
            int len2 = j2 - j1;

            merged = true;

            int a = i, b = j1;
            while (a < j1 && b < j2) {
              if (this->arr.at(a) <= this->arr.at(b))
                buf.at(writePos++) = this->arr.at(a++);              
                else
                  buf.at(writePos++) = this->arr.at(b++);                
            }
            while (a < j1) buf.at(writePos++) = this->arr.at(a++);
            while (b < j2) buf.at(writePos++) = this->arr.at(b++);

            i = j2;
        }

        this->arr = buf;
    }
}


private:
  void merge(T *begin1, T *begin2, int len1, int len2, T *ans) {
    T *i = begin1, *j = begin2;
    while (i - begin1 < len1 && j - begin2 < len2) {
      if (*i < *j)
        *(ans++) = *(i++);
      else
        *(ans++) = *(j++);
    }
    while (i - begin1 < len1)
      *(ans++) = *(i++);
    while (j - begin2 < len2)
      *(ans++) = *(j++);
  }
};
