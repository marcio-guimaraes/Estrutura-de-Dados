#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int casos;
    cin >> casos;

    while (casos--)
    {
        int quantidade;
        cin >> quantidade;

        vector<int> array(quantidade);

        for (int i = 0; i < quantidade; i++)
        {
            cin >> array[i];
        }

        sort(array.begin(), array.end());

        for (int i = 0; i < quantidade / 2; i++)
        {
            cout << array[i] << " ";
        }

        cout << array[quantidade - 1] << " ";

        for (int i = quantidade - 2; i >= quantidade / 2; i--)
        {
            cout << array[i];
            if (i != quantidade / 2)
                cout << " ";
        }

        cout << endl;
    }

    return 0;
}
