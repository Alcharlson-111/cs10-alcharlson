#pragma ONCE

#include <iostream>
#include <fstream> 
#include <string> 
#include <sstream>

using namespace std; 

struct Student 
{
    string fname; 
    string lname; 
    int t1; 
    int t2;
    int t3; 
    int t4; 
    float avg;
    char grade; 
};

struct Node
{
    Student * dptr; 
    Node * next; 
    Node * prev;
};



void createlist(Node *& head, Student *& stu); 
void addStu(Node *& head, string filename);
void freeLL(Node *& head);
void printLL(Node *& head);