/*
Given a string s, return the longest palindromic substring in s
Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"

*/
#include<bits/stdc++.h>
using namespace std ;  
int palindrome(string & s ){  
     int  l= 0 ; 
     int r = s.size() -1 ; 
     while( l  <r  ) { 
        if(s[l]  != s[r ]) { 
             l++ ; 
             r-- ; 
        }
        return false ; 
     }
     return true ; 
}

 