#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int colors[N+1];
int combo_sum[N+1];
int smoke[N][N];

int minSmoke(int i, int j)
{
    if (i == j)
    {
        return 0;
    }


    if (smoke[i][j] != -1)
    {
        return smoke[i][j];
    }


    smoke[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int mix = combo_sum[k] - combo_sum[i] + colors[i];
        int left_smoke = minSmoke(i, k);
        int right_smoke = minSmoke(k+1, j);
        smoke[i][j] = min(smoke[i][j], left_smoke + right_smoke%100 + mix*(combo_sum[j]-combo_sum[k]));
    }

    return smoke[i][j];
}

int main() {
    int n;
    while (cin >> n)
        {

        for (int i = 0; i < n; i++)
        {
            cin >> colors[i];
        }


        combo_sum[0] = colors[0];
        for (int i = 1; i < n; i++)
        {
            combo_sum[i] = combo_sum[i-1] + colors[i];
        }


        memset(smoke, -1, sizeof(smoke));


        int min_smoke = minSmoke(0, n-1);


        cout << min_smoke << endl;
    }

    return 0;
}
