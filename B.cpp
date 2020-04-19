#include <iostream>
#include <algorithm>
using namespace std;

#define intl long long
#define ts int

intl n, d;
intl bus[1000] = { 0 };
int a[2][100000] = { 0 };

int solve()
{
    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        cin >> bus[i];
    }
    int start = 0;
    bool a1 = false, a2 = false;
    bool a3 = true;
    int c = 0;
    int currentday = 0;
    for (int k = 0; k < d; k++)
    {
        currentday = k;
        for (int i = 0; i < n; i++)
        {
            if (currentday < bus[i])
            {
                currentday = bus[i];
                a1 = true;
            }
            else
            {
                for (int j = 2; j < d; j++)
                {
                    if (currentday <= (bus[i] * j))
                    {
                        currentday = bus[i]*j;
                        a2 = true;
                        break;
                    }
                }
            }
            if ((a1 || a2) && a3)
            {
                start = currentday;
                a3 = false;
            }
        }
        if (c <= currentday)
        {
            c = currentday;

            a[0][k] = start;
            a[1][k] = c;
        }
        a3 = true;
        a1 = false;
        a2 = false;
        if (currentday > d)
        {
            break;
        }
    }


    int max = 0;
    int index = 0;
    for (int i = 0; i < d; i++)
    {
        if (a[1][i] <= d)
        {
            max = a[1][i];
            index = i;
        }
        else
            break;
    }
    
    return a[0][index];
}


void main()
{
    int t;
    int num = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << ++num << ": " << solve() << endl;
    }
}
