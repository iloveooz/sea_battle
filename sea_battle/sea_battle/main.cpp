// Main.cpp
#include <iostream>
#include "Navy.h"

int main() {
	// Начальная позиция
	UserNavy userNavy;
	RobotNavy robotNavy;

	userNavy.Show();

	while (userNavy.IsLive() && robotNavy.IsLive()) {
		// Выстрел пользователя
		if (Space::u_state != Miss) {
			std::cout << "пропускается...: <Enter>" << std::endl;
			std::cin.get();
		}
		else {
			userNavy.FireOff();
			robotNavy. GetFire();
			userNavy.ResultAnalyse();

			if (!robotNavy.IsLive()) {
				userNavy.Show();
				break;
			}
		}
		// Выстрел робота
		if (Space::r_state != Miss)
			std::cout << "\nВыстрел неприятеля: пропускается..." << std::endl;
		else {
			robotNavy.FireOff();
			userNavy.GetFire();
			robotNavy.ResultAnalyse();
			}

		userNavy.Show();
	}

	if (userNavy.IsLive())
		std::cout <<"\n:-))) Ура! Победа!!! :-)))" << std::endl;
	else {
		std::cout << "\n:-((( Увы. Непрятель оказался сильнее." << std::endl;
		std::cout << ":-((( Но ничего, в следующий раз мы ему покажем!!!" << std::endl;
	}

	std::cin.get();
	return 0;
}