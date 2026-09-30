import BubbleSortClass;
import InsertionSortClass;
import SelectionSortClass;
    
#include "../tests/universal_tests.h"
#define TEST(x)                                                                \
  BOUNDARY_TESTS_MACRO(x)                                                      \
  BASE_TESTS_MACRO(x)                                                          \
  RANDOM_TESTS_MACRO(x)

TEST(BubbleSort)
TEST(InsertionSort)
TEST(SelectionSort)
