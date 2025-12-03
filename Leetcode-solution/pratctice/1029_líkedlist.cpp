#include<bits/stdc++.h>
using namespace std ;
    struct ListNode{ 
     int val ; 
     ListNode* next ;
    ListNode(int x): val(x), next(NULL) {}
     }; 
 class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int num = 0; 
        while (head) {
            num = (num << 1) | head->val; 
            head = head->next;
        }
        return num;
    }
};
int main() { 
    Solution = sol ;
    ListNode* head = new ListNode(1) ; 
    head->next = new ListNode(0) ; 
    head->next = new ListNode(1) ; 



}