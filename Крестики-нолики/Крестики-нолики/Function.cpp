#pragma once
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <algorithm>
#include "Vars.h"
#include "Classr.h"

using namespace std;

bool Win(char w) {
    if (arr[0] == w && arr[1] == w && arr[2] == w) return true;
    if (arr[3] == w && arr[4] == w && arr[5] == w) return true;
    if (arr[6] == w && arr[7] == w && arr[8] == w) return true;
    if (arr[0] == w && arr[3] == w && arr[6] == w) return true;
    if (arr[1] == w && arr[4] == w && arr[7] == w) return true;
    if (arr[2] == w && arr[5] == w && arr[8] == w) return true;
    if (arr[0] == w && arr[4] == w && arr[8] == w) return true;
    if (arr[2] == w && arr[4] == w && arr[6] == w) return true;
    return false;
}

int Game() {
    if (arr[4] == '5')
        return 5;
    for (int i = 0; i < 9; i++)
        if (arr[i] == char(i + 49)) {
            arr[i] = 'O';
            if (Win('O'))
                return i + 1;
            else
                arr[i] = char(i + 49);

            arr[i] = 'X';
            if (Win('X'))
                return i + 1;
            else
                arr[i] = char(i + 49);
        }
    for (int i = 0; i < 9; i++)
        if (arr[i] == char(i + 49))
            return i + 1;
}

bool TNum(string b) {
    
    try
    {
        stoi(b);
    }
    catch (const exception&)
    {
        return false;
    }
    return true;
}

char Play(int f) {
    int moveNum = 1, move;
    char a, b;
    string m0;
    Games board;

    if (f == 0) {
        a = 'O'; 
        b = 'X';
    }
    else {
        a = 'X';
        b = 'O';
    }
    while (true) {
        if (moveNum % 2 == f) {
            board.Print(arr);
            if (moveNum > 1) {
                cout << "Компьютер поставил " << b << " на " << move << endl;
            }
            cout << endl;
            cout << "Ваш ход, введите номер ячейки:  ";
            cin >> m0;
            while (TNum(m0) == false) {
                cout << "Вы ввели не число, повторите ввод: " << endl;
                cin >> m0;
            }
            move = stoi(m0);
            while (arr[move - 1] == 'X' || arr[move - 1] == 'O' || move > 9 || move < 1) {
                cout << "! Пожалуйста, введите коректное значение (1-9) !" << endl;
                cout << "Ваш ход:  ";
                cin >> m0;
                while (TNum(m0) == false) {
                    cout << "Вы ввели не число, повторите ввод: " << endl;
                    cin >> m0;
                }
                move = stoi(m0);
            }

            arr[move - 1] = a;
            if (Win(a)) {
                board.Print(arr);
                return a;
            }
        }
        else {
            board.Print(arr);
            if (moveNum > 1) {
                cout << "Вы поставили " << a << " на " << move << endl;
            }
            move = Game();
            arr[move - 1] = b;
            if (Win(b)) {
                board.Print(arr);
                return b;
            }
        }
        moveNum++;
        if (moveNum == 10) {
            board.Print(arr);
            return 'N';
        }
    }
}


void Output(Player p) {
    cout << endl;
    HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hwnd, 10);
    cout << "Игрок " << p.Name << " выиграл " << p.ScoreWin << " раз!" << endl;
    cout << "Компьютер выиграл " << p.ScoreLoose << " раз!" << endl;
    cout << "Ничья " << p.ScoreN << " раз!" << endl;
    SetConsoleTextAttribute(hwnd, 7);
}

vector<Player> Input(int n) {
    Player p;
    vector<Player> players;

    for (int i = 0; i < n; i++) {
        cout << "Введите имя " << (i + 1) << " игрока: " << endl;
        cin >> p.Name;

        p.ScoreLoose = 0;
        p.ScoreN = 0;
        p.ScoreWin = 0;
        cout << endl;
        players.push_back(p);
    }
    return players;
}

bool comp0(Player p1, Player p2) {
    return p1.ScoreWin < p2.ScoreWin;
}

bool comp1(Player p1, Player p2) {
    return p1.ScoreN < p2.ScoreN;
}

bool comp2(Player p1, Player p2) {
    return p1.ScoreLoose < p2.ScoreLoose;
}

int Games::Start() {
    string c;
    cout << "Выберете режим игры (0 - вы играете за нолики, 1 - за крестики, 2 - случайно, 3 - если хотите считать из файла): " << endl;
    cin >> c;

    while (c != "0" && c != "1" && c != "2" && c != "3") {
        cout << "Введено неправильное значение, повторите ввод" << endl;
        cin >> c;
    }

    if (c == "3") {
        ifstream f("Текст.txt");
        getline(f, c);
    }

    while (c != "0" && c != "1" && c != "2") {
        cout << "Введено неправильное значение, повторите ввод" << endl;
        cin >> c;
    }

    if (c == "0")
        return 0;
    else if (c == "1")
        return 1;
    else if (c == "2")
        return rand() % 2;      
}

void Games::Print(char a[9]) {
    cout << endl;
    HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < 3; i++) {
        if (a[i] == 'X' || a[i] == 'O') {
            SetConsoleTextAttribute(hwnd, 9);
            cout << " " << a[i];
            SetConsoleTextAttribute(hwnd, 15);
        }
        else
            cout << " " << a[i];
    }
    cout << endl;
    for (int i = 3; i < 6; i++) {
        if (a[i] == 'X' || a[i] == 'O') {
            SetConsoleTextAttribute(hwnd, 9);
            cout << " " << a[i];
            SetConsoleTextAttribute(hwnd, 15);
        }
        else
            cout << " " << a[i];
    }
    cout << endl;
    for (int i = 6; i < 9; i++) {
        if (a[i] == 'X' || a[i] == 'O') {
            SetConsoleTextAttribute(hwnd, 9);
            cout << " " << a[i];
            SetConsoleTextAttribute(hwnd, 15);
        }
        else
            cout << " " << a[i];
    }
    cout << endl;
}

int Menu :: change() {
    string s0;

    cout << "Введите 1, если хотите вывести рейтинг игроков" << endl;
    cout << "Введите 2, если хотите найти игрока с максимальным числом побед" << endl;
    cout << "Введите 3, если хотите найти игрока с максимальным числом ничей" << endl;
    cout << "Введите 4, если хотите найти игрока с максимальным числом поражений" << endl;
    cout << "Введите 5, если хотите найти игрока с минимальным числом побед" << endl;
    cout << "Введите 6, если хотите найти игрока с минимальным числом ничей" << endl;
    cout << "Введите 7, если хотите найти игрока с минимальным числом поражений" << endl;
    cout << "Нажмите 8 для выхода" << endl;

    cin >> s0;

    while (TNum(s0) == false) {
        cout << "Вы ввели не число, повторите ввод: " << endl;
        cin >> s0;
    }
    return stoi(s0);
}

bool Menu::menu(int s, vector<Player> players) {
    switch (s)
    {
    case(1):
        sort(players.begin(), players.end(), comp0);
        for (int i = 0; i < players.size(); i++)
            Output(players[i]);
        return true;
        break;
    case(2): {
        auto max0 = max_element(players.begin(), players.end(), comp0);
        Output(players[max0 - players.begin()]);
        return true;
        break;
    }
    case(3): {
        auto max1 = max_element(players.begin(), players.end(), comp1);
        Output(players[max1 - players.begin()]);
        return true;
        break;
    }
    case(4): {
        auto max2 = max_element(players.begin(), players.end(), comp2);
        Output(players[max2 - players.begin()]);
        return true;
        break;
    }
    case(5): {
        auto min0 = min_element(players.begin(), players.end(), comp0);
        Output(players[min0 - players.begin()]);
        return true;
        break;
    }
    case(6): {
        auto min1 = min_element(players.begin(), players.end(), comp1);
        Output(players[min1 - players.begin()]);
        return true;
        break;
    }
    case(7): {
        auto min2 = min_element(players.begin(), players.end(), comp2);
        Output(players[min2 - players.begin()]);
        return true;
        break;
    }
    case(8):
        return false;
        break;
    }
}