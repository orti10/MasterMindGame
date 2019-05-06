#include "calculate.hpp"
#include <exception>
#include <iostream>

using namespace std;
using std::string;
namespace bullpgia{
    string bullpgia::calculateBullAndPgia(string choice, string guess){
       
        int bull=0;
        int pgia=0;
        int array[10] = {0}; // Initialize the array with zero's
        string ans="0,0";
        
        //first check:if the strings are in the same size
        if(choice.length()!=guess.length())  return "Technical WIN!";
        
        //loop to check pgia only
        for(int i=0;i<choice.length();i++){
        //    if(containce(choice.at(i),guess)==true){

              if(choice.at(i)==guess.at(i)){
                    bull=bull+1; //there is a perfect guess
                }
                    else {
                        
                        if(array[guess.at(i) - '0'] ++ < 0) pgia=pgia+1;
                        if(array[choice.at(i) - '0'] -- > 0) pgia=pgia+1;
                    }
           //}
        }//end loop for
        
      //  cout<<"bull= "<<bull<<","<<"pgia= "<<pgia<<endl;//index 6,index13
        ans=to_string(bull) + "," + to_string(pgia); //a way to add chars into same string
        return ans;
    }

    // bool bullpgia::containce(char c,string s){
    //     bool flag=false;
    //     for(int i=0;i<s.length();i++){
    //         cout <<i<<endl;
    //         if(s.at(i)==c) {
    //             flag=true;
    //             return flag;
    //         }
    //     }
    //     return flag;
    // }
}
