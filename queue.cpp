#include <iostream>

using namespace std;

class Queue
{
    int front, rear, size;
    unsigned capacity;
    int *array;

public:
    Queue(unsigned capacity)
    {
        this->capacity = capacity;
        front = this->size = 0;
        rear = capacity - 1;
        array = new int[this->capacity];
    }
    ~Queue()
    {
        delete[] array;
    }
    bool isFull(Queue *queue)
    {
        return (queue->size == queue->capacity);
    }
    bool isEmpty(Queue *queue)
    {
        return (queue->size == 0);
    }
    void enqueue(int item)
    {
        if (isFull(this))
            return;
        this->rear = (this->rear + 1) % this->capacity;
        this->array[this->rear] = item;
        this->size = this->size + 1;
        cout << item << " enqueued to queue" << endl;
    }
    int dequeue()
    {
        if (isEmpty(this))
            return 0;
        int item = this->array[this->front];
        this->front = (this->front + 1) % this->capacity;
        this->size = this->size - 1;
        return item;
    }
    int count()
    {
        return this->size;
    }

    void display()
    {
        int i;
        for (i = front; i <= rear; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    cout << "Enter the size of the queue: ";
    int size;
    cin >> size;
    Queue queue(size);
    int choice;
    do
    {
        cout << "What operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. IsEmpty" << endl;
        cout << "4. IsFull" << endl;
        cout << "5. count" << endl;
        cout << "6. display" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 0:
            break;
        case 1:
            cout << "Enter the element to be enqueued: ";
            int item;
            cin >> item;
            queue.enqueue(item);
            break;
        case 2:
            cout << "The dequeued element is: " << queue.dequeue() << endl;
            break;
        case 3:
            if (queue.isEmpty(&queue))
                cout << "The queue is empty" << endl;
            else
                cout << "The queue is not empty" << endl;
            break;
        case 4:
            if (queue.isFull(&queue))
                cout << "The queue is full" << endl;
            else
                cout << "The queue is not full" << endl;
            break;
        case 5:
            cout << "The number of elements in the queue are: " << queue.count() << endl;
            break;
        case 6:
            cout << "The elements in the queue are: ";
            queue.display();
            break;
        case 7:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 0);
    return 0;
}