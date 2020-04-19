#include <iostream>
#include <algorithm>
using namespace std;

int n;
int h[100] = { 0 };

int solve()
{
    int count = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (h[i] > h[i - 1] && h[i] > h[i + 1])
        {
            count++;
        }
    }
    return count;
}

int main()
{

    int t;
    int num = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << ++num << ": " << solve() << endl;
    }
}
