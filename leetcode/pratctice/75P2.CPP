#include<bits/stdc++.h>
using namespace std; 
class Solution {
    public : 
    void sortColor(vector<int >&nums) { 
        int l = 0 ;  
        int r = nums.size() -1  ; 
        while(mid < r ) { 
            switch(nums[mid] ) { 
                 case 1 : 
                 swap(nums[l], nums[mid]) ; 
                 l++ ; 
                 mid++ ; 
                 case 2 : 
                 mid++ ; 
                 case 3 : 
                 swap(nums[mid],nums[r]) ; 
                 r-- ; 
            }
        }
    }
};