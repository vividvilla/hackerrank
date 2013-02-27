#include <iostream>
#include <vector>
#include <set>

using namespace std;

long long getTriplets(vector<int> v) {
    return 0;
}

int main() {
    int N, x;
    vector<int> v;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        v.push_back(x);
    }

    cout << getTriplets(v) << endl;

    return 0;
}
