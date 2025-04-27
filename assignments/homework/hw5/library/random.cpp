#include "random.h"



int randomNumber()
{
    srand(time(NULL));
    // Seed random
    return (rand() % 20 + 1); 
    // Return generated random number between 1 & 20
    
}

void greeting()
{   
    string user;
    // Init username string
    
    cout << "Welcome to the Guessing game!\n\nPlease enter your name:\t";
    // Greeting

    do 
    {
       getline(cin, user);
        
    } while (user.length() <= 0);
    // Input verification
    // Requires user to have a username
    // Min of 1 character

    cout << "\n\nHello, " << user << ", this game will generate a number "
         << "greater than one and less than twenty. \n"
         << "Try and guess the number by entering it "
         << "into the terminal and pressing return. ";
    // Program info for user 

}

void readNumber(int& guess)
{
    cout << "\n\nPlease enter a number: ";

    while (true) // Loop for input validation
    {
        cin >> guess;

        // Check for bad input
        if (cin.fail())
        {
            cin.clear(); 
            // Clear err state on fail
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            // Discard extrenuous input
            cout << "Invalid input. Please enter a number between 1 and 20: ";
            continue;
            // Re-cycles loop on fail
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Clean up input 

        // Verify input is in range
        if (guess < 1 || guess > 20)
        {
            cout << "Your number is either less than one or greater than twenty.\n"
                 << "Please enter a new number between 1 and 20: ";
            continue;
            // Re-cucle loop on fail
        }

        break; // valid input
    }
}


void guessAssignment(int& guess, vector<int>& guesses)
{
    // Input validation for repeat guesses    
    while (true) {

        // Initial call for user input
        readNumber(guess);

    
        // Check for duplicate guess
        if (find(guesses.begin(), guesses.end(), guess) != guesses.end()) 
        {
            cout << "You have re-entered an existing guess. Please enter a new number:\n";
            cout << "Your previous guesses: ";
                        for (int g : guesses) 
                        // For each previous guess
                        {
                            if (g != -1) cout << g << " ";
                            // Conditional is fragment from previous
                            // - build, may not be needed ¯\_(ツ)_/¯
                        }
                        cout << "\n";
            continue;
            // If (true) skips break to read in new value
        }
    
        break;
    }
    
    guesses.push_back(guess);
    // Store guess into vector for future checks
    
}


int checkGuess(int ran, int& guess)
{
    if ( guess == ran )
    {
        // game win
        return 0;
    }
    else if ( ran < guess )
    {
        // hint less than
        return -1;
    }
    else 
    {
        // hint greater than
        return 2;
    }
}

void tests()
{
    int check = 3; // Due to using passby reference in function call
    assert(checkGuess(2, check) == -1); 
    // Less than works
    check--;
    // Decrement to make check ==
    cout << "Test [1/3]: Passed. " << endl;
    assert(checkGuess(2, check) == 0);
    // Equal to works
    check--;
    cout << "Test [2/3]: Passed. " << endl;
    assert(checkGuess(2, check) == 2);
    // Greater than works
    cout << "Test [3/3]: Passed. \n" 
         << "All tests passed: Game starting. \n\n\n";
}

bool game()
{
    
    //      Init variables
    int ran = randomNumber(); 
    int guess; 
    vector <int> guesses;
    // guesses.push_back(-1);


    // Loop start
    // While (lives > 0 || win != true)
    do
    {
        //readNumber is called by guess assignment
        guessAssignment(guess, guesses);
        //Saving guess assignment to var for conditionals
        int check = 0; // Clears check due to bug
        check = checkGuess(ran, guess);

        //Conditionals: 
        
        if (guesses.size() >= 6)
        // Uses vector to check lives
        {
            cout << "You are out of tries. Thank you for playing!\n\n"
                 << "YOU LOSE!" << endl; 

            cout << "\nThe generated number is: "
                 << ran << "." << endl;
                 return false;
                 // Increments loss 
                 break; 
                 // Break loop
        }
        
        switch (check)
        {
        case 0:
        {
            // game win
            cout << "Congrats! Your guess is correct. \n\n" 
                 << "YOU WIN!" << endl;

            cout << "\nThe generated number is: "
                 << ran << "." << endl;
            // Out: Random Number
            
            return true;
            // Counts Win
            break;
            // Breaks loop
        }
        case -1:
        {
            // Guess is high
            cout << "Your guess is high. ";
            continue;
        }
        case 2:
        {
            // Guess is low
            cout << "Your guess is low. ";
            continue;
        }
        default: { cout << "This shouldn't happen"; continue;}

        
        }
        

    } while (true);
    // Using break to break loop 
    
}



void menu()
{
    // Init Vars
    int wins = 0, losses = 0, total = 0;
    float wlr;
    // Verify checkAnswer before running
    
    tests(); 
    // Greet user
    
    greeting();
    
    
    // Loop while continue == true
    do
    {
        char playAgain; // For continue conditional

        bool wl = game(); // Saves Win/Loss

        if (wl == true) // Increments W/L based on return of game()
        {
            wins++;
        }
        else { losses++; }

        cout << "\n\nWould you like to play again? [Y/N]"
             << endl;
        cin >> playAgain;
        // Ask to continue -- Save input 

        if (wins > 0) // Avoid divide-by-zero
        {
            wlr = (float)(wins) / (wins + losses); 
            // Get ratio
            wlr *= 100; 
            // So that it can read as a percent
        } else {
            wlr = 0.0;  
        }
        

        if (playAgain != 89 && playAgain != 121)
        {
            cout << "Thank you for playing! "
                 << "\n\n Your stats: \n"
                 << "|Wins                -  " << wins
                 << "\t|\n|Losses         -  " << losses
                 << "\t|\n|Win Ratio      -  " << wlr 
                 << "%"
                 << "\t|\n|Games Played   -  " << total
                 << "\t|\n\n Press return to exit.";
            cin.ignore();
            cin.get();
            break;
        }


    } while (true);
    
}