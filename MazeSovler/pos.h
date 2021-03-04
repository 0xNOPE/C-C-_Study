#pragma once

typedef struct Pos {
	int x;
	int y;
	Pos() : x(0), y(0) {}
	Pos(int x, int y) : x(x), y(y) {}
	Pos(int a[2]) : x(a[0]), y(a[1]) {}

	Pos operator+(Pos p) {
		Pos tmp = Pos(this->x + p.x, this->y + p.y);
		return tmp;
	}
	Pos operator+(int a[2]) {
		Pos tmp = Pos(this->x + a[0], this->y + a[1]);
		return tmp;
	}
	Pos operator-(Pos p) {
		Pos tmp = Pos(this->x - p.x, this->y - p.y);
		return tmp;
	}
	Pos operator-(int a[2]) {
		Pos tmp = Pos(this->x - a[0], this->y - a[1]);
		return tmp;
	}
	bool operator==(Pos p) {return this->x == p.x && this->y == p.y; }
	bool operator==(int a[2]) { return this->x == a[0] && this->y == a[1]; }
}Pos;
