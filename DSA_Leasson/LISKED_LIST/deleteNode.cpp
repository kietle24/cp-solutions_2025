#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void drawList(Node* head, Node* highlight = nullptr, const string& label = "") {
    cout << "\n" << label << "\n";
    
    if (head == nullptr) {
        cout << "head -> NULL\n";
        return;
    }
    
    cout << "head -> ";
    Node* temp = head;
    
    while (temp != nullptr) {
        if (temp == highlight) {
            cout << "[" << temp->data << "]"; // Highlight node
        } else {
            cout << "|" << temp->data << "|";
        }
        
        if (temp->next != nullptr) {
            cout << " -> ";
        } else {
            cout << " -> NULL";
        }
        temp = temp->next;
    }
    cout << "\n";
}

Node* deleteLast_Visual(Node* head) {
    cout << "========================================\n";
    cout << "     XÓA PHẦN TỬ CUỐI - TRỰC QUAN      \n";
    cout << "========================================\n";
    
    drawList(head, nullptr, "BƯỚC 0: Danh sách ban đầu");
    
    // Bước 1: Kiểm tra danh sách rỗng
    cout << "\nBƯỚC 1: if (head == nullptr) return nullptr;\n";
    if (head == nullptr) {
        cout << "-> Danh sách RỖNG, trả về nullptr\n";
        return nullptr;
    }
    cout << "-> Danh sách KHÔNG rỗng, tiếp tục\n";
    
    // Bước 2: Kiểm tra chỉ có 1 phần tử
    cout << "\nBƯỚC 2: if (head->next == nullptr)\n";
    if (head->next == nullptr) {
        cout << "-> Chỉ có 1 phần tử, xóa head\n";
        drawList(head, head, "Phần tử sẽ bị xóa:");
        delete head;
        cout << "-> Sau khi xóa: head -> NULL\n";
        return nullptr;
    }
    cout << "-> Có nhiều hơn 1 phần tử, tiếp tục\n";
    
    // Bước 3: Khởi tạo con trỏ curr
    cout << "\nBƯỚC 3: Node* curr = head;\n";
    Node* curr = head;
    drawList(head, curr, "curr trỏ đến head:");
    
    // Bước 4: Vòng lặp tìm phần tử áp cuối
    cout << "\nBƯỚC 4: while (curr->next->next != nullptr)\n";
    int step = 1;
    
    while (curr->next->next != nullptr) {
        cout << "  Lần lặp " << step << ":\n";
        cout << "    curr hiện tại: " << curr->data << "\n";
        cout << "    curr->next: " << curr->next->data << "\n";
        cout << "    curr->next->next: " << curr->next->next->data << " (khác nullptr)\n";
        
        drawList(head, curr, "    Trước khi di chuyển curr:");
        
        curr = curr->next;
        
        drawList(head, curr, "    Sau khi curr = curr->next:");
        cout << "\n";
        step++;
    }
    
    cout << "  Kết thúc vòng lặp:\n";
    cout << "    curr hiện tại: " << curr->data << " (phần tử áp cuối)\n";
    cout << "    curr->next: " << curr->next->data << " (phần tử cuối)\n";
    cout << "    curr->next->next: NULL\n";
    
    drawList(head, curr, "curr dừng tại phần tử áp cuối:");
    
    // Bước 5: Xóa phần tử cuối
    cout << "\nBƯỚC 5: delete curr->next;\n";
    Node* nodeToDelete = curr->next;
    cout << "-> Xóa phần tử có giá trị: " << nodeToDelete->data << "\n";
    
    // Vẽ trước khi xóa
    cout << "\nTrước khi xóa:\n";
    cout << "curr -> |" << curr->data << "| -> |" << curr->next->data << "| -> NULL\n";
    cout << "              ^curr        ^sẽ bị xóa\n";
    
    delete curr->next;
    
    // Bước 6: Cập nhật liên kết
    cout << "\nBƯỚC 6: curr->next = nullptr;\n";
    curr->next = nullptr;
    
    cout << "Sau khi xóa và cập nhật:\n";
    cout << "curr -> |" << curr->data << "| -> NULL\n";
    cout << "              ^curr (giờ là phần tử cuối)\n";
    
    drawList(head, nullptr, "\nKết quả cuối cùng:");
    
    return head;
}

// Hàm demo với nhiều trường hợp
void demoAllCases() {
    cout << "\n" << string(50, '=') << "\n";
    cout << "           DEMO TẤT CẢ CÁC TRƯỜNG HỢP\n";
    cout << string(50, '=') << "\n";
    
    // Test 1: Danh sách rỗng
    cout << "\n>>> TEST 1: DANH SÁCH RỖNG <<<\n";
    Node* head1 = nullptr;
    head1 = deleteLast_Visual(head1);
    
    // Test 2: Chỉ có 1 phần tử
    cout << "\n\n>>> TEST 2: CHỈ CÓ 1 PHẦN TỬ <<<\n";
    Node* head2 = new Node(42);
    head2 = deleteLast_Visual(head2);
    
    // Test 3: Có 2 phần tử
    cout << "\n\n>>> TEST 3: CÓ 2 PHẦN TỬ <<<\n";
    Node* head3 = new Node(10);
    head3->next = new Node(20);
    head3 = deleteLast_Visual(head3);
    
    // Test 4: Có nhiều phần tử
    cout << "\n\n>>> TEST 4: CÓ NHIỀU PHẦN TỬ <<<\n";
    Node* head4 = new Node(1);
    head4->next = new Node(2);
    head4->next->next = new Node(3);
    head4->next->next->next = new Node(4);
    head4->next->next->next->next = new Node(5);
    head4 = deleteLast_Visual(head4);
}

int main() {
    demoAllCases();
    return 0;
}