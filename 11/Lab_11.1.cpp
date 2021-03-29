#include <iostream>
#include <ctime>
using namespace std;


struct List
{
    int num;
    char data;
    List* next;
};

List* make(int size)
{
    if (size == 0) {
        cout << "Список не может быть создан" << endl;
        return 0;
    }
    List* first, * p;
    first = NULL;
    cout << "Введите 0 элемент: ";
    p = new List;
    cin >> p->data;
    first = p;
    for (int i = 1; i <= size-1; i++) {
        List* h = new List;
        p->next = h;
        p = p->next;
        cout << "Введите " << i << " элемент: ";
        cin >> p->data;
        p->next = NULL;
    }
    return first;
}

void print(List* first) {
    if (first == NULL) {
        cout << "Список пустой" << endl;
    }
    else {
        List* p = first;
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}

void del(List* first)
{
    while (first)
    {
        List* tmp = first;
        first = first->next;
        delete tmp;
    }
}

void add(List* first)
{
    List* p = first;
    List* n = new List;
    while (p != 0)
    {
        if (p->num % 2 != 0) {
            List* o = new List;
            n = p->next;
            p->next = o;
            p = p->next;
            cout << "Введите новый элемент: ";
            cin >> p->data;
            p->next = n;
        }
        p = p->next;
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    int size;
    cout << "Введите размер списка: ";
    cin >> size;
    List* head;

    List* list = make(size);
    cout << "Ваш список: ";
    print(list);
    add(list);
    print(list);
    return 0;
}
