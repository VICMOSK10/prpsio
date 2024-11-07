// babelkowe.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

void buble_sort_for_for(int n, int* tab)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (tab[i] < tab[j])
            {
                int savedValueFromFirstArray = tab[i];
                tab[i] = tab[j];
                tab[j] = savedValueFromFirstArray;
            }
        }
    }
}

int check_if_sorted(int n, int* tab)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (tab[i] < tab[i + 1])
        {
            return 1;
        }
    }
    return 0;
}

void cout_array(int n, int* tab)
{
    if (n > 30)
    {
        return;
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << tab[i];
    }
}

void buble_sort_while_for_index(int n, int* tab)
{
    bool zamiana = true;
    while (zamiana)
    {
        zamiana = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (tab[i] > tab[i + 1])
            {
                zamiana = true;
                int savedValueFromElement = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = savedValueFromElement;
            }
        }
    }
}

int main()
{
    int n = 5;
    int* tab = new int[n]{ 5,3,2,1,6 };

    //buble_sort_for_for(n, tab);
    buble_sort_while_for_index(n, tab);



    if (check_if_sorted(n, tab) == 1)
    {
        std::cout << "Failed to sort array";
        return 1;
    }
}

void buble_sort_while_shorten_for_index()
{

}

