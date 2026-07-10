#include <bits/stdc++.h>
using namespace std;

int main()
{
    pair<int, int> a, b, c;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;

    a.first -= c.first;
    a.second -= c.second;
    b.first -= c.first;
    b.second -= c.second;

    float s = static_cast<float>(abs(a.first * b.second - a.second * b.first)) / 2.0f;
    cout << fixed << setprecision(1) << s << endl;
    return 0;
}
