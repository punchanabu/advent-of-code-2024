#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> left;
    map<int, int> right;

    int left_num ,right_num;
    while (cin >> left_num && cin >> right_num) {
        left.push_back(left_num);
        if (right.find(right_num) != right.end()) {
            right[right_num]++;
        } 
        else {
            right[right_num] = 1;
        }
    }

    int sum = 0;
    for (int i = 0; i < left.size(); i++) {
        if (right.find(left[i]) != right.end()) {
            sum += left[i] * right[left[i]];
        }
    }

    cout << sum << endl;

    return (0);
}