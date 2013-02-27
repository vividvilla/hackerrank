#include <iostream>
#include <vector>

using namespace std;

vector<int> partition(vector<int> ar) {
    int N = ar.size();

    int p = ar[0];
    vector<int> p1;
    vector<int> p2;
    for (int i = 0; i < N; i++) {
        if (ar[i] < p)
            p1.push_back(ar[i]);
        else if (ar[i] > p)
            p2.push_back(ar[i]);
    }
    p1.push_back(p);
    p1.insert(p1.end(), p2.begin(), p2.end());

    return p1;
}

int main() {
    int n, x;
    cin >> n;

    vector<int> ar;
    for (int i = 0; i < n; i++) {
        cin >> x;
        ar.push_back(x);
    }

    vector<int> p = partition(ar);
    for (int i = 0; i < n; i++) {
        cout << p[i];
        if (i + 1 < n)
            cout << " ";
        else
            cout << endl;
    }

    return 0;
}
