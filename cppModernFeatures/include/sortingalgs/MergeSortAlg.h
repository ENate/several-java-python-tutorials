#ifndef MERGESORTALG_H
#define MERGESORTALG_H
#include <array>
#include <iostream>
namespace mergesortalg {

    class MergeSortAlg {

        private:
            int myArrSize;
            std::array<int, 10> arrayToSort;

        public:
            MergeSortAlg() = default;
            MergeSortAlg(int argSizeA, std::array<int, 10>* arrayArg);
            // Getters and Setters
            int getMyArrSize() const;
            std::array<int, 10> getArrayToSort() const;
    };
}
#endif