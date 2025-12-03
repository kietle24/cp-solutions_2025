#include<bits/stdc++.h>
using namespace std; 
struct ListNode{ 
    int val ; 
    ListNode* next ; 
    ListNode(int x ):val(x), next(NULL) {}; 

};
void in(ListNode* head) {  
    while(head != NULL) { 
        cout << head->val ; 
if(head->next != NULL) 
cout <<"->"; 
head= head->next ; 
}
cout << endl ; 
}
class Solution{ 
     public: 
      ListNode* swapParis(ListNode *head){  
        ListNode* dummy = new ListNode(0);
        dummy->next =  head ; 
         ListNode* point = dummy ;   
         while (point->next != NULL && point->next->next != NULL ) 
         {
            ListNode* swap1 = point->next ; 
            ListNode* swap2 = point->next->next; 
            // doi 
           swap1->next = swap2->next ; 
           swap2->next = swap1 ; 
           point->next  =swap2 ; 
           point = swap1; 

         }
         return dummy->next ; 
         
      }
};

int main() { 
    Solution  sol  ; 
    ListNode* head = new ListNode(1); 
    head->next = new ListNode(2); 
    head->next ->next = new ListNode(3);
     head->next->next ->next  = new ListNode(4);
in(head) ; 
ListNode* swap  =sol.swapParis(head) ;
in(swap);  
return 0;  


}