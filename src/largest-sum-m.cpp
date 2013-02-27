#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007

int largestSum(int k, vector<int> d, int M) {
    int best = 0;
    int N = d.size();
    vector<vector<bool> > s = vector<vector<bool> >(M, vector<bool>(k + 1, false));
    s[0][0] = true;

    for (int j = 0; j < N; j++) {
        for (int l = M - 1; l >= d[j]; l--) {
            for (int i = 1; i <= k; i++) {
                s[l][i] = s[l][i] || s[l - d[j]][i - 1];
                if (i == k && s[l][i] && l > best)
                    best = l;
            }
        }
    }

    return best;
}

int partitions(int Z) {
    vector<int> p = vector<int>(Z + 1, 0);
    p[0] = 1;

    for (int i = 1; i <= Z; i++) {
        for (int j = i; j <= Z; j++) {
            p[j] = (p[j] + p[j - i]) % MOD;
        }
    }

    return p[Z];
}

int main() {
    int n, k, M, x;
    cin >> n >> k >> M;

    vector<int> d;
    for (int i = 0; i < n; i++) {
        cin >> x;
        d.push_back(x);
    }

    int Z = largestSum(k, d, M);
    cout << Z << endl;
    cout << partitions(Z) << endl;

    return 0;
}
