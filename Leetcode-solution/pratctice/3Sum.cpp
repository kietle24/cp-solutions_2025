#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution { 
public:  
    vector<vector<int>> threeSum(vector<int>& nums) { 
        if(nums.size() < 3) {  
            return vector<vector<int>>(); 
        }
        set<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size() - 2; i++) {
            int l = i + 1;
            int r = nums.size() - 1;
            
            while(l < r) { 
                int sum = nums[i] + nums[l] + nums[r]; 
                if(sum == 0) {
                    result.insert({nums[i], nums[l], nums[r]});
                    l++;  
                    r--;
                } else if(sum < 0) { 
                    l++;
                } else { 
                    r--;
                }
            }
        }
        return vector<vector<int>>(result.begin(), result.end());
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result1 = solution.threeSum(nums1);
    cout << "Test 1: [-1,0,1,2,-1,-4]" << endl;
    for(const auto& triplet : result1) {
        cout << "[" << triplet[0] << "," << triplet[1] << "," << triplet[2] << "]" << endl;
    }
    
    // Test case 2
    vector<int> nums2 = {0, 1, 1};
    vector<vector<int>> result2 = solution.threeSum(nums2);
    cout << "\nTest 2: [0,1,1]" << endl;
    cout << "Result size: " << result2.size() << endl;
    
    // Test case 3
    vector<int> nums3 = {0, 0, 0};
    vector<vector<int>> result3 = solution.threeSum(nums3);
    cout << "\nTest 3: [0,0,0]" << endl;
    for(const auto& triplet : result3) {
        cout << "[" << triplet[0] << "," << triplet[1] << "," << triplet[2] << "]" << endl;
    }
    
    return 0;
}