#include "Searching.h"
#include <iostream>
#include <iomanip>

int Searching::comparisonCount = 0;

void Searching::resetCounters() {
    comparisonCount = 0;
}

void Searching::printComplexityTable() {
    std::cout << "\n" << std::string(70, '=') << "\n";
    std::cout << "          SEARCHING COMPLEXITY ANALYSIS\n";
    std::cout << std::string(70, '=') << "\n";
    std::cout << std::left << std::setw(20) << "Algorithm"
              << std::setw(25) << "Time Complexity"
              << std::setw(25) << "Space Complexity" << "\n";
    std::cout << std::string(70, '-') << "\n";
    std::cout << std::setw(20) << "Linear Search"
              << std::setw(25) << "O(n)"
              << std::setw(25) << "O(1)" << "\n";
    std::cout << std::setw(20) << "Binary Search"
              << std::setw(25) << "O(log n)"
              << std::setw(25) << "O(1)" << "\n";
    std::cout << std::string(70, '=') << "\n";
    std::cout << "Note: Binary Search requires a SORTED array!\n";
    std::cout << std::string(70, '=') << "\n\n";
}

std::string Searching::searchResultToString(int index, int target) {
    if (index != -1) {
        return "Element " + std::to_string(target) + " found at index " + 
               std::to_string(index);
    } else {
        return "Element " + std::to_string(target) + " not found in the array";
    }
}

// ==================== LINEAR SEARCH ====================
// Time Complexity: O(n) - worst and average case
// Best Case: O(1) - element found at first position
// Space Complexity: O(1)
int Searching::linearSearch(const std::vector<int>& arr, int target, bool showSteps) {
    resetCounters();
    
    if (showSteps) {
        std::cout << "\n--- Linear Search Steps ---\n";
        std::cout << "Searching for: " << target << "\n";
        std::cout << "Array: ";
        for (int num : arr) std::cout << num << " ";
        std::cout << "\n\n";
    }
    
    for (size_t i = 0; i < arr.size(); i++) {
        comparisonCount++;
        
        if (showSteps) {
            std::cout << "Step " << i + 1 << ": Comparing arr[" << i 
                      << "] = " << arr[i] << " with target " << target;
        }
        
        if (arr[i] == target) {
            if (showSteps) {
                std::cout << " ✓ MATCH FOUND!\n";
                std::cout << "\nLinear Search Completed!\n";
                std::cout << "Total comparisons: " << comparisonCount << "\n";
            }
            return i;
        }
        
        if (showSteps) {
            std::cout << " ✗ No match\n";
        }
    }
    
    if (showSteps) {
        std::cout << "\nLinear Search Completed!\n";
        std::cout << "Element not found after " << comparisonCount << " comparisons\n";
    }
    
    return -1;
}

// ==================== BINARY SEARCH ====================
// Time Complexity: O(log n) - worst and average case
// Best Case: O(1) - element found at middle
// Space Complexity: O(1) iterative, O(log n) recursive
int Searching::binarySearch(const std::vector<int>& arr, int target, bool showSteps) {
    resetCounters();
    
    if (showSteps) {
        std::cout << "\n--- Binary Search Steps ---\n";
        std::cout << "Searching for: " << target << "\n";
        std::cout << "Array (must be sorted): ";
        for (int num : arr) std::cout << num << " ";
        std::cout << "\n\n";
    }
    
    return binarySearchHelper(arr, 0, arr.size() - 1, target, showSteps);
}

int Searching::binarySearchHelper(const std::vector<int>& arr, int left, int right, 
                                  int target, bool showSteps) {
    if (left > right) {
        if (showSteps) {
            std::cout << "Search space exhausted. Element not found!\n";
            std::cout << "Total comparisons: " << comparisonCount << "\n";
        }
        return -1;
    }
    
    int mid = left + (right - left) / 2;
    comparisonCount++;
    
    if (showSteps) {
        std::cout << "Searching in range [" << left << ".." << right 
                  << "], mid = " << mid << ", arr[" << mid << "] = " << arr[mid] << "\n";
        std::cout << "Comparing " << arr[mid] << " with target " << target << ": ";
    }
    
    if (arr[mid] == target) {
        if (showSteps) {
            std::cout << "MATCH!\n";
            std::cout << "\nBinary Search Completed!\n";
            std::cout << "Total comparisons: " << comparisonCount << "\n";
        }
        return mid;
    }
    
    if (showSteps) {
        std::cout << (arr[mid] < target ? "Target is larger" : "Target is smaller") << "\n";
    }
    
    if (arr[mid] < target) {
        return binarySearchHelper(arr, mid + 1, right, target, showSteps);
    } else {
        return binarySearchHelper(arr, left, mid - 1, target, showSteps);
    }
}
