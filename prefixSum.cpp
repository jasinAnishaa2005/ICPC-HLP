#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n), pref(n+1, 0);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i+1] = pref[i] + a[i];
    }

    int l, r;
    cin >> l >> r;

    cout << pref[r+1] - pref[l] << '\n';
}
