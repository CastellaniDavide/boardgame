/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>
using namespace std;

// input data
int N, L, U;

bool my_check(int test);

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(3 == scanf("%d %d %d", &N, &L, &U));

    int min_ = 0;
    int max_ = N / L;

    while (max_ > min_ + 1)
    {
        if(my_check((min_ + max_) / 2))
        {
            max_ = (min_ + max_) / 2;
        }
        else
        {
            min_ = (min_ + max_) / 2;
        }
    }
    if (my_check(min_))
    {
        cout << min_ << endl;
        return 0;
    }
    if (my_check(max_))
    {
        cout << max_ << endl;
        return 0;
    }

    cout << -1 << endl; // Impossible
    return 0;
}

bool my_check(int test)
{
    int min_ = L * test;
    int max_ = U * test;
    return N <= max_ && N >= min_;
}
