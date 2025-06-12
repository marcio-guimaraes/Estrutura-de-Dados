void selectionSort(int array[], int n)
{

    if (n < 2) return;

    for (int i = 0; i < n - 1; i++)
    {
        int menor = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[menor])
            {
                menor = j;
            }
        }

        if (i != menor)
        {
            int temp = array[i];
            array[i] = array[menor];
            array[menor] = temp;
        }
    }
}