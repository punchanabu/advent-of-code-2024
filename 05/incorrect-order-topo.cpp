#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    map<int, set<int> > comeafter;
    while(getline(cin, line)) {
        if (line == "") {
            break;
        }
        int n_before = stoi(line.substr(0,2));
        int n_after = stoi(line.substr(3,2));
        comeafter[n_before].insert(n_after);
    }

    const int MAX_PAGE = 100;
    vector<vector<int>> graph(MAX_PAGE);
    vector<int> in_degree(MAX_PAGE, 0);

    set<int> page_involved;
    for (auto &p: comeafter) {
        int u = p.first;
        page_involved.insert(u);
        for (auto &v: p.second) {
            page_involved.insert(v);
            graph[u].push_back(v);
        }
    }

    for (int u : page_involved) {
        for (auto &v: graph[u]) {
            in_degree[v]++;
        }
    }

    // Run Topo
    queue<int> q;
    for (int u : page_involved) {
        if (in_degree[u] == 0) {
            q.push(u);
        }
    }

    vector<int> topo_order;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        topo_order.push_back(u);
        for (int v: graph[u]) {
            if (--in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    const int UNCONSTRAINED_RANK = page_involved.size() + 1000;
    vector<int> rank(MAX_PAGE, UNCONSTRAINED_RANK);
    for (int i = 0; i < topo_order.size(); i++) {
        rank[topo_order[i]] = i;
    }

    vector<vector<int>> corrected_seqs;
    {
        string line;
        while (getline(cin, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            string page_str;
            vector<int> seq;
            while (getline(ss, page_str, ',')) {
                seq.push_back(stoi(page_str));
            }

            vector<int> orig_seq = seq;
            stable_sort(seq.begin(), seq.end(), [&](int a, int b) {
                return rank[a] < rank[b];
            });

            if (seq != orig_seq) {
                corrected_seqs.push_back(seq);
            }
        }
    }

    int sum = 0;
    for (auto &seq : corrected_seqs) {
        int mid = (seq.size() - 1) / 2;
        sum += seq[mid];
    }

    cout << sum << "\n";

    return 0;
}