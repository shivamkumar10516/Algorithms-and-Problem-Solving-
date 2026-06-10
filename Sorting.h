#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <string>

/**
 * @brief Sorting Algorithms Class
 * 
 * Implements Bubble Sort, Merge Sort, and Quick Sort
 * with detailed step tracking and complexity analysis
 */
class Sorting {
private:
    static int comparisonCount;
    static int swapCount;
    
public:
    // Bubble Sort - O(n²)
    static std::vector<int> bubbleSort(std::vector<int> arr, bool showSteps = false);
    
    // Merge Sort - O(n log n)
    static std::vector<int> mergeSort(std::vector<int> arr, bool showSteps = false);
    
    // Quick Sort - O(n log n) average, O(n²) worst
    static std::vector<int> quickSort(std::vector<int> arr, bool showSteps = false);
    
    // Utility methods
    static void resetCounters();
    static void printComplexityTable();
    static bool isSorted(const std::vector<int>& arr);
    
private:
    // Helper methods for Merge Sort
    static void mergeSortHelper(std::vector<int>& arr, int left, int right, 
                                std::vector<int>& temp, bool showSteps);
    static void merge(std::vector<int>& arr, int left, int mid, int right, 
                     std::vector<int>& temp, bool showSteps);
    
    // Helper methods for Quick Sort
    static void quickSortHelper(std::vector<int>& arr, int low, int high, bool showSteps);
    static int partition(std::vector<int>& arr, int low, int high, bool showSteps);
};

#endif // SORTING_H
