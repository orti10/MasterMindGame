#include "calculate.hpp"
#include <exception>
#include <iostream>

using namespace std;
using std::string;
namespace bullpgia{
    string bullpgia::calculateBullAndPgia(string choice, string guess){
        int bull=0;
        int pgia=0;
        string ans="";
        //first check:if the strings are in the same size
        if(choice.length()!=guess.length()) throw "you have a short/long guess";
        //loop to check pgia only
        for(int i=0;i<choice.length();i++){
           if(containce(choice.at(i),guess)==true){
              if(choice.at(i)==guess.at(i)){
                    bull=bull+1; //there is a perfect guess
                }
                    else pgia=pgia+1;//there is almost a perfect guess 
           }
        }
        cout<<"bull= "<<bull<<","<<"pgia= "<<pgia<<endl;//index 6,index13
        char b=bull+48;
        char p=pgia+48;
        ans=b+','+p;//0,2
        return ans;
    }

    bool bullpgia::containce(char c,string s){
        bool flag=false;
        for(int i=0;i<s.length();i++){
            if(s.at(i)==c) flag=true;
        }
        return flag;
    }
}
/*
#include "calculate.hpp"
using namespace std;
string calculateBullAndPgia(string choice, string guess) { 
int bull = 0;
int pgia = 0;
int length = choice.length();
int numbers[10] = {0};
for(int i=0; i<length; i++)
{
    if(choice.at(i) == guess.at(i))
    {
        bull++;
    }
    else
    {
        if(numbers[guess.at(i) - '0'] ++ < 0) pgia++;
        if(numbers[choice.at(i) - '0'] -- > 0) pgia++;
    } 
} // End for
string ans = to_string(bull) + "," + to_string(pgia);
return ans;
} // End calculateBullAndPgia
*/
