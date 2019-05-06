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

void bullpgia::SmartGuesser::swap(char &x, char &y) //swaping between 2 chars
{  
    char temp;  
    temp = x;  
    x = y;  
    y = temp;  
} 
//function that creates a list of optional combinations from the numbers we got from the guess
void bullpgia::SmartGuesser::PoolCombinations(string s ,int size, int n){
    if(size==1){
        combination.push_back(s);//addition string value to the list
        return;
    }
    for(int i=0;i<size;i++){
        PoolCombinations(s,size-1,n);//rec
        if(size%2==1){//if size id odd
            swap(s.at(0),s.at(size-1));//calling swap function to make option to the list
        }
        else{
            swap(s.at(i),s.at(size-1));
        }
    }
}

void bullpgia::SmartGuesser::startNewGame(uint length){
     
    if (!combination.empty()){
        combination.clear();//clearing the list
    }
    firstGuess="";            
    for(int i=0;i<length;i++){ //making sure we start with zeros '0000'
        firstGuess=firstGuess+'0';
    }   
    sumOf=0;//initilize
    counterGuess=0;//initilize
    cout<<"starts a new game"<<endl;
}

string bullpgia::SmartGuesser::guess(){
   
    if(counterGuess==0){
      counterGuess++;//counter goes up
    return firstGuess;
    }
    //checking if the counter less then 10 and also that the sum of bull+pgia not a 4
    else if(counterGuess<10 && sumOf!=4){
            counterGuess++;//counter goes up
            return firstGuess;
        }
    return firstGuess;
}


void bullpgia::SmartGuesser::learn(string calculate){
    sumOf=(calculate.at(0)-48)+(calculate.at(2)-48);//sum of bull and pgia in total
    if(sumOf==firstGuess.length() && combination.size()==0){ //combitations!!
        int n = sizeof firstGuess/sizeof firstGuess.at(0);
        PoolCombinations(firstGuess,sumOf,n);

        //printing the combinations:   -optional-
        // for(auto it=combination.begin();it!=combination.end();it++){
        //     cout<<*it<<" ";
        // }
	}
	if(sumOf==firstGuess.length()){
        auto it = combination.begin();//update the iterator to be the first element
        advance(it,0);//advance the iterator 'it' by n element position (here n=0) 
        firstGuess=*it;//update the first Guess to be the value of the iterator
        combination.pop_front();//remove the element from the begining
        return ;
    }
    if(sumOf<firstGuess.length()){
        for(int i=sumOf;i<firstGuess.length();i++){
            firstGuess.at(i)=firstGuess.at(i)+1;//0000 then 1111 then 2222 and so on
        }
        return;
    }    
}
