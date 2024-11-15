#include "dap.h"

set<char> ilegalChars = {'&', '|', '@', '"', '#', '\'', '\\', '/', '(', '^', '!', '{', '}', ')', '*', '$', '[', ']', '%', ':', ';', ',', '.', '?', '\0'};
set<char> whiteSpace = {'\n', '\t', '\v', '\f', '\a', ' '};
set<char> interuptChars = {'\n', '\t', '\v', '\f', '\a', ' '};
set<char> semiInterptChars = {'(', ')', '{', '}', '[', ']'};

string getline(string code, int pos){
    string returnStr = "";
    while (code[pos] != '\n'){
        returnStr += code[pos];
        pos++;
    }
    return returnStr;
}

string processLine(string line){

}

int goToNext(string code, int pos){
    while (pos < code.length() && whiteSpace.count(pos) != 1){
        pos++;
    }
    return code[pos];
}

string createInstructionList(string code){
    string main = "";
    int pos = 0;
    while(pos < code.length()){
        string line = getline(code, goToNext(code, pos));
        pos += goToNext(code, pos) + line.length();
        Serial.println(line.c_str());
    }
    return main;
};