void insertionSort(int array[], int n)
{
    if (n < 2) return;

    for (int i = 1; i < n; i++)
    {
        int temp = array[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (array[j] < temp)
            {
                break;
            }

            array[j + 1] = array[j];
        }
        array[j+1] = temp;
    }
}

