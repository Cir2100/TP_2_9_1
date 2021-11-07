#include "Train.h"
#include "UsersInput.h"
#include <iostream>
#include <fstream>
#include <typeinfo>

using namespace std;

void startInput(MyArray<Train>& trains);
void printMenu();
void addObject(MyArray<Train>& trains);
void editObject(MyArray<Train>& trains);
void deleteObject(MyArray<Train>& trains);
void print(MyArray<Train>& trains);
void searchTrain(MyArray<Train>& trains);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	MyArray<Train> trains;

	startInput(trains);

	bool isExit = false;
	while (!isExit) {
		printMenu();
		int method = processingInput(0, 6);
		switch (method)
		{
		case 1:
			addObject(trains);
			break;
		case 2:
			editObject(trains);
			break;
		case 3:
			deleteObject(trains);
			break;
		case 4:
			print(trains);
			break;
		case 5:
			trains.sort();
			Logger::printMessage("������ ������� ������������");
			break;
		case 6:
			searchTrain(trains);
			break;
		case 0:
			isExit = true;
			break;
		}
	}

}

void printMenu() {
	cout << "1. �������� �����" << endl;
	cout << "2. �������� ������" << endl;
	cout << "3. ������� ������" << endl;
	cout << "4. ������� ������" << endl;
	cout << "5. ������������� ������" << endl;
	cout << "6. ����� ������ �� �������" << endl;
	cout << "0. �����" << endl;
	cout << "�������� ����� ����: ";
}

void addObject(MyArray<Train>& trains) {
	Train train;
	train.inputFromConsole();
	trains += train;
	Logger::printMessage("������ ������� ��������");
}

void editObject(MyArray<Train>& trains) {
	if (trains.getSize() > 0) {
		print(trains);
		cout << "������� ����� ������ ��� ���������: ";
		trains[processingInput(1, trains.getSize()) - 1].edit();
		Logger::printMessage("������ ������� �������");
	}
	else
		Logger::printWarning("������ ������� ����. ������ ��������");
}

void deleteObject(MyArray<Train>& trains) {
	if (trains.getSize() > 0) {
		print(trains);
		cout << "������� ����� ������ ��� ��������: ";
		trains -= processingInput(1, trains.getSize()) - 1;
		Logger::printMessage("������ ������� ������");
	}
	else
		Logger::printWarning("������ ������� ����. ������ �������");
}

void print(MyArray<Train>& trains) {
	if (trains.getSize() == 0)
		cout << "������ ������� ����.";
	else {
		cout << "������ �������\n";
		for (int i = 0; i < trains.getSize(); i++)
			cout << i + 1 << ". �����\n" << trains[i];
	}
}

void searchTrain(MyArray<Train>& trains) {
	if (trains.getSize() == 0)
		Logger::printWarning("������ ������� ����.");
	else {
		string number;
		inputData("������� ����� ������: ", number);
		bool isPrint = false;
		for (int i = 0; i < trains.getSize(); i++)
			if (trains[i].getNumber() == number) {
				cout << trains[i];
				isPrint = true;
				break;
			}
		if (!isPrint)
			Logger::printWarning("����� � ������� " + number + " �� ������");
	}
}

void startInput(MyArray<Train>& trains) {
	cout << "������ ������ ������: " << endl;
	int method = chouseStream();
	if (method == 1) {
		string filename;
		if (processInputNameOfInputFile(filename))
			//train.inputFromFile(filename);
		{
			//todo
		}
	}
	else if (method == 2) {
		int size;
		inputData("������� ���������� �������: ", size, 0, INT32_MAX);
		for (int i = 0; i < size; i++) {
			Train train;
			train.inputFromConsole();
			trains += train;
		}
	}
}

