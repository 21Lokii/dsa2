#include <iostream>
using namespace std;

class CircularQueue {
private:
int front, rear, size;
int* queue;

public:
CircularQueue(int s) {
front = rear = -1;
size = s;
queue = new int[s];
}
~CircularQueue() {
delete[] queue;
}

void enqueue(int value) {
if ((rear + 1) % size == front) {
cout << "Queue is full" << endl;
} else if (front == -1) {
front = rear = 0;
queue[rear] = value;
} else {
rear = (rear + 1) % size;
queue[rear] = value;
}
}

int dequeue() {
if (front == -1) {
cout << "Queue is empty" << endl;
return -1;
}

int temp = queue[front];
if (front == rear) {
front = rear = -1;
} else {
front = (front + 1) % size;
}
return temp;
}

void display() {
if (front == -1) {
cout << "Queue is empty" << endl;
return;
}

cout << "Queue elements: ";
if (rear >= front) {
for (int i = front; i <= rear; i++)
cout << queue[i] << " ";
} else {
for (int i = front; i < size; i++)
cout << queue[i] << " ";
for (int i = 0; i <= rear; i++)
cout << queue[i] << " ";
}
cout << endl;
}
};

int main() {
CircularQueue cq(5);
cq.enqueue(10);
cq.enqueue(20);
cq.enqueue(30);
cq.enqueue(40);
cq.enqueue(50);
cq.display();
cout << "Dequeued element: " << cq.dequeue() << endl;
cq.display();
cq.enqueue(60);
cq.display();

return 0;
}
