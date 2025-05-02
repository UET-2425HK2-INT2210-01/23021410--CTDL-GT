#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, X;
    cin >> n >> X;

    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }

    // dp[j] = giá trị lớn nhất đạt được khi tổng trọng lượng là j
    vector<int> dp(X + 1, 0);

    for (int i = 0; i < n; i++) {
        // Duyệt ngược để không dùng lại vật i nhiều lần
        for (int j = X; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    cout << dp[X] << endl;
    return 0;
}
