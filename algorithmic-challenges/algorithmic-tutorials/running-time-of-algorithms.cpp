#include <iostream>
#include <vector>

using namespace std;

int getShifts(vector<int> ar) {
    int M = ar.size();
    int s = 0;

    for (int N = 2; N <= M; N++) {
        int el = ar[N - 1];
        for (int i = N - 1; i >= 0; i--) {
            if (i > 0 && ar[i - 1] > el) {
                ar[i] = ar[i - 1];
                s++;
            } else
                ar[i] = el;

            if (ar[i] <= el)
                break;
        }
    }

    return s;
}

int main() {
    int s, x;
    cin >> s;

    vector<int> ar;
    for (int i = 0; i < s; i++) {
        cin >> x;
        ar.push_back(x);
    }

    cout << getShifts(ar) << endl;
}
