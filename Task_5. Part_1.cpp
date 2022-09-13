#include <iostream>

using namespace std;

int main() {
    int n, i; 
    cout << "Enter a value for n: "; cin >> n;
    int arr_1[n], arr_2[n], arr_res[n];
    
    cout << "Enter the first n elements: ";
    for (i = 0; i < n; i++) cin >> arr_1[i];
    
    cout << "Enter the second n elements: ";
    for (i = 0; i < n; i++) cin >> arr_2[i];
    
    for (i = 0; i < n; i++) arr_res[i] = arr_1[arr_2[i] - 1]; 
    
    cout << "The result: ";
    for (i = 0; i < n; i++) cout << arr_res[i] << ' ';
    
    return 0;
}
