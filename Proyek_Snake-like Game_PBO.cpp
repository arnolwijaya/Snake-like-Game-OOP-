#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip> 
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

void gotoxy(int column, int line) {
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

class Snake {
private:
	char body[100];
	char ch = 'x';
	int count;
	int coorX[100];
	int coorY[100];
	int dx = 0;
	int dy = 0;
public:
	Snake() {
		body[0] = 'O';
		count = 0;
		coorX[0] = 30;
		coorY[0] = 7;
	}

	void setdxdy(int _dx, int _dy) {
		dx = _dx;
		dy = _dy;
	}

	int getdx() {
		return dx;
	}

	int getdy() {
		return dy;
	}

	void printSnake() {
		for (int a = 0; a < count + 1; a++) {
			if (a > 0) {
				ch = 'x';
			}
			else {
				ch = 'O';
			}
			gotoxy(coorX[a], coorY[a]);
			body[a] = ch;
			cout << body[a];
		}
	}

	void update() {
		for (int i = count; i > 0; i--) {
			coorX[i] = coorX[i - 1];
			coorY[i] = coorY[i - 1];
		}
	}

	void updateSnakeTambah() {
		count++;
		body[count] = 'x';
	}

	void updateSnakeKurang() {
		count--;
		body[count] = ' ';
	}

	void updateSnakeDobel() {
		count = count * 2;
		body[count] = 'x';
	}

	int getcoorX(int i) {
		return coorX[i];
	}

	int getcoorY(int i) {
		return coorY[i];
	}

	void setcoorX(int coor) {
		coorX[0] = coor;
	}

	void setcoorY(int coor) {
		coorY[0] = coor;
	}

	int getCount() {
		return count;
	}
};

class Makanan {
protected:
	int x;
	int y;
	int score;
	int type;
	int dobel;
public:
	virtual int getDobel() {
		return dobel;
	}

	virtual int getType() {
		return type;
	}

	virtual void setCoor(int _x, int _y) {
		x = _x;
		y = _y;
	}

	virtual void print() {

	}

	virtual int getscore() {
		return score;
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}
};

class MakananBiasa : public Makanan {
public:
	int getDobel() {
		dobel = 0;
		return dobel;
	}

	int getType() {
		type = 1;
		return type;
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	void setCoor(int _x, int _y) {
		x = _x;
		y = _y;
	}

	void print() {
		gotoxy(x, y);
		cout << "@";
	}
	int getscore() {
		score = 10;
		return score;
	}
};

class MakananCepat : public Makanan {
public:
	int getDobel() {
		dobel = 0;
		return dobel;
	}

	int getType() {
		type = 2;
		return type;
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	void setCoor(int _x, int _y) {
		x = _x;
		y = _y;
	}

	int getscore() {
		score = 10;
		return score;
	}

	void print() {
		gotoxy(x, y);
		cout << "&";
	}
};

class MakananPengurangPanjang : public Makanan {
public:
	int getDobel() {
		dobel = 0;
		return dobel;
	}

	int getType() {
		type = 0;
		return type;
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	void setCoor(int _x, int _y) {
		x = _x;
		y = _y;
	}

	int getscore() {
		score = -10;
		return score;
	}

	void print() {
		gotoxy(x, y);
		cout << "%";
	}
};

class MakananScoreBesar : public Makanan {
public:
	int getDobel() {
		dobel = 0;
		return dobel;
	}

	int getType() {
		type = 1;
		return type;
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	void setCoor(int _x, int _y) {
		x = _x;
		y = _y;
	}

	int getscore() {
		score = 50;
		return score;
	}

	void print() {
		gotoxy(x, y);
		cout << "$";
	}
};

class MakananPanjangDobel : public Makanan {
public:
	int getDobel() {
		dobel = 1;
		return dobel;
	}

	int getType() {
		type = 1;
		return type;
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	void setCoor(int _x, int _y) {
		x = _x;
		y = _y;
	}

	int getscore() {
		score = 10;
		return score;
	}

	void print() {
		gotoxy(x, y);
		cout << "?";
	}
};

class GameSnake {
private:
	Snake ular;
	bool hidup;
	int areaX = 60;
	int areaY = 15;
public:
	GameSnake() {
		hidup = true;
	}

	void printUlar() {
		ular.printSnake();
	}

	void printArea() {
		for (int i = 0; i < areaY; i++) {
			for (int j = 0; j < areaX; j++) {
				if (i == 0 || i == areaY - 1 || j == 0 || j == areaX - 1) {
					cout << "#";
				}
				else {
					cout << " ";
				}
			}
			cout << endl;
		}
	}

	int getHidup() {
		return hidup;
	}

	void setcoorUlar(int x, int y) {
		ular.update();
		ular.setcoorX(ular.getcoorX(0) + x);
		ular.setcoorY(ular.getcoorY(0) + y);
	}

	int getX() {
		return ular.getcoorX(0);
	}

	int getY() {
		return ular.getcoorY(0);
	}

	int getXb(int a) {
		return ular.getcoorX(a);
	}

	int getYb(int a) {
		return ular.getcoorY(a);
	}

	void updateUlarTambah() {
		ular.updateSnakeTambah();
	}

	void updateUlarKurang() {
		ular.updateSnakeKurang();
	}

	void updateUlarDobel() {
		ular.updateSnakeDobel();
	}

	void setdxdy(int _dx, int _dy) {
		ular.setdxdy(_dx, _dy);
	}

	int getdx() {
		return ular.getdx();
	}

	int getdy() {
		return ular.getdy();
	}
};

void main() {
	srand(time(NULL));
	int a, i, count = 0, mode = 0;
	int mati = 0;
	int score = 0;
	Makanan* food[5];
	GameSnake game;

	for (i = 0; i < 5; i++) {
		a = rand() % 5;
		if (a == 0) {
			food[i] = new MakananBiasa;
		}
		else if (a == 1) {
			food[i] = new MakananCepat;
		}
		else if (a == 2) {
			food[i] = new MakananPengurangPanjang;
		}
		else if (a == 3) {
			food[i] = new MakananScoreBesar;
		}
		else if (a == 4) {
			food[i] = new MakananPanjangDobel;
		}
		food[i]->setCoor(rand() % 58 + 1, rand() % 13 + 1);
	}

	while (game.getHidup()) {
		game.printArea();

		for (i = 0; i < 5; i++) {
			if (game.getX() == food[i]->getX() && game.getY() == food[i]->getY()) {
				if (food[i]->getDobel() == 1) {
					game.updateUlarDobel();
					mode = 0;
					count = count * 2;
				}
				else if(food[i]->getDobel() == 0) {
					if (food[i]->getType() == 1) {
						game.updateUlarTambah();
						mode = 0;
						count++;
					}
					else if (food[i]->getType() == 2) {
						mode = 1;
						game.updateUlarTambah();
						count++;
					}
					else if (food[i]->getType() == 0 && count != 0) {
						mode = 0;
						game.updateUlarKurang();
						count--;
					}
				}

				score += food[i]->getscore();

				a = rand() % 5;
				if (a == 0) {
					food[i] = new MakananBiasa;
				}
				else if (a == 1) {
					food[i] = new MakananCepat;
				}
				else if (a == 2) {
					food[i] = new MakananPengurangPanjang;
				}
				else if (a == 3) {
					food[i] = new MakananScoreBesar;
				}
				else if (a == 4) {
					food[i] = new MakananPanjangDobel;
				}
				food[i]->setCoor(rand() % 58 + 1, rand() % 13 + 1);
			}
			food[i]->print();
		}

		game.setcoorUlar(game.getdx(), game.getdy());
		game.printUlar();

		if (_kbhit())                               //checkif a key is pressed
		{
			int ch = _getch();
			if (ch == 80)                           //move upward
			{
				game.setdxdy(0, 1);
			}

			if (ch == 75)                           //move left
			{
				game.setdxdy(-1, 0);
			}

			if (ch == 77)                           //move right
			{
				game.setdxdy(1, 0);
			}

			if (ch == 72)                           //move downward
			{
				game.setdxdy(0, -1);
			}
		}
		if (game.getX() <= 0 || game.getX() >= 59 || game.getY() <= 0 || game.getY() >= 14) {
			break;
		}
		for (int i = 1; i < count; i++) {
			if (game.getX() == game.getXb(i) && game.getY() == game.getYb(i)) {
				mati = 1;
				break;
			}
		}
		if (mati == 1) {
			break;
		}

		gotoxy(65, 0);
		cout << "Your Score : " << score;
		gotoxy(65, 3);
		cout << "KETERANGAN MAKANAN : " << endl;
		gotoxy(65, 4);
		cout << "@ = Makanan Biasa" << endl;
		gotoxy(65, 5);
		cout << "& = Makanan Cepat" << endl;
		gotoxy(65, 6);
		cout << "% = Makanan Pengurang Penjang dan Score" << endl;
		gotoxy(65, 7);
		cout << "$ = Makanan Score Besar +50" << endl;
		gotoxy(65, 8);
		cout << "? = Makanan Penambah Panjang x2" << endl;
		system("CLS");
		if (mode == 0) {
			Sleep(50);
		}
		else {
			Sleep(1);
		}
	}
	gotoxy(65, 0);
	cout << "You Lose Brader, You got : " << score << " Points";
	gotoxy(0, 17);
}