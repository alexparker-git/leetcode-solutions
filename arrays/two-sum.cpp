// Problem: Two Sum
// Link: https://leetcode.com/problems/two-sum/
// Difficulty: Easy
// Runtime: 2 ms | Memory: 14.8 MB
// Approach: used the map

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // Stores {number : index}
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // Check if the complement was already visited
            if (seen.find(complement) != seen.end()) {
                return {seen[complement], i};
            }
            
            // Store current number and index for future lookups
            seen[nums[i]] = i;
        }
        
        return {};
    }
};


// ---------- Solution 2 ----------
// Runtime: 0 ms | Memory: 14.7 MB
// Approach: used the map

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         vector<pair<int, int>> indexedNums;
        for (int i = 0; i < nums.size(); ++i) {
            indexedNums.push_back({nums[i], i});
        }
        
        // Sort based on the values
        sort(indexedNums.begin(), indexedNums.end());
        
        int left = 0;
        int right = indexedNums.size() - 1;
        
        while (left < right) {
            int sum = indexedNums[left].first + indexedNums[right].first;
            if (sum == target) {
                return {indexedNums[left].second, indexedNums[right].second};
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }
        return {};
    }
};
