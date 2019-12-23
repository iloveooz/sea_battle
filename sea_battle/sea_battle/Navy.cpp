// Navy.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Navy.h"

Cell Space::u_fire;
Cell Space::r_fire;

CurrentState Space::u_state = Miss;
CurrentState Space::r_state = Miss;

int Space::step = 1;

// Функция gap(n) возвращает строку из n пробелов
std::string gap(int n) { return std::string(n, ' ' ); }


// Класс Navy
Navy::Navy() : nLiveShip(10) {
// Заполняем игровые поля символом "точка"
for (int i = 0; 1 < N; i++)
	for (int j = 0; j < N; j++) {
		ownField[i][j] = '.';
		enemyField[i][j] = '.';
	}
}

Rect Navy::Shell(Rect r) const {
	Rect sh(r);
	sh.lt.row = (-sh.lt.row < 0) ? 0 : sh.rb.row;
	sh.lt.col = (-sh.lt.col < 0) ? 0 : sh.rb.col;
	sh.rb.row = (++sh.rb.row > (N -	1)) ? (N - 1) : sh.lt.row;
	sh.rb.col = (++sh.rb.col > (N -	1)) ? (N - 1) : sh.lt.col;
	return sh;
}

void Navy::AddToVetoSet(Rect r) {
	for (int i = r.lt.row; i <= r.rb.row; i++)
		for (int j = r.lt.col; j <= r.rb.col; j++)
			vetoSet.insert(Cell(i, j));
}

void Navy::AllocSh1p(1nt 1ndSh1p. int nDeck. string name) {
int 1. j;
Cell It. rb;
// Генерация случайно размещенной начальной клетки корабля
// с учетом недопустимости "пересечения" нового корабля
// с множеством клеток vetoSet
whiled) {
It.row = randO ^ (N + 1 - nDeck);
It.col = rb.col = randO % N;
rb.row = It.row + nDeck - 1;
i f (IRectdt. rb).Intersect(vetoSet)) break;
}
// Сохраняем данные о новом корабле
ship[indSh1p] = ShipCnDeck. name. Rectdt. rb));
// Наносим новый корабль на игровое поле (символ DECK).
// Добавляем соответствующие элементы в словарь ассоциаций
for (i = It.row; 1 <= rb.row; i++)
for (j = It.col; j <= rb.col; j++) {
ownField[i][j] = DECK;
shipMap[Cell(i.j)] = indShip;
}

// Добавляем в множество vetoSet клетки нового корабля
// вместе с пограничными клетками
AddToVetoSet(Shell (Rectdt. rb)));
void Navy::$how() const {
char rowNameClO] = {'A'. 'B'. 'C. 'D'. 'E'. 'F'. '6*. 'H'. T . 'J']
	std::string colName("l 2 3 4 5 6 7 8 9 10");
int i. j;
std::cout << " \n";
std::cout << gap(3) << "Мой флот" << gap(18) << "Флот неприятеля" << std::endl;
std::cout << gap(3) << colName << gap(6) << colName << std::endl;
for (i = 0 ; i < N; i++) {
// Own
std::string line = gapd) + rowName[i];
for (j = 0; j < N; j++)
line += gapd) + (char)ownField[i][j];
// Enemy
line += gap(5) + rowName[i];
for (j = 0; j < N; j++)

Ипе += gap(l) + (char)eneniyF1eld[i][j];
std::cout << line << std::endl;
std::cout << std::endl:
std::cout << "====
}
=\n":
std::cout << step << ". " << "Мой выстрел:
step++;
1nt Navy:: Get Into {
1nt value:
while (true) {
cin >> value:
if ('\n' == cin.peek()) { cin.getO: break: }
else {
std::cout << "Повторите ввод колонки (ожидается целое число):" << endl:
cin.clearO:
while (Cin.getO != ' \ n ' ) {}:
return value:
///////////////////////////////////////////////////////////
// Класс UserNavy
void UserNavy::Allocation() {
srand((unsigned)time(NULL)):
AllocShip(0. 4. "Авианосец 'Варяг'"):
AllocShipd, 3. "Линкор 'Муромец'")
AllocShip(2, 3. "Линкор 'Никитич'")
AllocShip(3. 2. "Крейсер 'Чудный'")
AllocShip(4, 2, "Крейсер 'Добрый'")
AllocSh1p(5, 2. "Крейсер 'Справедливый'"):
AllocShip(6. 1. "Миноносец 'Храбрый'"):
AllocSh1p(7, 1. "Миноносец 'Ушлый'"):
AllocShip(8. 1. "Миноносец 'Проворный'"):
AllocShip(9, 1. "Миноносец 'Смелый" ):
vetoSet.clearO:
void UserNavy::FillDeadZone(Rect
int
Reel
for
for
for
i.
: si
(i
if
(1
if
(J
J:
1 = Shell(r):
= sh.lt.row.
(sh.lt.row <
= sh.rb.row.
(sh.rb.row >
= sh.lt.col.
j
r
j
r
i
= sh.lt
It.row)
= sh.lt
rb.row)
= sh.lt
^ Fields fie
col: j
field[-
col: j
field[-
row: i
<= sh
][j] -
<= sh
][j] =
<= sh
Id) {
rb.col:
= '
rb
= '
rb
' .
col:
'.
row:
J-^+)
j++)
i++)
i f (sh.lt.col < r . I t . c o l ) f i e l d [ i ] [ j]

for (j = sh.rb.col. 1 = sh.lt.row: 1 <= sh.rb.row; 1++)
1f (sh.rb.col > r.rb.col) f1eld[1][j] = ' ';
void UserNavy::F1reOff() {
string capltaljetter = "ABCDEFGHIJ";
string small_letter = "abcdefghlj";
unsigned char rowName; // обозначение ряда (A. В. ... . J)
Int colName; // обозначение колонки (1. 2 10)
Int row; // индекс ряда (О, 1 9)
1nt col: // индекс колонки (0. 1 9)
bool success = false;
while (!success) {
	std::cin >> rowName;
row = cap1tal__letter.f1nd(rowName):
If (-1 == row) row = small_letter.f1nd(rowName);
If (-1 == row) { std::cout << "Ошибка. Повторите ввод.\п"; continue;
col Name = Getlnt();
col = col Name - 1;
If ((col < 0) li (col > 9)) {
std::cout << "Ошибка. Повторите ввод.Хп"; continue;
}
success = true;
}
u_f1re = Cell(row. col);
}
void UserNavy:;ResultAnalys() {
// r_state - сообщение робота о результате выстрела
// пользователя по клетке u_f1re
sw1tch(r_state) {
case Miss;
enemyF1eld[u_f1re.row][u_f1re.col] = MISS;
break;
case Damage:
enemyF1eld[u_f1re.row][u_f1re.col] = DAMAGE;
crushSet.1nsert(u_f1re);
break;
cdse Kill:
enemyF1eld[u_f1re.row][u_f1re.col] = DAMAGE;
crushSet.1nsert(u_f1 re);
Rect k i l l;
k i l l . I t = ^crushSet.begln();
k l l l . r b = ^(-crushSet.end());
// Заполняем "обрамление" пробелами
F1llDeadZone(k1ll. enemyFleld);
crushSet.clear();
}

void UserNavy::GetF1re() {
/ / выстрел робота - по клетке r_f1re
string capUalJetter = "ABCDEFGHIJ":
char rowName = cap1tal_letter[r_f1re.row];
1nt col Name = r_f1re.col + 1;
std::cout << 'ЛпВыстрел неприятеля: " << rowName << colName << endl;
i f (DECK == ownF1eld[r_f1re.row][r_fire.col]) {
std::cout << "'^^^ Есть попадание! ^*^";
ownField[r_f1re.row][r_f1re.col] = DAMAGE;
u_state = Damage:
// индекс корабля, занимающего клетку r_f1re
int ind = sh1pMap[r_f1re]:
sh1p[1nd].nL1veDeck-:
i f (!sh1p[1nd].nL1veDeck) {
u_state = K i l l:
std::cout << gap(6) << "0 ужас! Погиб " << ship[ind].name <<
nLiveShip-:
Rect k i l l = shipCind].place:
FillDeadZone(kill. ownField):
else {
u_state = Miss;
std::cout << "**^ Мимо! ***":
ownField[r 1
}
std::cout << endl:
nre.row][r_fire.col] = MISS:
1
///////////////////////////////////////////////////////////
// Класс RobotNavy
RobotNavy::RobotNavy() {
AllocationO:
isCrushContinue
upEmpty = false
}
= false;
void RobotNavy::Allocation0 {
AllocSh^
AllocSh"
AllocSh^
AllocShi
AllocShi
AllocSh!
AllocShi
AllocShi
AllocShi
p(0. 4.
p(l. 3.
p(2. 3.
p(3. 2.
p(4. 2.
p(5. 2.
p(6. 1.
p(7. 1.
p(8. 1.
AllocShip(9. 1.
vetoSet. clearO:
"Авианосец 'Алькаида'"):
"Линкор 'БенЛаден'"):
"Линкор 'Хусейн*");
"Крейсер 'Подлый•");
"Крейсер 'Коварный'");
"Крейсер 'Злой'");
"Миноносец 'Гадкий'");
"Миноносец 'Мерзкий'");
"Миноносец 'Пакостный'");
"Миноносец 'Душный'");

void RobotNavy::F1reOff() {
Cell с. cUp;
1f (!1sCrushCont1nue) {
// случайный выбор координат выстрела
wh1le(l) {
crow = randO % N;
с.col = randO % N:
1f (!c.InSet(vetoSet)) break;
}
}
else {
/ / "пляшем" от предыдущего попадания
с = clip = r_f1re:
clip, row-;
i f (dupEmpty) && crow && (!cUp. InSet(vetoSet)))
с.row-;
else {
с = ^(-crushSet.end());
с.row++;
r_f1re = c;
vetoSet.insert(r fire);
void RobotNavy:;ResultAnalys() {
// u_state - сообщение пользователя о результате
// выстрела робота по клетке r_fire
switch(u__state) {
case Miss:
if (isCrushContinue) upEmpty = true;
break;
case Damage:
isCrushContinue = true;
crushSet.insert(r_fire);
break;
case Kill:
isCrushContinue = false;
upEmpty = false;
crushSet.i nsert(r_fi re);
Rect kill;
k i l l . I t = ^crushSet.begin();
k i l l . r b = ^(-crushSet.end());
AddToVetoSet(Shell(kill));
crushSet.clear();
}
}

void RobotNavy::GetF1re() {
/ / выстрел пользователя - по клетке u_f1re
1f (DECK == ownF1eld[u_f1re.row][u_f1re.col]) {
std::cout << "*** Есть попадание! '^^^";
r_state = Damage;
// индекс корабля, занимающего клетку u_f1re
1nt 1nd = sh1pMap[u_f1re];
sh1p[1nd].nL1veDecl<-;
if (!sh1p[1nd].nL1veDeck) {
r_state = Kill;
std::cout << gap(6) << "Уничтожен " << sh1p[1nd].name << " !!!'
nLiveShIp-:
else {
r_state = Miss:
std::cout << "*^^ Мимо! ***";
}
std::cout << std::endl:
}