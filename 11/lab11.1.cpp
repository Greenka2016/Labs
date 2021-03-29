#include <iostream>
#include <ctime>
using namespace std;

struct List
{
	char data;
	List* next;
};

List* make(int size)
{
    if (size == 0){
        cout << "������ �� ����� ���� ������" << endl;
        return 0;
    }
    List* first, *p;
    first = NULL;
    cout << "������� 1 �������:";
    p = new List;
    cin >> p->data;
    first = p;
    for (int i = 2; i <= size; i++){
        List* h = new List;
        p->next = h;
        p = p -> next;
        cout << "������� " << i << "�������: ";
        cin >> p->data;
        p-> next = NULL;
    }
    return first;
}

void print(List* first){
    if (first == NULL){
        cout << "������ ������" << endl;
    }else{
    List* p = first;
    while (p != NULL){
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

void add(List* &first,int size) {
    if (first == NULL)
    {
        cout << "������ ����" << endl;
    }
    int k;
    int n;
    int l = 1;
    cout << "������� ���������� ����������� ���������";
    cin >> k;
    List*p = first;
    for (int i = 1; i < k; i++){
            cout << "������� " << l << " �������: ";
            List* h = new List;
            cin >> h->data;
            List* p = first;
            for (n = 1; n < size; n++){
                if (n = l){
                    while (p != NULL)
                    {
                        if (n == l)
                        {
                            h -> next = p;
                            p-> next = h;
                            p = p-> next -> next;
                        }
                        else{
                            p=p->next;
                        }
                    }
                }
            }

    }
    l+=2;
}


int main(){
    setlocale(LC_ALL, "Rus");
    int size;
    cout << "������� ������ ������: ";
    cin >> size;

    List* list = make(size);
    cout << "��� ������: ";
    print(list);
    add(list, size);
    print(list);
    return 0;
}
