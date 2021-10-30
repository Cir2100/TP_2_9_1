#pragma once
#include "MyArray.h"
#include "Strings.h"
#include "Logger.h"
#include <iostream>
#include <fstream>
#include <string>

template <typename T>
T processingInput(T minInput, T maxInput);
template <typename T>
void inputData(std::string help, T& data, T minValue, T maxValue);
int chouseStream();
bool processInputNameOfInputFile(std::string& filename);
bool processInputNameOfOutputFile(std::string& filename);
bool checkFilename(std::string file);
void inputData(std::string help, std::string& data);
void inputTimeDeparture(std::string help, std::string& data);

template <typename T>
T processingInput(T minInput, T maxInput) {
	while (true)
	{
		T method;
		std::cin >> method;
		if (std::cin.fail() || method < minInput || method > maxInput)
		{
			std::cin.clear();
			Logger::printWarning("�������� ����.");
			std::cout << "������� ��������: ";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			std::cin.clear();
			return method;
		}
		std::cin.ignore(32767, '\n');
	}
}

template <typename T>
void inputData(std::string help, T& data, T minValue, T maxValue) {
	std::cout << help;
	data = processingInput(minValue, maxValue);
}
