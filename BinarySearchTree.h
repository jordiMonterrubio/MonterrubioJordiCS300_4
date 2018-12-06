//Jordi Monterrubio
//CS 300
//Assignment 4
//Binary Search Tree
#include <iostream>
using namespace std;

//node which contains the data of each entry
template<class T>
struct node {
    int id;
    T data;
    node<T>* left;
    node<T>* right;
};
template<class T>
class BinarySearchTree {
    //root of the tree
    node<T>* root;
    //finds an empty node to place a new node based on the id
    void findEmpty(node<T>* &a, node<T>* b) {
        if(a == NULL) {
            a = b;
        } else if (b->id < a->id) {
            findEmpty(a->left, b);
        } else if(b->id > a->id) {
            findEmpty(a->right, b);
        }
    }
    //prints data from a node which has the given id
    void returnData(node<T>* n, int id) {
        if(id == n->id) {
            cout<<n->data<<endl;
        } else if (id < n->id) {
            returnData(n->left, id);
        } else if(id > n->id) {
            returnData(n->right, id);
        }
    }
    public:
        //constructor
        BinarySearchTree(){}
        //inserts a new node into the tree
        void insert(int id, T data) {
            node<T> n;
            n.id = id;
            n.data = data;
            if(root == NULL) {
                root = &n;
            } else {
                findEmpty(root, &n);
            }
        }
        //finds a node based on the id and prints the data
        void findData(int id) {
            returnData(root, id);
        }
};
