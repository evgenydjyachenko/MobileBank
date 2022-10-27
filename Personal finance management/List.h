#pragma once
#include <iostream>
using namespace std;

template <typename T>
class List
{
private:
    template <typename T>
    class Node
    {
    public:
        T data;
        Node<T>* pNext;
        Node<T>* pPrev;
        Node() = default;
        Node(T data, Node<T>* pNext = nullptr, Node<T>* pPrev = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
            this->pPrev = pPrev;
        }
    };
    int size;
    Node<T>* head;
    Node<T>* tail;
public:
    List() : size(0), head(nullptr), tail(nullptr) {}

    void push_back(T data)
    {
        if (size == 0)
        {
            head = tail = new Node<T>(data);
        }
        else
        {
            Node<T>* temp = this->tail;
            tail = new Node<T>(data, nullptr, tail);
            temp->pNext = tail;
        }
        size++;
    }

    void push_front(T data)
    {
        if (head == nullptr)
        {
            head = tail = new Node<T>(data);
        }
        else
        {
            Node<T>* temp = this->head;
            head = new Node<T>(data, head, nullptr);
            temp->pPrev = head;         
        }
        size++;
    }

    void pop_front()
    {
        if (head == nullptr)
        {
            return;
        }
        else
        {
            Node<T>* temp = new Node<T>;
            temp = head;
            head = head->pNext;
            delete temp;
            size--;
        }
    }

    void pop_back()
    {
        if (tail == nullptr)
            return;
        else
        {
            Node<T>* temp = new Node<T>;
            temp = tail;
            tail = tail->pPrev;
            delete temp;
            size--;
        }
    }

    void insert(T data, int index)
    {
        if (index == 0)
        {
            push_front(data);
        }
        else if (index == size)
        {
            push_back(data);

        }
        else if (index > size - 1)
        {
            cout << "������ ������� �� ����������" << endl;
        }
        else
        {
            if (size / 2 < index)
            {
                Node<T>* next = this->tail;
                for (int i = size - 1; i > index - 1; i--)
                {
                    next = next->pPrev;
                }
                Node<T>* InsertPrev = next->pNext;
                Node<T>* temp = new Node<T>(data);
                InsertPrev->pPrev = temp;

                temp->pPrev = next;
                temp->pNext = InsertPrev;
                next->pNext = temp;
            }
            else
            {
                Node<T>* previous = this->head;
                for (int i = 0; i < index; i++)
                {
                    previous = previous->pNext;//������� �� �����, ������� ��������� �� ��� ������� ���� �� ����� �������� �������
                }
                Node<T>* InsertPrev = previous->pPrev;// ������� ����������, � ������� ���������� ����� ����������� ��������, ����� �������� ����� ��������� �������
                Node<T>* temp = new Node<T>(data);// ������� ����� ������� c �������
                InsertPrev->pNext = temp;//����������� ����� ������ ��������, ��� ����� ������������� ����� � ����������

                temp->pNext = previous;//������������� ����� ������ �������� � ������� ���� ��������(������� ����� �� �������), �� ������� ����� ��������� ��� ����� �������
                temp->pPrev = InsertPrev;// ������������� ����� ������ �������� � ������� ����������� ��������(index-1)
                previous->pPrev = temp;//��������� ������ ����� ����� ����������, �.� �� �������� ����� ���� �����, � ������������� �� ����� ���������� ��������� � �����

            }
            size++;
        }
    }

    void removeAt(int index)
    {
        if (index == 0)
        {
            pop_front();
        }
        else if (index == size - 1)
        {
            pop_back();
        }
        else if (index > size - 1)
        {
            cout << "������ ������� �� ����������" << endl;
        }
        else
        {
            if (size / 2 >= index)
            {
                Node<T>* previous = this->head;
                for (int i = 0; i < index - 1; i++)
                {
                    previous = previous->pNext;
                }
                Node<T>* temp = previous->pNext;

                Node<T>* prevDel = temp->pPrev;
                Node<T>* AfterDel = temp->pNext;

                prevDel->pNext = AfterDel;
                AfterDel->pPrev = prevDel;
                delete temp;
                size--;
            }
            else
            {
                Node<T>* next = this->tail;
                for (int i = size - 1; i > index + 1; i--)
                {
                    next = next->pPrev;
                }
                Node<T>* temp = next->pPrev;
                Node<T>* AfterDel = temp->pPrev;
                Node<T>* prevDel = temp->pNext;
                AfterDel->pNext = prevDel;
                prevDel->pPrev = AfterDel;

                delete temp;
                size--;
            }
        }
    }

    inline int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    T& operator[](int index)
    {
        Node<T>* current = this->head;
        int counter = 0;
        while (current->pNext != nullptr)
        {
            if (counter == index)
                return current->data;
            current = current->pNext;
            counter++;
        }
    }

    void print() const
    {
        Node<T>* current = this->head;
        for (int i = 0; i < size; i++)
        {
            cout << current->data;
            current = current->pNext;
        }
        cout << endl;
    }

    void clear()
    {
        while (size)
        {
            pop_front();
        }
    }

    ~List()
    {
        clear();
    }
};




