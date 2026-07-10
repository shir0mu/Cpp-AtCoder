#include <bits/stdc++.h>
using namespace std;

int main()
{
    string w;
    string r;
    cin >> w;
    for (char c: w) {
        if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
            continue;
        } else {
            r += c;
        }
    }

    cout << r << endl;
    return 0;
}
