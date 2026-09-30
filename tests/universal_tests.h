#pragma once
#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <random>

#pragma once
#define BOUNDARY_TESTS_MACRO(x)                                                \
  TEST_CASE("sort boundary tests for " #x, "[single-file]") {                          \
    std::vector<int> z(0);                                                     \
    REQUIRE_THROWS(x<int>(z));                                                 \
  }

#define BASE_TESTS_MACRO(x)                                                    \
  TEST_CASE("sort base tests for " #x, "[single-file]") {                              \
    x<int> t1({1, 2, 3});                                                      \
    std::vector<int> ans = {1, 2, 3};                                          \
    t1.sort();                                                                 \
    REQUIRE(t1.get_arr() == ans);                                              \
    x<int> t2({3, 2, 1});                                                      \
    t2.sort();                                                                 \
    REQUIRE(t2.get_arr() == ans);                                              \
  }

#define RANDOM_TESTS_MACRO(x)                                                  \
  TEST_CASE("100 random tests for " #x, "[single-file]") {                     \
    std::vector<int> t{}, t2{};                                                \
    int max = 0;                                                               \
    std::random_device rd;                                                     \
    std::mt19937 gen(rd());                                                    \
    std::uniform_int_distribution<> dist(1, 100);                              \
    for (int i = 0; i < 100; i++) {                                            \
      t.push_back(max);                                                        \
      t2 = t;                                                                  \
      std::shuffle(t2.begin(), t2.end(), gen);                                 \
      max += dist(gen);                                                        \
      x<int> testsort(t2);                                                     \
      testsort.sort();                                                         \
      REQUIRE(testsort.get_arr() == t);                                        \
    }                                                                          \
  }
