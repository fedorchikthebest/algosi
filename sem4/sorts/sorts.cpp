#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

void mergeRuns(std::ifstream &left, std::ifstream &right, std::ofstream &output,
               int leftSize, int rightSize) {
  int a = 0, b = 0;

  bool hasA = leftSize > 0 && static_cast<bool>(left >> a);
  bool hasB = rightSize > 0 && static_cast<bool>(right >> b);

  while (hasA && hasB) {
    if (a <= b) {
      output << a << ' ';
      --leftSize;
      hasA = leftSize > 0 && static_cast<bool>(left >> a);
    } else {
      output << b << ' ';
      --rightSize;
      hasB = rightSize > 0 && static_cast<bool>(right >> b);
    }
  }

  while (hasA) {
    output << a << ' ';
    --leftSize;
    hasA = leftSize > 0 && static_cast<bool>(left >> a);
  }

  while (hasB) {
    output << b << ' ';
    --rightSize;
    hasB = rightSize > 0 && static_cast<bool>(right >> b);
  }
}

void twoPhaseMergeSortRecursive(const std::string &inputFile,
                                const std::string &outputFile, int size,
                                const std::string &prefix) {
  if (size <= 1) {
    std::ifstream input(inputFile);
    std::ofstream output(outputFile);
    int value;

    while (input >> value)
      output << value << ' ';

    return;
  }

  int leftSize = size / 2;
  int rightSize = size - leftSize;

  std::string leftFile = prefix + "_left.txt";
  std::string rightFile = prefix + "_right.txt";
  std::string sortedLeft = prefix + "_sorted_left.txt";
  std::string sortedRight = prefix + "_sorted_right.txt";

  {
    std::ifstream input(inputFile);
    std::ofstream left(leftFile);
    std::ofstream right(rightFile);

    int value;

    for (int i = 0; i < leftSize; ++i) {
      input >> value;
      left << value << ' ';
    }

    for (int i = 0; i < rightSize; ++i) {
      input >> value;
      right << value << ' ';
    }
  }

  twoPhaseMergeSortRecursive(leftFile, sortedLeft, leftSize, prefix + "L");
  twoPhaseMergeSortRecursive(rightFile, sortedRight, rightSize, prefix + "R");

  {
    std::ifstream left(sortedLeft);
    std::ifstream right(sortedRight);
    std::ofstream output(outputFile);

    mergeRuns(left, right, output, leftSize, rightSize);
  }

  std::remove(leftFile.c_str());
  std::remove(rightFile.c_str());
  std::remove(sortedLeft.c_str());
  std::remove(sortedRight.c_str());
}

std::vector<int> twoPhaseMergeSort(std::vector<int> arr, int size) {
  size = std::min(size, static_cast<int>(arr.size()));

  if (size <= 1)
    return arr;

  {
    std::ofstream input("two_phase_input.txt");

    for (int i = 0; i < size; ++i)
      input << arr[i] << ' ';
  }

  twoPhaseMergeSortRecursive("two_phase_input.txt", "two_phase_output.txt",
                             size, "two_phase_temp");

  {
    std::ifstream output("two_phase_output.txt");

    for (int i = 0; i < size; ++i)
      output >> arr[i];
  }

  std::remove("two_phase_input.txt");
  std::remove("two_phase_output.txt");

  return arr;
}

std::vector<int> onePhaseMergeSort(std::vector<int> arr, int size) {
  size = std::min(size, static_cast<int>(arr.size()));

  if (size <= 1)
    return arr;

  {
    std::ofstream file("one_input.txt");

    for (int i = 0; i < size; ++i)
      file << arr[i] << ' ';
  }

  std::string source = "one_input.txt";
  std::string outputFile = "one_output_a.txt";

  for (int width = 1; width < size; width *= 2) {
    {
      std::ifstream input(source);
      std::ofstream left("one_left.txt");
      std::ofstream right("one_right.txt");

      int value;

      for (int i = 0; i < size; ++i) {
        input >> value;

        if ((i / width) % 2 == 0)
          left << value << ' ';
        else
          right << value << ' ';
      }
    }

    {
      std::ifstream left("one_left.txt");
      std::ifstream right("one_right.txt");
      std::ofstream output(outputFile);

      for (int start = 0; start < size; start += 2 * width) {
        int leftSize = std::min(width, size - start);
        int rightSize = std::min(width, size - start - leftSize);

        mergeRuns(left, right, output, leftSize, rightSize);
      }
    }

    std::remove("one_left.txt");
    std::remove("one_right.txt");

    if (source != "one_input.txt")
      std::remove(source.c_str());

    source = outputFile;
    outputFile = (outputFile == "one_output_a.txt") ? "one_output_b.txt"
                                                    : "one_output_a.txt";
  }

  {
    std::ifstream result(source);

    for (int i = 0; i < size; ++i)
      result >> arr[i];
  }

  std::remove("one_input.txt");
  std::remove("one_output_a.txt");
  std::remove("one_output_b.txt");

  return arr;
}

std::vector<int> naturalMergeSort(std::vector<int> arr, int size) {
  size = std::min(size, static_cast<int>(arr.size()));

  if (size <= 1)
    return arr;

  {
    std::ofstream file("natural_input.txt");

    for (int i = 0; i < size; ++i)
      file << arr[i] << ' ';
  }

  std::string source = "natural_input.txt";
  std::string outputFile = "natural_output_a.txt";

  while (true) {
    std::vector<int> leftRuns;
    std::vector<int> rightRuns;

    {
      std::ifstream input(source);
      std::ofstream left("natural_left.txt");
      std::ofstream right("natural_right.txt");

      int previous;

      if (!(input >> previous))
        break;

      int runIndex = 0;
      int runSize = 1;

      std::ofstream *target = &left;
      *target << previous << ' ';

      int current;

      while (input >> current) {
        if (current < previous) {
          if (runIndex % 2 == 0)
            leftRuns.push_back(runSize);
          else
            rightRuns.push_back(runSize);

          ++runIndex;
          runSize = 1;

          target = (runIndex % 2 == 0) ? &left : &right;
        } else {
          ++runSize;
        }

        *target << current << ' ';
        previous = current;
      }

      if (runIndex % 2 == 0)
        leftRuns.push_back(runSize);
      else
        rightRuns.push_back(runSize);
    }

    int runs = static_cast<int>(leftRuns.size() + rightRuns.size());

    if (runs <= 1)
      break;

    {
      std::ifstream left("natural_left.txt");
      std::ifstream right("natural_right.txt");
      std::ofstream output(outputFile);

      for (int i = 0; i < static_cast<int>(leftRuns.size()); ++i) {
        int leftSize = leftRuns[i];

        int rightSize =
            i < static_cast<int>(rightRuns.size()) ? rightRuns[i] : 0;

        mergeRuns(left, right, output, leftSize, rightSize);
      }
    }

    std::remove("natural_left.txt");
    std::remove("natural_right.txt");

    if (source != "natural_input.txt")
      std::remove(source.c_str());

    source = outputFile;

    outputFile = (outputFile == "natural_output_a.txt")
                     ? "natural_output_b.txt"
                     : "natural_output_a.txt";
  }

  {
    std::ifstream result(source);

    for (int i = 0; i < size; ++i)
      result >> arr[i];
  }


  return arr;
}

TEST_CASE("merge_sorts", "[single-file]") {
  std::vector<int> arr = {5, 4, 3, 2, 1};
  std::vector<int> ans = {1, 2, 3, 4, 5};

  REQUIRE(twoPhaseMergeSort(arr, static_cast<int>(arr.size())) == ans);
  REQUIRE(onePhaseMergeSort(arr, static_cast<int>(arr.size())) == ans);
  REQUIRE(naturalMergeSort(arr, static_cast<int>(arr.size())) == ans);
}
