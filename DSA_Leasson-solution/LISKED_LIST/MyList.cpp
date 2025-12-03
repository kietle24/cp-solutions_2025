#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
};

Node* CreateNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->next = nullptr ; 
    return p;
}

Node* insertFirst(Node* head, int x) {
    Node* temp = CreateNode(x);
    temp->next = head;
    return temp;
}

Node* insertLast(Node* head, int x) {
    Node* temp = CreateNode(x);
    if (head == nullptr) {
        return temp;
    }
    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

int size(Node* head) {
    int cnt = 0;
    while (head != nullptr) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

Node* insertMiddle(Node* head, int x, int pos) {
    int n = size(head);
    if (pos <= 0 || pos > n + 1) {
        cout << "Vi tri chen khong hop le\n";
        return head;
    }
    if (pos == 1) {
        return insertFirst(head, x);
    }
    if (pos == n + 1) {
        return insertLast(head, x);
    }
    Node* curr = head;
    for (int i = 1; i < pos - 1; i++) {
        curr = curr->next;
    }
    Node* tmp = CreateNode(x);
    tmp->next = curr->next;
    curr->next = tmp;
    return head;
}

Node* deleteFirst(Node* head) {
    if (head == nullptr) return nullptr;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deleteLast(Node* head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* curr = head;
    while (curr->next->next != nullptr) {
        curr = curr->next;
    }
    delete curr->next;
    curr->next = nullptr;
    return head;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}

int main() {
    Node* head = nullptr;
    head = insertLast(head, 10);
    head = insertLast(head, 20);
    head = insertLast(head, 30);
    printList(head);
cout << "Them Dau " << " " << endl ; 
    head = insertFirst(head, 5);
    printList(head);
cout << "Them Duoi" << " " << endl ; 
	head = insertLast(head , 19) ;
	printList(head) ; 
cout<<"Them vao giua " <<" "<< endl; 
    head = insertMiddle(head, 15, 3);
    printList(head);
cout << "Xoa Dau" << " " << endl ; 
    head = deleteFirst(head);
    printList(head);
cout << "Xoa Duoi" << endl ; 
    head = deleteLast(head);
    printList(head);
    return 0;
}
