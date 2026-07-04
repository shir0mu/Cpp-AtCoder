#include <bits/stdc++.h>
using namespace std;

int main()
{
    float distance;
    int vv;
    cin >> distance;
    distance /= 1000;
    if (distance <= 0.1) {
        vv = 0;
    } else if (0.1 <= distance && distance <= 5) {
        vv = distance * 10;
    } else if (6 <= distance && distance <= 30) {
        vv = distance + 50;
    } else if (35 <= distance && distance <= 70) {
        vv = (distance - 30) / 5 + 80;
    } else if (distance > 70) {
        vv = 89;
    } else {
        return 1;
    }

    cout << setfill('0') << setw(2) << vv << endl;
    return 0;
}
