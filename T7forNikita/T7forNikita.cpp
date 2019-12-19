#include <iostream>
#include <sstream>
#include <string>
#include <Windows.h>

std::string Input();
bool IsSizeSame(std::string& str1, std::string& str2);
bool IsPosible(std::string& str1, std::string& str2, bool sizeAnswer);
void PrintAnswer(bool answer);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string str1 = Input();
	std::string str2 = Input();
	bool sizeAnswer = IsSizeSame(str1, str2);
	bool answer = IsPosible(str1, str2, sizeAnswer);
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
	int size1 = (int)str1.size();
	int size2 = (int)str2.size();
	if ( size1 == size2 ) {
		return 1;
	} else {
		return 0;
	}
}

bool IsPosible(std::string& str1, std::string& str2, bool sizeAnswer) {
	if (sizeAnswer) {
		short size1 = str1.size();
		short size2 = str2.size();
		short count = size1;
		for (int i = 0; i < size1; i++) {
			for (int j = 0; j < size2; j++)
				if (str1[i] == str2[j]) {
					str2.erase(j, 1);
					size2--;
					count--;
					if ( count == 0 ) {
						return 1;
					}
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
		std::cout << "Да, можно преобразовать" << std::endl;
	}
	else {
		std::cout << "Нет, нельзя преобразовать" << std::endl;
	}
}