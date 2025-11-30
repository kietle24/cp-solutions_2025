#include<bits/stdc++.h>
using namespace std ; 
string largestNumber(vector<int>& nums) {
//chuyen doi gia tri so thanh gia tri chu de so sanh trong thuat toan 
vector<string> arr ; 
for(int n : nums ) arr.push_back(to_string(n)) ; 
//sap xep no lai 
sort(arr.begin(), arr.end(), [](const string &a, const string &b) { 
    return a + b > b + a; // check kiem tra so thu tu sap xep de xep thoa man dieu kien 
});
if (arr[0] == "0") return "0"; // neu ham do bang 0 thi tat cac cac day do bang 0  
string result; 
for (string &s : arr) {  // sap xep lai chuoi so arr 
    result += s; 
}
return result;
}

int main () { 
    vector<int> nums = {3,30,34,5,9 } ; 
    string str = largestNumber(nums) ; 
    cout <<"chuoi lon nhat "<< str  << endl ; 
    return 0; 
}