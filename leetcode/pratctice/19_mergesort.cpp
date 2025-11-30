    #include<bits/stdc++.h>
    using namespace std ; 
     struct ListNode{ 
     int val ; 
     ListNode* next ;
    ListNode(int x): val(x), next(NULL) {}
     }; 
    
    class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);  // tao mot not gia de sap xep lau danh sach 
        ListNode* returnnode = head; //     dung tro returnnode de duyet va xay dung danh sach moi (dang tai head) 
//ham so sanh cac gia tri cua 2 list neu nho hon thi them vao list moi da dc sort dam bao di toi duoi cua list  
        while (l1 != NULL && l2 != NULL) { 
            if (l1->val < l2->val) {  // neu l1 gia tri cua no nho hon thi cap nhat l1 vao danh sach va dua con tro di den tiep theo de so vs l2 
                returnnode->next = l1;
                l1 = l1->next;
            } else {
                returnnode->next = l2; // tuong tu  
                l2 = l2->next;
            }
            returnnode = returnnode->next; // tiep tuc tien toi node vua them xong vong tap tiep tuc tien toi 
        }

        returnnode->next = (l1 != NULL) ? l1 : l2; // neu l1 het thi tra no ve cuoi cung k thi tra be l2 

        return head->next; // tra ve danh sach head da duoc sap xep xoa node dummy 
    }
};
void in(ListNode *node) {
    while(node != NULL ) {  
        cout << node->val << " " ; 
        node = node->next ; 

    }  
    cout << endl; 

}
int main () { 
ListNode* l1 = new ListNode(1) ; 
l1->next = new ListNode(3) ; 
l1->next->next = new ListNode(5) ; 
ListNode* l2 = new ListNode(2); 
l2->next =new ListNode(4) ; 
l2->next->next = new ListNode(6) ; 
Solution sol ;
ListNode* kq = sol.mergeTwoLists(l1, l2 ) ; 
in(kq) ;  
return 0; 
}
