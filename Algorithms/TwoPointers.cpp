#include "TwoPointers.hpp"
#include <iostream>
#include <vector>
#include <optional>
#include <tuple>

TwoPointer::TwoPointer(std::vector<int>& vector) : intVector(vector) {}

int TwoPointer::findMiddle() {
    int slowPointer = 0;
    int fastPointer = 0;

    while (fastPointer < intVector.size() -1) {
        slowPointer += 1;
        fastPointer += 2;
    }

    return slowPointer;
}

std::optional<std::tuple<int, int>> TwoPointer::findPairSum(int targetNum) {
    int left = 0;
    int right = intVector.size() -1;

    while (left < right) {
        int sum = intVector.at(left) + intVector.at(right);

        if (sum == targetNum) {
            return std::make_tuple(intVector.at(left), intVector.at(right));
        }
        if (sum < targetNum) {
            left += 1;
        } else {
            right -= 1;
        }

    }
    std::cout << "No element pair found that adds up to target \n";
    return std::nullopt;
}

bool TwoPointer::isPalindrome(std::string word) {

    int left = 0;
    int right = word.length() - 1;

    while (left < right) {
        if (word[left] != word[right]) {
            return false;
        }
        left += 1;
        right -= 1;
    }
    return true;
}