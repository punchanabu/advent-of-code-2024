#include <bits/stdc++.h>

using namespace std;

int main()  {
	vector<int> left;
	vector<int> right;

	int left_num, right_num;

	while (cin >> left_num && cin >> right_num) {
		left.push_back(left_num);
		right.push_back(right_num);
	}

	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

	int n = left.size();
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += abs(left[i] - right[i]);
	}

	cout << sum << endl;

}