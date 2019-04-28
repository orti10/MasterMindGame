#include "DummyGuessers.hpp"
#include <stdlib.h>

std::string RandomGuesser::guess() {
	std::string r="";
	for (uint i=0; i<this->length; ++i) {
		char c = '0' + (rand()%10);
		r += c;
	}
	return r;
}

void ConstantGuesser::learn(string s) {

}
void ConstantGuesser::startNewGame(uint length) {

}

void RandomGuesser::learn(string s) {

}
void RandomGuesser::startNewGame(uint length) {

}