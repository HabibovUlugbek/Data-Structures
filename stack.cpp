#include <iostream>
using namespace std;

class Stack
{

    int top;
    unsigned capacity;
    int *array;

public:
    Stack(unsigned capacity)
    {
        this->capacity = capacity;
        top = -1;
        array = new int[this->capacity];
    }
    ~Stack()
    {
        delete[] array;
    }
    bool isFull()
    {
        return (top == capacity - 1);
    }
    bool isEmpty()
    {
        return (top == -1);
    }
    void push(int item)
    {
        if (isFull())
            return;
        this->array[++this->top] = item;
        cout << item << " pushed to stack" << endl;
    }
    int pop()
    {
        if (isEmpty())
            return 0;
        return this->array[this->top--];
    }
    int peek(int position)
    {
        if (isEmpty())
            return 0;
        return this->array[this->top - position + 1];
    }
    void change(int position, int value)
    {
        this->array[position] = value;
        cout << "Value changed at location " << position << endl;
    }
    int count()
    {
        return this->top + 1;
    }
    void display()
    {
        int i;
        for (i = top; i >= 0; i--)
        {
            cout << array[i] << " ";
        }
    }
};

int main()
{

    cout << "Enter the size of stack: ";
    int size;
    cin >> size;
    Stack s1(size);
    int option, position, value;

    do
    {
        cout << "What operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Push()" << endl;
        cout << "2. Pop()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. peek()" << endl;
        cout << "6. count()" << endl;
        cout << "7. change()" << endl;
        cout << "8. display()" << endl;
        cout << "9. Clear Screen" << endl
             << endl;

        cin >> option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enter an item to push in the stack" << endl;
            cin >> value;
            s1.push(value);
            break;
        case 2:
            cout << "Pop Function Called - Poped Value: " << s1.pop() << endl;
            break;
        case 3:
            if (s1.isEmpty())
                cout << "Stack is Empty" << endl;
            else
                cout << "Stack is not Empty" << endl;
            break;
        case 4:
            if (s1.isFull())
                cout << "Stack is Full" << endl;
            else
                cout << "Stack is not Full" << endl;
            break;
        case 5:
            cout << "Enter position of item you want to peek: " << endl;
            cin >> position;
            cout << "Peek Function Called - Value at position " << position << " is " << s1.peek(position) << endl;
            break;
        case 6:
            cout << "Count Function Called - Number of Items in the Stack are: " << s1.count() << endl;
            break;
        case 7:
            cout << "Change Function Called - " << endl;
            cout << "Enter position of item you want to change : ";
            cin >> position;
            cout << endl;
            cout << "Enter value of item you want to change : ";
            cin >> value;
            s1.change(position, value);
            break;
        case 8:
            cout << "Display Function Called - " << endl;
            s1.display();
            break;
        case 9:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);
}
