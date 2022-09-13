#include <iostream>

using namespace std;

int main() {
    int n, i; 
    cout << "Enter a value for n: "; cin >> n;
    int arr[n], arr_res[n];
    
    cout << "Enter n elements: ";
    for (i = 0; i < n; i++) cin >> arr[i];
    
    for (i = 0; i < n; i++) arr_res[arr[i] - 1] = i + 1;
    
    cout << "The result: ";
    for (i = 0; i < n; i++) cout << arr_res[i] << ' ';
    
    return 0;
}
