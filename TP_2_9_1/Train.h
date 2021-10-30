#pragma once
#include "Logger.h"
#include "UsersInput.h"
#include <iostream>

class Train
{
private:
	std::string number, timeDeparture, destination;
public:
	Train();
	Train(std::string number, std::string timeDeparture, std::string destination);
	Train(const Train& train);
	~Train() { Logger::printDeconstuctor("Train"); }

	void inputFromConsole();
	void edit();
	friend std::ostream& operator<<(std::ostream& out, const Train& train); 
	bool operator>(const Train& train);


	std::string	getNumber() const { return number; }
	void setNumber(std::string _number) { number = _number; }

	std::string	getTimeDeparture() const { return timeDeparture; }
	void setTimeDeparture(std::string _timeDeparture) { timeDeparture = _timeDeparture; }

	std::string	getDestination() const { return destination; }
	void setDestination(std::string _destination) { destination = _destination; }
};

