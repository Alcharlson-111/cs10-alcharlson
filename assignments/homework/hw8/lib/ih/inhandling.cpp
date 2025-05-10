#include "inhandling.h"


void createlist (Node *& head, Student *& stu)
{  
    Node* temp = head; 
    if (temp->dptr == nullptr)
    {
        temp->dptr = stu;
        return;
    }
    while (temp->next != nullptr)
        {
            temp = temp -> next;
        }
    Node * N = new Node {stu, nullptr, temp};
    temp->next = N;

    
}

void addStu(Node *& head, string filename)
{
    ifstream inFile(filename);
    string line;
    

    while (getline(inFile, line))
    {
        istringstream in(line);
        Student *stu = new Student;

        in >> stu->fname >> stu->lname >> stu->t1 >> stu->t2
        >> stu->t3 >> stu->t4;

        createlist(head, stu);
    }

    inFile.close();
    
}

void freeLL(Node *& head)
{
    while(head)
    {
        Node* this1 = head->next;
        delete head->dptr;
        delete head;
        head = this1;
    }
}

void printLL(Node *& head)
{
    Node * temp = head;

    while (temp->next != nullptr)
    {
        Student * stu = temp->dptr;
        Student n = *stu;
        cout << n.fname << " " << n.lname 
             << n.t1 << " " << n.t2 << " "
             << n.t3 << " " << n.t4 << endl;
        temp = temp->next;  
    }
}