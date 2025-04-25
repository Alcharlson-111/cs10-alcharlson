#include "random.h"



int ranNum()
{
    srand(time(NULL));
    return (rand() % 20 + 1); 
    // Return generated random number between 1 & 20
    
}

void greeting()
{   
    string user;
    
    cout << "Welcome to the Guessing game!\n\nPlease enter your name:";
    
    do 
    {
       getline(cin, user);
        
    } while (user.length() <= 0);

    cout << "Hello, " << user << " this game will generate a number "
         << "greater than one and less than twenty. \n"
         << "Try and guess the number by entering it "
         << "into the terminal and pressing return. ";

}

void readNumber(int& guess)
{
    cout << "\n\nPlease enter a number: ";

    while (true)
    {
        cin >> guess;

        // Check for bad input (e.g., letters or symbols)
        if (cin.fail())
        {
            cin.clear(); // clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard the rest of the line
            cout << "Invalid input. Please enter a number between 1 and 20: ";
            continue;
        }

        // Clean up extra inputs on the line (e.g., 1 2 3)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (guess < 1 || guess > 20)
        {
            cout << "Your number is either less than one or greater than twenty.\n"
                 << "Please enter a new number between 1 and 20: ";
            continue;
        }

        break; // valid input
    }
}


void guessAssignment(int& guess, vector<int>& guesses)
{
    
    //Call Guess
    // readNumber(guess);

    
    while (true) {
        readNumber(guess);
    
        // Check for duplicate guess
        if (find(guesses.begin(), guesses.end(), guess) != guesses.end()) {
            cout << "You have re-entered an existing guess. Please enter a new number:\n";
            cout << "Your previous guesses: ";
                        for (int g : guesses) {
                            if (g != -1) cout << g << " ";
                        }
                        cout << "\n";
            continue;
        }
    
        break;
    }
    
    guesses.push_back(guess);
    
}


int checkGuess(int ran, int& guess)
{
    if ( guess == ran )
    {
        //game win
        return 0;
    }
    else if ( ran < guess )
    {
        // Hit
        return -1;
    }
    else 
    {
        //continue game
        return 2;
    }
}

void tests()
{
    int check = 3; // due to using reference in function call
    assert(checkGuess(2, check) == -1);
    check--;
    cout << "Test [1/3]: Passed. " << endl;
    assert(checkGuess(2, check) == 0);
    check--;
    cout << "Test [2/3]: Passed. " << endl;
    assert(checkGuess(2, check) == 2);
    cout << "Test [3/3]: Passed. \n" 
         << "All tests passed: Game starting. \n\n\n";
}

bool game()
{
    
    // Init variables
    int ran = ranNum();
    // cout << "Random: " << ran;
    int guess; //No assignment 'til called by function
    vector <int> guesses;
    guesses.push_back(-1);

    

    // Loop start
    do
    {
        //readNumber is called by guess assignment
        guessAssignment(guess, guesses);
        //Saving guess assignment to var for conditionals
        int check = checkGuess(ran, guess);

        //Conditionals: 
        

        if ( check == 0 )
        {
            // game win
            cout << "Congrats! Your guess is correct. \n\n" 
                 << "YOU WIN!" << endl;

            cout << "\nThe generated number is: "
                 << ran << "." << endl;
            return true;
            break;
        }
        else if (check == -1)
        {
            // guess is high
            cout << "Your guess is high. ";
        }
        else
        {
            // guess is low
            cout << "Your guess is low. ";
        }

        if (guesses.size() >= 7)
        {
            cout << "You are out of tries. Thank you for playing!\n\n"
                 << "YOU LOSE!" << endl; 

            cout << "\nThe generated number is: "
                 << ran << "." << endl;
                 return false;
                 break; 
        }

        

    } while (true);

    


    
}

void menu()
{
    int wins = 0, losses = 0 ;
    float wlr;
    // Greet user
    tests(); 
    greeting();
    do
    {
        char playAgain;

        bool wl = game();

        if (wl == true)
        {
            wins++;
        }
        else { losses++; }

        cout << "\n\nWould you like to play again? [Y/N]"
             << endl;
        cin >> playAgain;

        if (wins > 0) {
            wlr = (float)(wins) / (wins + losses);  
        } else {
            wlr = 0.0;  // Avoid divide-by-zero
        }
        

        if (playAgain != 89 && playAgain != 121)
        {
            cout << "Thank you for playing! "
                 << "\n\n Your stats: \n"
                 << "|Wins      -  " << wins
                 << "|\n|Losses    -  " << losses
                 << "|\n|Win Ratio -  " << wlr 
                 << "|\n\n Press return to exit.";
            cin.ignore();
            cin.get();
            break;
        }


    } while (true);
    
}