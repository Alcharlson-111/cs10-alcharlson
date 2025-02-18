// Include necessary libraries
#include <iostream> 
#include <string> 
#include <array>
#include <cctype>
#include <limits> 
using namespace std;    

// Common variables
string userName, wordStand;

// Gallows stages for the Hangman game
string mt = "|-----------------\n|/\t\t!\n|\n|\n|\n|\n|\n===========";
string hd = "|-----------------\n|/\t\t!\n|\t\t0\n|\n|\n|\n|\n===========";
string ch = "|-----------------\n|/\t\t!\n|\t\t0\n|\t\t|\n|\t\t|\n|\n|\n===========";
string ll = "|-----------------\n|/\t\t!\n|\t\t0\n|\t\t|\n|\t\t|\n|\t       /\n|\n===========";
string rl = "|-----------------\n|/\t\t!\n|\t\t0\n|\t\t|\n|\t\t|\n|\t       / \\\n|\n===========";
string la = "|-----------------\n|/\t\t!\n|\t\t0\n|\t       /|\n|\t\t|\n|\t       / \\\n|\n===========";
string ra = "|-----------------\n|/\t\t!\n|\t\t0\n|\t       /|\\\n|\t\t|\n|\t       / \\\n|\n===========";

// ---------------------------- FUNCTIONS ---------------------------- //

// Request user's name
string reqName(string &userName){
    cout << "\n\n\n\n\n\nHey there, what's your name? " << endl;
    getline(cin, userName);
    return userName;
}

// Greet the user
void greetUser(string &userName){
    cout << "\nHello, " << userName << endl << "Welcome to the hangman game!" << endl; 
}

// Word operations
string gameWord = "Cabbage";
string lTray = "_ ";
string gameTray, gSubo;
string guess = "a";
int lives = 6;
const int wordLen = gameWord.length();
bool iP = true;
int a = 0;

// Function to check if input is an integer
bool isInteger(const string& input) {
    for (char c : input) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

// Create the initial blank game tray
string createTray(string &gameTray, string &lTray, int wordLen) {
    for (int i = 0; i < wordLen; i++) {
        gameTray += lTray;
    }
    return gameTray;
}   

// Convert input to lowercase
void casing(string &x) {
    for (char &c : x) {
        c = tolower(c);
    }
}

// Get a single-letter guess from the player
void guessLetter(string &x) {
    cout << "Please enter a character:" << endl;
    cin >> x;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
    cout << "\n\n" << endl;

    while (x.length() != 1) {
        cout << "You've entered more than one character. Please enter a single character:" << endl;
        cin >> x;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer again
    }
}

// Get a full-word guess from the player
void guessWord(string &x, int wordLen) {
    cout << "Please guess a word:" << endl;
    cin >> x;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
    cout << "\n\n" << endl;
    int a = x.length();

    while (a != wordLen) {
        cout << "Your entry does not match the length of the word. Please reference the most recent gametray before entering a new guess." << endl;
        cin >> x;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer again
    }
}


// Check if the guessed letter is in the word and update the tray
void checkLetter(string x, string y, string &gameTray, int &lives, int wordLen) {
    casing(y);
    int i;
    int l = 0;

    for (i = 0; i < wordLen; i++) {
        string c = y.substr(i, 1);
        if (c == x) {
            gameTray.replace(2 * i, 2, x + " ");
            l++;
        }
    }

    if (l == 0) {
        cout << x << " is not in this word!" << endl;
        lives--;  // Ensure lives decrease properly
    }
}


// Check if the guessed word is correct
void checkWord(string guess, string gameWord, bool &iP) {
    casing(guess);
    casing(gameWord);
    if (guess == gameWord) {
        cout << "Congratulations, you won!" << endl;
        iP = false;
    } else {
        cout << "This word is incorrect" << endl;
        iP = true;
        lives--;
    }
}


// Handle user input selection between guessing a letter or a word
void selection() {
    string sInput;
    cout << "You may either guess a letter or attempt to guess a word. Enter 1 for letter and 2 for word: " << endl;
    getline(cin, sInput);

    while (!isInteger(sInput)) {
        cout << "That's not a valid integer. Please try again: ";
        getline(cin, sInput);
    }
    cout << "Remaining Lives: " << lives << endl;

    if (sInput == "1") {
        guessLetter(guess);
        checkLetter(guess, gameWord, gameTray, lives, wordLen);
        guess = "";
    } else if (sInput == "2") {
        guessWord(guess, wordLen);
        checkWord(guess, gameWord, iP);
    }
}

// Display the hangman based on remaining lives
void pGallows(int x) {
    if (x == 6) {cout << mt << endl;}
    else if (x == 5) {cout << hd << endl;}
    else if (x == 4) {cout << ch << endl;}
    else if (x == 3) {cout << ll << endl;}
    else if (x == 2) {cout << rl << endl;}
    else if (x == 1) {cout << la << endl;}
    else if (x == 0) {cout << ra << endl;}
}

// Main game loop
void game(bool &iP) {
    gameTray = createTray(gameTray, lTray, wordLen);
    reqName(userName);
    greetUser(userName);
    
    cout << "\n\nWelcome to Hangman!" << endl;
    cout << "The following tiles each represent a letter in your word: " << gameTray << endl;
    cout << "Guess correctly to reveal letters, but be careful! Wrong guesses cost lives.\n\n\n\n\n" << endl;
    
    while (iP && lives >= 0) {

        if (lives == 0) {
            cout << ra << "\n\n\t\tGAME OVER" << endl;
            break;
        } else if (!iP) {
            cout << "Congratulations, " << userName << "! You guessed the word: " << gameWord << endl;
            break;
        }


        pGallows(lives);
        cout << "\n" << gameTray << "\n\n";
        selection();
    }
}

// Main function
int main() {
   game(iP);
}
