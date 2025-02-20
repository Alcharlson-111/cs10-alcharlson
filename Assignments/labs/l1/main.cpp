#include <iostream>
#include <string>
using namespace std;

/*
     |\_/|          	*****************************    	   (\_/)
 /  @  @ \      	*                   ASCII Lab               *  	  (='.'=)
( >   0  <   )       *              By: <Your name>      * 	( " )_( " )
    >>x<<        	*                     CSCI 111              *
   /   O  \       	******************************/



int main() 
{
    string l1,l2,l3,l4,l5;
    l1 = "    |\\_/|          	*******************************************    	  (\\_/)";
    l2 = "  /  @  @ \\      	*\t\tASCII Lab                 *  	 (='.'=)";
    l3 = "( >   0  <   )          *\t   By: Aubrey Charlson            *    ( \" )_( \" )";
    l4 = "    >>x<<               *\t\t CSCI 111                 *";
    l5 = "  /   O  \\       	*******************************************/";

    string uName;
    cout << "Please enter your name: ";
    cin >> uName;

    cout << "Hello, nice meeting you, " << uName 
    << " !" << endl;

    cout << "Hope you like my Tom & Jerry ASCII art... \n\n";
    cout << l1 << endl << l2 << endl << l3
         << endl << l4 << endl << l5 << endl;

};