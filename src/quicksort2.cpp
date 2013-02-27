#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quickSortAux(vector<int> & v, int l, int r) {
    if (l >= r)
        return;

    int p = v[l];
    vector<int> p1;
    vector<int> p2;
    for (int i = l + 1; i <= r; i++) {
        if (v[i] < p)
            p1.push_back(v[i]);
        else if (v[i] > p)
            p2.push_back(v[i]);
    }
    int m = l + p1.size();
    p1.push_back(p);
    p1.insert(p1.end(), p2.begin(), p2.end());

    for (int i = l; i <= r; i++)
        v[i] = p1[i - l];

    quickSortAux(v, l, m - 1);
    quickSortAux(v, m + 1, r);

    for (int i = l; i <= r; i++) {
        cout << v[i];
        if (i + 1 <= r)
            cout << " ";
        else
            cout << endl;
    }
}

void quickSort(vector<int> & v) {
    quickSortAux(v, 0, v.size() - 1);
}

int main() {
    int n, x;
    vector <int> v;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }

    quickSort(v);

    return 0;
}
