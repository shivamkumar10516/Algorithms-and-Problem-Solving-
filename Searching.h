#ifndef SEARCHING_H
#define SEARCHING_H

#include <vector>
#include <string>

/**
 * @brief Searching Algorithms Class
 * 
 * Implements Linear Search and Binary Search
 * with performance metrics and complexity analysis
 */
class Searching {
private:
    static int comparisonCount;
    
public:
    // Linear Search - O(n)
    static int linearSearch(const std::vector<int>& arr, int target, bool showSteps = false);
    
    // Binary Search - O(log n) (requires sorted array)
    static int binarySearch(const std::vector<int>& arr, int target, bool showSteps = false);
    
    // Utility methods
    static void resetCounters();
    static void printComplexityTable();
    static std::string searchResultToString(int index, int target);
    
private:
    static int binarySearchHelper(const std::vector<int>& arr, int left, int right, 
                                  int target, bool showSteps);
};

#endif // SEARCHING_H
