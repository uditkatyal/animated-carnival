// approach 1
// Time Complexity -> O(N)
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int i;
    int k;
    for (i = n - 1; i > 0; i--)
    {
        if (permutation[i] > permutation[i - 1])
        {
            k = i;
            break;
        }
    }
    if (i == 0)
    {
        reverse(permutation.begin(), permutation.end());
        return permutation;
    }
    for (int j = n - 1; j >= k; j--)
    {
        if (permutation[j] > permutation[k - 1])
        {
            swap(permutation[j], permutation[k - 1]);
            break;
        }
    }
    reverse(permutation.begin() + k, permutation.end());
    return permutation;
}

// approach 2
// STL : Using C++ in-build function
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    next_permutation(permutation.begin(), permutation.end());
    return permutation;
}