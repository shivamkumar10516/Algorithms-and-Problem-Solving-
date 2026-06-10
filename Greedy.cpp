#include "Greedy.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

// ==================== ACTIVITY SELECTION ====================
// Greedy Strategy: Always pick the activity with earliest finish time
// Time Complexity: O(n log n) for sorting, O(n) for selection
// Space Complexity: O(n)
std::vector<int> Greedy::activitySelection(const std::vector<std::pair<int, int>>& activities, 
                                           bool showSteps) {
    if (activities.empty()) {
        return {};
    }
    
    std::vector<Activity> actList;
    for (size_t i = 0; i < activities.size(); i++) {
        actList.push_back({static_cast<int>(i), activities[i].first, activities[i].second});
    }
    
    // Sort activities by finish time
    std::sort(actList.begin(), actList.end(), 
        [](const Activity& a, const Activity& b) {
            return a.finish < b.finish;
        });
    
    if (showSteps) {
        std::cout << "\n" << std::string(70, '=') << "\n";
        std::cout << "        ACTIVITY SELECTION PROBLEM\n";
        std::cout << std::string(70, '=') << "\n";
        std::cout << "Activities sorted by finish time:\n";
        std::cout << std::left << std::setw(10) << "Activity"
                  << std::setw(15) << "Start"
                  << std::setw(15) << "Finish" << "\n";
        std::cout << std::string(40, '-') << "\n";
        for (const auto& act : actList) {
            std::cout << std::setw(10) << act.id
                      << std::setw(15) << act.start
                      << std::setw(15) << act.finish << "\n";
        }
        std::cout << "\nApplying Greedy Strategy (Earliest Finish Time First):\n";
    }
    
    std::vector<int> selected;
    int lastFinish = -1;
    
    for (const auto& act : actList) {
        if (showSteps) {
            std::cout << "\nChecking Activity " << act.id 
                      << " [Start: " << act.start << ", Finish: " << act.finish << "]: ";
        }
        
        if (act.start >= lastFinish) {
            selected.push_back(act.id);
            lastFinish = act.finish;
            
            if (showSteps) {
                std::cout << "SELECTED! (Start time >= last finish time)\n";
            }
        } else {
            if (showSteps) {
                std::cout << "REJECTED! (Start time < last finish time)\n";
            }
        }
    }
    
    if (showSteps) {
        std::cout << "\n" << std::string(70, '-') << "\n";
        std::cout << "Total activities selected: " << selected.size() 
                  << " out of " << activities.size() << "\n";
        std::cout << "Selected activity indices: ";
        for (size_t i = 0; i < selected.size(); i++) {
            std::cout << selected[i];
            if (i < selected.size() - 1) std::cout << ", ";
        }
        std::cout << "\n" << std::string(70, '=') << "\n";
    }
    
    return selected;
}

// ==================== COIN CHANGE (GREEDY) ====================
// Greedy Strategy: Always take the largest denomination possible
// Time Complexity: O(amount / min_denomination)
// Note: Works optimally for standard coin systems (US, Indian, Euro)
std::vector<int> Greedy::coinChange(int amount, const std::vector<int>& denominations, 
                                    bool showSteps) {
    if (amount <= 0) {
        return {};
    }
    
    std::vector<int> sortedDenoms = denominations;
    std::sort(sortedDenoms.begin(), sortedDenoms.end(), std::greater<int>());
    
    if (showSteps) {
        std::cout << "\n" << std::string(70, '=') << "\n";
        std::cout << "        COIN CHANGE PROBLEM (Greedy Approach)\n";
        std::cout << std::string(70, '=') << "\n";
        std::cout << "Amount to make: " << amount << "\n";
        std::cout << "Available denominations: ";
        for (size_t i = 0; i < denominations.size(); i++) {
            std::cout << denominations[i];
            if (i < denominations.size() - 1) std::cout << ", ";
        }
        std::cout << "\n\nApplying Greedy Strategy (Largest First):\n";
        std::cout << std::string(70, '-') << "\n";
    }
    
    std::vector<int> usedCoins;
    int remaining = amount;
    
    for (int denom : sortedDenoms) {
        int count = remaining / denom;
        if (count > 0) {
            for (int i = 0; i < count; i++) {
                usedCoins.push_back(denom);
            }
            
            if (showSteps) {
                std::cout << "Take " << count << " x " << denom 
                          << " = " << (count * denom) << "\n";
                std::cout << "Remaining: " << (remaining - count * denom) << "\n";
            }
            
            remaining %= denom;
        }
        
        if (remaining == 0) break;
    }
    
    if (showSteps) {
        std::cout << std::string(70, '-') << "\n";
        if (remaining == 0) {
            std::cout << "Success! Made exact amount using " << usedCoins.size() 
                      << " coins.\n";
            std::cout << "Coins used: ";
            for (size_t i = 0; i < usedCoins.size(); i++) {
                std::cout << usedCoins[i];
                if (i < usedCoins.size() - 1) std::cout << ", ";
            }
            std::cout << "\n";
        } else {
            std::cout << "Cannot make exact amount with given denominations!\n";
            std::cout << "Remaining amount: " << remaining << "\n";
        }
        std::cout << std::string(70, '=') << "\n";
    }
    
    return usedCoins;
}

void Greedy::printComplexityInfo() {
    std::cout << "\n" << std::string(70, '=') << "\n";
    std::cout << "          GREEDY ALGORITHMS - COMPLEXITY\n";
    std::cout << std::string(70, '=') << "\n";
    std::cout << "Activity Selection:\n";
    std::cout << "  - Time: O(n log n) for sorting + O(n) for selection\n";
    std::cout << "  - Space: O(n) for storing activities\n";
    std::cout << "  - Greedy Choice: Pick activity with earliest finish time\n\n";
    
    std::cout << "Coin Change (Greedy):\n";
    std::cout << "  - Time: O(n log n) for sorting + O(amount/min_denom)\n";
    std::cout << "  - Space: O(1) extra space\n";
    std::cout << "  - Greedy Choice: Always pick largest denomination\n";
    std::cout << "  - Note: Optimal for standard coin systems\n";
    std::cout << std::string(70, '=') << "\n\n";
}

void Greedy::printActivityTable(const std::vector<std::pair<int, int>>& activities) {
    std::cout << std::left << std::setw(10) << "Activity"
              << std::setw(15) << "Start Time"
              << std::setw(15) << "Finish Time" << "\n";
    std::cout << std::string(40, '-') << "\n";
    for (size_t i = 0; i < activities.size(); i++) {
        std::cout << std::setw(10) << i
                  << std::setw(15) << activities[i].first
                  << std::setw(15) << activities[i].second << "\n";
    }
}
