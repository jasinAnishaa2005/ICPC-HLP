#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll INF = 1e18;
ll dp[100005];

ll minCost(int i, int n, vector<ll>& arr)
{
    // Base case
    if (i == n)
        return 0;

    // Already calculated
    if (dp[i] != -1)
        return dp[i];

    // Jump 1 step
    ll cost1 = abs(arr[i] - arr[i + 1])
             + minCost(i + 1, n, arr);

    // Jump 2 steps
    ll cost2 = INF;

    if (i + 2 <= n)
    {
        cost2 = abs(arr[i] - arr[i + 2])
              + minCost(i + 2, n, arr);
    }

    return dp[i] = min(cost1, cost2);
}

void Solve()
{
    int n;
    cin >> n;

    vector<ll> arr(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    memset(dp, -1, sizeof(dp));

    cout << minCost(1, n, arr) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solve();

    return 0;
}
 
