void QuadraticProbing(vector<int> &res, int m, int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int h = arr[i] % m;
        if (res[h] == -1)
        {
            res[h] = arr[i];
        }
        else
        {
            int flag = 0, j = 1;
            int k = h;
            int counter = 0;
            while (counter < m and res[k] != -1 and res[k] != arr[i])
            {
                k = (h + (j * j)) % m;
                j++;
                counter++;
            }
            if (res[k] == -1)
            {
                res[k] = arr[i];
            }
        }
    }
}

int main()
{
    
    return 0;
}