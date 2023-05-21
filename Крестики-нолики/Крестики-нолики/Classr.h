#pragma once
using namespace std;

//Класс игрока
class Player
{
public:
    string Name; //Имя
    int ScoreWin; //Количество побед
    int ScoreLoose; //Количество поражений
    int ScoreN; //Количество ничей
};

//Класс игры
class Games
{
public:
    int Start(); //Начало игры, для определения режима игры
    void Print(char a[9]); //Вывод игровой ситуации
};

//Класс меню
class Menu
{
public:
    int change(); //Выбора что искать
    bool menu(int s, vector<Player> players); //Выводит рейтинга и т.п.
};