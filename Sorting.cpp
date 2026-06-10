#include "Sorting.h"
#include <iostream>
#include <iomanip>

int Sorting::comparisonCount = 0;
int Sorting::swapCount = 0;

void Sorting::resetCounters() {
    comparisonCount = 0;
    swapCount = 0;
}

void Sorting::printComplexityTable() {
    std::cout << "\n" << std::string(70, '=') << "\n";
    std::cout << "          TIME COMPLEXITY ANALYSIS\n";
    std::cout << std::string(70, '=') << "\n";
    std::cout << std::left << std::setw(20) << "Algorithm"
              << std::setw(20) << "Best Case"
              << std::setw(20) << "Average Case"
              << std::setw(20) << "Worst Case" << "\n";
    std::cout << std::string(70, '-') << "\n";
    std::cout << std::setw(20) << "Bubble Sort"
              << std::setw(20) << "Ω(n)"
              << std::setw(20) << "Θ(n²)"
              << std::setw(20) << "O(n²)" << "\n";
    std::cout << std::setw(20) << "Merge Sort"
              << std::setw(20) << "Ω(n log n)"
              << std::setw(20) << "Θ(n log n)"
              << std::setw(20) << "O(n log n)" << "\n";
    std::cout << std::setw(20) << "Quick Sort"
              << std::setw(20) << "Ω(n log n)"
              << std::setw(20) << "Θ(n log n)"
              << std::setw(20) << "O(n²)" << "\n";
    std::cout << std::string(70, '=') << "\n";
    std::cout << "Space Complexity:\n";
    std::cout << "- Bubble Sort: O(1)\n";
    std::cout << "- Merge Sort: O(n)\n";
    std::cout << "- Quick Sort: O(log n)\n";
    std::cout << std::string(70, '=') << "\n\n";
}

bool Sorting::isSorted(const std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i-1]) return false;
    }
    return true;
}

// ==================== BUBBLE SORT ====================
// Time Complexity: O(n²) worst case, O(n) best case (optimized)
// Space Complexity: O(1)
std::vector<int> Sorting::bubbleSort(std::vector<int> arr, bool showSteps) {
    resetCounters();
    int n = arr.size();
    bool swapped;
    
    if (showSteps) {
        std::cout << "\n--- Bubble Sort Steps ---\n";
        std::cout << "Initial array: ";
        for (int num : arr) std::cout << num << " ";
        std::cout << "\n";
    }
    
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            comparisonCount++;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapCount++;
                swapped = true;
            }
        }
        
        if (showSteps) {
            std::cout << "Pass " << i + 1 << ": ";
            for (int num : arr) std::cout << num << " ";
            std::cout << "\n";
        }
        
        // Optimization: If no swapping occurred, array is sorted
        if (!swapped) break;
    }
    
    if (showSteps) {
        std::cout << "\nBubble Sort Results:\n";
        std::cout << "Comparisons: " << comparisonCount << "\n";
        std::cout << "Swaps: " << swapCount << "\n";
    }
    
    return arr;
}

// ==================== MERGE SORT ====================
// Time Complexity: O(n log n) for all cases
// Space Complexity: O(n)
std::vector<int> Sorting::mergeSort(std::vector<int> arr, bool showSteps) {
    resetCounters();
    if (showSteps) {
        std::cout << "\n--- Merge Sort Steps ---\n";
        std::cout << "Initial array: ";
        for (int num : arr) std::cout << num << " ";
        std::cout << "\n\n";
    }
    
    std::vector<int> temp(arr.size());
    mergeSortHelper(arr, 0, arr.size() - 1, temp, showSteps);
    
    if (showSteps) {
        std::cout << "\nMerge Sort Results:\n";
        std::cout << "Comparisons: " << comparisonCount << "\n";
        std::cout << "Merges: " << swapCount << "\n";
    }
    
    return arr;
}

void Sorting::mergeSortHelper(std::vector<int>& arr, int left, int right, 
                              std::vector<int>& temp, bool showSteps) {
    if (left >= right) return;
    
    int mid = left + (right - left) / 2;
    
    // Divide step
    mergeSortHelper(arr, left, mid, temp, showSteps);
    mergeSortHelper(arr, mid + 1, right, temp, showSteps);
    
    // Conquer step - merge
    merge(arr, left, mid, right, temp, showSteps);
}

void Sorting::merge(std::vector<int>& arr, int left, int mid, int right, 
                   std::vector<int>& temp, bool showSteps) {
    int i = left;
    int j = mid + 1;
    int k = left;
    
    if (showSteps) {
        std::cout << "Merging: [";
        for (int x = left; x <= mid; x++) std::cout << arr[x] << " ";
        std::cout << "] and [";
        for (int x = mid + 1; x <= right; x++) std::cout << arr[x] << " ";
        std::cout << "]\n";
    }
    
    while (i <= mid && j <= right) {
        comparisonCount++;
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
        swapCount++;
    }
    
    // Copy remaining elements
    while (i <= mid) {
        temp[k++] = arr[i++];
        swapCount++;
    }
    
    while (j <= right) {
        temp[k++] = arr[j++];
        swapCount++;
    }
    
    // Copy back to original array
    for (int x = left; x <= right; x++) {
        arr[x] = temp[x];
    }
    
    if (showSteps) {
        std::cout << "Result: [";
        for (int x = left; x <= right; x++) std::cout << arr[x] << " ";
        std::cout << "]\n";
    }
}

// ==================== QUICK SORT ====================
// Time Complexity: O(n log n) average, O(n²) worst
// Space Complexity: O(log n) for recursion stack
std::vector<int> Sorting::quickSort(std::vector<int> arr, bool showSteps) {
    resetCounters();
    if (showSteps) {
        std::cout << "\n--- Quick Sort Steps ---\n";
        std::cout << "Initial array: ";
        for (int num : arr) std::cout << num << " ";
        std::cout << "\n\n";
    }
    
    quickSortHelper(arr, 0, arr.size() - 1, showSteps);
    
    if (showSteps) {
        std::cout << "\nQuick Sort Results:\n";
        std::cout << "Comparisons: " << comparisonCount << "\n";
        std::cout << "Swaps: " << swapCount << "\n";
    }
    
    return arr;
}

void Sorting::quickSortHelper(std::vector<int>& arr, int low, int high, bool showSteps) {
    if (low < high) {
        int pi = partition(arr, low, high, showSteps);
        
        if (showSteps) {
            std::cout << "Pivot placed at index " << pi << "\n";
        }
        
        quickSortHelper(arr, low, pi - 1, showSteps);
        quickSortHelper(arr, pi + 1, high, showSteps);
    }
}

int Sorting::partition(std::vector<int>& arr, int low, int high, bool showSteps) {
    // Choose pivot (using median-of-three for better performance)
    int pivot = arr[high];
    int i = low - 1;
    
    if (showSteps) {
        std::cout << "Partitioning [" << low << ".." << high 
                  << "] with pivot: " << pivot << "\n";
    }
    
    for (int j = low; j < high; j++) {
        comparisonCount++;
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
            swapCount++;
        }
    }
    
    std::swap(arr[i + 1], arr[high]);
    swapCount++;
    
    if (showSteps) {
        std::cout << "After partition: ";
        for (int x = low; x <= high; x++) std::cout << arr[x] << " ";
        std::cout << "\n";
    }
    
    return i + 1;
}
