#pragma once
#include "Logger.h"
#include <iostream>

class Train
{
private:
	std::string number, timeDeparture, destination;
public:
	Train(std::string number, std::string timeDeparture, std::string destination);
	Train(const Train& train);
	~Train() { Logger::printDeconstuctor("Train"); }

	std::string	getNumber() { return number; }
	void setNumber(std::string _number) { number = _number; }

	std::string	getTimeDeparture() { return timeDeparture; }
	void setTimeDeparture(std::string _timeDeparture) { timeDeparture = _timeDeparture; }

	std::string	getDestination() { return destination; }
	void setDestination(std::string _destination) { destination = _destination; }
};

