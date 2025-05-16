#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define MAX 1001

using namespace std;

// Lớp Solution dùng để giải bài toán tìm đường đi trên đồ thị có hướng
class Solution {
  private:
   int n, m, s, t;                // n: số đỉnh, m: số cạnh, s: đỉnh bắt đầu, t: đỉnh kết thúc
   vector<int> adj[MAX];          // adj[u]: danh sách kề của đỉnh u
   bool visited[MAX];             // visited[u]: đánh dấu đã thăm đỉnh u hay chưa
   int parent[MAX];               // parent[v]: lưu cha của v trên đường đi

  public:
   // Hàm nhập dữ liệu đồ thị
   void input() {
      cout << "Nhap so dinh : ";
      cin >> n;
      cout << "Nhap so canh : ";
      cin >> m;
      cout << "Nhap dau duong di : ";
      cin >> s;
      cout << "Nhap cuoi duong di : ";
      cin >> t;
      for (int i = 0; i < m; i++) {
         int x, y;
         cin >> x >> y;
         adj[x].push_back(y);  // chỉ thêm 1 chiều: x -> y (đồ thị có hướng)
      }
   }

   // Hàm duyệt đồ thị theo chiều sâu (DFS) từ đỉnh u
   void dfs(int u) {
      visited[u] = true;           // Đánh dấu đã thăm u
      for (int v : adj[u]) {       // Duyệt các đỉnh kề với u
         if (!visited[v]) {        // Nếu v chưa được thăm
            parent[v] = u;         // Lưu cha của v là u
            dfs(v);                // Đệ quy DFS từ v
         }
      }
   }

   // Hàm duyệt đồ thị theo chiều rộng (BFS) từ đỉnh u
   void bfs(int u) {
      queue<int> q;
      q.push(u);                   // Đưa u vào hàng đợi
      visited[u] = true;           // Đánh dấu đã thăm u
      while (!q.empty()) {
         int v = q.front();
         q.pop();
         for (int x : adj[v]) {    // Duyệt các đỉnh kề với v
            if (!visited[x]) {     // Nếu x chưa được thăm
               q.push(x);          // Đưa x vào hàng đợi
               visited[x] = true;  // Đánh dấu đã thăm x
               parent[x] = v;      // Lưu cha của x là v
            }
         }
      }
   }

   // Hàm tìm và in đường đi từ s đến t (nếu có), đồng thời in độ dài đường đi
   void path() {
      memset(visited, false, sizeof(visited)); // Khởi tạo lại mảng visited
      memset(parent, 0, sizeof(parent));       // Khởi tạo lại mảng parent
      bfs(s);  // hoặc dfs(s);                 // Duyệt đồ thị từ s (có thể dùng BFS hoặc DFS)

      if (!visited[t]) {                       // Nếu không tìm được đường đi tới t
         cout << "Khong co duong di" << endl;
      } else {
         vector<int> Path;                     // Lưu đường đi từ s đến t
         int cur = t;
         while (cur != s) {                    // Truy vết ngược từ t về s qua mảng parent
            Path.push_back(cur);
            cur = parent[cur];
         }
         Path.push_back(s);                    // Thêm đỉnh bắt đầu
         reverse(Path.begin(), Path.end());    // Đảo ngược để có đường đi đúng thứ tự s -> t
         int len = Path.size() - 1;            // Độ dài đường đi là số cạnh = số đỉnh - 1
         cout << "Độ dài đường đi là: " << len << endl;
         cout << "Duong di la: ";
         for (int x : Path) {
            cout << x << " ";
         }
      }
   }
};

int main() {
   Solution s;
   s.input();   // Nhập dữ liệu đồ thị
   s.path();    // Tìm và in đường đi từ s đến t
}