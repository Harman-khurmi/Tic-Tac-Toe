// At the beginning of your code
// #if __cplusplus < 201103L
// #error This file requires C++11 support
// #endif
#include <iostream>
#include <string>
#include <ctime>
// ctime helps to work with time related things s.a get_current_time, compare_time
#include <random>
// random help to generate random numbers
using namespace std;

char board[9] = {
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
};
void instructions();
void show_board();
void computer_choice();
void player_one_choice();
void player_two_choice();
int choice_count(char symbol);
char check_winner();
void computer_vs_player();
void player_vs_player();
int main()
{
    instructions();
    int mode;
    cout<<"1. Computer VS Player Mode"<<endl;
    cout<<"2. Player VS Player Mode"<<endl;
    cout<<"Enter mode:";
    cin>>mode;
    switch (mode)
    {
    case 1:
        computer_vs_player();
        break;
    case 2:
        player_vs_player();
        break;
    
    default:
    cout<<"Choose corrent mode";
        break;
    }

    return 0;
}

void computer_vs_player()
{
    string player_name;
    cout << "enter player name:";
    cin>>player_name;
    //getline(cin, player_name);
    while (true)
    {
        system("cls");
        show_board();
        if (choice_count('X') == choice_count('O'))
        {
            cout << player_name << "'s turn:" << endl;
            player_one_choice();
        }
        else
        {
            cout << "Computer's Turn" << endl;
            computer_choice();
        }
        char winner = check_winner();
        if (winner == 'X')
        {
            system("cls");
            show_board();
            cout << player_name << " Won";
            break;
        }
        else if (winner == 'O')
        {
            system("cls");
            show_board();
            cout << "Computer Won";
            break;
        }
        else if (winner == 'D')
        {
            system("cls");
            show_board();
            cout << "Draw Game";
            break;
        }
    }
}

void player_vs_player()
{
     string player1_name;
    cout << "enter player 1 name:"<<endl;
    cin>>player1_name;
    //getline(cin, player1_name);
    string player2_name;
    cout << "enter player 2 name:"<<endl;
     cin>>player2_name;
    //getline(cin, player2_name);

    while (true)
    {
        system("cls");
        show_board();
        if (choice_count('X') == choice_count('O'))
        {
            cout << player1_name << "'s Turn" << endl;
            player_one_choice();
            //break;
        }
        else
        {
            cout << player2_name << "'s Turn" << endl;
            player_two_choice();
            //break;
        }
        char winner = check_winner();
        if (winner == 'X')
        {
            system("cls");
            show_board();
            cout << player1_name << " Won The Game" << endl;
        }
        else if (winner == 'O')
        {
            system("cls");
            show_board();
            cout << player2_name << " Won The Game" << endl;
        }
        else if (winner == 'D')

        {
            system("cls");
            show_board();
            cout << "Draw Game";
            break;
        }
    }
}

void computer_choice()
{
    srand(time(0)); // srand:sets the starting points for the random num. seq to make them random wach time ||time:gets the curernt time in sec  || there can be anything instead of 0 as they act as constants.
    int choice;
    do
    {
        choice = rand() % 10; // return a random number btw 0 to 9
    } while (board[choice] != ' ');
    board[choice] = 'O'; // as computer enters O
}

void player_one_choice()
{
    while (true)
    {
        // int choice;
        cout << "Enter the positon from (1-9):";
        int choice;
        cin >> choice;
        choice--;
        if (choice < 0 || choice > 8)
        {
            cout << "Please enter from position (1-9).";
        }
        else if (board[choice] != ' ')
        {
            cout << "please enter another postion.";
        }
        else
        {
            board[choice] = 'X';
            break; // mistake
        }
    }
}
void player_two_choice()
{
    while (true)
    {
        int choice;
        cout << "Enter the positon from (1-9):";
        cin >> choice;
        choice--;
        if (choice < 0 || choice > 9)
        {
            cout << "Please enter from position (1-9).";
        }
        else if (board[choice] != ' ')
        {
            cout << "please enter another postion.";
        }
        else
        {
            board[choice] = 'O';
            break;
        }
    }
}
int choice_count(char symbol)
{
    int total = 0;
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == symbol)
        {
            total = total + 1;
        }
    }
    return total;
}

char check_winner()
{
    // checking for horizontal
    if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
    {
        return board[0];
    }
    if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
    {
        return board[3];
    }
    if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
    {
        return board[6];
    }

    // checking for vertical
    if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
    {
        return board[0];
    }
    if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
    {
        return board[1];
    }
    if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
    {
        return board[2];
    }
    // checking for diagnols
    if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
    {
        return board[0];
    }
    if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
    {
        return board[2];
    }
    if (choice_count('X') + choice_count('O') < 9)
    {
        return 'C';
    }
    else
        return 'D';
}

void show_board()
{
    cout << "      |       |       " << endl;
    cout << "   " << board[0] << "  |   " << board[1] << "   |   " << board[2] << "   " << endl;
    cout << "______|_______|_______" << endl;
    cout << "      |       |       " << endl;
    cout << "   " << board[3] << "  |   " << board[4] << "   |   " << board[5] << "   " << endl;
    cout << "______|_______|_______" << endl;
    cout << "      |       |       " << endl;
    cout << "   " << board[6] << "  |   " << board[7] << "   |   " << board[8] << "   " << endl;
    cout << "      |       |       " << endl
         << endl;
}

void instructions()
{
    cout << "Enter any key to start the game";
    getchar();
    cout << "\n";
    cout << "............." << endl;
    cout << " TIC-TAC-TOE" << endl;
    cout << "............." << endl;
    cout << "PLAYER 1 ->  X" << endl;
    cout << "PLAYER 2 ->  O" << endl;
    cout << "COMPUTER ->  O" << endl;
    cout << "      |       |       " << endl;
    cout << "   1  |    2  |   3   " << endl;
    cout << "______|_______|_______" << endl;
    cout << "      |       |       " << endl;
    cout << "   4  |   5   |   6   " << endl;
    cout << "______|_______|_______" << endl;
    cout << "      |       |       " << endl;
    cout << "   7  |   8   |   9   " << endl;
    cout << "      |       |       " << endl
         << endl;
}