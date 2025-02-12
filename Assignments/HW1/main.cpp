// libraries
#include <iostream> 
#include <string> 
#include <cstdio> 
using namespace std; 


// common var 
string userName, wordStand;

// gallows
string mt = "|-----------------\n|/\t\t!\n|\n|\n|\n|\n|\n===========";
string hd = "|-----------------\n|/\t\t!\n|\t\t0\n|\n|\n|\n|\n===========";
string ch = "|-----------------\n|/\t\t!\n|\t\t0\n|\t\t|\n|\t\t|\n|\n|\n===========";
string ll = "|-----------------\n|/\t\t!\n|\t\t0\n|\t\t|\n|\t\t|\n|\t       /\n|\n===========";
string rl = "|-----------------\n|/\t\t!\n|\t\t0\n|\t\t|\n|\t\t|\n|\t       / \\\n|\n===========";
string la = "|-----------------\n|/\t\t!\n|\t\t0\n|\t       /|\n|\t\t|\n|\t       / \\\n|\n===========";
string ra = "|-----------------\n|/\t\t!\n|\t\t0\n|\t       /|\\\n|\t\t|\n|\t       / \\\n|\n===========";

//




// -------------------------------------FUNCTIONS---------------------------------------- //

// greeting
// - request
string reqName(string &userName){
    cout << "Hey there, what's your name? " << endl;
    getline(cin, userName);
    return userName;
}
 // - greet
void greetUser(string &userName){
    cout << "Hey, " << userName <<
    endl << "Welcome to the hangman game!" << endl; 
}


// word operations
// - vars
string gameWord = "Cabbage";
string lTray = "_";
string gameTray; 
string guess = "a";
int wordLen = gameWord.length();
int base = 0;
int gNum = 0; 
int gMax = 6;
string gSub(int base){
    return gameWord.substr(base);
    }


// - calculate length
void createTray(int base, int wordLen, string &gameTray, string lTray){
    while (base < wordLen)
    {
        gameTray += lTray;
        base++; 
    }   
} 



// - check for guess
int subChar(string gameWord, string gSub, string &gameTray, string guess, int base){
    if (gSub == guess){
        gameTray = gameTray.replace(base, 1, guess);
    }
    return 0; 
}
int substring(string &gameWord, string guess, string gameTray, int wordLen, int base){
    int i;
    for (i = 0; i < wordLen; i++)
    {
        subChar(gameWord, gSub(base), gameTray, guess, base);
        base++; 
    }
    return 0;
}
// int guessCheck(string &gameWord, string &guess){
//     if ()
//     {
//         /* code */
//     }
//     else
//     {
//         /* code */
//     }
    
// }



int main() {
    
    createTray(base, wordLen, gameTray, lTray);
    cout << gameTray;
    string s = "a";
    string t = "x";
    int oneT = gameWord.find(s);
    int twoT = gameWord.find(t); 

    if (oneT > 0) {
        cout << oneT << endl;
    }else {cout << "oneT not found"; }
    if (twoT > 0) {
        cout << twoT << endl;
    }else {cout << "twoT not found";}
    substring(gameWord, guess, gameTray, wordLen, base);
    cout << gameTray;


}
