#pragma once
#include "calculate.hpp"
#include "Guesser.hpp"
#include <string>
#include<list>
#include<iterator>
#include<map>
#include <vector> //a dynamic array

using std::string;

namespace bullpgia{
    class SmartGuesser:public bullpgia::Guesser{
        
        private:
        void initialize(string s);
        void swap(char *x, char *y);
        void PoolCombinations(string s, int l, int r);
        public:
        string lastGuess,firstGuess;
        string smartSave="0123456789";
        vector <string> combination;
        uint length;
        int counterGuess=0;
        int sumOf=0;

        void learn(string calculate)override;
        void startNewGame(uint length)override;
        string guess() override;
        
    }; 
}
