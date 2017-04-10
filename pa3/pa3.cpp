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
    
  /*
   
   for(;;){
        char cPick;
        cout<<"Would you like to add new string y/n->";
        cin>>cPick;
        if(cPick=='n') break;
   
        string sTemp;
        cin>>sTemp;
        keywordStack.emplace(sTemp);
        cout<<endl;
    }

    while(!keywordStack.empty()){
        string sTemp;
        //FIRST WE TAKE COPY AND THEN WE TAKE FROM TOP OF THE STRING
        sTemp=keywordStack.top();
        keywordStack.pop();
        cout<<sTemp<<endl;
    }
    */
//Get User Input
    string input = " ";
    cout << "Enter the file name (including the .txt) : ";
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
   
    
    /*
    string program = " ";
    getline(codeFile,program, (char) codeFile.eof());
    cout << program;
    
    */
    
    int line = 0;
    string teststring = " ";
    string stringarray[100];
    

    
    while(codeFile.good()){
        getline (codeFile, teststring, ' ');
        if(teststring!=""){
            stringarray[line]=teststring;
           // cout << stringarray[line] << endl;
            line++;
        }
    }
    
    //output whole array with spaces between each word
    cout<<"\nArray contents:\n";
    for (int k=0;k<100;k++)
        cout<<stringarray[k]<<" ";
    
    for (int j=0;j<100;j++){
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
        while(!keywordStack.empty()){
            string temp;
            temp=keywordStack.top();
            keywordStack.pop();
            cout<<temp<< " ";
        }
    }
    
    cout << endl;
    
    cout << "Identifier(s): ";
    if(syntaxErrors.empty()){
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
  
}





/*
 

            
 
//LOOP THROUGH FILE
    bool checkKeywords(string teststring);
    bool checkIdentifiers(string teststring);
    bool checkDelimiters(string teststring);
    bool checkOperators(string teststring);
 
    bool checkBeginEnd(string teststring);
    bool checkParenthesis(string teststring);
//GENERATE OUTPUT
    
    
    return 0; */
// }
