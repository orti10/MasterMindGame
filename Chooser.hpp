#pragma once
#include <string>
using std::string;
using namespace std;

namespace bullpgia{
    
    class Chooser{
        private:
        uint length;
        string choice;
        
        public: 
        virtual string choose(uint length)=0;

    };

}
