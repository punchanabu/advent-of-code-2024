#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    map<int, set<int> > comeafter;
    vector<vector<int> > corrected_seqs;
    
    while(getline(cin, line)) {
        if (line == "") {
            break;
        }
        int n_before = stoi(line.substr(0,2));
        int n_after = stoi(line.substr(3,2));
        comeafter[n_before].insert(n_after);
    }


    while(getline(cin, line)) {
        stringstream ss(line);
        string page;
        vector<int> seq;
        while(getline(ss, page, ',')) {
            seq.push_back(stoi(page));
        }

        bool corrected = false;
        for (int k = 0; k < seq.size(); k++) {
            for (int i = 1; i < seq.size(); i++) {
                for (int j = i - 1; j >= 0; j--) {
                    if (comeafter[seq[i]].find(seq[j]) != comeafter[seq[i]].end()) {
                        swap(seq[i], seq[j]);
                        corrected = true;
                    }
                }
            }
        }
        if (corrected) {
            corrected_seqs.push_back(seq);
        }
    }

    int sum = 0;
    for (auto seq: corrected_seqs) {
        int mid = ( seq.size() - 1 ) / 2;
        sum += seq[mid];
    }

    cout << sum << endl;
}

