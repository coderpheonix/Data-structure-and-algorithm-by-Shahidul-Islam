#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    // constructor
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};


// function for inorder traversal
void inorderTraversal(Node* root) {
    if (root == nullptr) return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}


// function for preorder traversal
void preorderTraversal(Node* root) {
    if (root == nullptr) return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}


// function for postorder traversal
void postorderTraversal(Node* root) {
    if (root == nullptr) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}


// function to insert a node
Node* insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}


// function to search for a value in the BST
Node* search(Node* root, int value) {
    if (root == nullptr || root->data == value) return root;

    if (value < root->data) {
        return search(root->left, value);
    } else { // fixed missing semicolon and conditional structure
        return search(root->right, value);
    }
}


// Function for min value node
Node* minValueNode(Node* node)
{
    Node* current= node;
    while(current && current->left !=nullptr )
    {
        current=current->left;
    }
    return current;
}


//Function to delete a node

Node* deletenode(Node* root, int value)
{
    if (root==nullptr) return root;

    if(value<root->data)
    {
        root->left= deletenode(root->left, value);
    }
    else if (value>root->data)
    {
        root->right=deletenode(root->right, value);
    }

    else
    {
        if(root->left==nullptr)
        {
            Node* temp = root->right;
            delete root;
            delete temp;
        }
        else if (root->right==nullptr)
        {
            Node* temp = root->left;
            delete root;
            delete temp;
        }

        Node* temp = minValueNode(root->right);

        // Copy the in-order successor's content to this node
        root->data = temp->data;

        // Delete the in-order successor
        root->right = deletenode(root->right, temp->data);
    }
    return root;
}



int main() {
    Node* root = nullptr;

    // Insert nodes into the BST
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 15);

    cout << "The value of the root is: " << root->data << endl;
    cout << "The value of the left is: " << root->left->data << endl;
    cout << "The value of the right is: " << root->right->data << endl;

    cout << "The inorder traversal value is: ";
    inorderTraversal(root);
    cout << endl;

    cout << "The preorder traversal is: ";
    preorderTraversal(root);
    cout << endl;

    cout << "The postorder traversal is: ";
    postorderTraversal(root);
    cout << endl;

    // Call the search function
    int valueToSearch = 15; // Specify the value to search for
    Node* foundNode = search(root, valueToSearch);

    // Check the result of the search
    if (foundNode != nullptr) {
        cout << "Value " << valueToSearch << " found in the BST." << endl;
    } else {
        cout << "Value " << valueToSearch << " not found in the BST." << endl;
    }

     // Call deleteNode function to delete a node
    int valueToDelete = 25; // Specify the value to delete
    root = deletenode(root, valueToDelete);

    inorderTraversal(root);



    return 0;
}

