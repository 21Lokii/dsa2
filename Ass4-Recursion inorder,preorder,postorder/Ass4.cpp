#include <iostream> 
using namespace std; 
struct Node { 
char data; 
struct Node *left, *right; 
}; 
Node* newNode(char data) 
{ 
Node* temp = new Node; 
temp->data = data; 
temp->left = temp->right = NULL; 
return temp; 
} 
void printInorder (struct Node* node) 
{ 
if (node == NULL) 
return; 
printInorder(node->left); 
cout<<node->data<< " "; 
printInorder(node->right); 
} 
void printPreorder(struct Node* node) 
{ 
if (node == NULL) 
return; 
cout<< node->data <<" "; 
printPreorder(node->left); 
printPreorder(node->right);  
} 
void printPostorder(struct Node* node) 
{ 
if (node == NULL) 
return; 
printPostorder(node->left); 
printPostorder(node->right); 
cout<<node->data<<" "; 
} 
int main() 
{ 
struct Node* root = newNode('+'); 
root->left = newNode('-'); 
root->right = newNode('*'); 
root->left->left = newNode('4'); 
root->left->right = newNode('2'); 
root->right->left = newNode('6'); 
root->right->right = newNode('7'); 
cout<<"\npreorder transversal of binary tree is \n"; 
printPreorder(root); 
cout<<"\nInorder transversal of binary tree is \n"; 
printInorder(root); 
cout<<"\nPostorder transversal of binary tree is \n"; 
printPostorder(root); 
return 0; 
} 