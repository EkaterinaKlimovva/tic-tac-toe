#pragma once

char arr[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

bool Win(char w); //�������� ������
int Game(); //����������, ���� ������ ����������
bool TNum(string b); //��������� �������� �� ���������� ������
char Play(int f); //����
void Output(Player p); //����� ���������� �� ������
vector<Player> Input(int n); //���� ������ �� �������
bool comp0(Player p1, Player p2); //��������� �� �������
bool comp1(Player p1, Player p2); //��������� �� ������
bool comp2(Player p1, Player p2); //��������� �� ����������