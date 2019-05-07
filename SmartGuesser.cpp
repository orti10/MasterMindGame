/*
http://www.cplusplus.com/forum/beginner/138600/ 

https://searchcode.com/codesearch/view/87676843/

https://www.daniweb.com/programming/software-development/threads/149245/game-evaluation-mastermind 

https://en.cppreference.com/w/cpp/algorithm/next_permutation
*/

#include "SmartGuesser.hpp"
#include "Guesser.hpp"
#include <iostream>
#include<string>
#include<iostream>
#include<algorithm>
using std::string;
using namespace std;


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
    if(sumOf==firstGuess.length() && combination.size()==0){ // making the combination list
        do
        {

            combination.push_back(firstGuess); //adding the strings to the array

        }while(std::next_permutation(firstGuess.begin(),firstGuess.end()));//iterate the string

        //   printing the combinations:   -optional-
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
