#include "UsersInput.h"

//��������� ����� �������� ����a
//���� 0 �������� ����� �� ����� ������ �� �����.
bool processInputNameOfInputFile(std::string& filename)
{
	std::ifstream file;
	//��������� �������� �����
	bool isCorrect;
	std::cout << "������� �������� ����� (� �����������): ";
	std::cin >> filename;
	isCorrect = checkFilename(filename);
	if (isCorrect)
		file.open(filename);
	while (!file.is_open() && filename[0] != '0')
	{
		
		if (isCorrect)
			Logger::printWarning("������ ����� �� ����������.");
		std::cout << "������� �������� �������� (� �����������): ";
		std::cin >> filename;
		isCorrect = checkFilename(filename);
		if (isCorrect)
			file.open(filename);
	}
	file.close();
	if (filename[0] != '0') {
		Logger::printMessage("���� ������� ������");
		return true;
	}
	else {
		Logger::printMessage("�� ���������� �� ����� ������ �� �����");
		return false;
	}
		
}
//��������� ����� ��������� ����a
//���� 0 �������� ����� �� ����� ������ �� �����.
bool processInputNameOfOutputFile(std::string& filename)
{
	//��������� �������� �����
	bool isCorrect;
	std::cout << "������� �������� ����� (� �����������): ";
	std::cin >> filename;
	isCorrect = checkFilename(filename);
	while (!isCorrect && filename[0] != '0') {
		std::cout << "������� �������� �������� (� �����������): ";
		std::cin >> filename;
		isCorrect = checkFilename(filename);
	}
	if (filename[0] != '0') {
		Logger::printMessage("���� ������� ������");
		return true;
	}
	else {
		Logger::printMessage("�� ���������� �� ����� ������ �� �����");
		return false;
	}
}
//�������� ������������ ����� �����
bool checkFilename(std::string file)
{
	if (file.size() < 4 && file[0] != '0') {
		Logger::printWarning("��� ����� ������� ��������.");
		return false;
	}
	if ((((file[0] == 'c') || (file[0] == 'C')) && ((file[1] == 'o') || (file[1] == 'O'))
		&& ((file[2] == 'n') || (file[2] == 'N')) && ((file[3] == '.') || (file[3] == '\0')))
		|| (((file[0] == 'a') || (file[0] == 'A')) && ((file[1] == 'u') || (file[1] == 'U'))
			&& ((file[2] == 'x') || (file[2] == 'X')) && ((file[3] == '.') || (file[3] == '\0')))
		|| (((file[0] == 'p') || (file[0] == 'P')) && ((file[1] == 'r') || (file[1] == 'R'))
			&& ((file[2] == 'n') || (file[2] == 'N')) && ((file[3] == '.') || (file[3] == '\0')))
		|| (((file[0] == 'c') || (file[0] == 'C')) && ((file[1] == 'o') || (file[1] == 'O'))
			&& ((file[2] == 'm') || (file[2] == 'M')) && ((file[3] == '1') || (file[3] == '2')
				|| (file[3] == '3') || (file[3] == '4') || (file[3] == '5') || (file[3] == '6')
				|| (file[3] == '7') || (file[3] == '8') || (file[3] == '9')) && ((file[4] == '.')
					|| (file[4] == '\0'))) || (((file[0] == 'l') || (file[0] == 'L')) && ((file[1] == 'p')
						|| (file[1] == 'P')) && ((file[2] == 't') || (file[2] == 'T')) && ((file[3] == '1')
							|| (file[3] == '2') || (file[3] == '3') || (file[3] == '4') || (file[3] == '5')
							|| (file[3] == '6') || (file[3] == '7') || (file[3] == '8') || (file[3] == '9'))
						&& ((file[4] == '.') || (file[4] == '\0'))))
	{
		std::cin.ignore(INT_MAX, '\n');
		Logger::printWarning("������ ��� ����� ������������ Windows.");
		return false;
	}
	int i = file.size();
	if ((file[i] == '\0') && (file[i - 1] == 't') && (file[i - 2] == 'x') && (file[i - 3] == 't') && (file[i - 4] == '.') ||
		(file[i] == '\0') && (file[i - 1] == 'v') && (file[i - 2] == 's') && (file[i - 3] == 'c') && (file[i - 4] == '.') ||
		(file[i] == '\0') && (file[i - 1] == 't') && (file[i - 2] == 'a') && (file[i - 3] == 'd') && (file[i - 4] == '.'))
		return true;
	else
	{
		if (file[i - 1] != '0')
			Logger::printWarning("���� ������ ����� ������ .txt ��� .csv ��� .dat");
		return false;
	}
}

void inputData(std::string help, std::string& data) {
	std::cout << help;
	getline(std::cin, data);
	while (data.size() < 1) {
		Logger::printWarning("������ �� ������ ���� ������.");
		std::cout << "������� ��������: ";
		getline(std::cin, data);
	}
}

bool isNumeric(const char& ch) {
	return ch >= '0' && ch <= '9';
}

bool checkTime(const std::string& s) {
	if (s.size() != 5)
		return false;
	int intTime = ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + (s[0] - '0') * 10 + (s[0] - '0');
	return intTime > 0 && intTime < 1439;
}

void inputTimeDeparture(std::string help, std::string& data) {
	std::cout << help;
	while (true)
	{
		getline(std::cin, data);
		if (data.size() < 5 || !isNumeric(data[0]) || !isNumeric(data[1])
			|| !isNumeric(data[3]) || !isNumeric(data[4]) || !checkTime(data)) {
			Logger::printWarning("�������� ����.");
			std::cout << "������� ��������: ";
		}
		else
			break;
	}
}