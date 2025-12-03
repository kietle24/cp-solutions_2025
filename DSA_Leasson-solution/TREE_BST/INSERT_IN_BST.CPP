#include<bits/stdc++.h>
using namespace std  ; 
struct Node { 
     int val ; 
     Node* left , * right  ; 
     Node(int x ) {
             val = x  ; 
             right = left = nullptr ; 
     }
};
Node* insert(Node* root , int x ) { 
    if(root == nullptr) {  
        return new Node(x) ; 
    } 
    else if (root->val < x ) { 
         root->right = insert(root->right  ,x) ; 
    }else if (root->val  > x ) { 
         root->left = insert(root->left    ,x) ; 
    }
        return root ;     
}
// NAR 
void incay(Node* root ) { 
    if(root == nullptr ) return ; 
    incay(root->left ) ; 
    cout << root->val << " " ; 
    incay(root->right ) ;
}
int main () { 
     Node* root = nullptr ; 
    root = insert(root, 5 )  ; 
    root  = insert(root,1); 
    root = insert(root, 4);
    cout << " sau node chen cay moi ";
    incay(root) ; 
    return 0; 
}