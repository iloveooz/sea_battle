// Navy.h
#include "Ship.h"
#define DECK 176 // ��������� ������-������
#define DAMAGE 'X' // ����������� ������-������
#define MISS 'o' // ������ ������, � ������� ���� ������

typedef unsigned char Field[N][N]; // ������� ����
typedef std::map<Cell, int> ShipMap; // ������� ���������� "������ - ������ �������"

enum CurrentState { Miss, Damage, Kill }; // ��������� ��������� � ����

// ����� Space - �������������� ������������ ��� ������ ����������� ����� ��������
struct Space {
public:
	static Cell u_fire; // ����� �� ������������
	static Cell r_fire; // ����� �� ������ (����������)
	static CurrentState u_state; // ��������� ������������
	static CurrentState r_state; // ��������� ������
	static int step;
};

// ������� ����� Navy
class Navy : public Space {
public:
	Navy();
	void AllocShip(int, int, std::string); // ���������� ������� 
	void Show() const; 	// �������� ���� ownField � enemyField
	int GetInt(); // ���� ������ �����
	bool IsLive() { return (nLiveShip > 0); } // �� ��� ����?
	Rect Shell(Rect) const; // ������� "�������� ��� ��������� �������������� c�� ������������� ���� ����������� ������)
	void AddToVetoSet(Rect); // �������� ������ �������������� � ��������� vetoSet.
protected:
	Ship ship[10]; // ������� �����
	Field ownField; // ��� ������� ����
	Field enemyField; // ������� ���� ����������
	ShipMap shipMap; // ������� ���������� "������ - ������ �������"
	CellSet vetoSet; // ��������� "�����������" ������
	CellSet crushSet; // ��������� "������������" ������
	int nLiveShip; // ���������� ������������ ��������
};

// ����� UserNavy
class UserNavy : public Navy {
public:
	UserNavy() { Allocation(); }
	void Allocation(); 
	void FireOff(); // ������� no ����������
	void ResultAnalyse(); // ������ ����������� ��������
	void GetFire(); // "�����" ���� ����������
	void FillDeadZone(Rect r, Field &); // ��������� ��������� ����������� ������ ��� r
};

// ����� RobotNavy
class RobotNavy : public Navy {
public:
	RobotNavy();
	void Allocatlon(); 
	void FireOff(); // ������� no ����������
	void ResultAnalyse(); // ������ ����������� ��������
	void GetFire(); // "�����" ���� ����������
	private:
	bool IsCrushContinue; // ���������� ������� ��� ��������
	bool upEmpty; // � ������������� ������� ���������� ��� "�����" ������ � ������� �����������
};