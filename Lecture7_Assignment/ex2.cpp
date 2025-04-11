#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

// Cấu trúc để lưu kết quả: tọa độ hình chữ nhật có tổng lớn nhất và giá trị tổng đó
struct Result {
    int top, left, bottom, right, maxSum;
};

// Hàm tìm hình chữ nhật con có tổng lớn nhất
Result findMaxSumRectangle(vector<vector<int>>& matrix, int m, int n) {
    int maxSum = INT_MIN; // Khởi tạo tổng lớn nhất ban đầu là nhỏ nhất có thể
    Result res = {0, 0, 0, 0, maxSum}; // Khởi tạo kết quả ban đầu

    // Duyệt qua tất cả các cặp cột left và right
    for (int left = 0; left < n; ++left) {
        vector<int> temp(m, 0); // Mảng tạm để lưu tổng theo hàng

        for (int right = left; right < n; ++right) {
            // Cập nhật mảng temp với tổng theo hàng từ cột left đến cột right
            for (int i = 0; i < m; ++i) {
                temp[i] += matrix[i][right];
            }

            // Áp dụng thuật toán Kadane để tìm đoạn con có tổng lớn nhất trong mảng temp
            int sum = 0, startRow = 0;
            int localMax = INT_MIN, top = 0, bottom = 0;

            for (int i = 0; i < m; ++i) {
                sum += temp[i];
                if (sum > localMax) {
                    localMax = sum;
                    top = startRow;
                    bottom = i;
                }
                if (sum < 0) {
                    sum = 0;
                    startRow = i + 1;
                }
            }

            // Nếu tìm được tổng lớn hơn maxSum hiện tại, thì cập nhật kết quả
            if (localMax > maxSum) {
                maxSum = localMax;
                res = {top, left, bottom, right, maxSum};
            }
        }
    }

    return res; // Trả về kết quả
}

int main() {
    ifstream fin("matrix.txt");     // Mở file input
    ofstream fout("matrix.out");    // Mở file output

    int m, n;
    fin >> m >> n; // Đọc kích thước ma trận

    // Đọc ma trận từ file
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            fin >> matrix[i][j];

    // Gọi hàm tìm hình chữ nhật con có tổng lớn nhất
    Result r = findMaxSumRectangle(matrix, m, n);

    // In kết quả ra file (chuyển sang chỉ số bắt đầu từ 1)
    fout << r.top + 1 << " " << r.left + 1 << " "
         << r.bottom + 1 << " " << r.right + 1 << " "
         << r.maxSum << endl;

    // Đóng file
    fin.close();
    fout.close();
    return 0;
}
