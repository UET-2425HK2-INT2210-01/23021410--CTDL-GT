#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, X;
    cin >> n >> X;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Khởi tạo bảng dp: dp[i][j] = true nếu có thể tạo tổng j từ i phần tử đầu tiên
    vector<vector<bool>> dp(n + 1, vector<bool>(X + 1, false));

    // Với tổng bằng 0 thì luôn đúng (tập rỗng)
    for (int i = 0; i <= n; ++i)
        dp[i][0] = true;

    // Duyệt qua từng phần tử và từng tổng có thể tạo được
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= X; ++j) {
            if (j < A[i - 1]) {
                dp[i][j] = dp[i - 1][j]; // Không lấy phần tử thứ i
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - A[i - 1]]; // Lấy hoặc không lấy phần tử thứ i
            }
        }
    }

    // In kết quả cuối cùng
    if (dp[n][X])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
