/*
http://www.cplusplus.com/forum/beginner/138600/ 

https://searchcode.com/codesearch/view/87676843/

https://www.daniweb.com/programming/software-development/threads/149245/game-evaluation-mastermind 

*/
#include <string>
#include "SmartGuesser.hpp"
#include "Guesser.hpp"
#include <iostream>
#include <random>
using std::string;


void bullpgia::SmartGuesser::initialize(string s){
    if(s.empty()) throw "technical win";
    for(int i=0;i<s.length();i++){
        firstGuess=firstGuess+'0';
    }
}
void bullpgia::SmartGuesser::swap(char *x, char *y)  
{  
    char temp;  
    temp = *x;  
    *x = *y;  
    *y = temp;  
} 
void bullpgia::SmartGuesser::PoolCombinations(string s ,int l, int r){
    int i;  
    if (l == r){
        combination.add(s);
    }
          
    else
    {  
        for (i = l; i <= r; i++)  
        {  
            swap((a+l), (a+i));  
            permute(a, l+1, r);  
            swap((a+l), (a+i)); //backtrack  
        }  
    }  
}

void bullpgia::SmartGuesser::startNewGame(uint length){
    for(int i=0;i<length;i++){
        firstGuess=firstGuess+'0';
    }   
    sumOf=0;
    counterGuess=0;
    combination.clear();
    cout<<"starts a new game"<<endl;
}
string bullpgia::SmartGuesser::guess(){
   if(counterGuess==0){
       counterGuess++;
       return firstGuess;
   }
   else if(counterGuess<10 && sumOf!=4){
            counterGuess++;
            return firstGuess;
        }
   return firstGuess;
}


void bullpgia::SmartGuesser::learn(string calculate){
    
    sumOf=(calculate.at(0)-48)+(calculate.at(2)-48);//sum of bull and pgia in total
    if(sumOf==firstGuess.length() && !combination.empty()){ //combitations!!
		PoolCombinations(firstGuess);
	}
	if(sumOf==firstGuess.length()){
        firstGuess=combination.at[0];
        combination.erase(combination.begin()/*at[0]*/);
        return ;
    }
    if(sumOf<firstGuess.length()){
        for(int i=sumOf;i<firstGuess.length();i++){
            firstGuess.at(i)=firstGuess.at(i)+1;
        }
        return;
    }    
        
    
}
