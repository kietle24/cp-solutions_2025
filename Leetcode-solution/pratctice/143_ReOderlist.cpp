#include<bits/stdc++.h>
using namespace std;
// I feel it is easy to sort out one's life than sorting a linked list😵‍💫
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(NULL) {}
      ListNode(int x) : val(x), next(NULL) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;

        // Step 1: Find middle
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (p2->next != NULL && p2->next->next != NULL) {
            p1 = p1->next;
            p2 = p2->next->next;
        }

        // Step 2: Reverse the second half in-place (starting after p1)
        ListNode* preMiddle = p1;
        ListNode* preCurrent = p1->next;
        while (preCurrent != NULL && preCurrent->next != NULL) {
            ListNode* current = preCurrent->next;
            preCurrent->next = current->next;
            current->next = preMiddle->next;
            preMiddle->next = current;
        }

        // Step 3: Merge two halves
        p1 = head;
        p2 = preMiddle->next;
        while (p1 != preMiddle && p2 != NULL) {
            preMiddle->next = p2->next;
            p2->next = p1->next;
            p1->next = p2;

            p1 = p2->next;
            p2 = preMiddle->next;
        }
    }
};

int main () { 
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    sol.reorderList(head);

    ListNode* current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}
