#ifndef GREEDY_H
#define GREEDY_H

#include <vector>
#include <string>
#include <utility>

/**
 * @brief Greedy Algorithms Class
 * 
 * Implements Activity Selection Problem
 * Uses greedy approach to select maximum non-overlapping activities
 */
class Greedy {
private:
    struct Activity {
        int id;
        int start;
        int finish;
    };
    
public:
    // Activity Selection Problem
    static std::vector<int> activitySelection(const std::vector<std::pair<int, int>>& activities, 
                                               bool showSteps = false);
    
    // Coin Change Problem (Greedy version - works for standard denominations)
    static std::vector<int> coinChange(int amount, const std::vector<int>& denominations, 
                                       bool showSteps = false);
    
    // Utility methods
    static void printComplexityInfo();
    static void printActivityTable(const std::vector<std::pair<int, int>>& activities);
    
private:
    static bool compareActivities(const Activity& a, const Activity& b);
};

#endif // GREEDY_H
