#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int > > reports;
    string line;

    while(getline(cin, line)) {
        vector<int> levels;

        stringstream ss(line);

        int num;

        while (ss >> num) {
            levels.push_back(num);
        }

        reports.push_back(levels);
    }

    int cnt = 0;
    for (int i = 0; i < reports.size(); i++) {
        bool safe_one = false;
        for (int k = 0; k < reports[i].size(); k++) {
            vector<int> lv = reports[i];
            lv.erase(lv.begin() + k);
            bool decr = true;
            bool incr = true;
            bool safe = true;
            for (int j = 1; j < lv.size(); j++) {

                int diff = lv[j] - lv[j - 1];
                if (abs(diff) < 1 || abs(diff) > 3) {
                    safe = false;
                }

                if (diff < 0) {
                    incr = false;
                }

                if (diff > 0) {
                    decr = false;
                }

            }
            if (safe && (incr || decr)) {
                safe_one = true;
            }
        }
        if (safe_one) {
            cnt++;
        }
    }

    cout << cnt << endl;
}
