//Jordi Monterrubio
//CS 300
//Assignment 4
//BarcodeBSTScanner
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include "BinarySearchTree.h"
using namespace std;
int main() {
    ifstream file;
    file.open("upc_corpus.txt");
    BinarySearchTree<string> bst;
    string line;
    //load data into binary search tree
    while(getline(file, line)) {
        istringstream ss(line);
        string token;
        int id;
        string data;
        getline(ss, token, ',');
        std::string s = token;
        id = std::stoi(s);
        getline(ss, token, ',');
        data = token;
        bst.insert(id, data);
    }
    string myStr;
    int upcCode;
    cout<<"UPC Code: ";
    //get user input
    getline(cin, myStr);
    stringstream(myStr)>>upcCode;
    //keep track of time
    clock_t t;
    t = clock();
    //print out data
    bst.findData(upcCode);
    t = clock() - t;
    cout<<"time: "<<t*1.0/CLOCKS_PER_SEC<<" seconds"<<endl;
    return 0;
}
