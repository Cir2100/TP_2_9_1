#include "Train.h"
#include "UsersInput.h"
#include "graphics.h"
#include <iostream>
#include <fstream>
#include <typeinfo>
#pragma comment(lib, "winmm.lib")


using namespace std;

void printMenu();
void addObject(MyArray<Train>& trains);
void editObject(MyArray<Train>& trains);
void deleteObject(MyArray<Train>& trains);
void print(MyArray<Train>& trains);
void searchTrain(MyArray<Train>& trains);
void poezd();


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	MyArray<Train> trains;

	bool isExit = false;
	while (!isExit) {
		printMenu();
		int method = processingInput(0, 7);
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
		case 7:
			poezd();
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
	cout << "7. ���������� �� �����" << endl;
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

void poezd() {
	int gm, gd = DETECT;
	char a[2] = " ";
	initgraph(&gd, &gm, a);
	int xStart = 800, yStart = 100;
	int speed = 10;

	mciSendString(L"open \"D:\\Projects\\VS\\TP_3_kurs\\TP_2_9_1\\TP_2_9_1\\Poezd.mp3\" type mpegvideo alias song", NULL, 0, NULL);
	mciSendString(L"play song from 0", NULL, 0, NULL);
	delay(3900);
	mciSendString(L"close song", NULL, 0, NULL);
	while (xStart > -75) {
		//������
		rectangle(xStart, yStart, xStart + 100, yStart + 200);
		//����
		rectangle(xStart + 25, yStart + 25, xStart + 75, yStart + 75);
		line(xStart + 25, yStart + 50, xStart + 75, yStart + 50);
		line(xStart + 50, yStart + 25, xStart + 50, yStart + 75);
		//�����
		rectangle(xStart + 20, yStart + 100, xStart + 50, yStart + 105);
		//���������
		rectangle(xStart - 200, yStart + 100, xStart, yStart + 200);
		//�����
		rectangle(xStart - 150, yStart + 50, xStart - 130, yStart + 100);
		//������
		circle(xStart - 130, yStart + 200, 50);

		circle(xStart + 30, yStart + 200, 50);

		xStart -= speed;
		delay(10);
		cleardevice();
	}
	closegraph();
}
