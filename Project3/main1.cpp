#include "Stack.h"

using namespace std;

bool delimitersOk(char *infixStr){

    Stack<char> infix, operatorStack, postfix;

    int i = 0;
    while(*(infixStr+i) != '\0'){
        infix.push(*(infixStr+i));
        ++i;
    }

    while (infix.getLength()){
        char e = infix.pop();

        if (isdigit(e)) {
            postfix.push(e);
        }
        else if (e != ')') {
            operatorStack.push(e);
        }
        // have ) but does not have (
        else { // e == ')'
            char o;
            while((o = operatorStack.pop_back()) != '('){
                postfix.push(o);
                if (!postfix.getLength() || !operatorStack.getLength()) {
                    return false;
                }
            }
        }
    }

    while (operatorStack.getLength()) {
        postfix.push(operatorStack.pop_back());
    }

    while(postfix.getLength()){
        if (postfix.pop() == '(') return false;
    };

    return true;
}

int main(){
    string inputLine;            // Input line
    char   ch;                   // Holding pen for input chars

    cout << "This program checks for properly matched delimiters."
         << endl;

    while( cin )
    {
        cout << "Enter delimited expression (<EOF> to quit) : "
             << endl;

        // Read in one line
        inputLine = "";
        cin.get(ch);
        while( cin && ch != '\n' )
        {
            inputLine = inputLine + ch;
            cin.get(ch);
        }

        if( ! cin )              // Reached EOF: stop processing
            break;

        if ( delimitersOk ((char*)inputLine.c_str()) )
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }

    return 0;
}