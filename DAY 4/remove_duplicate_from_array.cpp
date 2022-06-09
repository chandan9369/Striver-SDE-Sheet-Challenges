int removeDuplicates(vector<int> &arr, int n) {
    if (arr.size() == 0)
        return 0;
    int k = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] != arr[k - 1])
        {
            arr[k] = arr[i];
            k++;
        }
    }
    return k;
}