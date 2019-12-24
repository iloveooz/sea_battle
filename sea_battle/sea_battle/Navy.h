// Navy.h
#include "Ship.h"
#define DECK 176 // исправная клетка-палуба
#define DAMAGE 'X' // разрушенная клетка-палуба
#define MISS 'o' // пустая клетка, в которую упал снаряд

typedef unsigned char Field[N][N]; // игровое поле
typedef std::map<Cell, int> ShipMap; // словарь ассоциаций "клетка - индекс корабля"

enum CurrentState { Miss, Damage, Kill }; // результат попадания в цель

// Класс Space - информационное пространство для обмена информацией между игроками
struct Space {
public:
	static Cell u_fire; // огонь от пользователя
	static Cell r_fire; // огонь от робота (компьютера)
	static CurrentState u_state; // состояние пользователя
	static CurrentState r_state; // состояние робота
	static int step;
};

// Базовый класс Navy
class Navy : public Space {
public:
	Navy();
	void AllocShip(int, int, std::string); // разместить корабль 
	void Show() const; 	// показать поля ownField и enemyField
	int GetInt(); // ввод целого числа
	bool IsLive() { return (nLiveShip > 0); } // мы еще живы?
	Rect Shell(Rect) const; // вернуть "оболочку для заданного прямоугольника cам прямоугольник плюс пограничные клетки)
	void AddToVetoSet(Rect); // Добавить клетки прямоугольника в множество vetoSet.
protected:
	Ship ship[10]; // корабли флота
	Field ownField; // мое игровое поле
	Field enemyField; // игровое поле неприятеля
	ShipMap shipMap; // словарь ассоциаций "клетка - индекс корабля"
	CellSet vetoSet; // множество "запрещенных" клеток
	CellSet crushSet; // множество "уничтоженных" клеток
	int nLiveShip; // количество боеспособных кораблей
};

// Класс UserNavy
class UserNavy : public Navy {
public:
	UserNavy() { Allocation(); }
	void Allocation(); 
	void FireOff(); // выстрел no неприятелю
	void ResultAnalyse(); // анализ результатов выстрела
	void GetFire(); // "прием" огня противника
	void FillDeadZone(Rect r, Field &); // заполнить пробелами пограничные клетки для r
};

// Класс RobotNavy
class RobotNavy : public Navy {
public:
	RobotNavy();
	void Allocation(); 
	void FireOff(); // выстрел no неприятелю
	void ResultAnalyse(); // анализ результатов выстрела
	void GetFire(); // "прием" огня противника
private:
	bool isCrushContinue; // предыдущий выстрел был успешным
	bool upEmpty; // у поврежденного корабля противника нет "живых" клеток в верхнем направлении
};
