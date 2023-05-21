#pragma once

char arr[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

bool Win(char w); //Проверка победы
int Game(); //Определяет, куда ходить компьютеру
bool TNum(string b); //Проверяет является ли переменная числом
char Play(int f); //Игра
void Output(Player p); //Вывод информации об игроке
vector<Player> Input(int n); //Ввод данных об игроках
bool comp0(Player p1, Player p2); //Сравнение по победам
bool comp1(Player p1, Player p2); //Сравнение по ничьям
bool comp2(Player p1, Player p2); //Сравнение по поражениям