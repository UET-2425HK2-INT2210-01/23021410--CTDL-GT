// Chương trình đếm số thành phần liên thông của đồ thị vô hướng bằng DFS
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj; // Danh sách kề của đồ thị (adjacency list)
vector<bool> visited;    // Mảng đánh dấu các đỉnh đã được thăm

// Hàm duyệt DFS từ một đỉnh
void dfs(int node) {
  visited[node] = true; // Đánh dấu đỉnh hiện tại đã thăm
  for (size_t i = 0; i < adj[node].size(); i++) { // Duyệt các đỉnh kề
    int neighbor = adj[node][i];
    if (!visited[neighbor]) {
      dfs(neighbor); // Đệ quy DFS với đỉnh kề chưa thăm
    }
  }
}

// Hàm đếm số thành phần liên thông của đồ thị
int countConnectedComponents(int n) {
  int count = 0; // Biến đếm số thành phần liên thông
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      count++; // Tìm thấy thành phần liên thông mới
      dfs(i);  // Duyệt tất cả các đỉnh trong thành phần đó
    }
  }
  return count;
}

int main() {
  int n, m; // n: số đỉnh, m: số cạnh
  cin >> n >> m;

  // Ví dụ:
  // n = 5, m = 3
  // Các cạnh:
  // 1 2
  // 2 3
  // 4 5
  // Đồ thị này có 2 thành phần liên thông: {1,2,3} và {4,5}
  // Kết quả in ra sẽ là 2
  adj.resize(n + 1); // Khởi tạo danh sách kề với n đỉnh (đánh số từ 1)
  visited.assign(n + 1, false); // Khởi tạo mảng visited với giá trị false

  // Nhập các cạnh của đồ thị
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y); // Thêm cạnh x-y vào danh sách kề
    adj[y].push_back(x); // Đồ thị vô hướng nên thêm cả hai chiều
  }

  cout << countConnectedComponents(n) << endl; // In ra số thành phần liên thông

  return 0;
}
