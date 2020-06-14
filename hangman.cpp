/*
 * Name: Md Fazle Rabbi
 * Professor Vincent Mierlak
 * CISC 1600
 * Final Project Part II
 * hangman.cpp
 */

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

constexpr int L = 3;

//displays the game difficulty levels
//Parameters:
//      pickLevel = takes users input and based on that game starts
//srtore the users input for level of difficulty
void displayLevel(int &pickLevel);

//it sets the chances for each level of the game
//Parameters:
//      string secretWord = takes the secretWord to determine the chances
//return chances
int chancesLeft(string secretWord);

//checks users input is in the secret letter or not
//Precondition: letter == Word[i] 
//Parameters:
//      char letter: user input
//      string word: secretWord/wrongLetter
//returns result = true
bool checkLetter(char letter, string word);

//creates the hint word based on the leve
//Parameters: 
//      char guessedWord[] = takes the array & creates the guessedWord array
//      string secretWord = takes the secretWord based on level
void hint(char guessedWord[], string secretWord);

//displays the hint word on the screen for player
//Parameters: 
//      char guessedWord[] = takes guessedWord for so it can create array
//      string secretWord = takes the secretWord to get the word length
void displayHintWord(char guessedWord[], string secretWord);

//tells the player if they won/lost the game
//Precondition: secretWord == guessedWord
//Parameters:
//      string secretWord = used for if statement condition
//      string guessedWord = used for if statement condition
void gameResult(string secretWord, char guessedWord[]);

//plays the game
//Parameters:
//      string secretWord = takes the word based on player level of difficulty
bool play_game(string secretWord, int chances);


int main()
{
    //used to initialize the pseudo-random number generator by passing
    //the argument seed
    srand(time(0));
    
    //variables
    int pickLevel, chances;
    string storeWord[L][4];
    int randomWord = rand() % 3;
    bool playAgain = true;
    
    //word storage for easy level
    storeWord[0][0] = "cow";
    storeWord[0][1] = "goat";
    storeWord[0][2] = "mango";

    //word storage for medium level
    storeWord[1][0] = "subtle";
    storeWord[1][1] = "jinxed";
    storeWord[1][2] = "facebook";

    //word storage for hard level
    storeWord[2][0] = "commencement";
    storeWord[2][1] = "instructions";
    storeWord[2][2] = "expeditionary";
    
    //asks users to pick a difficulty level
    displayLevel(pickLevel);
   
    do
    {
        //based on users difficulty level it assigns a secret word
        string secretWord = storeWord[pickLevel][randomWord];

        //set the chances left for player based on difficulty level
        chances = chancesLeft(secretWord);

        //user starts the game
        playAgain = play_game(secretWord, chances);
 
    } while(playAgain == false);

    return 0;
}

//----------------------------------------------------------------------------
//                         Function Definition                          
//----------------------------------------------------------------------------


//displays level & sets the game level
void displayLevel(int &pickLevel)
{
    cout <<"\n\tThe Hangman Game!!\n";
    cout << endl;
    
    do
    {
        cout <<"\tDifficulties: "<< endl << endl;
        cout <<"Press (0) for Easy\n";
        cout <<"Press (1) for Medium\n";
        cout <<"Press (2) for Hard\n";
        cout <<"Enter: ";
        cin >> pickLevel;

    } while (pickLevel < 0 || pickLevel > 2);

    return;
}


//sets the chances based on level difficulty
int chancesLeft(string secretWord)
{
    int chances;

    if (secretWord.length() < 6)
        chances = 6;
    else if (secretWord.length() >= 6 && secretWord.length() < 12)
        chances = 8;
    else if (secretWord.length() >= 12)
        chances = 10;

        return chances;
}


//checks the guess letter is in the secretWord or not
bool checkLetter(char letter, string word)
{
    bool result = false;
    
    for (int i = 0; i < word.length(); i++)
    {
        if(letter == word[i])
        {
            result = true;
            break;
        }
    }
        return result;
}


//creates the hint word based on difficulty level
void hint(char guessedWord[], string secretWord)
{
    for(int i = 0; i < secretWord.length(); i++)
    {
        guessedWord[i] = '_';
    }

    return;
}


//displays the hint word to player
void displayHintWord(char guessedWord[], string secretWord)
{
    for(int i = 0; i < secretWord.length(); i++)
        cout << guessedWord[i] <<" ";
    return;
}


//tells the player if they won the game or lost the game
void gameResult(string secretWord, char guessedWord[])
{
    if(guessedWord == secretWord)
    {
        cout <<"\n\nANS: " << secretWord << endl;
        cout <<"\nCongratulations!! Victory!!\n"<< endl;
    }
    else 
    {
        cout <<"\nToo bad you lost!"<< endl;
    }
}

//player plays the game
bool play_game(string secretWord, int chances)
{
    using namespace std;

    //variables
    bool playAgain;
    char letter;
    char replay;
    char guessedWord [secretWord.length()];
    string wrongLetter = "";

    //creates the hint word
    hint(guessedWord, secretWord);

    cout <<"\nTotal Chances : "<< chances << endl;

    //player keep guessing letters and shows the stats
    while ((chances > 0) && (secretWord != guessedWord))
    {
        cout <<"Secret Word   : ";
        //displays the hint word
        displayHintWord(guessedWord, secretWord);
        cout << endl;

        cout <<"\nEnter letter  : ";
        cin >> letter;

        //if the players input letter is in their it replaces the hint
        if(checkLetter(letter, secretWord) == true)
        {
            for(int i = 0; i < secretWord.length(); i++)
            {
                if (letter == secretWord[i])
                    guessedWord[i] = letter;
            }   
        }

        //if the players input letter is wrong then it shows the wrong letters
        else 
        {
            //if player uses same wrong letter it does nothing
            if(checkLetter(letter, wrongLetter) == true)
            {

            }
            else
            {
                //adds the wrong letter on the screen
                wrongLetter += letter;
                wrongLetter += " ";
                //if its a wrong letter it takes away 1 chances each time
                chances--;
            }
        } 

        cout <<"\nWrong Letters : "<< wrongLetter << endl;
        cout <<"Chances Left  : "<< chances << endl;

    }

    //gives the player game stats if they won
    if(secretWord == guessedWord)
    {
        cout <<"\n\nSecret Word    : "; 
        displayHintWord(guessedWord, secretWord);
        cout << endl;
        cout <<"Wrong Letters  : "<< wrongLetter << endl;
        cout <<"Chances Left   : "<< chances << endl;
    }

    //tells the game result
    gameResult(secretWord, guessedWord);

    //if the player loses the game, then they get a chance to replay
    if (secretWord != guessedWord)
    {
        cout <<"\nDo you want to replay [y]es or [n]o: ";
        cin >> replay;

        if (replay == 'y' || replay == 'Y')
            playAgain = false;
        else
            cout <<"\t\nGames Over!!\n";
    }

    return playAgain;
}


