#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int MAX_N = 1000;
const int num_pockets = 50;

int pocket_sort (vector <int > &arr) {
    int result = 0, i;
    vector <list <int > > lst_pockets(num_pockets);
    for (i = 0; i < arr.size(); i++) {
        int position = (arr[i] - 1) / (MAX_N / num_pockets);
        auto iter = lst_pockets[position].begin();
        int next_position = 0;
        while (iter != lst_pockets[position].end() && *iter < arr[i]) {
            iter++;
            next_position++;
        }
        result += lst_pockets[position].size() - next_position;
        lst_pockets[position].insert(iter, arr[i]); 
        for (int j = position + 1; j < num_pockets; j++) {
            result += lst_pockets[j].size();
        }
    }
    return result;
}

int main() {
    int n, i; 
    cout << "Enter a value for n: "; cin >> n;
    vector <int > arr(n);
    
    cout << "Enter n elements: ";
    for (i = 0; i < n; i++) cin >> arr[i];
    
    int result = pocket_sort(arr);
    
    if (result % 2 == 0) cout << "Even\n";
    else cout << "Odd\n";
    
    return 0;
}
