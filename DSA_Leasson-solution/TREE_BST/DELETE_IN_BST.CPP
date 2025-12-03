 static const bool __boost = []() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	return std::ios_base::sync_with_stdio(false);
	}();

const size_t BUFFER_SIZE = 0x6fafffff;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;
void* operator new(size_t size) {
	constexpr std::size_t alignment = alignof(std::max_align_t);
	size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
	size_t total_size = size + padding;
	char* aligned_ptr = &buffer[buffer_pos + padding];
	buffer_pos += total_size;
	return aligned_ptr
}
void operator delete(void* ptr, unsigned long) {}
void operator delete(void* ptr) {}
void operator delete[](void* ptr) {}

class Solution  { 
public  : 
TreeNode* minValueNode(TreeNode* node) {
    TreeNode* curr = node;
    while (curr && curr->left) {
        curr = curr->left;
    }
    return curr;
}

TreeNode* deleteNode(TreeNode* root, int x) {
    if (!root) return nullptr;

    if (x < root->val) {
        root->left = deleteNode(root->left, x);
    } else if (x > root->val) {
        root->right = deleteNode(root->right, x);
    } else {
        // Tìm thấy node cần xoá
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        } else {
            // Hai con: lấy successor (nhỏ nhất bên phải)
            TreeNode* succ = minValueNode(root->right);
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
    }
    return root;
}
};















/*
Trường hợp 1: Node không có con (Lá)
Cây ban đầu:
        20
       /  \
     10    30
    /  \   
   5   15
Giả sử bạn muốn xóa node 15.

Quy trình:
Cây sau khi xóa:
        20
       /  \
     10    30
    /   
   5  

Trường hợp 2: Node có một con
Cây ban đầu:
        20
       /  \
     10    30
    /  
   5

   Giả sử bạn muốn xóa node 10.

Quy trình:

Node 10 có một con (con trái là 5).

Bạn thay thế node 10 bằng node 5, vì node 5 là con duy nhất của nó.

Cây sau khi xóa:
        20
       /  \
     5     30


Trường hợp 3: Node có hai con
Cây ban đầu:
        20
       /  \
     10    30
    /  \   /  \
   5   15 25   40

Giả sử bạn muốn xóa node 20.

Quy trình:

Node 20 có cả hai con.

Bạn tìm node nhỏ nhất trong cây con phải của node 20, tức là 25.

Thay thế giá trị của node 20 bằng 25.

Sau đó, bạn xóa node 25 (node nhỏ nhất trong cây con phải, không có con trái).

Cây sau khi xóa:

        25
       /  \
     10    30
    /  \     \
   5   15    40

### Tóm tắt:

* **Node không có con**: Chỉ cần loại bỏ node.
* **Node có một con**: Thay thế node bị xóa bằng con của nó.
* **Node có hai con**: Thay thế node bị xóa bằng 
**node nhỏ nhất trong cây con phải** (hoặc node lớn nhất trong cây con trái), sau đó xóa node thay thế.













*/











