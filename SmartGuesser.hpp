#pragma once
#include "calculate.hpp"
#include "Guesser.hpp"
#include <string>
#include <list>
#include<iterator>

using std::string;

namespace bullpgia{
    class SmartGuesser:public bullpgia::Guesser{
        
        private:
        void swap(char &x, char &y);
        void PoolCombinations(string s, int l, int r);
        
        public:
        string firstGuess;
        list <string> combination;
        uint length;
        int counterGuess=0;
        int sumOf=0;

        void learn(string calculate)override;
        void startNewGame(uint length)override;
        string guess() override;
        
    }; 
}
