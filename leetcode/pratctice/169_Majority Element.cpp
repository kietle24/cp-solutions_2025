#include<bits/stdc++.h>
using namespace std ; 
int sx(vector<int>& nums)  { 
sort(nums.begin(), nums.end()) ; 
int n = nums.size()  ; 
return nums[n/2] ;

}
int main () {
int n ; 
cin >> n; 
vector<int>nums(n) ;
for(int i  = 0 ; i < n ;i++){
	cin >> nums[i] ; 
}
int kq = sx(nums) ; 
cout << kq <<"" ; 
}