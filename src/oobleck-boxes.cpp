#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007

int getWays(int n, int m) {
    vector<int> w = vector<int>(n + 1, 0);

    for (long long i = 1; i <= n; i *= m) {
        w[i] = (w[i] + 1) % MOD;
        for (int j = i + 1; j <= n; j++) {
            w[j] = (w[j] + w[j - i]) % MOD;
        }
    }

    return w[n];
}

int main() {
    int n, m;
    cin >> n >> m;

    cout << getWays(n, m) << endl;

    return 0;
}
