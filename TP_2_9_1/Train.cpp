#include "Train.h"

Train::Train()
	: number(MY_NULL_STRING), timeDeparture(MY_NULL_STRING), destination(MY_NULL_STRING)
	{ Logger::printBuilder("Train"); }

Train::Train(std::string number, std::string timeDeparture, std::string destination)
	: number(number), timeDeparture(timeDeparture), destination(destination)
	{ Logger::printBuilder("Train"); }

Train::Train(const Train& train) 
	: number(train.number), timeDeparture(train.timeDeparture), destination(train.destination)
	{ Logger::printCopyBuilder("Train"); }

void Train::inputFromConsole() {
	inputData("Введите номер поезда: ", number);
	inputTimeDeparture("Введите время отправления поезда: ", timeDeparture);
	inputData("Введите пункт назначения поезда: ", destination);
}

void Train::edit() {
	std::string tmpString = MY_NULL_STRING;
	bool isExit = false;
	while (!isExit) {

		std::cout << "1. Изменить номер" << std::endl;
		std::cout << "2. Изменить время отправления" << std::endl;
		std::cout << "3. Изменить пункт назначения" << std::endl;
		std::cout << "4. Вывести данные на экран" << std::endl;
		std::cout << "0. Сохранить изменения" << std::endl;
		std::cout << "Выберете пункт меню: ";

		int method = processingInput(0, 4);
		switch (method)
		{
		case 1:
			inputData("Введите номер поезда: ", number);
			break;
		case 2:
			inputTimeDeparture("Введите время отправления поезда: ", timeDeparture);
			break;
		case 3:
			inputData("Введите пункт назначения поезда: ", destination);
			break;
		case 4:
			std::cout << *this;
			break;
		case 0:
			isExit = true;
			break;
		}
	}
}

bool Train::operator>(const Train& train) {
	return number > train.number;
}

//friend
std::ostream& operator<<(std::ostream& out, const Train& train) {
	out << TRAIN_NUMBER_STRING << train.number << std::endl;
	out << TRAIN_TIMEDEPARTURE_STRING << train.timeDeparture << std::endl;
	out << TRAIN_DESTINATION_STRING << train.destination << std::endl;
	return out;
}