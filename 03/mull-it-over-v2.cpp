#include <bits/stdc++.h>

using namespace std;

int main() {
    string seq = "";
    string line;

    while (getline(cin, line)) {
        seq += line;
    }

    int state = 0;
    int sum = 0;
    int a = 0;
    int b = 0;
    bool trigger = true;
    for (int i = 0; i < seq.length(); i++) {
        if (seq.substr(i, 3) == "do(" && seq[i + 3] == ')') {
            trigger = true;
            i += 4; 
            continue;
        }

        if (seq.substr(i, 6) == "don't(" && seq[i + 6] == ')') {
            trigger = false;
            i += 7; 
            continue;
        }

        if (seq[i] == 'm' && state == 0 && trigger) {
            state = 1;
        } 
        else if (seq[i] == 'u' && state == 1) {
            state = 2;
        } 
        else if (seq[i] == 'l' && state == 2) {
            state = 3;
        } 
        else if (seq[i] == '(' && state == 3) {
            state = 4;
            a = 0; 
            b = 0;
        } 
        else if (isdigit(seq[i]) && state == 4) {
            a = a * 10 + (seq[i] - '0'); 
        } 
        else if (seq[i] == ',' && state == 4) {
            state = 5; 
        } 
        else if (isdigit(seq[i]) && state == 5) {
            b = b * 10 + (seq[i] - '0');
        } 
        else if (seq[i] == ')' && state == 5) {
            sum += (a * b);
            state = 0;
        } 
        else {
            state = 0;
        }
    }

    cout << sum << endl;

    return 0;
}
