#include <bits/stdc++.h>
using namespace std;

void buildsegtree(vector<int> &arr, int i, int l, int r, vector<int> &segtree)
{ // O(n) in building the segment tree
    if (l == r)
    {
        segtree[i] = arr[l];
        return;
    }

    int mid = (l + r) / 2;

    buildsegtree(arr, (2 * i + 1), l, mid, segtree);
    buildsegtree(arr, (2 * i + 2), mid + 1, r, segtree);

    segtree[i] = segtree[2 * i + 1] + segtree[2 * i + 2];
}

int main()
{
    int n = 4;
    vector<int> arr = {3, 1, 2, 4};

    vector<int> segtree(2 * n - 1);

    buildsegtree(arr, 0, 0, n - 1, segtree);

    for (int i : segtree)
    {
        cout << i << " ";
    }
    return 0;
}