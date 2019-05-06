/*
http://www.cplusplus.com/forum/beginner/138600/ 

https://searchcode.com/codesearch/view/87676843/

https://www.daniweb.com/programming/software-development/threads/149245/game-evaluation-mastermind 

*/

#include "SmartGuesser.hpp"
#include "Guesser.hpp"
#include <iostream>

using std::string;
using namespace std;

void bullpgia::SmartGuesser::swap(char &x, char &y)  
{  
    char temp;  
    temp = x;  
    x = y;  
    y = temp;  
} 
void bullpgia::SmartGuesser::PoolCombinations(string s ,int size, int n){
    if(size==1){
    
     combination.push_back(s);
       
        return;
    }

    for(int i=0;i<size;i++){
        PoolCombinations(s,size-1,n);

        if(size%2==1){
            swap(s.at(0),s.at(size-1));
        }
        else{
            swap(s.at(i),s.at(size-1));
        }
    }
}

void bullpgia::SmartGuesser::startNewGame(uint length){
     
    if (!combination.empty()){
        combination.clear();
    }
    firstGuess="";            
    for(int i=0;i<length;i++){ //making sure we start with zeros
        firstGuess=firstGuess+'0';
    }   
    sumOf=0;//fresh start
    counterGuess=0;//fresh start
    cout<<"starts a new game"<<endl;
}

string bullpgia::SmartGuesser::guess(){
   
    if(counterGuess==0){
      counterGuess++;
    return firstGuess;
    }
    //checking if the counter less then 10 and also that the sum of bull+pgia not a 4
    else if(counterGuess<10 && sumOf!=4){
            counterGuess++;
            return firstGuess;
        }
    return firstGuess;
}


void bullpgia::SmartGuesser::learn(string calculate){
   // cout<<sumOf << endl;
    sumOf=(calculate.at(0)-48)+(calculate.at(2)-48);//sum of bull and pgia in total
    if(sumOf==firstGuess.length() && combination.size()==0){ //combitations!!
        int n = sizeof firstGuess/sizeof firstGuess.at(0);
        PoolCombinations(firstGuess,sumOf,n);

        for(auto it=combination.begin();it!=combination.end();it++){
            cout<<*it<<" ";
        }
	}
	if(sumOf==firstGuess.length()){
        auto it = combination.begin();
        advance(it,0);
        firstGuess=*it;
        combination.pop_front();
        return ;
    }
    if(sumOf<firstGuess.length()){
    		cout << "in third if"<<endl;
    
        for(int i=sumOf;i<firstGuess.length();i++){
            firstGuess.at(i)=firstGuess.at(i)+1;
        }
        return;
    }    
}
