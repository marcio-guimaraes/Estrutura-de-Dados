void mergeSort(int array[], int n)
{
    if (n < 2)
        return;

    int meio = n / 2;
    int inicio[meio];
    int fim[n - meio];

    for (int i = 0; i < meio; i++)
    {
        inicio[i] = array[i];
    }
    for (int i = meio; i < n; i++)
    {
        fim[i - meio] = array[i];
    }

    mergeSort(inicio, meio);
    mergeSort(fim, n - meio);

    int i = 0, j = 0, k = 0;
    while (i < meio && j < n - meio)
    {
        if (inicio[i] <= fim[j])
        {
            array[k++] = inicio[i++];
        }
        else
        {
            array[k++] = fim[j++];
        }
    }

    while (i < meio)
    {
        array[k++] = inicio[i++];
    }

    while (j < n - meio)
    {
        array[k++] = fim[j++];
    }
}