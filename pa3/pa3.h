//
//  pa3.h
//  pa3
//
//  Created by Andrew Ortega on 4/3/17.
//  Copyright © 2017 Andrew E. Ortega. All rights reserved.
//


#ifndef Header_h
#define Header_h

#include <iostream>
#include <string>
#include <fstream>
#include <stack>

using namespace std;
using std::string;

class Syntax{
    
public:
    

    bool checkKeywords(string input){
        string keywords[] = { "BEGIN", "END", "FOR" };
        int keywordCheck=0;
        if(input[0]<=97 && input[0]>=122)
            return false;
       
        for(int i=0;i<3;i++){           //loops though keyword list
            if(input == keywords[i]){
                keywordCheck = 1;
                break;                  //if match- break loop
            }
        }
        
        if(keywordCheck == 1)           //if keyword return true/ else return false
            return true;
        else
            return false;
    } //end of bool checkKeywords
    
    
    bool checkMath(string input){
        string math[] = {"+","-","/","%","*"};
        int mathCheck = 0;
        
        for(int i=0;i<5;i++){
            if(input == math[i]){
                mathCheck = 1;
                break;
            }
        }
        
        if(mathCheck == 1){
            return true;
        }
        else
            return false;

    } //end of bool 'checkMath'
    
    
    bool checkOperators(string input){
        string operators[] = {"=","==","!=",">=","<=",">","<","&&","||"};
        int operatorsCheck = 0;
        
        for(int i=0;i<9;i++){
            if(input == operators[i]){
                operatorsCheck = 1;
                break;
            }
        }
        
        if(operatorsCheck == 1){
            return true;
        }
        else
            return false;

    } //end of bool 'checkOperators'
    
    
    bool checkDelimiters(string input){
        string delimiters[] = {"(",")","{","}",",",":",";"};
        int delimitersCheck = 0;
        
        for(int i=0;i<5;i++){
            if(input == delimiters[i]){
                delimitersCheck = 1;
                break;
            }
        }
        
        if(delimitersCheck == 1){
            return true;
        }
        else
            return false;

    } //end of check delimiters 
    void checkParenthesis(){
        //if ( != )
        {
           //if ( > )
            // extra open parenthesis ((
           //else if ( < )
            // extra closed parenthesis ))
        }
        
        //else
        {
            //continue
        }
        
    }
    
    void checkBeginEnd(){
        //if (begin != end){
        {
          //if (begin > end)
            //extra begin
          //else
            //extra end
        }
        //else{
        {
            //continue
        }
    }
    void nestedLoop(){
        
    }
    
    
    void checkIdentifiers(){
        
    }
    
    void checkConstants(){
        
    }
    void checkSyntaxErrors(){
        
    }
    
};

#endif
