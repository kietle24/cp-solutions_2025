class Solution  { 
public: 
    int threeSumClosest(vector<int>& arr, int target) {  
        sort(arr.begin(), arr.end()); 
        int n = arr.size();
        // Khởi tạo kết quả ban đầu bằng tổng của 3 phần tử đầu tiên
        int resultSum = arr[0] + arr[1] + arr[2]; 
        int minDifference  = INT_MAX; // Khởi tạo bằng giá trị cực lớn để dễ so sánh

        for (int i = 0; i < n - 2; i++) {  
            int left = i + 1; 
            int right = n - 1; 

            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right]; 
                int diffToTarget = abs(sum - target); // khoảng cách giữa sum và target
                if (sum == target) { 
                    return target; // nếu bằng target thì trả về luôn
                } 
                else if (sum < target) { 
                    left++; // cần tổng lớn hơn
                } 
                else { 
                    right--; // cần tổng nhỏ hơn
                }
                  if (diffToTarget < minDifference) { 
                    resultSum = sum;            // cập nhật kết quả tốt nhất
                    minDifference = diffToTarget; 
                }

            }
        }
        return resultSum; 
    }
};  
