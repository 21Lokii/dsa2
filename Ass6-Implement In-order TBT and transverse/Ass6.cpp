#include <iostream>
using namespace std;

class Node {
public:
int key;
Node *left, *right;
bool lthread, rthread;

Node(int key) {
this->key = key;
left = right = nullptr;
lthread = rthread = false;
}
};

class ThreadedBinaryTree {
private:
Node* root;

public:
ThreadedBinaryTree() {
root = nullptr;
}

void insert(int key) {
if (root == nullptr) {
root = new Node(key);
return;
}

Node* current = root;
Node* parent = nullptr;
while (current != nullptr) {
if (key < current->key) {
if (current->lthread) break;
parent = current;
current = current->left;
} else {
if (current->rthread) break;
parent = current;
current = current->right;
}
}

Node* new_node = new Node(key);
if (key < parent->key) {
new_node->left = parent->left;
new_node->right = parent;
parent->lthread = false;
parent->left = new_node;
} else {
new_node->left = parent;
new_node->right = parent->right;
parent->rthread = false;
parent->right = new_node;
}
}
void in_order() {
Node* current = root;
while (current != nullptr && !current->lthread) {
current = current->left;
}

while (current != nullptr) {
cout << current->key << " ";
if (current->rthread) {
current = current->right;
} else {
current = current->right;
while (current != nullptr && !current->lthread) {
current = current->left;
}
}
}
}

void pre_order() {
Node* current = root;
while (current != nullptr) {
cout << current->key << " ";
if (!current->lthread) {
current = current->left;
} else {
while (current != nullptr && current->rthread) {
current = current->right;
}
if (current != nullptr) {
current = current->right;
}
}
}
}
};

int main() {
ThreadedBinaryTree tbt;
tbt.insert(20);
tbt.insert(10);
tbt.insert(30);
tbt.insert(5);
tbt.insert(15);

cout << "In-order Traversal: ";
tbt.in_order();
cout << endl;

cout << "Pre-order Traversal: ";
tbt.pre_order();
cout << endl;

return 0;
}
