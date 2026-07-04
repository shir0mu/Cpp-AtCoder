#include <bits/stdc++.h>
using namespace std;

int toMinutes(int t) {
    int h = t / 100;
    int m = t % 100;
    return h * 60 + m;
}

int toHHMM(int minutes) {
    int h = minutes / 60;
    int m = minutes % 60;
    return h * 100 + m;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> rain;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        int start = stoi(s.substr(0, s.find('-')));
        int end = stoi(s.substr(s.find('-') + 1));

        int st = toMinutes(start);
        int en = toMinutes(end);

        st = st / 5 * 5;
        en = (en + 4) / 5 * 5;

        rain.push_back({st, en});
    }

    sort(rain.begin(), rain.end());

    vector<pair<int, int>> merged;

    for (auto [st, en] : rain) {
        if (merged.empty()) {
            merged.push_back({st, en});
        } else {
            auto& last = merged.back();
            if (last.second >= st) {
                last.second = max(last.second, en);
            } else {
                merged.push_back({st, en});
            }
        }
    }

    for (auto [st, en] : merged) {
        cout << setfill('0') << setw(4) << toHHMM(st);
        cout << "-";
        cout << setfill('0') << setw(4) << toHHMM(en) << endl;
    }
}
