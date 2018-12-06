//Jordi Monterrubio
//CS 300
//Assignment 4
//BarcodeArrayScanner
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
using namespace std;
int main() {
    ifstream file;
    file.open("upc_corpus.txt");
    int size = 100;
    int id[100];
    string data[100];
    string line;
    //load data into arrays
    for(int i = 0, i < size; i++) {
        getline(file, line)
        istringstream ss(line);
        string token;
        int id;
        string data;
        getline(ss, token, ',');
        std::string s = token;
        id[i] = std::stoi(s);
        getline(ss, token, ',');
        data[i] = token;
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
    for(int i = 0; i < size; i++) {
        if(i == upcCode) {
            cout<<data[i]<<endl;
            break;
        }
    }
    t = clock() - t;
    cout<<"time: "<<t*1.0/CLOCKS_PER_SEC<<" seconds"<<endl;
    return 0;
}
