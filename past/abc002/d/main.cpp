#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> know(N, 0);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        know[x] |= 1 << y;
        know[y] |= 1 << x;
    }

    int ans = 0;

    for (int mask = 1; mask < (1 << N); mask++) {
        int cnt = __builtin_popcount(mask);
        if (cnt <= ans) continue;

        bool ok = true;

        for (int i = 0; i < N; i++) {
            if (!(mask & (1 << i))) {
                continue;
            }

            int others = mask ^ (1 << i);

            if ((others & ~know[i]) != 0) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans = cnt;
        }
    }

    cout << ans << endl;

    return 0;
}
