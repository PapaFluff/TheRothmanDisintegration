// Required libraries to create this output/program
#include <iostream>

using namespace std;

// GLOBAL VARIABLES -- Rock, Paper, Scissors, Lizard, Spock, yes_OR_no, numLost, numWon
const int Rock = 1, Paper = 2, Scissors = 3, Lizard = 4, Spock = 5;
char yes_OR_no;
int numLost = 0;
int numWon = 0;

// 5 Prototypes for all the functions (NOT including MAIN)
void display_menu();
int get_user_response();
int get_computer_choice();
void compare_choices(int userResponse, int computerChoice);
void runGame();


// MAIN function that calls the functions and is the drivers for the program
int main()
{
    runGame();  // Calls the function runGame to output the game
    return 0;
}

// Function used to allow the game to run and prompts user if they want to continue while incrementing values
void runGame()
{
    int userResponse, computerChoice;   // Declares userResponse and computerChoice
    bool runner = true;    // Declares runner to be used later in while statement
    int totalGamesPlayed = 1;   // Declares total games played with a starting value of 1 for the first game
    
    // Loop that gets user and computer choice, compares them, while incrementing for end values
    while(runner)
    {
        userResponse = get_user_response();     // Sets userResponse to the function get_user_response
        computerChoice = get_computer_choice(); // Sets computerChoice to the function get_computer_choice
        compare_choices(userResponse, computerChoice);  // Calls function to compare userResponse and computerChoice
        
        // Prompts user if they want to continue
        cout << "Do you want to play again?(Y/N): ";
        cin >> yes_OR_no;       // INPUT here in reply to prompt
        
        if (yes_OR_no == 'Y' || yes_OR_no == 'y')   // if user wants to KEEP playing
        {
            if (userResponse != computerChoice)
            {
                ++totalGamesPlayed;     // Increments total games played by 1
            }
            else
            continue;
        }
        else if (yes_OR_no == 'N' || yes_OR_no == 'n')   // if user wants to STOP playing
        {
            cout << endl;
            cout << "Total Games Played: " << totalGamesPlayed << endl; // Displays total games PLAYED
            cout << "Games Lost: " << numLost << endl;  // Displays total games LOST
            cout << "Games Won: " << numWon << endl;    // Displays total games WON
            runner = false;     // Sets while statement to false
            exit(0);    // Exits out of the program
            
        }
    }
}

// DISPLAY MENU function that outputs
void display_menu()
{
    cout << "Lets play Rock, Paper, Scissors, Lizard, Spock!" << endl;
    cout << "Choose from the menu." << endl;
    cout << "1 Rock" << endl;
    cout << "2 Paper" << endl;
    cout << "3 Scissors" << endl;
    cout << "4 Lizard" << endl;
    cout << "5 Spock" << endl;
    
}

// READ Function calls display function and outputs it as well as getting the users choice based on menu
int get_user_response()
{
    int userResponse;   // Declares and initializes userResponse
    
    // While loop that ensures USER is giving a value 1-5
    while (true)
    {
        display_menu();     // Calls display function to be outputted
        cout << "Your choice: ";    // Prompts user
        cin >> userResponse;    // INPUT here based on menu
        
        // Detects if user types in a value outside 1-5
        if (userResponse < 1 || userResponse > 5)
        {
            cout << "Choose a value within 1-5." << endl;
            continue;
        }
        else
        {
            break;
        }
    }
    
    return userResponse;    // Returns userResponse
}

// READ Function that gets a random number 1-5 for the computers choice
int get_computer_choice()
{
    srand((unsigned)time(0));
    int computerChoice = (rand() % 5) + 1;  //  Generates a random number for the computer 1-5
    
    // Displays the choice the computer has made
    if (computerChoice == Rock)
    {
        cout << "The computer has chosen Rock!" << endl;
    }
    else if (computerChoice == Paper)
    {
        cout << "The computer has chosen Paper!" << endl;
    }
    else if (computerChoice == Scissors)
    {
        cout << "The computer has chosen Scissors!" << endl;
    }
    else if (computerChoice == Lizard)
    {
        cout << "The computer has chosen Lizard!" << endl;
    }
    else if (computerChoice == Spock)
    {
        cout << "The computer has chosen Spock!" << endl;
    }
    
    return computerChoice;    // Returns computerChoice
}


// COMPARE function that determines the winner of the game
void compare_choices(int userResponse, int computerChoice)
{
    
    // The losses -- (Gotta have losses before you have W's)
    if (userResponse == Rock && computerChoice == Paper)
    {
        cout << "Paper covers Rock! You lost to a computer. :/" << endl;
        ++numLost;
    }
    else if (userResponse == Rock && computerChoice == Spock)
    {
        cout << "Spock vaporizes Rock! You lost to a computer. :/" << endl;
        ++numLost;
    }
    else if (userResponse == Paper && computerChoice == Scissors)
    {
        cout << "Scissors cuts Paper! You lost to a computer. :/" << endl;
        ++numLost;
    }
    else if (userResponse == Paper && computerChoice == Lizard)
    {
        cout << "Lizard eats Paper! You lost to a computer. :/"  << endl;
        ++numLost;
    }
    else if (userResponse == Scissors && computerChoice == Rock)
    {
        cout << "Rock crushes Scissors! You lost to a computer. :/" << endl;
        ++numLost;
    }
    else if (userResponse == Scissors && computerChoice == Spock)
    {
        cout << "Spock smashes Scissors! You lost to a computer. :/" << endl;
        ++numLost;
    }
    else if  (userResponse == Lizard && computerChoice == Rock)
    {
        cout << "Rock crushes Lizard! You lost to a computer. :/" << endl;
        ++numLost;
    }
    else if (userResponse == Lizard && computerChoice == Scissors)
    {
        cout << "Scissors decapitates Lizard! You lost to a computer. :/" << endl;
        ++numLost;
    }
    else if  (userResponse == Spock && computerChoice == Paper)
    {
        cout << "Paper disproves Spock! You lost to a computer. :/" << endl;
        ++numLost;
    }
    else if (userResponse == Spock && computerChoice == Lizard)
    {
        cout << "Lizard poisons Spock! You lost to a computer. :/" << endl;
        ++numLost;
    }
    
    // The wins -- (Your to good to take losses :))
    if (userResponse == Paper && computerChoice == Rock)
    {
        cout << "Paper covers Rock! You win!" << endl;
        ++numWon;
    }
    else if (userResponse == Spock && computerChoice == Rock)
    {
        cout << "Spock vaporizes Rock! You win!" << endl;
        ++numWon;
    }
    else if (userResponse == Scissors && computerChoice == Paper)
    {
        cout << "Scissors cuts Paper! You win!" << endl;
        ++numWon;
    }
    else  if (userResponse == Lizard && computerChoice == Paper)
    {
        cout << "Lizard eats Paper! You win!" << endl;
        ++numWon;
    }
    else if (userResponse == Rock && computerChoice == Scissors)
    {
        cout << "Rock crushes Scissors! You win!" << endl;
        ++numWon;
    }
    else if (userResponse == Spock && computerChoice == Scissors)
    {
        cout << "Spock smashes Scissors! You win!" << endl;
        ++numWon;
    }
    else  if (userResponse == Rock && computerChoice == Lizard)
    {
        cout << "Rock crushes Lizard! You win!" << endl;
        ++numWon;
    }
    else  if (userResponse == Scissors && computerChoice == Lizard)
    {
        cout << "Scissors decapitates Lizard! You win!" << endl;
        ++numWon;
    }
    else  if (userResponse == Paper && computerChoice == Spock)
    {
        cout << "Paper disproves Spock! You win!" << endl;
        ++numWon;
    }
    else  if (userResponse == Lizard && computerChoice == Spock)
    {
        cout << "Lizard poisons Spock! You win!" << endl;
        ++numWon;
    }
    
    // The ties -- (Your equally matched with the computer >:o)
    if (userResponse == Rock && computerChoice == Rock)
    {
        cout << "No one wins. The game is a tie!" << endl;
        runGame();
    }
    else if (userResponse == Paper && computerChoice == Paper)
    {
        cout << "No one wins. The game is a tie!" << endl;
        runGame();
    }
    else if (userResponse == Scissors && computerChoice == Scissors)
    {
        cout << "No one wins. The game is a tie!" << endl;
        runGame();
    }
    else if (userResponse == Lizard && computerChoice == Lizard)
    {
        cout << "No one wins. The game is a tie!" << endl;
        runGame();
    }
    else if (userResponse == Spock && computerChoice == Spock)
    {
        cout << "No one wins. The game is a tie!" << endl;
        runGame();
    }
}

