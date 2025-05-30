// fainalproject for 5 course.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>   // Include iostream for input/output operations.
#include <cstdlib>    // Include cstdlib for system functions like clearing the screen.
#include <ctime>      // Include ctime for random number seeding.
using namespace std;  // Use the standard namespace to avoid prefixing std:: before standard functions.

// Enumeration: enGameChoice
// Purpose: Defines the choices available in the game.
enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };

// Enumeration: enWinner
// Purpose: Defines possible winners for a round or game.
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

// Structure: stRoundInfo
// Purpose: Stores details of a single round of the game.
struct stRoundInfo
{
    short RoundNumber = 0;          // Round number.
    enGameChoice Player1Choice;     // Player's choice.
    enGameChoice ComputerChoice;    // Computer's choice.
    enWinner Winner;                // Stores the winner of the round.
    string WinnerName;               // Stores the winner's name.
};

// Structure: stGameResults
// Purpose: Stores overall game results after all rounds are played.
struct stGameResults
{
    short GameRounds = 0;        // Number of rounds played.
    short Player1WinTimes = 0;   // Count of Player1's wins.
    short ComputerWinTimes = 0;  // Count of Computer's wins.
    short DrawTimes = 0;         // Number of rounds that ended in a draw.
    enWinner GameWinner;         // Stores the overall game winner.
    string WinnerName = "";      // Name of the game winner.
};

// Function: RandomNumber
// Purpose: Generates a random number within the given range [From, To].
// Parameters:
//   - From: Lower bound of the random range.
//   - To: Upper bound of the random range.
// Returns: A random integer between From and To.
int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

// Function: GetComputerChoice
// Purpose: Randomly selects the computer's choice.
// Returns: An enGameChoice value representing the computer's move.
enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}

// Function: WhoWonTheRound
// Purpose: Determines the winner of a round based on player and computer choices.
enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
    // If both choices are the same, it's a draw.
    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
        return enWinner::Draw;

    // Determine the winner based on game rules.
    switch (RoundInfo.Player1Choice)
    {
    case enGameChoice::Stone:
        return (RoundInfo.ComputerChoice == enGameChoice::Paper) ? enWinner::Computer : enWinner::Player1;
    case enGameChoice::Paper:
        return (RoundInfo.ComputerChoice == enGameChoice::Scissors) ? enWinner::Computer : enWinner::Player1;
    case enGameChoice::Scissors:
        return (RoundInfo.ComputerChoice == enGameChoice::Stone) ? enWinner::Computer : enWinner::Player1;
    }
}

// Function: WhoWonTheGame
// Purpose: Determines the final game winner based on win counts.
enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
    if (Player1WinTimes > ComputerWinTimes) return enWinner::Player1;
    else if (ComputerWinTimes > Player1WinTimes) return enWinner::Computer;
    else return enWinner::Draw;
}

// Function: ChoiceName
// Purpose: Converts an enGameChoice enum to a string representation.
string ChoiceName(enGameChoice Choice)
{
    string arrGameChoices[3] = { "Stone", "Paper", "Scissors" };
    return arrGameChoices[Choice - 1];
}

// Function: WinnerName
// Purpose: Converts an enWinner enum to a string representation.
string WinnerName(enWinner Winner)
{
    string arrWinnerName[3] = { "Player1", "Computer", "No Winner (Draw)" };
    return arrWinnerName[Winner - 1];
}

// Function: ReadPlayer1Choice
// Purpose: Prompts the player to input their choice.
enGameChoice ReadPlayer1Choice()
{
    short Choice;
    do
    {
        cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors? ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 3);
    return (enGameChoice)Choice;
}

// Function: PrintRoundResults
// Purpose: Displays the results of a single round.
void PrintRoundResults(stRoundInfo RoundInfo)
{
    cout << "\n____________ Round [" << RoundInfo.RoundNumber << "] ____________\n\n";
    cout << "Player1 Choice: " << ChoiceName(RoundInfo.Player1Choice) << endl;
    cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner   : [" << RoundInfo.WinnerName << "]\n";
    cout << "_________________________________________\n" << endl;
}

// Function: PlayGame
// Purpose: Runs the game for a given number of rounds and determines the final winner.
stGameResults PlayGame(short HowManyRounds)
{
    stRoundInfo RoundInfo;
    short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

    for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
    {
        cout << "\nRound [" << GameRound << "] begins:\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.Player1Choice = ReadPlayer1Choice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

        if (RoundInfo.Winner == enWinner::Player1)
            Player1WinTimes++;
        else if (RoundInfo.Winner == enWinner::Computer)
            ComputerWinTimes++;
        else
            DrawTimes++;

        PrintRoundResults(RoundInfo);
    }

    return { HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes, WhoWonTheGame(Player1WinTimes, ComputerWinTimes), WinnerName(WhoWonTheGame(Player1WinTimes, ComputerWinTimes)) };
}

// Function: StartGame
// Purpose: Controls the game loop, allowing players to replay the game.
void StartGame()
{
    char PlayAgain = 'Y';

    do
    {
        system("cls");  // Clear the screen before starting a new game.
        stGameResults GameResults = PlayGame(3); // Play 3 rounds.
        cout << "\nGame Over! Winner: " << GameResults.WinnerName << endl;

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

// Main Function
int main()
{
    srand((unsigned)time(NULL));  // Seed random number generator.
    StartGame();  // Start the game.
    return 0;  // Return 0 to indicate successful execution.
}






























//_______________________________________my solution____________________________________
/*
#include <iostream>
#include <windows.h>

using namespace std;

enum ResultOfGame { win, lose, tie };

enum Choices { Paper, Rock, Scissor };

ResultOfGame DetermineResult(Choices userchoice, Choices computerchoice) {
    if (userchoice == computerchoice)
        return tie;
    else if ((userchoice == Paper && computerchoice == Rock) ||
        (userchoice == Rock && computerchoice == Scissor) ||
        (userchoice == Scissor && computerchoice == Paper))
        return win;
    else
        return lose;
}

Choices GenerateComputerChoice() {
    return static_cast<Choices>(rand() % 3);
}

void DisplayResult(ResultOfGame result) {
    switch (result) {
    case win:
        system("color 2F");
        cout << "You win this round!" << endl;
        break;
    case lose:
        system("color 4F");
        cout << "You lose this round!" << endl;
        Beep(750, 300);
        break;
    case tie:
        system("color 6F");
        cout << "It's a tie this round!" << endl;
        
        break;
    }
}

Choices UserChoice() {
    char x;
    while (true) {
        cout << "Enter your choice (R for Rock - P for Paper - S for Scissor): ";
        cin >> x;

        if (x == 'P' || x == 'p')
            return Paper;
        
        else if (x == 'R' || x == 'r')
            return Rock;
        else if (x == 'S' || x == 's')
            return Scissor;
        else
            cout << "Invalid input. Please try again." << endl;
    }
}

void PlayGame() {
    int rounds=0;
    int userscore=0, computerscore=0 , tiescore=0;
    char playagain;
    do {
        system("color 0f");
        system("cls");
        
        cout << "Enter the number of rounds: ";
        cin >> rounds;
        for (int i = 0; i < rounds; i++) {
            cout << "\nRound {" << (i + 1)<<"} Begins :" << endl;
            ResultOfGame result = DetermineResult(UserChoice(), GenerateComputerChoice());

            DisplayResult(result);
            if (result == win) 
                
                userscore++;
            
            else if (result == lose) 

                computerscore++;
            
            else
               
                tiescore++;
        }
        cout << "\t\t___________________________________________________________________\n";
        cout << "\n\t\t\t\t-------------- Game Over ----------------" << endl;
        cout << "\t\t___________________________________________________________________\n";
      
        cout << "\t\t\t\t|You won " << userscore << " rounds." << endl;
        cout << "\t\t\t\t|Computer won " << computerscore << " rounds." << endl;
        cout << "\t\t\t\t|Ties: " << tiescore << endl;
        cout << "\t\t___________________________________________________________________\n";
        if (userscore > computerscore)
            cout << "----- You are the winner! Congratulations! -----" << endl;
        else if (userscore < computerscore)
            cout << "----- You lost the game. Better luck next time! -----" << endl;
        else
            cout << "----- The game is a tie! -----" << endl;

        cout << "\n\tDo you want to play again? (Y/N): ";
        cin >> playagain;

        userscore = 0;
        computerscore = 0;
        tiescore = 0;

    } while (playagain == 'Y' || playagain == 'y');
}

int main() {
    srand((unsigned)(time(nullptr)));
    PlayGame();
    return 0;
}*/

