#include<bits/stdc++.h>
using namespace std  ; 
class Solution { 
    public : 
    void sortColors(vector<int>& nums) { 
        int l = 0 ; 
        int r = nums.size() -1 ; 
        int mid = 0 ;  // khoi tao bien l gia tri bang  0 
      // r = cuoi mang 
        while(mid <= r ) {  // ham nay de duyet cho mid chay den cuoi mang 
            switch (nums[mid]) // su dung swich de chia truong hop neu gia tri num duyet 
            {
           case 0 : 
            swap(nums[l], nums[mid]);
            l++ ; 
            mid++ ; 
            case 1 :  
            mid++;  
            
            case 2 : 
            swap(nums[mid], nums[r]);
            r-- ; 
            break ; 
        }
    }
    }
};
/*
idea : 
1. Ý tưởng

Mảng chỉ có 3 giá trị: 0, 1, 2.

Dùng 3 con trỏ:

l (left): vị trí tiếp theo để đặt số 0.

r (right): vị trí tiếp theo để đặt số 2.

mid: con trỏ đang duyệt mảng.

Khi duyệt:

Nếu nums[mid] == 0: đưa nó về đầu (swap với l).

Nếu nums[mid] == 1: giữ nguyên, tăng mid.

Nếu nums[mid] == 2: đưa nó về cuối (swap với r).

2. Vì sao lại kiểm tra nums[mid]?

Bởi vì mid chính là con trỏ đang duyệt từng phần tử trong mảng.

Ta cần dựa vào giá trị của phần tử tại vị trí mid (nums[mid]) để quyết định hành động:

Nếu là 0 → cần đưa sang trái.

Nếu là 1 → đúng chỗ rồi, chỉ tiến tiếp.

Nếu là 2 → cần đưa sang phải.

3. Minh họa

Ví dụ nums = [2,0,2,1,1,0]

Bước 1: mid=0, nums[mid]=2 → đổi với r (cuối).

Bước 2: mid=0, nums[mid]=0 → đổi với l, tăng l và mid.

Cứ thế đến khi mid > r, mảng được sắp xếp thành [0,0,1,1,2,2].


*/