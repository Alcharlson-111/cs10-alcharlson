#include "inhandling.h"
#include "../m/math.h"


void createlist (Node *& head, Student *& stu)
{  
    Node* temp = head; // save to temp
    if (temp->dptr == nullptr)
    { // if head is empty save to head
        temp->dptr = stu;
        return;
    }
    while (temp->next != nullptr)
        { // while there is a next node
            temp = temp -> next;
            // parse
        }
    Node * N = new Node {stu, nullptr, temp};
    // create new node
    temp->next = N;
    // move parser to new node

    
}

void addStu(Node *& head, string filename)
{
    ifstream inFile(filename);
    // init input file
    string line;
    // init line to parse
    

    while (getline(inFile, line))
    { // while there is a line in input
        istringstream in(line);
        // so that input can cast to struct
        Student *stu = new Student;
        // allocate new student

        in >> stu->fname >> stu->lname >> stu->t1 >> stu->t2
        >> stu->t3 >> stu->t4;
        // fill known vars

        grade(stu);
        // grade stu & add unk vars


        createlist(head, stu);
        // add student to linked list
    }

    inFile.close();
    // close file
    
}

void freeLL(Node *& head)
{
    while(head)
    {
        Node* this1 = head->next; // set parser
        delete head->dptr; // delete Student * data
        delete head; // delete Node
        head = this1; // parse
    }
}

void printLL(Node *& head)
{
    Node * temp = head; // set parser
    cout << left // format to left
        // Table header
        << setw(12) << "First Name"
        << setw(12) << "Last Name"
        << right // set widths for comftarble spacing
        << setw(6)  << "T1"
        << setw(6)  << "T2"
        << setw(6)  << "T3"
        << setw(6)  << "T4"
        << setw(8)  << "Avg"
        << setw(8)  << "Grade" << endl
        << string(64, '=') << endl ;


    while (temp/*->next*/ != nullptr)
    {// while the parser is not a nullptr
        Student * stu = temp->dptr;
        // init a student ptr that is equal to the 
        // current Node's data
        Student n = *stu;
        // cast to temp n Student for readability
        

        cout << left // format left for names
             << setw(12) << n.fname 
             << setw(12)<< n.lname 
             << right
             << setw(6) << n.t1  
             << setw(6) << n.t2 
             << setw(6) << n.t3  
             << setw(6) << n.t4 
             << fixed << setprecision(2) << setw(8) << n.avg 
             // setting float precision to a readable 2
             << setw(8) << n.grade << endl 
             << string(64, '-') << endl;

        temp = temp->next;  // parse
    }


    float arr1[12];
    // init float array
    avg(head, arr1);
    // pass array into average function to 
    // save average, mins, max

    cout << string(64, '*') << endl
    << left
    << setw(24) << "Class Average:"
    // print average
    << right
    << setprecision(2) 
    << setw(6) << arr1[0]
    << setw(6) << arr1[1]
    << setw(6) << arr1[2]
    << setw(6) << arr1[3]
    << endl; 

    cout << string(64, '=') << endl
    << left
    << setw(24) << "Class Maximum:"
    // print max
    << right
    << setprecision(0)
    << setw(6) << arr1[4]
    << setw(6) << arr1[5]
    << setw(6) << arr1[6]
    << setw(6) << arr1[7]
    << endl; 

    cout << string(64, '=') << endl
    << left
    << setw(24) << "Class Minimum:"
    << right
    // print min
    << setprecision(0)
    << setw(6) << arr1[8]
    << setw(6) << arr1[9]
    << setw(6) << arr1[10]
    << setw(6) << arr1[11]
    << endl; 

        
    int arr2[5];
    // init int array for total grades
    gAvg(head, arr2);
    // calculate and save grade averages

    // print averages
    cout << string(64, '=') << endl
         << left << setw(28) << "Total As:" << right << setw(3) << arr2[0] << "%" << endl
         << left << setw(28) << "Total Bs:" << right << setw(3) << arr2[1] << "%" << endl
         << left << setw(28) << "Total Cs:" << right << setw(3) << arr2[2] << "%" << endl
         << left << setw(28) << "Total Ds:" << right << setw(3) << arr2[3] << "%" << endl
         << left << setw(28) << "Total Fs:" << right << setw(3) << arr2[4] << "%" << endl;

}


/*
There was likely a less verbose way of doing
this function after writing the print function
but I know this works, so it is the same
barring using the find and replace tool
to change cout -> out*/

void p2fLL(Node *& head)
{
    string ofname;// string to save out file name
    cout << "Please enter the exact path and name of the file: ";
    getline(cin, ofname); // get out name

    ofstream out(ofname);// open out file
    Node * temp = head; // set parser
    out << left 
        << setw(12) << "First Name"
        << setw(12) << "Last Name"
        << right
        << setw(6)  << "T1"
        << setw(6)  << "T2"
        << setw(6)  << "T3"
        << setw(6)  << "T4"
        << setw(8)  << "Avg"
        << setw(8)  << "Grade" << endl
        << string(64, '=') << endl ;
    while (temp/*->next*/ != nullptr)
    {
        Student * stu = temp->dptr;
        Student n = *stu;
        

        out << left 
             << setw(12) << n.fname 
             << setw(12)<< n.lname 
             << right
             << setw(6) << n.t1  
             << setw(6) << n.t2 
             << setw(6) << n.t3  
             << setw(6) << n.t4 
             << fixed << setprecision(2) << setw(8) << n.avg 
             << setw(8) << n.grade << endl 
             << string(64, '-') << endl;
        temp = temp->next;  
    }
    float arr1[12];
    avg(head, arr1);

    out << string(64, '*') << endl
    << left
    << setw(24) << "Class Average:"
    
    << right
    << setprecision(2)
    << setw(6) << arr1[0]
    << setw(6) << arr1[1]
    << setw(6) << arr1[2]
    << setw(6) << arr1[3]
    << endl; 

    out << string(64, '=') << endl
    << left
    << setw(24) << "Class Maximum:"
    << right
    << setprecision(0)
    << setw(6) << arr1[4]
    << setw(6) << arr1[5]
    << setw(6) << arr1[6]
    << setw(6) << arr1[7]
    << endl; 

    out << string(64, '=') << endl
    << left
    << setw(24) << "Class Minimum:"
    << right
    << setprecision(0)
    << setw(6) << arr1[8]
    << setw(6) << arr1[9]
    << setw(6) << arr1[10]
    << setw(6) << arr1[11]
    << endl; 

        
    int arr2[5];
    gAvg(head, arr2);

    out << string(64, '=') << endl
         << left << setw(28) << "Total As:" << right << setw(3) << arr2[0] << "%" << endl
         << left << setw(28) << "Total Bs:" << right << setw(3) << arr2[1] << "%" << endl
         << left << setw(28) << "Total Cs:" << right << setw(3) << arr2[2] << "%" << endl
         << left << setw(28) << "Total Ds:" << right << setw(3) << arr2[3] << "%" << endl
         << left << setw(28) << "Total Fs:" << right << setw(3) << arr2[4] << "%" << endl;
    out.close(); // close outfile
}

