#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<bool>> know(N, vector<bool>(N, false));
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        know[x][y] = true;
        //know[y][x] = true;
    }

    int ans = 0;

    for (int mask = 0; mask < (1 << N); mask++) {
        bool ok = true;

        for (int i = 0; i < N && ok; i++) {
            for (int j = i + 1; j < N; j++) {
                if ((mask & (1 << i)) && (mask & (1 << j))) {
                    if (!know[i][j]) {
                        ok = false;
                        break;
                    }
                }
            }
        }

        if (ok) {
            ans = max(ans, __builtin_popcount(mask));
        }
    }

    cout << ans << endl;

    return 0;
}
