#include <iostream>
#include <vector>
using namespace std;

// use extra space
void mergeSort(vector<int> &vec, int st, int mid, int en)
{
    int a = mid - st + 1;
    int b = en - mid;

    vector<int> A(a);
    vector<int> B(b);
    int idx = st;
    for (int i = 0; i < a; i++)
        A[i] = vec[idx++];

    for (int i = 0; i < b; i++)
        B[i] = vec[idx++];

    int aidx = 0, bidx = 0;
    idx = st;
    while (aidx < a && bidx < b)
    {

        if (A[aidx] < B[bidx])
            vec[idx++] = A[aidx++];
        else
            vec[idx++] = B[bidx++];
    }

    while (aidx < a)
        vec[idx++] = A[aidx++];
    while (bidx < b)
        vec[idx++] = B[bidx++];
}

void devide(vector<int> &vec, int st, int en)
{

    if (st == en)
        return;
    int mid = st + (en - st) / 2;
    devide(vec, st, mid);
    devide(vec, mid + 1, en);
    mergeSort(vec, st, mid, en);
}

int main()
{

    int n;
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    devide(vec, 0, n - 1);

    for (auto ele : vec)
        cout << ele << " ";
}