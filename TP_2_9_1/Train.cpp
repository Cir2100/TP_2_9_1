#include "Train.h"

Train::Train(std::string number, std::string timeDeparture, std::string destination)
	: number(number), timeDeparture(timeDeparture), destination(destination)
	{ Logger::printBuilder("Train"); }

Train::Train(const Train& train) 
	: number(train.number), timeDeparture(train.timeDeparture), destination(train.destination)
	{ Logger::printCopyBuilder("Train"); }
