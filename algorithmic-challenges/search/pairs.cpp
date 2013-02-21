#include <iostream>
#include <vector>
#include <set>

using namespace std;

int getPairs(vector<int> v, int K) {
    int p = 0;
    int N = v.size();
    set<int> ns;

    for (int i = 0; i < N; i++)
        ns.insert(v[i]);

    for (set<int>::iterator itr = ns.begin(); itr != ns.end(); itr++)
        if (ns.find(*itr + K) != ns.end())
            p++;

    return p;
}

int main() {
    int N, K, x;
    cin >> N >> K;

    vector<int> v;
    for (int i = 0; i < N; i++) {
        cin >> x;
        v.push_back(x);
    }

    cout << getPairs(v, K) << endl;

    return 0;
}
