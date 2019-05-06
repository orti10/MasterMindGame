/*
http://www.cplusplus.com/forum/beginner/138600/ 

https://searchcode.com/codesearch/view/87676843/

https://www.daniweb.com/programming/software-development/threads/149245/game-evaluation-mastermind 

*/
#include <string>
#include "SmartGuesser.hpp"
#include "Guesser.hpp"
#include <iostream>
#include <iterator>
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
    // for(auto it=combination.begin();it!=combination.end();it++){
    //     combination.pop_back();
    // }
    cout << combination.size()<<endl;
    if (!combination.empty()){
        cout<<"asdas"<<endl;
        combination.clear();
    }
    cout<<"ll"<<endl;
   firstGuess="";            
    for(int i=0;i<length;i++){

        firstGuess=firstGuess+'0';
    }   
    cout<<firstGuess<<endl;

    sumOf=0;
    counterGuess=0;
    cout<<"starts a new game"<<endl;
}
string bullpgia::SmartGuesser::guess(){
   
    // int random = rand() % combination.size();
    // auto it = combination.begin();
    // advance(it, random); //advance the iterator 'it' by n element positions (here n=random)
    // firstGuess = *it;
    // if(counterGuess==0){
    //    counterGuess++;
    //    return firstGuess;
    // }

    // return firstGuess;
   
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
   // cout<<sumOf << endl;
    sumOf=(calculate.at(0)-48)+(calculate.at(2)-48);//sum of bull and pgia in total
    cout<<"asdasdasdjad: "<<combination.empty()<<endl;
    if(sumOf==firstGuess.length() && combination.empty()){ //combitations!!
       
        cout << "in first if"<<endl;
        int n = sizeof firstGuess/sizeof firstGuess.at(0);
        PoolCombinations(firstGuess,sumOf,n);
        cout<<"the size is: " << combination.size()<<endl;
        cout << "\nthe elements are: ";
        for(auto it=combination.begin();it!=combination.end();it++){
            cout<<*it<<" ";
        }
	}
	if(sumOf==firstGuess.length()){
        cout << "in second if"<<endl;
        auto it = combination.begin();
        advance(it,0);
        firstGuess=*it;
        combination.pop_back();
      //  cout<<"the size is: " << combination.size()<<endl;
        return ;
    }
    if(sumOf<firstGuess.length()){
    		cout << "in third if"<<endl;
    
        for(int i=sumOf;i<firstGuess.length();i++){
            firstGuess.at(i)=firstGuess.at(i)+1;
        }
        return;
    }    

    // auto it = combination.begin();
    // while( it != combination.end()) {
    //     string ans = calculateBullAndPgia(firstGuess, *it);
    //     if(ans != calculate) {
    //        it = combination.erase(it);
    //     }
    //     else it++;
    // }
        
    
}
