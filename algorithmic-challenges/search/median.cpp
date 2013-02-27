#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

void outputMedians(vector<char> ops, vector<long long> ints) {
    int N = ops.size();

    multiset<long long> left;
    multiset<long long> right;

    for (int i = 0; i < N; i++) {
        bool valid = true;

        if (ops[i] == 'r') {
            multiset<long long>::iterator li = left.find(ints[i]);
            multiset<long long>::iterator ri = right.find(ints[i]);
            if (li != left.end())
                left.erase(li);
            else if (ri != right.end())
                right.erase(ri);
            else
                valid = false;
        } else if (ops[i] == 'a') {
            if (left.size() == 0 || ints[i] < *left.rbegin())
                left.insert(ints[i]);
            else
                right.insert(ints[i]);
        }

        if (left.size() > right.size() + 1) {
            right.insert(*left.rbegin());
            left.erase(left.find(*left.rbegin()));
        } else if (right.size() > left.size()) {
            left.insert(*right.begin());
            right.erase(right.find(*right.begin()));
        }

        if (valid && left.size() + right.size() > 0) {
            if (left.size() > right.size())
                cout << *left.rbegin() << endl;
            else {
                long long m = *left.rbegin() + *right.begin();
                if (m % 2)
                    printf("%.1lf\n", m / 2.);
                else
                    printf("%.0lf\n", m / 2.);
            }
        } else {
            cout << "Wrong!" << endl;
        }
    }
}

int main() {
    int n;
    long long x;
    char o;
    cin >> n;

    vector<char> ops;
    vector<long long> ints;
    for (int i = 0; i < n; i++) {
        cin >> o >> x;
        ops.push_back(o);
        ints.push_back(x);
    }

    outputMedians(ops, ints);

    return 0;
}
