#include "lib/ih/inhandling.h"
#include "lib/m/math.h"

string getFile();


int main()
{
    ifstream inFile("class111.txt");
    Node * head = new Node {nullptr, nullptr, nullptr}; 
    string file = getFile();
    addStu(head, file);
    printLL(head);
    freeLL(head);
    return 0;

}

string getFile()
{
    string file;
    cout << "Please enter the file name:\t";
    getline(cin, file);
    return file;
}