#include <bits/stdc++.h>
using namespace std;

int main() {
    string seq, line;
    while (getline(cin, line)) {
        seq += line;
    }

    bool trigger = true;
    long long sum = 0;

    for (int i = 0; i < (int)seq.size(); i++) {
        if (i + 4 <= (int)seq.size() && seq.substr(i, 4) == "do()") {
            trigger = true;
            i += 3;
            continue;
        }
        if (i + 7 <= (int)seq.size() && seq.substr(i, 7) == "don't()") {
            trigger = false;
            i += 6; 
            continue;
        }

        if (trigger && i + 4 <= (int)seq.size() && seq.substr(i,4) == "mul(") {
            int j = i + 4; 

            long long a = 0;
            bool valid = true;
            bool found = false;

            while (j < (int)seq.size() && isdigit((unsigned char)seq[j])) {
                a = a * 10 + (seq[j] - '0');
                j++;
                found = true;
            }
            
            if (!found) {
                continue;
            }

            if (j >= (int)seq.size() || seq[j] != ',') {
                continue;
            }
            j++;

            long long b = 0;
            found = false;
            while (j < (int)seq.size() && isdigit((unsigned char)seq[j])) {
                b = b * 10 + (seq[j] - '0');
                j++;
                found = true;
            }

            if (!found) {
                continue;
            }

            if (j >= (int)seq.size() || seq[j] != ')') {
                continue;
            }

            sum += (a * b);

            i = j;
        }
    }

    cout << sum << "\n";

    return 0;
}