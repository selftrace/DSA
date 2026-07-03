#include "SlidingWindow.hpp"
#include <iostream>
#include <unordered_set>

void SlidingWindow::nonRepeatingSubArray(const char (&charArray)[9]) {
    std::unordered_set<char> currentWindow;
    std::string longestSubstring;
    int size = sizeof(charArray) / sizeof(charArray[0]);
    int left = 0;
    int right = 0;
    int longestStart = 0;
    int longestLength = 0;
    
    while (right < size) {
        while (currentWindow.count(charArray[right])) { 
            /*while the hash set has a duplicate, remove all the characters*/
            std::cout << "Duplicate found: " << charArray[right] << " removing: " << charArray[left] << "\n";
            currentWindow.erase(charArray[left]);
            left++;
        }

        /*keep adding succeeding elements and increment right pointer index to hash set*/
        
        currentWindow.insert(charArray[right]);
        right++;

        int currentLen = right - left;
        
        if (currentLen > longestLength) {
            /*check if the length of the current window between the pointers is larger than the longest length recorded, if it is, set the new record to the current length
            and track the start of the new longest current*/
            longestLength = currentLen;
            longestStart = left;
        }
        
        std::cout << "Current window: ";
        for (int i = left; i < right; i++) {
            std::cout << charArray[i] << ",";
        }
        std::cout << "\n";
    }
    
    for (int i = longestStart; i < longestStart + longestLength; i++) {
        longestSubstring.push_back(charArray[i]);
    }
    
    std::cout << "\nLongest substring: " << longestSubstring << "\n";
};