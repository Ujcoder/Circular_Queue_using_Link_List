#include<iostream>
using namespace std;

struct node
{
    int info;
    node* link;
};

node* front = 0;
node* rear = 0;

void enqueue(int x)
{
    node* p = new node;
    p->info = x;
    p->link = 0;

    if (front == 0 && rear == 0)
    {
        front = rear = p;
        rear->link = front;  
    }
    else
    {
        rear->link = p;
        rear = p;
        rear->link = front;  
    }
}

int dequeue()
{
    int x;
    node* p;

    if (front == 0 && rear == 0)
    {
        cout << "Cqueue is empty........! " << endl;
        return -1;
    }

    x = front->info;
    p = front;

    if (front == rear)
        front = rear = 0;
    else
    {
        front = front->link;
        rear->link = front;  
    }

    delete p;
    return x;
}

void display()
{
    node* t = front;

    if (t == 0)
    {
        cout << "Cqueue is Empty........! " << endl;
        return;
    }

    cout << "All the Elem in Cqueue is : " << endl;

    do
    {
        cout << t->info << endl;
        t = t->link;
    } while (t != front);
}

int main()
{
    int v, ch;

    do
    {
        cout << "1.Enqueue \n2.Dequeue \n3.Display \n4.Exit" << endl;
        cout << "Enter the choice : "; cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter Enqueue Elem : " << endl;
            cin >> v;
            enqueue(v);
            break;
        case 2:
            v = dequeue();
            if (v != -1)
                cout << "The value is deleted : " << v << endl;
            break;
        case 3:
            display();
            break;
        default:
            cout << "Exiting" << endl;
            ch = 4;
        }
    } while (ch != 4);

    return 0;
}
