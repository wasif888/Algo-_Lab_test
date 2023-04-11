#include<bits/stdc++.h>
using namespace std;
const int MAXN = 16;
int n, a[MAXN][MAXN], dp[1<<MAXN];
bool isOn(int N, int pos) {
    return (bool)(N & (1<<pos));
}

int turnOn(int N, int pos) {
    return (N | (1<<pos));
}

int call(int mask) {
    if (mask == (1<<n) - 1)
    {
        return 0;
    }
    if (dp[mask] != -1)
    {
        return dp[mask];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
    if (!isOn(mask, i))
    {
    int val = 0;
    for (int j = 0; j < n; j++)
    {
    if (isOn(mask, j))
    {
      val += a[i][j];
    }
    }
      ans = max(ans, val + call(turnOn(mask, i)));
    }
    }

    return dp[mask] = ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        memset(dp, -1, sizeof(dp));


    }

    return 0;
}
