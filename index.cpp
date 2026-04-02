#include <iostream> using
namespace std;
struct Node { int 
data; Node* 
left; Node*
right;
};
Node* createNode(int value) { Node*
newNode = new Node(); newNode-
>data = value;
newNode->left = newNode->right = NULL; return 
newNode;
}
Node* insert(Node* root, int value) { if 
(root == NULL)
return createNode(value);
if (value < root->data)
root->left = insert(root->left, value); else if 
(value > root->data)
root->right = insert(root->right, value);
return root;
}
bool search(Node* root, int key) { if 
(root == NULL)
return false;
if (root->data == key) return 
true;
else if (key < root->data)
return search(root->left, key); else
return search(root->right, key);
}
void inorder(Node* root) { if 
(root != NULL) {
inorder(root->left);
cout << root->data << " "; 
inorder(root->right);
}
}
int main() {
Node* root = NULL; int 
n, value, key;
cout << "Enter number of nodes: "; cin 
>> n;
cout << "Enter elements:\n"; for 
(int i = 0; i < n; i++) {
cin >> value;
root = insert(root, value;
}
cout << "\nInorder Traversal (Sorted Order): "; inorder(root);
cout << "\n\nEnter element to search: "; cin >> 
key;
if (search(root, key))
cout << "Element found in BST"; else
cout << "Element not found in BST";
return 0;
}
