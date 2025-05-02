#include <iostream>
#include <vector>
#include <iomanip> // để định dạng số thực (setprecision)

using namespace std;

// Hàm phân hoạch cho thuật toán quicksort
int partition(vector<double>& arr, int low, int high) {
    double pivot = arr[high]; // chọn phần tử cuối cùng làm pivot
    int i = low - 1; // chỉ số của phần tử nhỏ hơn pivot

    for (int j = low; j < high; j++) {
        // nếu phần tử hiện tại nhỏ hơn pivot
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); // hoán đổi phần tử nhỏ hơn về phía bên trái
        }
    }
    swap(arr[i + 1], arr[high]); // đặt pivot vào đúng vị trí
    return i + 1; // trả về vị trí của pivot
}

// Hàm quicksort đệ quy
void quickSort(vector<double>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high); // tìm chỉ số pivot
        quickSort(arr, low, pivotIndex - 1);        // sắp xếp bên trái pivot
        quickSort(arr, pivotIndex + 1, high);       // sắp xếp bên phải pivot
    }
}

int main() {
    int n;
    cin >> n; // nhập số lượng phần tử

    vector<double> numbers(n);
    // nhập n số thực
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // gọi hàm quicksort
    quickSort(numbers, 0, n - 1);

    // in kết quả đã sắp xếp, cách nhau bởi dấu cách
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(6) << numbers[i]; // in với 6 chữ số sau dấu phẩy
        if (i != n - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
