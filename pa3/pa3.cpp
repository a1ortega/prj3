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
    stack<string> mathStack;
    stack<string> delimiterStack;
    stack<string> operatorStack;
    stack<string> beginEndStack;
    stack<string> parenthesisStack;
  /*
   for(;;)
    {
        char cPick;
        cout<<"Would you like to add new string y/n->";
        cin>>cPick;
        if(cPick=='n') break;
        
    
        string sTemp;
        cin>>sTemp;
        keywordStack.emplace(sTemp);
        cout<<endl;
    }
    
    while(!keywordStack.empty())
    {
        //YES, AND NEGATION WILL TAKE SOME TIME!
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
   
//OPEN FILE -- checks if valid file name
    ifstream codeFile;
    codeFile.open(input);
        if(codeFile.is_open()){
            cout << "File Open Success" << endl;
        }
        else{
            cout << "File Open Failed - Program Terminating" << endl;
            exit(9);
        }
    
    string fileInput = " ";

    while(!codeFile.eof()){
    codeFile >> noskipws >> fileInput;
    }
    
     cout << fileInput;
    
    
}







    /*
//Separate Input File
    int line = 0;
    string teststring = " ";
    string stringarray[100];
    while(codeFile.good() )
    {
        getline (codeFile, teststring, ' ');
        if(teststring!= " "){
            stringarray[line]=teststring;
            cout << stringarray[line] << endl;
            line++;
        }
    }
    
    //output whole array with spaces between each word
    cout<<"\nArray contents:\n";
    for (int k=0;k<line;k++)
        cout<<stringarray[k]<<endl;
    return 0;
} */
    /*
//LOOP THROUGH FILE
    bool checkKeywords(string teststring);
    bool checkMath(string teststring);
    bool checkDelimiters(string teststring);
    bool checkOperators(string teststring);
    bool checkBeginEnd(string teststring);
    bool checkParenthesis(string teststring);
//GENERATE OUTPUT
    
    
    return 0; */
// }
