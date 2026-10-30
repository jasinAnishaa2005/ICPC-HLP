//Pattern A: Fixed-size window

long long sum = 0;

for(int i = 0; i < k; i++)
    sum += a[i];

long long ans = sum;

for(int i = k; i < n; i++) {
    sum += a[i];
    sum -= a[i-k];

    ans = max(ans, sum);
}

cout << ans << '\n';

//Pattern B: Variable-size window

int l = 0;
long long sum = 0;
int ans = INT_MAX;

for(int r = 0; r < n; r++) {
    sum += a[r];

    while(sum >= k) {
        ans = min(ans, r-l+1);

        sum -= a[l];
        l++;
    }
}

cout << (ans == INT_MAX ? -1 : ans);
