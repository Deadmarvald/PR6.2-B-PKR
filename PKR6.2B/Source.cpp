#include <iostream>
#include <Windows.h>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Info info;
};

void enqueue(Elem*& first, Elem*& last, int first_, int end_)
{
    Info a;
    if (first_ <= end_)
    {
        cout << "a" << first_ << "="; cin >> a;
        Elem* tmp = new Elem;
        tmp->info = a;
        tmp->link = NULL;
        if (last != NULL)
            last->link = tmp;
        last = tmp;
        if (first == NULL)
            first = tmp;
        enqueue(first, last, first_ + 1, end_);
    }
}

void print(Elem* first)
{
    if (first != NULL)
    {
        cout << first->info << " ";
        print(first->link);
    }
}

void dequeue(Elem*& first, Elem*& last)
{
    if (first != NULL)
    {
        Elem* tmp = first->link;
        delete first;
        first = tmp;
        if (first == NULL)
            last == NULL;
        dequeue(first, last);
    }
}

bool Scan(Elem*& L)
{
    if (L != NULL && L->link != NULL)
    {
        if (L->info == L->link->info)
        {
            return true;
        }
        else
        {
            Scan(L = L->link);
        }
    }
    else
    {
        return false;
    }
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Elem* first = NULL,
        * last = NULL;

    int N;

    cout << "Введіть кількість елементів: "; cin >> N;

    enqueue(first, last, 1, N);

    cout << endl;

    cout << "Список: "; print(first); cout << endl << endl;

    if (Scan(first))
    {
        cout << "Список містить пару сусідніх елементів "
            << "з однаковим значенням інформаційного поля" << endl << endl;
    }
    else
    {
        cout << "Список НЕ містить пару сусідніх елементів "
            << "з однаковим значенням інформаційного поля" << endl << endl;
    }

    dequeue(first, last);

    system("pause");
    return 0;
}