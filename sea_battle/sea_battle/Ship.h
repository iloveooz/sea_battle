// Ship.h
#ifndef SHIP_H
#define SHIP_H
#include <set>
#include <map>
#include <string>

#define N 10 // ������ ���� ��� ���������� ����� (N * N ������)

struct Cell;

typedef std::set<Cell> CellSet; // ��������� ������

// ������ (������) �� ������� ����
struct Cell {
	Cell(int _r = 0, int _� = 0) : row(_r), col(_�) {}
	bool InSet(const CellSet &) const; // ���������� �������������� ������ ��������� ���� CellSet
	
	bool operator < (const Cell &) const;

	int row; // ���
	int col; // �������
};

// ������������� ������� (���������� �������� � �� "��������")
struct Rect {
	Rect() {}
	Rect(Cell _lt, Cell _rb) : lt(_lt), rb(_rb) { FillCset(); }

	void FillCset(); // ��������� cset �������� ������ �������
	bool Intersect(const CellSet& cs) const; // ���������� ������� ��������� ����������� �������������� � ���������� cs
	Cell lt; // left-top-������
	Cell rb; // rlght-bottom-������
	CellSet cset; // ��������� ������, ������������� ��������������
};

// ����� Ship (��� ������������� �������)

class Ship {
	friend class UserNavy;
	friend class RobotNavy;
public:
	Ship() : nDeck(0), nLiveDeck(0) {}
	Ship(int, std::string, Rect);
protected:
	Rect place; // ���������� ����������
	std::string name; // ��� �������
	int nDeck; // ���������� �����
	int nLiveDeck; // ���������� �������������� �����
};
#endif /* SHIP_H */