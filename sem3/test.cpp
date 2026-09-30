import ShellSortClass;
import QuickSortClass;
    
#include "../tests/universal_tests.h"
#define TEST(x)                                                                \
  BOUNDARY_TESTS_MACRO(x)                                                      \
  BASE_TESTS_MACRO(x)                                                          \
  RANDOM_TESTS_MACRO(x)

TEST(ShellSort)
TEST(QuickSort)
