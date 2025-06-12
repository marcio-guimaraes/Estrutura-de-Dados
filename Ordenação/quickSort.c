int partition(int array[], int inicio, int fim)
{
    int pivo = array[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++)
    {
        if (array[j] <= pivo)
        {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[fim];
    array[fim] = temp;

    return i + 1;
}

void quickSort(int array[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int pivo = partition(array, inicio, fim);
        quickSort(array, inicio, pivo - 1);
        quickSort(array, pivo + 1, fim);
    }
}