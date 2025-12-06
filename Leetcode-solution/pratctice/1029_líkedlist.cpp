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
