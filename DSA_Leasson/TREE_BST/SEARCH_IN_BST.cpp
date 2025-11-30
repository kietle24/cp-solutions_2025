#include<bits/stdc++.h>
using namespace std ; 

// --- Định nghĩa cấu trúc Node ---
struct Node { 
    int key ; 
    Node* left ,* right ; 
    Node(int x ) { 
        key = x; 
        left = right = nullptr ; 
    }
};

// --- Hàm tìm kiếm (Search) ---
bool search(Node* root , int x ) { 
    // Phương pháp lặp (Iterative) thường hiệu quả hơn, nhưng đệ quy cũng đúng
    if(root == nullptr ) { 
        return false ; 
    }else if (root->key == x ) { // Tìm thấy
        return true; 
    }else if (root->key > x ) { 
        return search(root->left, x ) ; // Tìm bên trái
    }else { // root->key < x
        return search(root->right, x ) ; // Tìm bên phải
    }
}
// --- Hàm chèn Node (InsertNode) ---
// CHÚ Ý: Hàm phải luôn trả về con trỏ root (có thể đã được thay đổi)
Node* InsertNode(Node* root , int x ) { 
    if(root == nullptr ) {
        // Nếu tìm thấy vị trí chèn, trả về Node mới
        return new Node(x) ;
    } 
    
    if ( x < root->key ) { 
        // Gán lại con trỏ left bằng kết quả của lời gọi đệ quy (Node mới hoặc root cũ)
        root->left = InsertNode(root->left , x ) ; 
    }else if ( x > root->key ) { 
        // Gán lại con trỏ right bằng kết quả của lời gọi đệ quy
        root->right = InsertNode(root->right ,x ) ; 
    }else { 
        // Xử lý trường hợp key đã tồn tại (Không làm gì, trả về root hiện tại)
        return root; 
    }
    
    // !!! ĐIỀU CHỈNH QUAN TRỌNG: Phải luôn trả về root của cây/cây con hiện tại
    return root; 
}

// --- Hàm chính ---
int main () { 
    Node* root = nullptr ; 
    
    // Xây dựng cây
    root = InsertNode(root , 5 );
    root = InsertNode(root, 5); // Bỏ qua vì đã tồn tại
    root = InsertNode(root, 3);
    root = InsertNode(root, 7);
    root = InsertNode(root, 1);
    root = InsertNode(root, 4);
    
    int x ;
    cout << "Nhap gia tri can tim: ";
    if (!(cin >> x)) return 1; // Xử lý lỗi nhập liệu
    
    if(search(root , x ) ) { 
        cout << "Tim thay " << x << " trong BST." ; 
    }else { 
        cout << "Khong tim thay " << x << " trong BST." ; 
    }
    
    // CHÚ Ý: Trong môi trường thực tế, bạn cần thêm hàm để giải phóng bộ nhớ (hàm DeleteTree)
    // Sau khi chương trình kết thúc, bộ nhớ sẽ tự động được giải phóng.
    
    return 0 ; 
}