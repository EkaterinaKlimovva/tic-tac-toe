#pragma once
using namespace std;

//����� ������
class Player
{
public:
    string Name; //���
    int ScoreWin; //���������� �����
    int ScoreLoose; //���������� ���������
    int ScoreN; //���������� �����
};

//����� ����
class Games
{
public:
    int Start(); //������ ����, ��� ����������� ������ ����
    void Print(char a[9]); //����� ������� ��������
};

//����� ����
class Menu
{
public:
    int change(); //������ ��� ������
    bool menu(int s, vector<Player> players); //������� �������� � �.�.
};