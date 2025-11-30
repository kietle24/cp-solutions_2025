#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
	if(nums.size() <=1 ) return false ; 
	sort(nums.begin(),nums.end())  ;
	int l = 0  ; 
	int r = 1 ;  
	while(nums[r] < nums.size())  { 
	if(nums[l] == nums[r]) { 
	return true; 
	}
	l++ ; 
	r++ ; 
	}     
	return false  ;   
    }
};
int main () {
	 int n ; 
	 cin >> n; 
	 vector<int>nums(n) ; 
	 for(int i =0 ; i < n ; i++) {
	 	cin >> nums[i] ; 
	 } 
	 Solution sol ; 
	 bool kq = sol.containsDuplicate(nums);
	 cout << kq ; 
	 return 0 ;  
}