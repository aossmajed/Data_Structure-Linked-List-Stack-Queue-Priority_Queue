//@aossmajed
#include <iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include <conio.h>
#include <stdlib.h>
#include<vector>
#include <iostream>
#include <stack>
#include <string>
#include<cassert>
using namespace std;
const int max_size = 10;
using namespace std;
////////////////////////class SINGLE LL/////////////////////////
template <class T>
class FCISLL
{
private:
    struct Node
    {
        T data;
        Node*next;
    };
    Node *head;
    Node *tail;
    int count;
public:
    template <class TT>
    friend ostream& operator<<(ostream&, FCISLL< TT>);
    FCISLL()
    {
        head = tail = NULL;
        count = 0;
    }
    bool isEmpty()
    {
        return (count == 0);
    }
    void addToHead(T item)
    {
        Node*newNode = new Node;
        newNode->data = item;
        if (count == 0)
        {
            head = tail = newNode;
            newNode->next = NULL;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        count++;
    }

    void addToTail(T item)
    {
        Node*newNode = new Node;
        newNode->data = item;
        if (count == 0)
        {
            head = tail = newNode;
            newNode->next = NULL;
        }
        else
        {
            tail->next = newNode;
            newNode->next = NULL;
            tail = newNode;
        }
        count++;
    }


    void addToIndex(int index, T item)
    {
        if (index < 0 || index > count)
            cout << "ERROR: Out of range" << endl;
        else
        {
            Node *newNode = new Node;
            newNode->data = item;
            if (index == 0) //insert at the begining
                addToHead(item);
            else if (index== count) //insert at the end;
                addToTail(item);
            else
            {
                Node*current = head;
                for (int i = 1; i < index; i++)
                    current = current->next;

                newNode->next = current->next;
                current->next = newNode;
                count++;
            }

        }
    }
    int removeOddSprintEven()
    {
        int sum = head->data;
        Node *current = head->next;
        Node *trailCurrent = head;

        while (current != NULL)
        {
            if (current->data % 2 == 0)
            {
                trailCurrent = current;
                current = current->next;
                Node*current = head;
            }
            else
            {
                trailCurrent->next = current->next;
                delete current;
                count--;
                current = trailCurrent->next;
            }
        }
        return sum;
    }
    void removeHead()
    {
        if (count== 0)
            cout << "ERROR: EMPTY LIST" << endl;
        else if (count == 1)
        {
            delete head;
            tail = head = NULL;
            count--;
        }
        else
        {
            Node*current = head;
            head = head->next;
            delete current;
            count--;
        }
    }
    void removeTial()
    {
        if (count == 0)
            cout << "ERROR: EMPTY LIST" << endl;
        else if (count== 1)
        {
            delete head;
            tail = head = NULL;
            count--;
        }
        else
        {
            Node*current = head->next;
            Node*trailCurrent = head;
            while (current != tail)
            {
                trailCurrent = current;
                current = current->next;
            }
            delete current;
            trailCurrent->next = NULL;
            tail = trailCurrent;
            count--;
        }
    }
    void removeitem(int index)
    {
        if (index < 0 || index >= count)
            cout << "ERROR: Out of range" << endl;
        else
        {
            Node*current, *trailCurrent;
            if (index == 0)
            {
                current = head;
                head = head->next;
                delete current;
                count--;
                if (count == 0)
                    tail = NULL;
            }
            else
            {
                current = head->next;
                trailCurrent = head;
                for (int i = 1; i < index; i++)
                {
                    trailCurrent = current;
                    current = current->next;
                }

                trailCurrent->next = current->next;
                if (tail == current)
                    tail = trailCurrent;
                delete current;
                count--;
            }
        }
    }
    void reverse()
    {
        Node *prev, *next, *curr;
        prev = NULL;
        curr = head;
        next = curr->next;
        while (next != NULL)//curr!=NULL
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    void print()
    {
        Node*current = head;
        while (current != NULL)
        {
            cout << current->data<<" ";
            current = current->next;
        }
    }
    clearList()
    {
        Node *current;
        while (head != NULL)
        {
            current = head;
            head = head->next;
            delete current;
        }
        tail = NULL;
        count = 0;
    }
    ~FCISLL()
    {
        clearList();
    }
};
////////////////////////class Double LL/////////////////////////
template <class t>
class FCIDLL
{
private:
    struct Node
    {
        t item;
        Node* next;
        Node* prev;
    };
    Node* first;
    Node* last;
    int count;

public:
    FCIDLL()
    {
        first = NULL;
        last = NULL;
        count = 0;
    }
    bool isEmpty()
    {
        return (first == NULL);
    }
    void destroy()
    {
        Node *temp;
        while (first != NULL)
        {
            temp = first;
            first = first->next;
            delete temp;
        }
        last = NULL;
        count = 0;
    }

    void addtoTail(int val)
    {
        Node* newNode = new Node;
        newNode->item = val;
        if (count == 0)
        {
            first = last = newNode;
            newNode->next = newNode->prev = NULL;
        }
        else
        {
            newNode->next = NULL;
            newNode->prev = last;
            last->next = newNode;
            last = newNode;



        }
        count++;
    }



    void addtoHead(t item)
    {
        Node*newNode = new Node;
        newNode->item = item;
        if (count == 0)
        {
            first = last = newNode;
            newNode->next = newNode->prev = NULL;
        }
        else
        {
            newNode->next = first;
            newNode->prev = NULL;
            first->prev = newNode;
            first = newNode;

        }
        count++;
    }






    void addtoindex(int index, t item)
    {
        if (index < 0 || index > count)
            cout << "Out Of Range ...!" << endl;
        else
        {
            Node *newNode = new Node;
            newNode->item = item;
            if (index == 0)
                addtoHead(item);
            else if (index == count)
                addtoTail(item);
            else
            {
                Node *current = first;
                for (int i = 1; i < index; i++)
                {
                    current = current->next;
                }

                newNode->next = current->next;
                newNode->prev = current;
                current->next->prev = newNode;
                current->next = newNode;
                count++;
            }

        }
    }


    void removeHead()
    {
        if (count == 0)
            cout << "Empty List" << endl;
        else if (count == 1)//first == last
        {
            delete first;
            last = first = NULL;
        }
        else
        {
            Node* current = first;
            first = first->next;
            first->prev = NULL;
            delete current;

        }
        count--;
    }

    void deleteNthNode(int index)
    {
        if (index < 0 || index >= count)
        {
            cout << "Out Of Range" << endl;
            return;
        }
        else if (index == 0)
        {
            removeHead();
        }
        else if (index== count - 1)
        {
            removeTail();
        }
        else
        {
            Node *current = first->next;


            for (int i = 1; i < index; i++)
            {
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
        count--;
    }
    void removeTail()
    {
        if (count == 0)
            cout << "Empty List" << endl;
        else if (count == 1)
        {
            delete first;
            //		delete last;
            last = first = NULL;
            count--;
        }
        else
        {
            Node *current = last;
            last = last->prev;
            last->next = NULL;
            delete current;
            count--;
        }
    }



    void remove(t item)
    {
        if (isEmpty())
        {
            cout << "Empty List Can't Remove ";
            return;
        }
        Node*current = first->next;

        if (first->item == item)
        {

            removeHead();
            return;
        }
        else
        {


            while (current != NULL)
            {
                if (current->item == item)
                    break;
                current = current->next;
            }

            if (current == NULL)
            {
                cout << "The item is not there\n";
                return;
            }
            else if (current->next == NULL)
            {
                removeTail();
                return;
            }

            else
            {
                current->prev->next = current->next;
                //if (current->next != NULL)
                current->next->prev = current->prev;
                delete current;
                count--;
            }

        }


    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Empty List Can't Display...!";
        }
        else
        {
            Node* temp = first;
            while (temp != nullptr)
            {
                cout << temp->item << " ";
                temp = temp->next;
            }
        }
        cout << endl;

    }



    void reverse_print()
    {
        if (isEmpty())
        {
            cout << "Empty List Can't Display Reverse...!";
        }
        else
        {
            Node* temp = last;
            while (temp != NULL)
            {
                cout << temp->item << " ";
                temp = temp->prev;
            }
        }

    }
    int removeOddprintEven()
    {
        int sum = first->item;
        Node *current = first->next;
        Node *trailCurrent = first;

        while (current != NULL)
        {
            if (current->item % 2 == 0)
            {

                trailCurrent = current;
                current = current->next;
                Node*current = first;
            }
            else
            {
                trailCurrent->next = current->next;
                delete current;
                count--;
                current = trailCurrent->next;
            }
        }


    }


};
/////////////////////// class  of stack and Queue/////////////////
template<class t>
class Queues_and_Stacks
{
private:
    int top;
    t item[max_size];
    int rear;
    int front;
    int length;
    t *arr;
    int maxSize;

public:
    Queues_and_Stacks()
    {
        top=-1;
    }
    Queues_and_Stacks(int size)
    {
        if (size <= 0)
            maxSize = 100;
        else
            maxSize = size;

        front = 0;

        arr = new int[maxSize];
        rear = maxSize - 1;
        length = 0;
    }
    void push(t Element)
    {
        if (top >= max_size-1)
        {
            cout << "Stack full on push";
        }
        else
        {
            top++;
            item[top] = Element;
        }
    }
    void pop()
    {
        if (isEmpty())
            cout << "stack empty on pop";
        else
            top--;
    }
    void pop(t&Element)
    {
        if (isEmpty())
            cout << "stack empty on pop";
        else
        {
            Element = item[top];
            top--;
        }
    }
    void getTop(t&stackTop)
    {
        if (isEmpty())
            cout << "stack empty on getTop";
        else
        {
            stackTop = item[top];
            cout << stackTop << endl;
        }
    }
    void print()
    {
        cout << "[ ";
        for (int i = top; i >= 0; i--)
        {
            cout << item[i] << " ";
        }
        cout << "]";
        cout << endl;

    }
    bool isEmpty()
    {
        return top < 0;
    }
    int q_isEmpty()
    {
        return length == 0;
    }
    bool isFull()
    {
        return length == maxSize;
    }
    void enqueue(t Element)
    {
        if (isFull())
        {
            cout << "Queue Full Can't Enqueue ...!";
        }
        else
        {
            rear = (rear + 1) % maxSize;
            arr[rear] = Element;
            length++;
        }
    }
    void dequeue()
    {
        if (q_isEmpty())
        {
            cout << "Empty Queue Can't Dequeue ...!";
        }
        else
        {
            front = (front + 1) % maxSize;
            --length;

        }


    }
    int frontQueue()
    {
        assert(!q_isEmpty());
        return arr[front];
    }

    int rearQueue()
    {
        assert(!q_isEmpty());
        return arr[rear];
    }


    void printQueue()
    {
        if (!isEmpty())
        {
            for (size_t i = front; i != rear; i = (i + 1) % maxSize)
            {
                cout << arr[i] << " ";
            }
            cout << arr[rear];
        }
        else
            cout << "Empty Queue";
    }

    int queueSearch(t element)
    {
        int pos = -1;
        if (!q_isEmpty())
        {
            for (int i = front; i != rear; i = (i + 1) % maxSize)
                if (arr[i] == element)
                {
                    pos = i;
                    break;
                }
            if (pos == -1)
            {
                if (arr[rear] == element)
                    pos = rear;
            }
        }
        else
            cout << "Q is empty ! " << endl;
        return pos;
    }

};
/////////////////////// class of Priority  Queue/////////////////
template<class t>
class  Priority_Queue
{
private:
    struct Node
    {
        t item;
        Node *next;
        int prio;
    };
    int count;
    Node *head, *tail;

public:

    Priority_Queue()
    {
        tail=NULL;
        head=NULL;
        count=0;
    }
    bool isEmpty()
    {
        return (count == 0);
    }

    void dequeue()
    {
        if (isEmpty())
            cout << "Empty Queue" << endl;
        else if (count == 1)
        {
            delete head;
            tail= NULL;
            count = 0;
        }
        else
        {
            Node *current = head;
            head= head->next;
            delete current;//free(current)
            count--;
        }
    }

    void enqueue(t item,int prio )
    {
        Node *newNode = new Node;
        newNode->item = item;
        newNode->next = NULL;

        if (count == 0)
            tail = head = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    t front()
    {
        assert(!isEmpty());
        return head->item;
    }

    t rear()
    {
        assert(!isEmpty());
        return tail->item;
    }

    void clearQueue()
    {
        Node *current;

        while (head != NULL)
        {
            current = head;
            head = head->next;
            delete current;
        }
        tail = NULL;
        count = 0;
    }

    void display()
    {
        Node*cur = head;
        cout << "Item in the queue :[ ";
        while (cur!=NULL)
        {
            cout << cur->item<<" ";
            cur = cur->next;
        }
        cout << "]" << endl;
    }
    void priority_print()
    {
        Node*cur = head;
        int c = count;
        cout << c <<endl;
        cout << count <<endl;
        cout << "Item in the Priority queue :[ ";
        while ( cur!=NULL && c - 1 != 0)
        {
            if(cur->prio < cur->next->prio)
            {
                swap(cur->next->item,cur->item);
                cout << cur->item<<" ";
                cur=cur->next;

            }
            c -=1;
            cout << c <<endl;

        }

        cout << "]" << endl;
    }

};
int main()
{
    FCISLL<int> s;
    FCIDLL<int> d1;
    Queues_and_Stacks<int> q;
    Queues_and_Stacks<int> qq(20);
    Priority_Queue <int>q1;
    int x;
    cout<<" enter 1 if you wont SLL"<<endl;
    cout<<" enter 2 if you wont DLL"<<endl;
    cout<<" enter 3 if you wont queues and stack"<<endl;
    cout<<" enter 4 if you wont Priority  Queue"<<endl;
    cout<<"What is your choise :";
    cin>>x;

////////////////////////mail of class SINGLE LL/////////////////////////
    if (x == 1)
    {
        cout<<"enter your data how meny item you wont in SLL:";
        int y;
        cin>>y;
        int arr[y];
        for(int i=0 ; i<y; i++)
        {
            cout<<"please entar your  item "<<i<<":";
            cin>>arr[i];
        }
        s.addToHead(arr[0]);
        for(int j=1 ; j<y; j++)
        {
            s.addToTail(arr[j]);
        }
        cout<<"your item in SLL IS :"<<endl;
        s.print();
        cout<<endl;
        cout<<"your item in SLL after delite odd :"<<endl;
        s.removeOddSprintEven();
        s.print();
        cout<<endl;
        cout<<"-----------------------------------------------"<<endl;
        cout<<"to add head enter     1"<<endl;
        cout<<"to add tail enter     2"<<endl;
        cout<<"to add item enter     3"<<endl;
        cout<<"to remove head enter  4"<<endl;
        cout<<"to remove tail enter  5"<<endl;
        cout<<"to remove item enter  6"<<endl;
        cout<<"to reverse item enter 7"<<endl;
        cout<<"to print item enter   8"<<endl;
        cout<<"enter your choise :";
        int z;
        cin>>z;
        switch(z)
        {
        case 1:
            int y;
            cout<<"enter your namer to add in head :"<<endl;
            cin >>y;
            s.addToHead(y);
            cout<<"your SLL after add head: "<<endl;
            s.print();
            cout<<endl;
            cout<<"your SLL after remove odd :"<<endl;
            s.removeOddSprintEven();
            s.print();
            break;

        case 2:

            int p;
            cout<<"enter your namber to add in head :"<<endl;
            cin >>p;
            s.addToTail(p);
            cout<<"your SLL after add head: "<<endl;
            s.print();
            cout<<endl;
            cout<<"your SLL after remove odd :"<<endl;
            s.removeOddSprintEven();
            s.print();
            break;
        case 3:
            int Q, z;
            cout<<"enter your number of location or index :"<<endl;
            cin >>Q;
            cout<<"enter your namer to add :"<<endl;
            cin >>z;
            s.addToIndex(Q,z);
            cout<<"your SLL after add head : "<<endl;
            s.print();
            cout<<endl;
            cout<<"your SLL after remove odd :"<<endl;
            s.removeOddSprintEven();
            s.print();
            break;
        case 4:
            cout<<"your SLL after remove head :"<<endl;
            s.removeHead();
            s.print();
            break;
        case 5:
            cout<<"your SLL after remove Tail :"<<endl;
            s.removeTial();
            s.print();
            break;

        case 6:

            int W;
            cout<<"enter your index remove :"<<endl;
            cin>>W;
            s.removeitem(W);
            s.print();
            break;
        case 7:

            cout<<"your SLL after revers"<<endl;
            s.reverse();
            s.print();
            break;
        case 8:

            cout<<"your SLL ITEM"<<endl;
            s.print();
            break;
        default:
            break;
        }
    }
    ////////////////////////main class Double LL/////////////////////////
    if (x == 2)
    {
        cout<<"enter your data how meny item you wont in DLL:";
        int f;
        cin>>f;
        int arr[f];
        for(int i=0 ; i<f; i++)
        {
            cout<<"please entar your  item "<<i<<":";
            cin>>arr[i];
        }
        d1.addtoHead(arr[0]);
        for(int j=1 ; j<f; j++)
        {
            d1.addtoHead(arr[j]);
        }
        cout<<"your item in DLL IS :"<<endl;
        d1.print();
        cout<<endl;
        cout<<"your item in DLL after delite odd :"<<endl;
        d1.removeOddprintEven();
        d1.print();
        cout<<endl;
        cout<<"-----------------------------------------------"<<endl;
        cout<<"to add head enter     1"<<endl;
        cout<<"to add tail enter     2"<<endl;
        cout<<"to add item enter     3"<<endl;
        cout<<"to remove head enter  4"<<endl;
        cout<<"to remove tail enter  5"<<endl;
        cout<<"to remove item enter  6"<<endl;
        cout<<"to reverse item enter 7"<<endl;
        cout<<"to print item enter   8"<<endl;
        cout<<"enter your choise :";
        int z;
        cin>>z;
        switch(z)
        {
        case 1:
            int y;
            cout<<"enter your number to add in head :";
            cin >>y;
            d1.addtoHead(y);
            cout<<"your DLL after add head: "<<endl;
            d1.print();
            cout<<endl;
            cout<<"your DLL after remove odd:"<<endl;
            d1.removeOddprintEven();
            d1.print();
            break;

        case 2:
            int p;
            cout<<"enter your number to add in head: ";
            cin >>p;
            d1.addtoTail(p);
            cout<<"your DLL after add head: "<<endl;
            d1.print();
            cout<<endl;
            cout<<"your DLL after remove odd"<<endl;
            d1.removeOddprintEven();
            d1.print();
            break;
        case 3:
            int Q, z;
            cout<<"enter your number of location or index :";
            cin >>Q;
            cout<<"enter your number to add :";
            cin >>z;
            d1.addtoindex(Q,z);
            cout<<"your DLL after add head : "<<endl;
            d1.print();
            cout<<endl;
            cout<<"your DLL after remove odd :"<<endl;
            d1.removeOddprintEven();
            d1.print();
            break;
        case 4:
            cout<<"your DLL after remove head :"<<endl;
            d1.removeHead();
            d1.print();
            break;

        case 5:

            cout<<"your DLL after remove Tail :"<<endl;
            d1.removeTail();
            d1.print();
            break;
        case 6:

            int W;
            cout<<"enter your index remove"<<endl;
            cin>>W;
            d1.remove(W);
            d1.print();
            break;

        case 7:
            cout<<"your DLL after revers"<<endl;
            d1.reverse_print();
            break;
        case 8:
            cout<<"your DLL ITEM"<<endl;
            d1.print();
            break;
        default:
            cout << "something wrong !!" << endl;
            break;
        }
    }
    /////////////////////// main class of Priority  Queue/////////////////
    if(x==3)
    {
        cout<<" to stack enter 1"<<endl;
        cout<<" to queus enter 2"<<endl;
        cout<<"enter your choise :"<<endl;
        int n;
        cin>>n;
        ///////////////////// main  stack/////////////////////////
        if(n==1)
        {
            cout <<"how match number need for push "<<endl;
            int x;
            cin>>x;
            int item[x];
            for (int i=0; i<x; i++)
            {
                cout<<"enter your push  "<<i<<"  ";
                cin>>item[i];
            }
            for(int j=0; j<x; j++)
            {
                q.push(item[j]);
            }
            cout<<"your item  ";
            q.print();
            cout<<"-------------------------------------"<<endl;
            cout<<"choise what you need  "<<endl;
            cout<<"choise 1 to push number"<<endl;
            cout<<"choise 2 to pop number"<<endl;
            cout<<"choise 3 to get top"<<endl;
            cout<<"enter your choise :";
            int w;
            cin>>w;
            if(w==1)
            {
                int r;
                cout<<"enter your number to push = ";
                cin>>r;
                q.push(r);
                cout<<"your item after push ";
                q.print();
                cout<<"---------------------";
                cout<<"are you need to pop number"<<endl;
                cout<<"enter 1 for yes"<<endl;
                cout<<"enter 2 for NO"<<endl;
                int l;
                cin>>l;
                cout<<"enter your choise :";
                if(w==1)
                {
                    cout<<"your item  ";
                    q.print();
                    cout<<"your item after pop ";
                    q.pop();
                    q.print();
                }
            }
            if(w==2)
            {
                cout<<"your item  ";
                q.print();
                cout<<"your item after pop ";
                q.pop();
                q.print();
            }
            if(w==3)
            {
                int t;
                cout<<"enter your number to gettop  ";
                cin>>t;
                cout<<"your TOP is =";
                q.getTop(t);

            }

        }
        ///////////////////// main queue stack/////////////////////////
        if(n==2)
        {
            cout <<"how match number need for enqueue :"<<endl;
            int x;
            cin>>x;
            int p[x];
            for (int i=0; i<x; i++)
            {
                cout<<"enter your push  "<<i<<"  ";
                cin>>p[i];
            }
            //  q.enqueue(arr[x]);
            for(int j=0; j<x; j++)
            {
                qq.enqueue(p[j]);
            }
            // q.queueSearch(x);
            cout<<"your item after enqueue :"<<endl;
            qq.printQueue();
            cout<<endl;
            cout<<"-------------------------------------"<<endl;
            cout<<"choise what you need  "<<endl;
            cout<<"choise 1 to enqueue number"<<endl;
            cout<<"choise 2 to dequeue number"<<endl;
            cout<<"choise 3 to get front"<<endl;
            cout<<"choise 4 to get rear"<<endl;
            cout<<"enter your choise :";
            int w;
            cin>>w;
            switch (w)
            {
            case 1:
                int r;
                cout<<"enter your number to push enqueue= "<<endl;
                cin>>r;
                qq.enqueue(r);
                cout<<"your item after enqueue "<<endl;
                qq.printQueue();
                cout<<endl;
                cout<<"---------------------"<<endl;
                cout<<"are you need to dequeue number"<<endl;
                cout<<"enter 1 for yes"<<endl;
                cout<<"enter 2 for NO"<<endl;
                int l;
                cout<<"enter your choise :";
                cin>>l;
                if(w==1)
                {
                    cout<<"your item : "<<endl;;
                    qq.printQueue();
                    cout<<endl;
                    cout<<"your item after dequeue :"<<endl;;
                    qq.dequeue();
                    qq.printQueue();
                }
                break;
            case 2:
                cout<<"your item : "<<endl;
                qq.printQueue();
                cout<<"your item after dequeue : "<<endl;
                qq.dequeue();
                qq.printQueue();
                break;
            case 3:

                cout<<"your front is ="<<endl;;
                cout<<qq.frontQueue();
                break;
            case 4:
                cout<<"your rear is ="<<endl;
                cout<<qq.rearQueue()<<endl;
                break;
            default:
                cout << "something Wrong !! "<< endl;
                break;
            }
        }


    }
    if (x==4)
    {
        cout<<"enter your data how meny item you wont in SLL of queue :";
        int d ;
        cin>>d;
        int arr[d];
        int arr2[d];

        for(int i=0 ; i<d; i++)
        {
            cout<<"please entar your  item "<<i<<":";
            cin>>arr[i];
            cout<<"please entar parioity of item "<<i<<":";
            cin>>arr2[i];
        }
        q1.enqueue(arr[0],arr2[0]);
        for(int j=1 ; j<d; j++)
        {
            q1.enqueue(arr[j],arr2[j]);
        }
        cout<<"your item in SLL of queue is :"<<endl;
        q1.display();
        cout<<endl;
        q1.priority_print();
        cout<<endl;
        cout<<"-----------------------------------------------"<<endl;
        cout<<"to enqueue enter       1"<<endl;
        cout<<"to dequeue enter       2"<<endl;
        cout<<"to get front           3"<<endl;
        cout<<"to get rear            4"<<endl;
        cout<<"to clear item of queue 5"<<endl;
        cout<<"to print item of queue 6"<<endl;
        cout<<"enter your choise :";
        int z;
        cin>>z;
        switch(z)
        {
        case 1:

            int a,m;
            cout<<"enter your number to enqueue :"<<endl;
            cin>>a;
            cout<<"enter your number of pariority :"<<endl;
            cin>>m;
            q1.enqueue(a,m);
            cout<<"your item in SLL of queue IS :"<<endl;
            q1.display();
            break;
        case 2:
            q1.dequeue();
            cout<<"your SLL after dequeue: "<<endl;
            q1.display();
            break;
        case 3:
            cout<<"your frount is  :";
            cout<<q1.front();
            break;
        case 4 :
            cout<<"your rear is  :";
            cout<<q1.rear();
            break;

        case 5:
            cout<<"your list after clear  :";
            q1.clearQueue();
            q1.display();
            break;
        case 6 :
            q1.display();
            cout<<endl;
            cout<<"your item in priority queue is :"<<endl;
            q1.priority_print();
            break;
        default:
            cout<<"something is wrong !!"<<endl;
            break;
        }
    }

    return 0;

}

