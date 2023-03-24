#include <iostream>

using namespace std;

template<typename T>
class List
{
public:
    List();
    ~List();

    void push_back(T data);
    int GetSize() { return Size; }

    T& operator[](const int index);

    void Vivod();

    void Pop_front();

    void Clear();

    void push_front(T data);

    void insert(T data, int index);

    void remuveAt(int index);

    void pop_back();

private:

    template<typename T>
    class Node {
    public:
        Node* pNext;
        T data;

        Node(T data = T(), Node* pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
    };

    int Size;
    Node<T>* head;

};

template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List()
{
    Clear();
}

template<typename T>
void List<T>::push_back(T data) {
    if (head == nullptr) {
        head = new Node<T>(data);
    }
    else {
        Node<T>* current = this->head;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    Size++;
}

template<typename T>
T& List<T>::operator[](const int index) {
    int counter = 0;
    Node<T>* current = this->head;
    while (current != nullptr) {
        if (counter == index) {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

template<typename T>
void List<T>::Vivod() {
    Node<T>* current = this->head;
    while (current != nullptr) {
        cout << current->data<<" ";
        current = current->pNext;
    }
    cout << endl;
}

template<typename T>
void List<T>::Pop_front() {
    Node<T> *temp = head;
    head = head->pNext;
    delete temp;

    Size--;

}

template<typename T>
void List<T>::Clear() {
    while (Size!=0)
    {
        Pop_front();
    }

}

template<typename T>
void List<T>::push_front(T data) {
    head = new Node<T>(data,head);
    Size++;
}

template<typename T>
void List<T>::insert(T data,int index) {
    if (index == 0) {
        push_front(data);
    }
    else {
        Node<T>* previous = this->head;

        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }
        previous->pNext = new Node<T>(data, previous->pNext);
        Size++;
    }
}

template<typename T>
void List<T>::remuveAt(int index) {
    if (index == 0) {
        Pop_front();
    }
    else {
        Node<T>* previous = this->head;

        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }
        Node<T>* temp = previous->pNext;
        previous->pNext = temp->pNext;
        delete temp;
        Size--;
    }
}

template<typename T>
void List<T>::pop_back() {
    remuveAt(Size - 1);
    
}

int main()
{
    setlocale(LC_ALL, "Russian");
    List<int> a;
    int ans=10, meaning, index;
    while (ans != 0) {
        a.Vivod();
        cout << "1 - добавить элемент в начало списка" << endl << "2 - добать элемент в конец списка" << endl << "3 - доступ к значению элемента по индексу" << endl << "4 - вставить элемент по индексу " << endl << "5 - удалить эдемент по индексу" << endl << "6 - удалить первый эелмент" << endl << "7 - удалить последний элемент" << endl << "8 - размер списка" << endl << "0 - выйти" << endl;
        cin >> ans;
        switch (ans)
        {
        case 1:
            cout << "введите значение";
            cin >> meaning;
            a.push_front(meaning);
            break;
        case 2:
            cout << "введите значение";
            cin >> meaning;
            a.push_back(meaning);
            break;
        case 3:
            cout << "введите индекс элемента";
            cin >> index;
            cout << a[index] << endl;
            break;
        case 4:
            cout << "введите значение и индекс элемента";
            cin >> meaning >> index;
            a.insert(meaning, index);
            break;
        case 5:
            cout << "введите индекс элемента";
            
            cin >> meaning >> index;
            a.remuveAt(index);
            break;
        case 6:
            a.Pop_front();
            break;
        case 7:
            a.pop_back();
            break;
        case 8:
            cout<<a.GetSize()<<endl;
            break;
        }
    }
    return 0;
}
