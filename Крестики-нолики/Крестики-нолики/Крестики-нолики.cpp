#include <iostream>
#include <vector>
#include <string>
#include "Classr.h"
#include "Function.cpp"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int gameMode, numPlayers;
    char result, contin = ' ';
    string b;
    Games game;
    Menu menu;
    Player p;
    HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "Игра крестики-нолики!" << endl;

    cout << "Введите количество игроков: " << endl;
    cin >> b;

    while (TNum(b) == false) {
        cout << "Вы ввели не число, повторите ввод: " << endl;
        cin >> b;
    }

    numPlayers = stoi(b);
    vector<Player> players(numPlayers);

    players = Input(numPlayers);

    while (contin != 'M') {

        for (int i = 0; i < numPlayers; i++) {
            SetConsoleTextAttribute(hwnd, 7);
            cout << "Играет " << players[i].Name << endl;
            gameMode = game.Start();
            result = Play(gameMode);

            SetConsoleTextAttribute(hwnd, 12);
            if (gameMode == 0) {
                if (result == 'O') {
                    cout << "Вы победили! " << endl;
                    players[i].ScoreWin++;
                }
                else if (result == 'X') {
                    cout << "Вы проиграли" << endl;
                    players[i].ScoreLoose++;
                }
                else {
                    cout << "Ничья!" << endl;
                    players[i].ScoreN++;
                }
            }
            else if (gameMode == 1) {
                if (result == 'X') {
                    cout << endl;
                    cout << "Вы победили! " << endl;
                    players[i].ScoreWin++;
                }
                else if (result == 'O') {
                    cout << endl;
                    cout << "Вы проиграли" << endl;
                    players[i].ScoreLoose++;
                }
                else {
                    cout << endl;
                    cout << "Ничья!" << endl;
                    players[i].ScoreN++;
                }
            }
            SetConsoleTextAttribute(hwnd, 15);
            for (int j = 0; j < 9; j++)
                arr[j] = char(j + 49);
        }
        cout << endl;
        cout << "Если хотите закончить играть и выйте в меню введите M" << endl;
        cin >> contin;
        for (int j = 0; j < 9; j++)
            arr[j] = char(j + 49);
    }

    bool t = true;
    while (t)
        t = menu.menu(menu.change(), players);
}