#pragma once
#include "calculate.hpp"
#include <string>
#include "Guesser.hpp"
using std::string;

namespace bullpgia{
    class SmartGuesser:public bullpgia::Guesser{

        
        public:

        void learn(string s)override;
        void startNewGame(uint length)override;
        string guess() override;
        
    }; 
}
