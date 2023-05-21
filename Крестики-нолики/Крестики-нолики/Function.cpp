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
                cout << "��������� �������� " << b << " �� " << move << endl;
            }
            cout << endl;
            cout << "��� ���, ������� ����� ������:  ";
            cin >> m0;
            while (TNum(m0) == false) {
                cout << "�� ����� �� �����, ��������� ����: " << endl;
                cin >> m0;
            }
            move = stoi(m0);
            while (arr[move - 1] == 'X' || arr[move - 1] == 'O' || move > 9 || move < 1) {
                cout << "! ����������, ������� ��������� �������� (1-9) !" << endl;
                cout << "��� ���:  ";
                cin >> m0;
                while (TNum(m0) == false) {
                    cout << "�� ����� �� �����, ��������� ����: " << endl;
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
                cout << "�� ��������� " << a << " �� " << move << endl;
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
    cout << "����� " << p.Name << " ������� " << p.ScoreWin << " ���!" << endl;
    cout << "��������� ������� " << p.ScoreLoose << " ���!" << endl;
    cout << "����� " << p.ScoreN << " ���!" << endl;
    SetConsoleTextAttribute(hwnd, 7);
}

vector<Player> Input(int n) {
    Player p;
    vector<Player> players;

    for (int i = 0; i < n; i++) {
        cout << "������� ��� " << (i + 1) << " ������: " << endl;
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
    cout << "�������� ����� ���� (0 - �� ������� �� ������, 1 - �� ��������, 2 - ��������, 3 - ���� ������ ������� �� �����): " << endl;
    cin >> c;

    while (c != "0" && c != "1" && c != "2" && c != "3") {
        cout << "������� ������������ ��������, ��������� ����" << endl;
        cin >> c;
    }

    if (c == "3") {
        ifstream f("�����.txt");
        getline(f, c);
    }

    while (c != "0" && c != "1" && c != "2") {
        cout << "������� ������������ ��������, ��������� ����" << endl;
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

    cout << "������� 1, ���� ������ ������� ������� �������" << endl;
    cout << "������� 2, ���� ������ ����� ������ � ������������ ������ �����" << endl;
    cout << "������� 3, ���� ������ ����� ������ � ������������ ������ �����" << endl;
    cout << "������� 4, ���� ������ ����� ������ � ������������ ������ ���������" << endl;
    cout << "������� 5, ���� ������ ����� ������ � ����������� ������ �����" << endl;
    cout << "������� 6, ���� ������ ����� ������ � ����������� ������ �����" << endl;
    cout << "������� 7, ���� ������ ����� ������ � ����������� ������ ���������" << endl;
    cout << "������� 8 ��� ������" << endl;

    cin >> s0;

    while (TNum(s0) == false) {
        cout << "�� ����� �� �����, ��������� ����: " << endl;
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