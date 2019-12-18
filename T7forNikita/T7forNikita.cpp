#include <iostream>
#include <sstream>
#include <string>
#include <Windows.h>

std::string Input();
bool IsSizeSame(std::string& str1, std::string& str2);
bool IsPosible(std::string& str1, std::string& str2);
void PrintAnswer(bool answer);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string str1 = Input();
	std::string str2 = Input();
	bool answer = IsSizeSame(str1, str2);
	PrintAnswer(answer);
	system("PAUSE");
	return 0;
}

std::string Input() {
	std::string str;
	std::cout << "Введите строку: ";
	std::getline(std::cin, str);
	return str;
}

bool IsSizeSame(std::string& str1, std::string& str2) {
	int size1 = str1.size();
	int size2 = str2.size();
	if ( size1 == size2 ) {
		return 1;
	} else {
		return 0;
	}
}

bool IsPosible(std::string& str1, std::string& str2) {
	if ( IsSizeSame ) {
		int size = str1.size();
		//int counter = 0;
		for ( int i = 0; i < size; i++ ) {
			for ( int j = 0; j < size; j++ )
				if ( str1[i] == str2[j] ) {
					str2.erase(j, 1);
					//counter++;
				} else {
					return 0;
				}
		}
		return 1;
	} else {
		return 0;
	}
}

void PrintAnswer(bool answer) {
	if ( answer ) {
		std::cout << "Да, можно приобразовать" << std::endl;
	}
	else {
		std::cout << "Нет, нельзя приобразовать" << std::endl;
	}
}