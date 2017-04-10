//
//  pa3.cpp
//  pa3
//
//  Created by Andrew Ortega on 4/3/17.
//  Copyright © 2017 Andrew E. Ortega. All rights reserved.
//

#include <iostream>
#include <fstream> 
#include <string>
#include <stack>
#include "pa3.h"

using namespace std;
using std::string;


int main(){
    Syntax syntax;

    
    stack<string> keywordStack;
    stack<string> identifierStack;
    stack<string> constantStack;
    stack<string> delimiterStack;
    stack<string> operatorStack;
    
    stack<string> syntaxErrors;
    
    stack<string> beginEndStack;
    stack<string> parenthesisStack;
    

    
//Get User Input
    string input = " ";
    cout << "Enter the name of the input file (including the .txt) : ";
    cin >> input;
    
    //DEBUG - check if input was successfully passed from getInput() to main
    //cout << input << endl;
    
    cout << endl;
//OPEN FILE -- checks if valid file name
    ifstream codeFile;
    codeFile.open(input);
        if(codeFile.is_open()){
            cout << "*File Open Success*" << endl << endl;
        }
        else{
            cout << "File Open Failed - Program Terminating" << endl << endl;
            exit(9);
        }
   
    
    int line = 0;
    string teststring = " ";
    string stringarray[100];
    
    
    
    while (codeFile.good()){
        codeFile >> teststring;
    
        if(teststring!="" && teststring[0]!='\n' && teststring[0] != 9 && teststring[0] != 10 && teststring[0] != 32 && teststring[0]!=' '
           && teststring!=" "){
            stringarray[line]=teststring;
            line++;
        }
        teststring = "";
    }
    
    
   /* //output whole array with spaces between each word
    cout<<"\nArray contents:\n";
    for (int k=0;k<100;k++)
        cout<<stringarray[k]<< endl;
    */
    
    
  /*  cout<<"\nArray contents Parsed:\n";
    for (int k=0;k<100;k++)
        cout<<stringarray[k]<< endl;
    */
    
     
     
    //SORT THROUGH ARRAY
    
   for(int j=0;j<100;j++){
        if(syntax.checkKeywords(stringarray[j])==true){
            keywordStack.emplace(stringarray[j]);
        }
        else
            if(syntax.checkIdentifiers(stringarray[j])==true){
                identifierStack.emplace(stringarray[j]);
            }
         else
             if(syntax.checkConstants(stringarray[j])==true){
                 constantStack.emplace(stringarray[j]);
             }
            else
                if (syntax.checkOperators(stringarray[j])==true){
                    operatorStack.emplace(stringarray[j]);
                }
            else
                if(syntax.checkDelimiters(stringarray[j])==true){
                    delimiterStack.emplace(stringarray[j]);
                }
            else
                syntaxErrors.emplace(stringarray[j]);
    }


//GENERATE OUTPUT
    cout << endl << endl;
    
    cout << "Keyword(s): ";
   
    if(keywordStack.empty()){
        cout << "NA";
    }
    else{
        
        string keywordPrint[3] = { " ", " ", " ",};
        
        
        while(!keywordStack.empty()){
            string temp;
            temp=keywordStack.top();
            
            bool duplicate = false;
            
            for(int i=0;i<3;i++){
                if(temp == keywordPrint[i]){
                    duplicate = true;
                }
            }
            
            if(duplicate == false){
                for(int i=0;i<3;i++){
                    if(" " == keywordPrint[i]){
                        keywordPrint[i] = temp;
                        break;
                    }
                }
            }
            keywordStack.pop();
        }
        for(int i=0; i<3;i++){
            cout << keywordPrint[i] << " " ;
        }
    
    }
    
cout << endl;
    /*
    cout << "Identifier(s): ";
    if(identifierStack.empty()){
        cout << "NA";
    }
    else{
        
        while(!identifierStack.empty()){
            string temp;
            temp=identifierStack.top();
            identifierStack.pop();
            cout<<temp<< " ";
        }
    }
    cout << endl;
    cout << "Constant(s): ";
    if(syntaxErrors.empty()){
        cout << "NA";
    }
    else{
        while(!constantStack.empty()){
            string temp;
            temp=constantStack.top();
            constantStack.pop();
            cout<<temp<< " ";
        }
    }
    */
    /*
    cout << "Identifier(s): ";
    if(identifierStack.empty()){
        cout << "NA";
    }
    else{
        string identifierPrint[100] = {};
        
        
        while(!identifierStack.empty()){
            string temp;
            temp=identifierStack.top();
            
            bool duplicate = false;
            
            for(int i=0;i<3;i++){
                if(temp == identifierPrint[i]){
                    duplicate = true;
                }
            }
            
            if(duplicate == false){
                for(int i=0; i<100; i++){
                    if(" " == identifierPrint[i]){
                        identifierPrint[i] = temp;
                        break;
                    }
                }
            }
            keywordStack.pop();
        }
        for(int i=0; i<100;i++){
            cout << identifierPrint[i] << " " ;
        }
    }
    
    cout << endl;
    */
    
    /* 
     
    cout << "Constant(s): ";
    if(syntaxErrors.empty()){
        cout << "NA";
    }
    else{
        while(!constantStack.empty()){
            string temp;
            temp=constantStack.top();
            constantStack.pop();
            cout<<temp<< " ";
        }
    }
    
    cout << endl;
    
    cout << "Operator(s): ";
    if(operatorStack.empty()){
        cout << "NA";
    }
    else{
        while(!operatorStack.empty()){
            string temp;
            operatorStack.pop();
            cout<<temp<< " ";
        }
    }
    
    cout << endl;
    
    cout << "Delimiter(s): ";
    if(delimiterStack.empty()){
        cout << "NA";
    }
    else{
        
        while(!delimiterStack.empty()){
            string temp;
            temp=delimiterStack.top();
            syntaxErrors.pop();
            cout<<temp<< " ";
        }
    }
    
    cout << endl << endl;
    
    cout << "Syntax Error(s): ";
    if(syntaxErrors.empty()){
        cout << "NA";
    }
    else{
        while(!syntaxErrors.empty()){
            string temp;
            temp=syntaxErrors.top();
            syntaxErrors.pop();
            cout<<temp<< " ";
        }
    }
    
    cout << endl;
    
    */
  
}


