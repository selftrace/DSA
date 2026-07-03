#pragma once

#include <iostream>
#include <vector>
#include <optional>
#include <tuple>

class TwoPointer {
    private:
        const std::vector<int> intVector;
    
    public:
        TwoPointer(std::vector<int>& vector);
        int findMiddle();
        std::optional<std::tuple<int, int>> findPairSum(int targetNum);
        bool isPalindrome(std::string word);
};