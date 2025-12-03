#include<bits/stdc++.h>
using namespace std ; 
struct Node  { 
     int val ; 
     Node* left , * right ; 
     Node(int x) { 
        val =x ; 
        left = right = nullptr ;       
     }
};
Node* floor(Node *root , int x) {  
    Node* res = nullptr ;  // khia bao bien res hien tai dang null 
    while(root != nullptr){   // khien trai cho root chay 
        if (root->val == x ) {   // n
            return root; 
        }else if (root->val > x )   { 
             root = root-> left  ; 
        }else { 
            res = root ;  
            root =  root->right ;
        }
    }
    return res; 
}
Node* insert(Node* root , int x ) { 
    if (root = nullptr ) { 
        return new Node(x) ; 
    }
    if(root->val < x) { 
        root->left = insert(root->left ,x ) ; 
    }else  { 
        root->right =insert(root->right , x ) ;         
    }
    return root ; 
}
void inorder(Node* root ) {  
    if(root == nullptr  ) return ; 
    inorder(root->left) ; 
    cout << root->val << " " ; 
    inorder(root->right) ;
}
int main () {  
    Node* root = nullptr; 
    root = insert(root, 10) ; 
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 12);
    insert(root, 20);
}





























/*
Cây BST:        10
              /    \
             5      15
            / \    /  \
           3   7  12  20

- floor(root, 6)  → 5  (5 là số lớn nhất ≤ 6)
- floor(root, 15) → 15 (tìm chính xác)
- floor(root, 2)  → nullptr (không có số nào ≤ 2)
- floor(root, 14) → 12 (12 là số lớn nhất ≤ 14)
`







*/