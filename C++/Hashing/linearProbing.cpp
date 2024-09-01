vector<int> linearProbing(int m, int arr[], int n)
{
    vector<int> res(m, -1); // Initialize the result vector with -1

    for (int i = 0; i < n; i++)
    {
        int h = arr[i] % m; // Calculate the hash for the current element
        if (res[h] == -1)
        {
            res[h] = arr[i];
        }
        else
        {
            int flag = 0;
            int k = h;
            int counter = 0;
            while (counter < m and res[k] != -1 and res[k] != arr[i])
            {
                k = (k + 1) % m;
                counter++;
            }
            if (res[k] == -1)
            {
                res[k] = arr[i];
            }
        }
    }

    return res;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}