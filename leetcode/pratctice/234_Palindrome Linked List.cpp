#include<bits/stdc++.h>
using namespace std ;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; 
class Solution {
  public:
  bool isPalindrome(ListNode* head) {
        ListNode* slow = head ; 
        ListNode* fast = head ; 
        while(fast != NULL && fast->next != NULL) {  
            fast = fast->next->next  ;
            slow = slow->next ; 
        }
        slow = reverselist(slow) ; 
        fast = head ; 
        while(slow != NULL){  
            if(fast->val != slow->val ) return false ; 
            fast = fast->next ; 
            slow = slow->next ; 
        }
         return true; 
    }
private: 

    ListNode* reverselist(ListNode* head) {
        ListNode* prev = NULL ; 
        ListNode* curr = head ; 
        while(curr != NULL){
            ListNode* next = curr->next ; 
            curr->next = prev ; 
            prev = curr ; 
            curr = next ; 
        } 
        return prev ; 
    }
};
int main () { 
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);   
    head->next->next = new ListNode(3) ; 
    head->next->next->next  = new ListNode(6) ; 
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next  = new ListNode(1);
    bool result = sol.isPalindrome(head); // bool result = sol.isPalindrome(head) ; 
    cout << (result ? "TRUE" : "NO") << endl;
return 0;
}