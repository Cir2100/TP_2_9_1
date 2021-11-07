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
			Logger::printMessage("Массив поездов отсортирован");
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
	cout << "1. Добавить оъект" << endl;
	cout << "2. Изменить объект" << endl;
	cout << "3. Удалить объект" << endl;
	cout << "4. Вывести данные" << endl;
	cout << "5. Отсортировать поезда" << endl;
	cout << "6. Поиск поезда по номмеру" << endl;
	cout << "0. Выход" << endl;
	cout << "Выберете пункт меню: ";
}

void addObject(MyArray<Train>& trains) {
	Train train;
	train.inputFromConsole();
	trains += train;
	Logger::printMessage("Объект успешно добавлен");
}

void editObject(MyArray<Train>& trains) {
	if (trains.getSize() > 0) {
		print(trains);
		cout << "Введите номер поезда для изменения: ";
		trains[processingInput(1, trains.getSize()) - 1].edit();
		Logger::printMessage("Объект успешно изменен");
	}
	else
		Logger::printWarning("Список поездов пуст. Нечего изменять");
}

void deleteObject(MyArray<Train>& trains) {
	if (trains.getSize() > 0) {
		print(trains);
		cout << "Введите номер поезда для удаления: ";
		trains -= processingInput(1, trains.getSize()) - 1;
		Logger::printMessage("Объект успешно удален");
	}
	else
		Logger::printWarning("Список поездов пуст. Нечего удалять");
}

void print(MyArray<Train>& trains) {
	if (trains.getSize() == 0)
		cout << "Список поездов пуст.";
	else {
		cout << "Список поездов\n";
		for (int i = 0; i < trains.getSize(); i++)
			cout << i + 1 << ". Поезд\n" << trains[i];
	}
}

void searchTrain(MyArray<Train>& trains) {
	if (trains.getSize() == 0)
		Logger::printWarning("Список поездов пуст.");
	else {
		string number;
		inputData("Введите номер поезда: ", number);
		bool isPrint = false;
		for (int i = 0; i < trains.getSize(); i++)
			if (trains[i].getNumber() == number) {
				cout << trains[i];
				isPrint = true;
				break;
			}
		if (!isPrint)
			Logger::printWarning("Поезд с номером " + number + " не найден");
	}
}

void startInput(MyArray<Train>& trains) {
	cout << "Откуда ввести данные: " << endl;
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
		inputData("Введите количество поездов: ", size, 0, INT32_MAX);
		for (int i = 0; i < size; i++) {
			Train train;
			train.inputFromConsole();
			trains += train;
		}
	}
}

