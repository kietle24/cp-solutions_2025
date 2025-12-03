#include<bits/stdc++.h>
using namespace std ; 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:

    ListNode *detectCycle(ListNode *head){
    if (head == NULL || head->next == NULL) return NULL ; 
         ListNode* slow = head ; 
         ListNode* fast = head ;
         while (fast != NULL && fast->next != NULL) {  
            slow = slow->next ; 
            fast = fast->next->next ; 
            if(slow == fast ) { 
            break ; 
            }
     }
     if(fast == NULL || fast->next ==NULL ) {
        return NULL ; 
     }
        fast = head ; 
        while(fast != slow) { 
            fast = fast -> next ; 
            slow = slow -> next ; 
        }
return fast;  
    }
};
int main() { 
    Solution sol;
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Creating a cycle

    ListNode* cycleStart = sol.detectCycle(head);
    if (cycleStart) {
        cout << "Cycle detected at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}