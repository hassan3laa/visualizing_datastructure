#include <iostream>
using namespace std;

// -----Stack Class-----
class mystack {
private:
    int* arr;
    int capacity;
    int top;

    void resized (int newcap) {
        int* newarr = new int[newcap];
        for (int i = 0; i < capacity && i < newcap; i++) {
            newarr[i] = arr[i];
        }
        delete[] arr;
        arr = newarr;
        capacity = newcap;
    }

public:
    mystack(int size = 4) {
        capacity = size;
        arr = new int[size];
        top = -1;
    }

    ~mystack() {
        delete[] arr;
    }


    void push(int value) {
        if (top == capacity - 1) {
            resized(capacity * 2);
        }
        arr[++top] = value;
    }


    void pop() {
        if (top == -1) {
            cout << "There is nothing to pop. \n";
        }


        else if (top != -1) {
            top--;
        }
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty. \n";
        } else {
            cout << "-----Stack-----\n";
            for (int i = top; i >= 0; i--) {
                cout << "| " << arr[i] << " |";
                if (i == top) cout << "<--- Top";
                cout << '\n';
            }

            cout << "---------------\n";
        } 
    }

};
//--------------------------------------

// -----Vector Class-----

class myvector {
private:
    int* arr;
    int capacity;
    int length;
    

    void resized (int newcap) {
        int* newarr = new int[newcap];
        for (int i = 0; i < capacity && i < newcap; i++) {
            newarr[i] = arr[i];
        }
        delete[] arr;
        arr = newarr;
        capacity = newcap;
    }


public:
    myvector(int size = 4) {
        capacity = size;
        arr = new int[size];
        length = 0;
    }

    ~myvector() {
        delete[] arr;
    }


    void push_back(int val) {
        if (length == capacity) {
            resized(capacity * 2);
        }
        arr[length++] = val;
    }


    void pop_back() {

        if (length == 0) {
            cout << "Vector is empty. \n";
        }

        else if (length > 0) {
            length--;
        }

    }


    int size () const {
        return length;
    }

    int operator[] (int index) const {
        if (index < 0 || index >= length) {
            cerr << "Index out of bounds. \n";
            return -1;  // Meaningful value indicating error
        }
        return arr[index];
    }

    
    void display () {
        if (length == 0) {
            cout << "Vector is empty. \n";

            return ;
        }
        
        cout << "-----Vector-----\n";
        cout << "Vector Size : " << size() << '\n';
        
        for (int i = 0; i < length; i++) {
            cout << "  " << i <<  "  ";
        }
        cout << '\n';

        for (int i = 0; i < length; i++) {
            cout << "[" << arr[i] << "] ";
        }

        cout << '\n';
    }
};

//---------------------


// -----Queue Class-----

class myqueue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int count;

    void resized (int newcap) {
        int* newarr = new int[newcap];
        int idx = front;

        for (int i = 0; i < count; i++) {
            newarr[i] = arr[idx];
            idx = (idx + 1) % capacity;
        }

        delete [] arr;
        arr = newarr;
        capacity = newcap;

        front = 0;

        rear = count - 1;
    }


public :
    
    myqueue(int size = 4) {
        capacity = size;
        arr = new int [size];
        front = 0;
        rear = -1;
        count = 0;
    }


    ~myqueue() {
        delete[] arr;
    }


    void enqueue (int val) {
        if (count == capacity) {
            resized(capacity * 2);
        }

        rear = (rear + 1) % capacity;
        arr[rear] = val;
        count++;
    }


    void dequeue () {
        if (count == 0) {
            cout << "Queue is empty. \n";
            return;
        }

        front = (front + 1) % capacity;
        count--;
    }

    void display() {
        cout << "-----Queue-----\n";
        if (count == 0) {
            cout << "Queue is empty. \n";
            return;
        }
        
        cout << "Queue Size : " << count << '\n';

        int idx = front;
        for (int i = 0; i < count; i++) {
            if (i == 0) {
                cout << "Front -->" << "[" << arr[idx] << "] ";
            }

            else if (i == count - 1) {
                cout << "[" << arr[idx] << "] <-- Rear";
            }
            
            else {
                cout << "[" << arr[idx] << "] ";
            }
            idx = (idx + 1) % capacity;
        }


        cout << '\n';

    }

};

//-----------------------------------------


// -----Singly Linked list full structure-----

struct node {
    int data;
    node* next;

    node (int val) : data(val), next(nullptr) {}
};


class linkedlist {
private: 
    node* head;
    node* tail;

    int size;

    void deletenode (node* item) {
        if (item) {
            delete item;
            size--;
        }
    }


public: 
    linkedlist () : head(nullptr), tail(nullptr), size(0) {}


    void insertend(int val) {
        node* newnode = new node(val);
        
        if (!head) {
            
            head = tail = newnode;
        
        } else {
            
            tail->next = newnode;
            tail = newnode;
        
        }
        size++;
    }

    void insertfront (int val) {
        node* newnode = new node (val);

        if (!head) {
            
            head = tail = newnode;
        
        } else {
            
            newnode->next = head;
            head = newnode;
        
        }
        size++;
    }


    void deletevalue (int val) {

        if (!head) {
            return ;
        }

        if (head->data == val) {
            node* item = head;

            head = head->next;

            if (!head) {
                tail = nullptr;
            }

            deletenode(item);

            return ;
        }

        node* cur = head;

        while (cur->next && cur->next->data != val) {
            
            cur = cur->next;
        
        }

        if (cur->data) {
            
            node* item = cur->next;
            cur->next = cur->next->next;
            
            if (item == tail) { 
                tail = cur;
            }
            
            deletenode(item);
        
        }
    }


    void display () {

        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        node* cur = head;

        cout << "Size : " << size << '\n';
        cout << "Head --> ";
        while (cur) {

            cout << "[" << cur->data << "]";

            if (cur == tail) {
                cout << " <-- Tail";
            }

            if (cur->next) {
                cout << " --> ";
            }

            cur = cur->next;
        }

        cout << "--> Null";

    }

};

//------------------------------------


// -----Doubly Linked list full structure-----

struct Dnode {
    Dnode* next;
    Dnode* prev;
    int data;


    Dnode (int val) : data(val), next (nullptr), prev (nullptr) {}
};


class doublylinkedlist {
private:
    Dnode* head;
    Dnode* tail;
    
    int size;


    void deletenode (Dnode*item) {
        if (item) {
            delete item;
            size--;
        }
    }

    
public:
    doublylinkedlist () : head (nullptr), tail (nullptr), size (0) {}


    void insertend (int val) {
        Dnode* item = new Dnode (val);

        if (!head) {
        
            head = tail = item;
        
        } else {
            
            tail->next = item;
            item->prev = tail;
            tail = item;
        
        }

        size++;
    }


    void insertfront (int val) {
        Dnode* item = new Dnode (val);

        if (!head) {

            head = tail = item;

        } else {

            item->next = head;
            head->prev = item;
            head = item;

        }

        size++;
    }



    void deletevalue (int val) {
        
        if (!head) {
            return ;
        }
        

        if (head->data == val) {
            Dnode* item = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            deletenode(item);
            return;
        }

        Dnode* cur = head;
        
        while (cur && cur->data != val) {
            cur = cur->next;
        }

        if (cur) {
            Dnode* item = cur;
            
            if (cur->prev) {
                cur->prev->next = cur->next;
            }
            
            if (cur->next) {
                cur->next->prev = cur->prev;
            }

            if (cur == tail) {
                tail = cur->prev;
            }

            deletenode(item);
        }

        size--;
    }

};








int main () {
}