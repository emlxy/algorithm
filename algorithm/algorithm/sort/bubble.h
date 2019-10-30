void exchange(int a[], int i, int j)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "  " << a[i] << "  ";
    }
}


void bubblesort(int a[], int size)
{
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
        {
            if (a[i] > a[j])
                exchange(a, i, j);
        }
}