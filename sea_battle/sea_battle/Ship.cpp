// Ship.cpp
#include <string>
#include <algorithm>
#include "Ship.h"
#include <iterator>

bool Cell::InSet(const CellSet& cs) const {
	return (cs.count(Cell(row, col)) > 0);
}

bool Cell::operator < (const Cell& c) const {
	return ((row < c.row) || ((row == c.row) && (col < c.col)));
}

void Rect::FillCset() {
	for (int i = lt.row; i <= rb.row; i++)
		for (int j = lt.col; j <= rb.col; j++)
			cset.insert(Cell(i, j));
}

bool Rect::Intersect(const CellSet& cs) const {
	CellSet common_cell;
	set_intersection(cset.begin(), cset.end(), cs.begin(), cs.end(), inserter(common_cell, common_cell.begin()));
	return (common_cell.size() > 0);
}

Ship::Ship(int _nDeck, std::string _name, Rect _place) : place(_place), name(_name), nDeck(_nDeck), nLiveDeck(_nDeck) {}
