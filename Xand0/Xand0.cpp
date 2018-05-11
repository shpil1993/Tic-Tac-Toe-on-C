#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <string>
using namespace std;

struct highScore {
	string name;
	int scores;
};
//___________________scores__________________________________________
highScore highscore10[5];
highScore highscore3[5];
string names = "";
int scores = NULL;
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
COORD coord;
COORD coord1;
void addscores(highScore highscore[5]) {
	for (int i = 0; i < 5; i++) {
		if (highscore[i].scores == NULL) {
			highscore[i].name = names;
			highscore[i].scores = scores;
			break;
		}
		else if (highscore[4].scores > scores) {
			highscore[4].name = names;
			highscore[4].scores = scores;
			break;
		}
	}
	for (int i = 0; i < 5;) {
		if (highscore[i].scores > highscore[i + 1].scores && highscore[i + 1].scores != NULL) {
			int tmps = highscore[i].scores;
			highscore[i].scores = highscore[i + 1].scores;
			highscore[i + 1].scores = tmps;
			string tmpn = highscore[i].name;
			highscore[i].name = highscore[i + 1].name;
			highscore[i + 1].name = tmpn;
			i = 0;
		}
		else {
			i++;
		}
	}
}
void printscores(highScore highscore[5]) {
	setlocale(LC_ALL, "RUSSIAN");
	coord1.X = 50;
	coord1.Y = 5;
	SetConsoleCursorPosition(handle, coord1);
	SetConsoleTextAttribute(handle, 11);
	for (int i = 0; i < 5; i++) {
		SetConsoleCursorPosition(handle, coord1);
		cout << i + 1 << ". " << highscore[i].name << "  " << highscore[i].scores << endl;
		coord1.Y++;
	}
	_gettch();
}
void write_to_scores(highScore highscore1[5], highScore highscore2[5]) {
		ofstream score;
		score.open("score.txt");
		for (int i = 0; i < 5; i++) {
			if (highscore1[i].scores != NULL) {
				score << highscore1[i].name << " ";
				score << highscore1[i].scores << " ";
			}
		}
		score.close();
		ofstream score1;
		score1.open("score3.txt");
		for (int i = 0; i < 5; i++) {
			if (highscore2[i].scores != NULL) {
				score << highscore2[i].name << " ";
				score << highscore2[i].scores << " ";
			}
		}
		score1.close();
}
void read_from_scores(highScore highscore1[5], highScore highscore2[5]) {
	ifstream score2;
	score2.open("score.txt");
	for (int i = 0; i < 5; i++) {
		score2 >> highscore1[i].name;
		score2 >> highscore1[i].scores;
	}
	score2.close();
	for (int i = 0; i < 5;) {
		if (highscore1[i].scores > highscore1[i + 1].scores && highscore1[i + 1].scores != NULL) {
			int tmps = highscore1[i].scores;
			highscore1[i].scores = highscore1[i + 1].scores;
			highscore1[i + 1].scores = tmps;
			string tmpn = highscore1[i].name;
			highscore1[i].name = highscore1[i + 1].name;
			highscore1[i + 1].name = tmpn;
			i = 0;
		}
		else {
			i++;
		}
	}
	ifstream score3;
	score3.open("score3.txt");
	for (int i = 0; i < 5; i++) {
		score3 >> highscore2[i].name;
		score3 >> highscore2[i].scores;
	}
	score3.close();
	for (int i = 0; i < 5;) {
		if (highscore2[i].scores > highscore2[i + 1].scores && highscore2[i + 1].scores != NULL) {
			int tmps = highscore2[i].scores;
			highscore2[i].scores = highscore2[i + 1].scores;
			highscore2[i + 1].scores = tmps;
			string tmpn = highscore2[i].name;
			highscore2[i].name = highscore2[i + 1].name;
			highscore2[i + 1].name = tmpn;
			i = 0;
		}
		else {
			i++;
		}
	}
}
void draw_2_strings(string strin[]) {
	setlocale(LC_ALL, "RUSSIAN");
	coord1.X = 50;
	coord1.Y = 10;
	for (int i = 0; i < 3; i++) {
		SetConsoleCursorPosition(handle, coord1);
		SetConsoleTextAttribute(handle, 11);
		cout << strin[i];
		coord1.Y++;
	}
}
int move2strings(string strin[]) {
	setlocale(LC_ALL, "RUSSIAN");
	coord.X = 50;
	coord.Y = 11;
	int e = 0;
	for (int i = 1, j = 0; j != 1;) {
		SetConsoleCursorPosition(handle, coord);
		SetConsoleTextAttribute(handle, 15);
		cout << strin[i];
		e = _gettch();
		if (e == 224) {
			e = _gettch();
			switch (e) {
			case 80:
				if (i != 2) {
					SetConsoleCursorPosition(handle, coord);
					SetConsoleTextAttribute(handle, 11);
					cout << strin[i];
					i++;
					coord.Y++;
					SetConsoleCursorPosition(handle, coord);
					SetConsoleTextAttribute(handle, 15);
					cout << strin[i];
				}
				break;
			case 72:
				if (i != 1) {
					SetConsoleCursorPosition(handle, coord);
					SetConsoleTextAttribute(handle, 11);
					cout << strin[i];
					i--;
					coord.Y--;
					SetConsoleCursorPosition(handle, coord);
					SetConsoleTextAttribute(handle, 15);
					cout << strin[i];
				}
				break;
			default:
				break;
			}
		}
		else if (e == 13) {
			return i;
		}
	}
}
void winer_is(highScore highscore1[5], char pl, int count) {
	coord1.X = 50;
	coord1.Y = 27;
	SetConsoleCursorPosition(handle, coord1);
	SetConsoleTextAttribute(handle, 13);
	cout << "Победитель " << pl << "!";
	coord1.Y++;
	SetConsoleCursorPosition(handle, coord1);
	cout << "Введите имя: ";
	cin >> names;
	scores = count;
	addscores(highscore1);
}
void winer_is_pc(char pc) {
	coord1.X = 50;
	coord1.Y = 27;
	SetConsoleCursorPosition(handle, coord1);
	SetConsoleTextAttribute(handle, 13);
	cout << "Победитель " << pc << "!";
}
void no_one_wins() {
	coord1.X = 50;
	coord1.Y = 27;
	SetConsoleCursorPosition(handle, coord1);
	SetConsoleTextAttribute(handle, 13);
	cout << "Нет победителя!";
}
//___________________field3x3______________________________________
int checkWin(char f3x3[3][3], char pl) {//проверка победы
	if ((f3x3[0][0] == f3x3[0][1] && f3x3[0][1] == f3x3[0][2] && f3x3[0][0] == pl) ||
		(f3x3[1][0] == f3x3[1][1] && f3x3[1][1] == f3x3[1][2] && f3x3[1][2] == pl) ||
		(f3x3[2][0] == f3x3[2][1] && f3x3[2][1] == f3x3[2][2] && f3x3[2][2] == pl) ||
		(f3x3[0][0] == f3x3[1][0] && f3x3[1][0] == f3x3[2][0] && f3x3[2][0] == pl) ||
		(f3x3[0][1] == f3x3[1][1] && f3x3[1][1] == f3x3[2][1] && f3x3[2][1] == pl) ||
		(f3x3[0][2] == f3x3[1][2] && f3x3[1][2] == f3x3[2][2] && f3x3[2][2] == pl) ||
		(f3x3[0][0] == f3x3[1][1] && f3x3[1][1] == f3x3[2][2] && f3x3[2][2] == pl) ||
		(f3x3[2][0] == f3x3[1][1] && f3x3[1][1] == f3x3[0][2] && f3x3[2][0] == pl)) {
		return pl;
	}
	return 0;
}
int negamax(char f3x3[3][3], char pl, char pc) {
	int score = -9999;
	if (checkWin(f3x3, pl) == pl) {//возвращение результата в случаи победы 1 игрока
		return 1000;
	}
	else if (checkWin(f3x3, pc) == pc) {//возвращение результата в случаи победы 2 игрока
		return -1000;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (f3x3[i][j] == ' ') {
				f3x3[i][j] = pl;
				int s = -(negamax(f3x3, pc, pl));//
				f3x3[i][j] = ' ';
				if (s >= score) {
					score = s;
				}
			}
		}
	}
	if (score == -9999 || score == 0) {
		return 0;
	}
	else if (score < 0) {
		return score + 1;
	}
	else if (score > 0) {
		return score - 1;
	}
}
int pickBestMove(char f3x3[3][3], char pl, char pc) {
	int score = -9999;
	int r = -9999;
	int c = -9999;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (f3x3[i][j] == ' ') {
				f3x3[i][j] = pl;
				int s = -(negamax(f3x3, pc, pl));
				f3x3[i][j] = ' ';
				if (s >= score) {
					score = s;
					r = i;
					c = j;
				}
			}
		}
	}
	return (10 * r + c);
}
void drawfield3x3(char f3x3[3][3]) {//прорисовка поля
	coord1.X = 51;
	coord1.Y = 10;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (f3x3[i][j] == 'X') {
				SetConsoleCursorPosition(handle, coord1);
				SetConsoleTextAttribute(handle, 9);
				cout << f3x3[i][j];
				coord1.X += 4;
			}
			else if (f3x3[i][j] == '0') {
				SetConsoleCursorPosition(handle, coord1);
				SetConsoleTextAttribute(handle, 12);
				cout << f3x3[i][j];
				coord1.X += 4;
			}
			else {
				SetConsoleCursorPosition(handle, coord1);
				SetConsoleTextAttribute(handle, 15);
				cout << f3x3[i][j];
				coord1.X += 4;
			}
		}
		coord1.X = 51;
		coord1.Y += 2;
	}
}
void drawframe3x3() {
	coord1.X = 50;
	coord1.Y = 10;
	char frame3x3[5][11] = { ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ' };
	for (int i = 0; i < 5; i++) {//прорисовка рамки
		for (int j = 0; j < 11; j++) {
			SetConsoleCursorPosition(handle, coord1);
			SetConsoleTextAttribute(handle, 15);
			cout << frame3x3[i][j];
			coord1.X++;
		}
		coord1.X = 50;
		coord1.Y++;
	}
}
char move_at_3x3(char f3x3[3][3], int *i, int *j, int col, char pl, bool *end, int count) {
	int e = 0;
	if (count == 0) {
		coord.X = 51;
		coord.Y = 10;
	}
	for (*i, *j; *end != true;) {
		SetConsoleCursorPosition(handle, coord);
		SetConsoleTextAttribute(handle, col);
		cout << f3x3[*i][*j];
		e = _gettch();
		if (e == 224) {//нажатие стрелочек
			e = _gettch();
			switch (e) {
			case 80: //вниз
				if (coord.Y != 14) {
					drawfield3x3(f3x3);
					coord.Y += 2;
					*i += 1;
					SetConsoleCursorPosition(handle, coord);
					SetConsoleTextAttribute(handle, col);
					cout << f3x3[*i][*j];
				}
				break;
			case 72: //вверх
				if (coord.Y != 10) {
					drawfield3x3(f3x3);
					coord.Y -= 2;
					*i -= 1;
					SetConsoleCursorPosition(handle, coord);
					SetConsoleTextAttribute(handle, col);
					cout << f3x3[*i][*j];
				}
				break;
			case 77: //вправо
				if (coord.X != 59) {
					drawfield3x3(f3x3);
					coord.X += 4;
					*j += 1;
					SetConsoleCursorPosition(handle, coord);
					SetConsoleTextAttribute(handle, col);
					cout << f3x3[*i][*j];
				}
				break;
			case 75: //влево
				if (coord.X != 51) {
					drawfield3x3(f3x3);
					coord.X -= 4;
					*j -= 1;
					SetConsoleCursorPosition(handle, coord);
					SetConsoleTextAttribute(handle, col);
					cout << f3x3[*i][*j];
				}
				break;
			default:
				break;
			}
		}
		else if (e == 32) {//нажатие пробела
			if (f3x3[*i][*j] == ' ') {
				f3x3[*i][*j] = pl;
				return f3x3[*i][*j];
			}
		}
		else if (e == 27) {
			*end = true;
		}
	}
}
void PvAiF3x3() {//игра против ии
	setlocale(LC_ALL, "RUSSIAN");
	char f3x3[3][3] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	char pl = 'X';
	char pc = '0';
	int e = 0;
	int col = 31;
	bool end = false;
	int count = 0;
	drawframe3x3();
	for (int i = 0, j = 0; end != true;) {
		f3x3[i][j] = move_at_3x3(f3x3, &i, &j, col, pl, &end, count);
		drawfield3x3(f3x3);
		count++;
		if (checkWin(f3x3, pl) == pl) {//проверка победы игрока
			end = true;
			winer_is(highscore3, pl, count);
			break;
		}
		else if (count == 9) {//ничья
			end = true;
			no_one_wins();
			_gettch();
			break;
		}
		int w = pickBestMove(f3x3, pc, pl);
		int r = w / 10;
		int l = w % 10;
		f3x3[r][l] = pc;
		drawfield3x3(f3x3);
		count++;
		if (checkWin(f3x3, pc) == pc) {//проверка победы ии
			end = true;
			winer_is_pc(pc);
			_gettch();
			break;
		}
		else if (count == 9) {//ничья
			end = true;
			no_one_wins();
			_gettch();
			break;
		}
	}
}
void PvPF3x3() {//игра игрок против игрока
	setlocale(LC_ALL, "RUSSIAN");
	char f3x3[3][3] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	char pl = 'X';
	int e = 0;
	int col = 31;
	bool end = false;
	int count = 0;
	drawframe3x3();
	for (int i = 0, j = 0; end != true;) {
		f3x3[i][j] = move_at_3x3(f3x3, &i, &j, col, pl, &end, count);
		drawfield3x3(f3x3);
		count++;
		if (checkWin(f3x3, pl) == pl) {//проверка победы игрока
			end = true;
			winer_is(highscore3, pl, count);
			break;
		}
		else if (count == 9) {//ничья
			end = true;
			no_one_wins();
			_gettch();
			break;
		}
		if (pl == 'X') {//смена игрока
			pl = '0';
			col = 47;
		}
		else {
			pl = 'X';
			col = 31;
		}
	}
}
void pickmode() {//выбор режима
	setlocale(LC_ALL, "RUSSIAN");
	string mode[] = { "Выбирите режим.", "Игрок против игрока.", "Игрок против компьютера." };
	draw_2_strings(mode);
	for (int i = 1, j = 0; j != 1;) {
		i = move2strings(mode);
		switch (i) {
		case 1:
			j = 1;
			system("CLS");
			PvPF3x3();
			break;
		case 2:
			j = 1;
			system("CLS");
			PvAiF3x3();
			break;
		default:
			break;
		}
	}
}
//___________________field10x10_____________________________________
int checkWin10(char f10x10[10][10], char pl) {//проверка на победу
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (f10x10[i][j] != ' ') {
				if ((f10x10[i][j] == f10x10[i][j + 1] && f10x10[i][j + 1] == f10x10[i][j + 2] && f10x10[i][j + 2] == f10x10[i][j + 3] && f10x10[i][j + 3] == f10x10[i][j + 4] && j <= 5 && f10x10[i][j] == pl) ||
					(f10x10[i][j] == f10x10[i][j - 1] && f10x10[i][j - 1] == f10x10[i][j - 2] && f10x10[i][j - 2] == f10x10[i][j - 3] && f10x10[i][j - 3] == f10x10[i][j - 4] && j >= 4 && f10x10[i][j] == pl) ||
					(f10x10[i][j] == f10x10[i + 1][j] && f10x10[i + 1][j] == f10x10[i + 2][j] && f10x10[i + 2][j] == f10x10[i + 3][j] && f10x10[i + 3][j] == f10x10[i + 4][j] && i <= 5 && f10x10[i][j] == pl) ||
					(f10x10[i][j] == f10x10[i - 1][j] && f10x10[i - 1][j] == f10x10[i - 2][j] && f10x10[i - 2][j] == f10x10[i - 3][j] && f10x10[i - 3][j] == f10x10[i - 4][j] && i >= 4 && f10x10[i][j] == pl) ||
					(f10x10[i][j] == f10x10[i + 1][j + 1] && f10x10[i + 1][j + 1] == f10x10[i + 2][j + 2] && f10x10[i + 2][j + 2] == f10x10[i + 3][j + 3] && f10x10[i + 3][j + 3] == f10x10[i + 4][j + 4] && i <= 5 && j <= 5 && f10x10[i][j] == pl) ||
					(f10x10[i][j] == f10x10[i - 1][j + 1] && f10x10[i - 1][j + 1] == f10x10[i - 2][j + 2] && f10x10[i - 2][j + 2] == f10x10[i - 3][j + 3] && f10x10[i - 3][j + 3] == f10x10[i - 4][j + 4] && i >= 4 && j <= 5 && f10x10[i][j] == pl) ||
					(f10x10[i][j] == f10x10[i + 1][j - 1] && f10x10[i + 1][j - 1] == f10x10[i + 2][j - 2] && f10x10[i + 2][j - 2] == f10x10[i + 3][j - 3] && f10x10[i + 3][j - 3] == f10x10[i + 4][j - 4] && i <= 5 && j >= 4 && f10x10[i][j] == pl) ||
					(f10x10[i][j] == f10x10[i - 1][j - 1] && f10x10[i - 1][j - 1] == f10x10[i - 2][j - 2] && f10x10[i - 2][j - 2] == f10x10[i - 3][j - 3] && f10x10[i - 3][j - 3] == f10x10[i - 4][j - 4] && i >= 4 && j >= 4 && f10x10[i][j] == pl)) {
					return pl;
				}
				else {
					continue;
				}
			}
		}
	}
	return 0;
}
int pickbestmove10(char f10x10[10][10], int i, int j, int count) {//подбор хода для ии
	int mi, mj;
	if (count == 1) {
		if (f10x10[i - 1][j] == ' ') {
			mi = i - 1;
			mj = j;
		}
		else if (f10x10[i][j - 1] == ' ') {
			mi = i;
			mj = j - 1;
		}
		else if (f10x10[i][j + 1] == ' ') {
			mi = i;
			mj = j + 1;
		}
		else if (f10x10[i + 1][j] == ' ') {
			mi = i + 1;
			mj = j;
		}
		else if (f10x10[i - 1][j - 1] == ' ') {
			mi = i - 1;
			mj = j - 1;
		}
		else if (f10x10[i - 1][j + 1] == ' ') {
			mi = i - 1;
			mj = j + 1;
		}
		else if (f10x10[i + 1][j - 1] == ' ') {
			mi = i + 1;
			mj = j - 1;
		}
		else if (f10x10[i + 1][j + 1] == ' ') {
			mi = i + 1;
			mj = j + 1;
		}
	}
	if (f10x10[i][j] == f10x10[i][j + 1] && f10x10[i][j + 1] == f10x10[i][j + 2] && f10x10[i][j + 2] == f10x10[i][j + 3] && (f10x10[i][j + 4] == ' ' || f10x10[i][j - 1] == ' ') && f10x10[i][j] == 'X') {
		if (f10x10[i][j + 4] == ' ' && j != 9) {
			mi = i;
			mj = j + 4;
		}
		else if (f10x10[i][j - 1] == ' ' && j != 0) {
			mi = i;
			mj = j - 1;
		}
		else {
			if (f10x10[i][j + 5] == ' ' && j != 9) {
				mi = i;
				mj = j + 5;
			}
			else if (f10x10[i][j - 2] == ' '&& j != 0) {
				mi = i;
				mj = j - 2;
			}
		}
	}
	else if (f10x10[i][j] == f10x10[i][j - 1] && f10x10[i][j - 1] == f10x10[i][j - 2] && f10x10[i][j - 2] == f10x10[i][j - 3] && (f10x10[i][j - 4] == ' ' || f10x10[i][j + 1] == ' ') && f10x10[i][j] == 'X') {
		if (f10x10[i][j - 4] == ' ' && j != 0) {
			mi = i;
			mj = j - 4;
		}
		else if (f10x10[i][j + 1] == ' ' && j != 9) {
			mi = i;
			mj = j + 1;
		}
		else {
			if (f10x10[i][j - 5] == ' ' && j != 0) {
				mi = i;
				mj = j - 5;
			}
			else if (f10x10[i][j + 2] == ' ' && j != 9) {
				mi = i;
				mj = j + 2;
			}
		}
	}
	else if (f10x10[i][j] == f10x10[i + 1][j] && f10x10[i + 1][j] == f10x10[i + 2][j] && f10x10[i + 2][j] == f10x10[i + 3][j] && (f10x10[i + 4][j] == ' ' || f10x10[i - 1][j] == ' ') && f10x10[i][j] == 'X') {
		if (f10x10[i + 4][j] == ' ') {
			mi = i + 4;
			mj = j;
		}
		else if (f10x10[i - 1][j] == ' ') {
			mi = i - 1;
			mj = j;
		}
		else {
			if (f10x10[i + 5][j] == ' ') {
				mi = i + 5;
				mj = j;
			}
			else if (f10x10[i - 2][j] == ' ') {
				mi = i - 2;
				mj = j;
			}
		}
	}
	else if (f10x10[i][j] == f10x10[i - 1][j] && f10x10[i - 1][j] == f10x10[i - 2][j] && f10x10[i - 2][j] == f10x10[i - 3][j] && (f10x10[i - 4][j] == ' ' || f10x10[i + 1][j] == ' ') && f10x10[i][j] == 'X') {
		if (f10x10[i - 4][j] == ' ') {
			mi = i - 4;
			mj = j;
		}
		else if (f10x10[i + 1][j] == ' ') {
			mi = i + 1;
			mj = j;
		}
		else {
			if (f10x10[i - 5][j] == ' ') {
				mi = i - 5;
				mj = j;
			}
			else if (f10x10[i + 2][j] == ' ') {
				mi = i + 2;
				mj = j;
			}
		}
	}
	else if (f10x10[i][j] == f10x10[i + 1][j + 1] && f10x10[i + 1][j + 1] == f10x10[i + 2][j + 2] && f10x10[i + 2][j + 2] == f10x10[i + 3][j + 3] && (f10x10[i + 4][j + 4] == ' ' || f10x10[i - 1][j - 1] == ' ') && f10x10[i][j] == 'X') {
		if (f10x10[i + 4][j + 4] == ' ' && j != 9) {
			mi = i + 4;
			mj = j + 4;
		}
		else if (f10x10[i - 1][j - 1] == ' ' && j != 0) {
			mi = i - 1;
			mj = j - 1;
		}
		else {
			if (f10x10[i + 5][j + 5] == ' ' && j != 9) {
				mi = i + 5;
				mj = j + 5;
			}
			else if (f10x10[i - 2][j - 2] == ' ' && j != 0) {
				mi = i - 2;
				mj = j - 2;
			}
		}
	}
	else if (f10x10[i][j] == f10x10[i - 1][j - 1] && f10x10[i - 1][j - 1] == f10x10[i - 2][j - 2] && f10x10[i - 2][j - 2] == f10x10[i - 3][j - 3] && (f10x10[i - 4][j - 4] == ' ' || f10x10[i + 1][j + 1] == ' ') && f10x10[i][j] == 'X') {
		if (f10x10[i - 4][j - 4] == ' ' && j != 0) {
			mi = i - 4;
			mj = j - 4;
		}
		else if (f10x10[i + 1][j + 1] == ' ' && j != 9) {
			mi = i + 1;
			mj = j + 1;
		}
		else {
			if (f10x10[i - 5][j - 5] == ' ' && j != 0) {
				mi = i - 5;
				mj = j - 5;
			}
			else if (f10x10[i + 2][j + 2] == ' ' && j != 9) {
				mi = i + 2;
				mj = j + 2;
			}
		}
	}
	else if (f10x10[i][j] == f10x10[i - 1][j + 1] && f10x10[i - 1][j + 1] == f10x10[i - 2][j + 2] && f10x10[i - 2][j + 2] == f10x10[i - 3][j + 3] && (f10x10[i - 4][j + 4] == ' ' || f10x10[i + 1][j - 1] == ' ') && f10x10[i][j] == 'X') {
		if (f10x10[i - 4][j + 4] == ' ' && j != 9) {
			mi = i - 4;
			mj = j + 4;
		}
		else if (f10x10[i + 1][j - 1] == ' ' && j != 0) {
			mi = i + 1;
			mj = j - 1;
		}
		else {
			if (f10x10[i - 5][j + 5] == ' ' && j != 9) {
				mi = i - 5;
				mj = j + 5;
			}
			else if (f10x10[i + 2][j - 2] == ' ' && j != 0) {
				mi = i + 2;
				mj = j - 2;
			}
		}
	}
	else if (f10x10[i][j] == f10x10[i + 1][j - 1] && f10x10[i + 1][j - 1] == f10x10[i + 2][j - 2] && f10x10[i + 2][j - 2] == f10x10[i + 3][j - 3] && (f10x10[i + 4][j - 4] == ' ' || f10x10[i - 1][j + 1] == ' ') && f10x10[i][j] == 'X') {
		if (f10x10[i + 4][j - 4] == ' ' && j != 0) {
			mi = i + 4;
			mj = j - 4;
		}
		else if (f10x10[i - 1][j + 1] == ' ' && j != 9) {
			mi = i - 1;
			mj = j + 1;
		}
		else {
			if (f10x10[i + 5][j - 5] == ' ' && j != 0) {
				mi = i + 5;
				mj = j - 5;
			}
			else if (f10x10[i - 2][j + 2] == ' ' && j != 9) {
				mi = i - 2;
				mj = j + 2;
			}
		}
	}
	else if (f10x10[i][j] == f10x10[i][j - 1] && f10x10[i][j - 1] == f10x10[i][j - 2] && (f10x10[i][j - 3] == ' ' || f10x10[i][j + 1] == ' ') && f10x10[i][j] == 'X') {
		if (f10x10[i][j - 3] == ' ' && j != 0) {
			mi = i;
			mj = j - 3;
		}
		else if (f10x10[i][j + 1] == ' ' && j != 9) {
			mi = i;
			mj = j + 1;
		}
		else {
			if (f10x10[i][j - 4] == ' ' && j != 0) {
				mi = i;
				mj = j - 4;
			}
			else if (f10x10[i][j + 2] == ' ' && j != 9) {
				mi = i;
				mj = j + 2;
			}
		}
	}
	else if (f10x10[i][j] == f10x10[i][j + 1] && f10x10[i][j + 1] == f10x10[i][j + 2] && (f10x10[i][j + 3] == ' ' || f10x10[i][j - 1] == ' ') && f10x10[i][j] == 'X') {
		if (f10x10[i][j + 3] == ' ' && j != 9) {
			mi = i;
			mj = j + 3;
		}
		else if (f10x10[i][j - 1] == ' ' && j != 0) {
			mi = i;
			mj = j - 1;
		}
		else {
			if (f10x10[i][j + 4] == ' ' && j != 9) {
				mi = i;
				mj = j + 4;
			}
			else if (f10x10[i][j - 2] == ' ' && j != 0) {
				mi = i;
				mj = j - 2;
			}
		}
	}
	else if (f10x10[i][j] == f10x10[i + 1][j] && f10x10[i + 1][j] == f10x10[i + 2][j] && (f10x10[i + 3][j] == ' ' || f10x10[i - 1][j] == ' ') && f10x10[i][j] == 'X') {
		if (f10x10[i + 3][j] == ' ') {
			mi = i + 3;
			mj = j;
		}
		else if (f10x10[i - 1][j] == ' ') {
			mi = i - 1;
			mj = j;
		}
		else {
			if (f10x10[i + 4][j] == ' ') {
				mi = i + 4;
				mj = j;
			}
			else if (f10x10[i - 2][j] == ' ') {
				mi = i - 2;
				mj = j;
			}
		}
	}
	else if (f10x10[i][j] == f10x10[i - 1][j] && f10x10[i - 1][j] == f10x10[i - 2][j] && (f10x10[i - 3][j] == ' ' || f10x10[i + 1][j] == ' ') && f10x10[i][j] == 'X') {
		if (f10x10[i - 3][j] == ' ') {
			mi = i - 3;
			mj = j;
		}
		else if (f10x10[i + 1][j] == ' ') {
			mi = i + 1;
			mj = j;
		}
		else {
			if (f10x10[i - 4][j] == ' ') {
				mi = i - 4;
				mj = j;
			}
			else if (f10x10[i + 2][j] == ' ') {
				mi = i + 2;
				mj = j;
			}
		}
	}
	else if (f10x10[i][j] == f10x10[i + 1][j + 1] && f10x10[i + 1][j + 1] == f10x10[i + 2][j + 2] && (f10x10[i + 3][j + 3] == ' ' || f10x10[i - 1][j - 1] == ' ') && f10x10[i][j] == 'X') {
		if (f10x10[i + 3][j + 3] == ' ' && j != 9) {
			mi = i + 3;
			mj = j + 3;
		}
		else if (f10x10[i - 1][j - 1] == ' ' && j != 0) {
			mi = i - 1;
			mj = j - 1;
		}
		else {
			if (f10x10[i + 4][j + 4] == ' ' && j != 9) {
				mi = i + 4;
				mj = j + 4;
			}
			else if (f10x10[i - 2][j - 2] == ' ' && j != 0) {
				mi = i - 2;
				mj = j - 2;
			}
		}
	}
	else if (f10x10[i][j] == f10x10[i - 1][j - 1] && f10x10[i - 1][j - 1] == f10x10[i - 2][j - 2] && (f10x10[i - 3][j - 3] == ' ' || f10x10[i + 1][j + 1] == ' ') && f10x10[i][j] == 'X') {
		if (f10x10[i - 3][j - 3] == ' ' && j != 0) {
			mi = i - 3;
			mj = j - 3;
		}
		else if (f10x10[i + 1][j + 1] == ' ' && j != 9) {
			mi = i + 1;
			mj = j + 1;
		}
		else {
			if (f10x10[i - 4][j - 4] == ' ' && j != 0) {
				mi = i - 4;
				mj = j - 4;
			}
			else if (f10x10[i + 2][j + 2] == ' ' && j != 9) {
				mi = i + 2;
				mj = j + 2;
			}
		}
	}
	else if (f10x10[i][j] == f10x10[i - 1][j + 1] && f10x10[i - 1][j + 1] == f10x10[i - 2][j + 2] && (f10x10[i - 3][j + 3] == ' ' || f10x10[i + 1][j - 1] == ' ') && f10x10[i][j] == 'X') {
		if (f10x10[i - 3][j + 3] == ' ' && j != 9) {
			mi = i - 3;
			mj = j + 3;
		}
		else if (f10x10[i + 1][j - 1] == ' ' && j != 0) {
			mi = i + 1;
			mj = j - 1;
		}
		else {
			if (f10x10[i - 4][j + 4] == ' ' && j != 9) {
				mi = i - 4;
				mj = j + 4;
			}
			else if (f10x10[i + 2][j - 2] == ' ' && j != 0) {
				mi = i + 2;
				mj = j - 2;
			}
		}
	}
	else if (f10x10[i][j] == f10x10[i + 1][j - 1] && f10x10[i + 1][j - 1] == f10x10[i + 2][j - 2] && (f10x10[i + 3][j - 3] == ' ' || f10x10[i - 1][j + 1] == ' ') && f10x10[i][j] == 'X') {
		if (f10x10[i + 3][j - 3] == ' ' && j != 0) {
			mi = i + 3;
			mj = j - 3;
		}
		else if (f10x10[i - 1][j + 1] == ' ' && j != 9) {
			mi = i - 1;
			mj = j + 1;
		}
		else {
			if (f10x10[i + 4][j - 4] == ' ' && j != 0) {
				mi = i + 4;
				mj = j - 4;
			}
			else if (f10x10[i - 2][j + 2] == ' ' && j != 9) {
				mi = i - 2;
				mj = j + 2;
			}
		}
	}
	else if (f10x10[i][j] == f10x10[i][j - 1] && (f10x10[i][j - 2] == ' ' || f10x10[i][j + 1] == ' ') && f10x10[i][j] == 'X') {
		if (f10x10[i][j - 2] == ' ' && j != 0) {
			mi = i;
			mj = j - 2;
		}
		else if (f10x10[i][j + 1] == ' ' && j != 9) {
			mi = i;
			mj = j + 1;
		}
	}
	else if (f10x10[i][j] == f10x10[i][j + 1] && (f10x10[i][j + 2] == ' ' || f10x10[i][j - 1] == ' ') && f10x10[i][j] == 'X') {
		if (f10x10[i][j - 1] == ' ' && j != 0) {
			mi = i;
			mj = j - 1;
		}
		else if (f10x10[i][j + 2] == ' ' && j != 9) {
			mi = i;
			mj = j + 2;
		}
	}
	else if (f10x10[i][j] == f10x10[i + 1][j + 1] && (f10x10[i + 2][j + 2] == ' ' || f10x10[i - 1][j - 1] == ' ') && f10x10[i][j] == 'X') {
		if (f10x10[i + 2][j + 2] == ' ' && j != 9) {
			mi = i + 2;
			mj = j + 2;
		}
		else if (f10x10[i - 1][j - 1] == ' ' && j != 0) {
			mi = i - 1;
			mj = j - 1;
		}
	}
	else if (f10x10[i][j] == f10x10[i - 1][j - 1] && (f10x10[i - 2][j - 2] == ' ' || f10x10[i + 1][j + 1] == ' ') && f10x10[i][j] == 'X') {
		if (f10x10[i + 1][j + 1] == ' ' && j != 9) {
			mi = i + 1;
			mj = j + 1;
		}
		else if (f10x10[i - 2][j - 2] == ' ' && j != 0) {
			mi = i - 2;
			mj = j - 2;
		}
	}
	else if (f10x10[i][j] == f10x10[i - 1][j + 1] && (f10x10[i - 2][j + 2] == ' ' || f10x10[i + 1][j - 1] == ' ') && f10x10[i][j] == 'X') {
		if (f10x10[i - 2][j + 2] == ' ' && j != 9) {
			mi = i - 2;
			mj = j + 2;
		}
		else if (f10x10[i + 1][j - 1] == ' ' && j != 0) {
			mi = i + 1;
			mj = j - 1;
		}
	}
	else if (f10x10[i][j] == f10x10[i + 1][j - 1] && (f10x10[i + 2][j - 2] == ' ' || f10x10[i - 1][j + 1] == ' ') && f10x10[i][j] == 'X') {
		if (f10x10[i + 2][j - 2] == ' ' && j != 0) {
			mi = i + 2;
			mj = j - 2;
		}
		else if (f10x10[i - 1][j + 1] == ' ' && j != 9) {
			mi = i - 1;
			mj = j + 1;
		}
	}
	else if (f10x10[i - 1][j] == ' ') {
		mi = i - 1;
		mj = j;
	}
	else if (f10x10[i][j - 1] == ' ') {
		mi = i;
		mj = j - 1;
	}
	else if (f10x10[i][j + 1] == ' ') {
		mi = i;
		mj = j + 1;
	}
	else if (f10x10[i + 1][j] == ' ') {
		mi = i + 1;
		mj = j;
	}
	else {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (f10x10[i][j] == ' ') {
					mi = i;
					mj = j;
				}
			}
		}
	}
	return (10 * mi + mj);
}
void drawfield10x10(char f10x10[10][10]) {//прорисовка поля
	coord1.X = 31;
	coord1.Y = 7;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (f10x10[i][j] == 'X') {
				SetConsoleCursorPosition(handle, coord1);
				SetConsoleTextAttribute(handle, 9);
				cout << f10x10[i][j];
				coord1.X += 4;
			}
			else if (f10x10[i][j] == '0') {
				SetConsoleCursorPosition(handle, coord1);
				SetConsoleTextAttribute(handle, 12);
				cout << f10x10[i][j];
				coord1.X += 4;
			}
			else {
				SetConsoleCursorPosition(handle, coord1);
				SetConsoleTextAttribute(handle, 15);
				cout << f10x10[i][j];
				coord1.X += 4;
			}
		}
		coord1.X = 31;
		coord1.Y += 2;
	}
}
void drawframe10x10() {
	coord1.X = 30;
	coord1.Y = 7;
	char frame10x10[19][39] = { ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ',
		'-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-',
		' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ',
		'-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-',
		' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ',
		'-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-',
		' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ',
		'-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-',
		' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ',
		'-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-',
		' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ',
		'-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-',
		' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ',
		'-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-',
		' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ',
		'-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-',
		' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ',
		'-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-',
		' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ' };
	for (int i = 0; i < 19; i++) {//прорисока рамки
		for (int j = 0; j < 39; j++) {
			SetConsoleCursorPosition(handle, coord1);
			SetConsoleTextAttribute(handle, 15);
			cout << frame10x10[i][j];
			coord1.X++;
		}
		coord1.X = 30;
		coord1.Y++;
	}
}
char move_at_10x10(char f10x10[10][10], int *i, int *j, int col, char pl, bool *end, int count) {
	int e = 0;
	if (count == 0) {
		coord.X = 31;
		coord.Y = 7;
	}
	for (*i, *j; *end != true;) {
		SetConsoleCursorPosition(handle, coord);
		SetConsoleTextAttribute(handle, col);
		cout << f10x10[*i][*j];
		e = _gettch();
		if (e == 224) {//нажатие стрелочек
			e = _gettch();
			switch (e) {
			case 80: //вниз
				if (coord.Y != 25) {
					drawfield10x10(f10x10);
					coord.Y += 2;
					*i+=1;
					SetConsoleCursorPosition(handle, coord);
					SetConsoleTextAttribute(handle, col);
					cout << f10x10[*i][*j];
				}
				break;
			case 72: //вверх
				if (coord.Y != 7) {
					drawfield10x10(f10x10);
					coord.Y -= 2;
					*i-=1;
					SetConsoleCursorPosition(handle, coord);
					SetConsoleTextAttribute(handle, col);
					cout << f10x10[*i][*j];
				}
				break;
			case 77: //вправо
				if (coord.X != 67) {
					drawfield10x10(f10x10);
					coord.X += 4;
					*j+=1;
					SetConsoleCursorPosition(handle, coord);
					SetConsoleTextAttribute(handle, col);
					cout << f10x10[*i][*j];
				}
				break;
			case 75: //влево
				if (coord.X != 31) {
					drawfield10x10(f10x10);
					coord.X -= 4;
					*j-=1;
					SetConsoleCursorPosition(handle, coord);
					SetConsoleTextAttribute(handle, col);
					cout << f10x10[*i][*j];
				}
				break;
			default:
				break;
			}
		}
		else if (e == 32) {//нажатие пробела
			if (f10x10[*i][*j] == ' ') {
				f10x10[*i][*j] = pl;
				return f10x10[*i][*j];
			}
		}
		else if (e == 27) {//выход клавишей esc
			*end = true;
		}
	}
}
void PvPF10x10() {//игра 10х10 игрок против игрока
	setlocale(LC_ALL, "RUSSIAN");
	char f10x10[10][10]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	char pl = 'X';
	int e = 0;
	int col = 31;
	int count = 0;
	bool end = false;
	drawframe10x10();
	for (int i = 0, j = 0; end != true;) {
		f10x10[i][j] = move_at_10x10(f10x10, &i, &j, col, pl, &end, count);
		drawfield10x10(f10x10);
		count++;
		if (checkWin10(f10x10, pl) == pl) {//проверка победы
			end = true;
			winer_is(highscore10, pl, count);
			break;
		}
		else if (count == 84) {//ничья
			end = true;
			no_one_wins();
			_gettch();
			break;
		}
		if (pl == 'X') {//смена игрока
			pl = '0';
			col = 47;
		}
		else {
			pl = 'X';
			col = 31;
		}
	}
}
void PvAiF10x10() {
	setlocale(LC_ALL, "RUSSIAN");
	char f10x10[10][10]{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	char pl = 'X';
	char pc = '0';
	int e = 0;
	int col = 31;
	int count = 0;
	bool end = false;
	drawframe10x10();
	coord.X = 31;
	coord.Y = 7;
	for (int i = 0, j = 0; end != true;) {
		f10x10[i][j] = move_at_10x10(f10x10, &i, &j, col, pl, &end, count);
		drawfield10x10(f10x10);
		count++;
		if (checkWin10(f10x10, pl) == pl) {//проверка на победу игрока
			end = true;
			winer_is(highscore10, pl, count);
			break;
		}
		else if (count == 84) {//ничья
			end = true;
			no_one_wins();
			_gettch();
			break;
		}
		int w = pickbestmove10(f10x10, i, j, count);//подбор хода для ии
		int r = w / 10;
		int c = w % 10;
		f10x10[r][c] = pc;
		drawfield10x10(f10x10);
		count++;
		if (checkWin10(f10x10, pc) == pc) {//проверка победы ии
			end = true;
			winer_is_pc(pc);
			_gettch();
			break;
		}
		else if (count == 88) {//ничья
			end = true;
			no_one_wins();
			_gettch();
			break;
		}
	}
}
void pickmode10() {//выбор режима
	setlocale(LC_ALL, "RUSSIAN");
	string mode10[] = { "Выбирите режим.", "Игрок против игрока.", "Игрок против компьютера." };
	draw_2_strings(mode10);
	for (int i = 1, j = 0; j != 1;) {
		i = move2strings(mode10);
		switch (i) {
		case 1:
			j = 1;
			system("CLS");
			PvPF10x10();
			break;
		case 2:
			j = 1;
			system("CLS");
			PvAiF10x10();
			break;
		default:
			break;
		}
	}
}
//___________________menu____________________________________________
void pickscmode() {
	setlocale(LC_ALL, "RUSSIAN");
	string mode10[] = { "Выбирите таблицу.", "3х3.", "10х10." };
	draw_2_strings(mode10);
	for (int i = 0, j = 0; j != 1;) {
		i = move2strings(mode10);
		switch (i) {
		case 1:
			j = 1;
			system("CLS");
			printscores(highscore3);
			break;
		case 2:
			j = 1;
			system("CLS");
			printscores(highscore10);
			break;
		default:
			break;
		}
	}
}
void rules() {//правила
	setlocale(LC_ALL, "RUSSIAN");
	coord1.X = 25;
	coord1.Y = 5;
	SetConsoleCursorPosition(handle, coord1);
	SetConsoleTextAttribute(handle, 11);
	cout << "Чтобы ходить по полю используйте стрелочки.";
	coord1.Y++;
	SetConsoleCursorPosition(handle, coord1);
	cout << "Чтобы поставить метку нажмите пробел.";
	coord1.Y++;
	SetConsoleCursorPosition(handle, coord1);
	cout << "Нажмите 'esc' чтобы выйти.";
	coord1.Y++;
	SetConsoleCursorPosition(handle, coord1);
	cout << "Для победы в режиме 3х3 нужно поставить 3 'X' или '0' подряд.";
	coord1.Y++;
	SetConsoleCursorPosition(handle, coord1);
	cout << "Для победы в режиме 10х10 нужно поставить 5 'X' или '0' подряд.";
	_gettch();
}
void drmenu() {//прорисовка меню
	setlocale(LC_ALL, "RUSSIAN");
	coord1.X = 50;
	coord1.Y = 10;
	string name = { "Крестики-Нолики" };
	string menu[] = { "Поле 3 x 3","Поле 10 x 10","Правила","Результаты","О программе","Выход" };
	for (int i = 0; i < 1; i++) {
		SetConsoleCursorPosition(handle, coord1);
		SetConsoleTextAttribute(handle, 10);
		cout << name;
		coord1.Y++;
		for (int j = 0; j < 6; j++) {
			SetConsoleCursorPosition(handle, coord1);
			SetConsoleTextAttribute(handle, 11);
			cout << menu[j];
			coord1.Y++;
		}
	}
}
void about() {
	setlocale(LC_ALL, "RUSSIAN");
	coord1.X = 25;
	coord1.Y = 5;
	SetConsoleCursorPosition(handle, coord1);
	SetConsoleTextAttribute(handle, 11);
	cout << "Програму создал студент IT академии 'ШАГ'.";
	coord1.Y++;
	SetConsoleCursorPosition(handle, coord1);
	cout << "Рыбак Александр.";
	_gettch();
}
void menu() {//главное меню
	setlocale(LC_ALL, "RUSSIAN");
	HANDLE handle1 = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord3;
	string menu[] = { "Поле 3 x 3","Поле 10 x 10","Правила","Результаты","О программе","Выход" };
	int e = 0;
	bool end = false;
	drmenu();
	coord3.X = 50;
	coord3.Y = 11;
	for (int i = 0; end != true;) {
		SetConsoleCursorPosition(handle1, coord3);
		SetConsoleTextAttribute(handle1, 15);
		cout << menu[i];
		e = _gettch();
		if (e == 224) {
			e = _gettch();
			switch (e) {
			case 80:
				if (i != 5) {
					SetConsoleCursorPosition(handle1, coord3);
					SetConsoleTextAttribute(handle1, 11);
					cout << menu[i];
					i++;
					coord3.Y++;
					SetConsoleCursorPosition(handle1, coord3);
					SetConsoleTextAttribute(handle1, 15);
					cout << menu[i];
				}
				break;
			case 72:
				if (i != 0) {
					SetConsoleCursorPosition(handle1, coord3);
					SetConsoleTextAttribute(handle1, 11);
					cout << menu[i];
					i--;
					coord3.Y--;
					SetConsoleCursorPosition(handle1, coord3);
					SetConsoleTextAttribute(handle1, 15);
					cout << menu[i];
				}
				break;
			default:
				break;
			}
		}
		else if (e == 13) {
			switch (i) {
			case 0:
				system("CLS");
				pickmode();
				system("CLS");
				drmenu();
				break;
			case 1:
				system("CLS");
				pickmode10();
				system("CLS");
				drmenu();
				break;
			case 2:
				system("CLS");
				rules();
				system("CLS");
				drmenu();
				break;
			case 3:
				system("CLS");
				pickscmode();
				system("CLS");
				drmenu();
				break;
			case 4:
				system("CLS");
				about();
				system("CLS");
				drmenu();
				break;
			case 5:
				system("CLS");
				end = true;
				break;
			default:
				break;
			}
		}
	}
}

int main()
{
	read_from_scores(highscore10,highscore3);
	menu();
	setlocale(LC_ALL, "RUSSIAN");
	string exit[] = { "Вы хотите выйти?", "Да", "Нет" };
	draw_2_strings(exit);
	for (int i = 0, j = 0; j != 1;) {
		i = move2strings(exit);
		switch (i) {
		case 1:
			j = 1;
			break;
		case 2:
			system("CLS");
			menu();
			draw_2_strings(exit);
			break;
		default:
			break;
		}
	}
	write_to_scores(highscore10,highscore3);
	return 0;
}