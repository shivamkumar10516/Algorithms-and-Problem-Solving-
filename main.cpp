#include "Sorting.h"
#include "Searching.h"
#include "Greedy.h"
#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

// Function prototypes
void displayMainMenu();
void displaySortingMenu();
void displaySearchingMenu();
void displayGreedyMenu();
void displayComplexityMenu();
vector<int> getArrayFromUser();
void printArray(const vector<int>& arr, const string& title = "Array");
void waitForEnter();

int main() {
    int choice;
    vector<int> currentArray;
    
    cout << "\n╔══════════════════════════════════════════════════════════════╗\n";
    cout << "║     ALGORITHMS & PROBLEM SOLVING PROJECT v1.0               ║\n";
    cout << "║     Sorting | Searching | Greedy Algorithms                 ║\n";
    cout << "╚══════════════════════════════════════════════════════════════╝\n";
    
    do {
        displayMainMenu();
        cout << "Enter your choice (1-6): ";
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }
        
        switch (choice) {
            case 1:
                displaySortingMenu();
                break;
            case 2:
                displaySearchingMenu();
                break;
            case 3:
                displayGreedyMenu();
                break;
            case 4:
                displayComplexityMenu();
                break;
            case 5:
                // Generate random array for testing
                currentArray.clear();
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<> dis(1, 100);
                for (int i = 0; i < 10; i++) {
                    currentArray.push_back(dis(gen));
                }
                cout << "\n✓ Random test array generated!\n";
                printArray(currentArray, "Test Array");
                waitForEnter();
                break;
            case 6:
                cout << "\nThank you for using Algorithms & Problem Solving Project!\n";
                cout << "Exiting...\n\n";
                break;
            default:
                cout << "Invalid choice! Please enter number between 1 and 6.\n";
        }
        
    } while (choice != 6);
    
    return 0;
}

void displayMainMenu() {
    cout << "\n" << string(60, '=') << "\n";
    cout << "                    MAIN MENU\n";
    cout << string(60, '=') << "\n";
    cout << "1. Sorting Algorithms\n";
    cout << "2. Searching Algorithms\n";
    cout << "3. Greedy Algorithms\n";
    cout << "4. Complexity Analysis\n";
    cout << "5. Generate Random Test Array\n";
    cout << "6. Exit\n";
    cout << string(60, '=') << "\n";
}

void displaySortingMenu() {
    int choice;
    vector<int> arr, result;
    bool showSteps;
    
    do {
        cout << "\n" << string(60, '-') << "\n";
        cout << "              SORTING ALGORITHMS\n";
        cout << string(60, '-') << "\n";
        cout << "1. Bubble Sort (O(n²))\n";
        cout << "2. Merge Sort (O(n log n))\n";
        cout << "3. Quick Sort (O(n log n))\n";
        cout << "4. Compare All Sorting Algorithms\n";
        cout << "5. Back to Main Menu\n";
        cout << string(60, '-') << "\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        
        if (choice >= 1 && choice <= 3) {
            arr = getArrayFromUser();
            cout << "\nShow step-by-step execution? (1-Yes / 0-No): ";
            cin >> showSteps;
            
            cout << "\nOriginal ";
            printArray(arr);
            
            auto start = chrono::high_resolution_clock::now();
            
            switch (choice) {
                case 1:
                    result = Sorting::bubbleSort(arr, showSteps);
                    cout << "\n✓ Bubble Sort Complete!\n";
                    break;
                case 2:
                    result = Sorting::mergeSort(arr, showSteps);
                    cout << "\n✓ Merge Sort Complete!\n";
                    break;
                case 3:
                    result = Sorting::quickSort(arr, showSteps);
                    cout << "\n✓ Quick Sort Complete!\n";
                    break;
            }
            
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            
            cout << "\nSorted ";
            printArray(result);
            cout << "Execution time: " << duration.count() << " microseconds\n";
            cout << "Is array sorted? " << (Sorting::isSorted(result) ? "✓ Yes" : "✗ No") << "\n";
            waitForEnter();
            
        } else if (choice == 4) {
            arr = getArrayFromUser();
            cout << "\nComparing all sorting algorithms on same data:\n";
            cout << string(60, '=') << "\n";
            
            vector<int> arr1 = arr, arr2 = arr, arr3 = arr;
            
            auto start1 = chrono::high_resolution_clock::now();
            vector<int> bubbleResult = Sorting::bubbleSort(arr1, false);
            auto end1 = chrono::high_resolution_clock::now();
            auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);
            
            auto start2 = chrono::high_resolution_clock::now();
            vector<int> mergeResult = Sorting::mergeSort(arr2, false);
            auto end2 = chrono::high_resolution_clock::now();
            auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);
            
            auto start3 = chrono::high_resolution_clock::now();
            vector<int> quickResult = Sorting::quickSort(arr3, false);
            auto end3 = chrono::high_resolution_clock::now();
            auto duration3 = chrono::duration_cast<chrono::microseconds>(end3 - start3);
            
            cout << "\nAlgorithm     | Time (microseconds) | Sorted Correctly\n";
            cout << string(60, '-') << "\n";
            cout << "Bubble Sort   | " << duration1.count() << "                 | " 
                 << (Sorting::isSorted(bubbleResult) ? "Yes" : "No") << "\n";
            cout << "Merge Sort    | " << duration2.count() << "                 | " 
                 << (Sorting::isSorted(mergeResult) ? "Yes" : "No") << "\n";
            cout << "Quick Sort    | " << duration3.count() << "                 | " 
                 << (Sorting::isSorted(quickResult) ? "Yes" : "No") << "\n";
            cout << string(60, '=') << "\n";
            waitForEnter();
        }
        
    } while (choice != 5);
}

void displaySearchingMenu() {
    int choice, target, result;
    vector<int> arr;
    bool showSteps;
    
    do {
        cout << "\n" << string(60, '-') << "\n";
        cout << "             SEARCHING ALGORITHMS\n";
        cout << string(60, '-') << "\n";
        cout << "1. Linear Search (O(n))\n";
        cout << "2. Binary Search (O(log n))\n";
        cout << "3. Compare Search Algorithms\n";
        cout << "4. Back to Main Menu\n";
        cout << string(60, '-') << "\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        
        if (choice == 1 || choice == 2) {
            arr = getArrayFromUser();
            
            if (choice == 2) {
                cout << "\n⚠️  Note: Binary Search requires a SORTED array!\n";
                cout << "Sort the array first? (1-Yes / 0-No): ";
                int sortChoice;
                cin >> sortChoice;
                if (sortChoice == 1
