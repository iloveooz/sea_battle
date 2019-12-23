// Main.cpp
#include <iostream>
#include "Navy.h"

int main() {
	// ��������� �������
	UserNavy userNavy;
	RobotNavy robotNavy;

	userNavy.Show();

	while (userNavy.IsLive() && robotNavy.IsLive()) {
		// ������� ������������
		if (Space::u_state != Miss) {
			std::cout << "������������...: <Enter>" << std::endl;
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
		// ������� ������
		if (Space::r_state != Miss)
			std::cout << "\n������� ����������: ������������..." << std::endl;
		else {
			robotNavy.FireOff();
			userNavy.GetFire();
			robotNavy.ResultAnalyse();
			}

		userNavy.Show();
	}

	if (userNavy.IsLive())
		std::cout <<"\n:-))) ���! ������!!! :-)))" << std::endl;
	else {
		std::cout << "\n:-((( ���. ��������� �������� �������." << std::endl;
		std::cout << ":-((( �� ������, � ��������� ��� �� ��� �������!!!" << std::endl;
	}

	std::cin.get();
	return 0;
}