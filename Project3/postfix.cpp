#include "Stack.h"

using namespace std;

int main(){
	char infixStr[100];

	Stack<char> infix, operatorStack, postfix;

	cout<<"Input: ";
    cin >> infixStr;

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
	    else {
	    	char o;
	    	while((o = operatorStack.pop_back()) != '('){
	    		postfix.push(o);

	    	}
	    }
	}

	while (operatorStack.getLength()) {
    	postfix.push(operatorStack.pop_back());
	}

	postfix.print();

	Stack<double> operandStack;

	while (postfix.getLength()) {

	    char e = postfix.pop();

	    if (isdigit(e)) {
	        operandStack.push((int)e - 48);
	    }
	    else {
	    	double b = operandStack.pop_back();
	        double a = operandStack.pop_back();

	        double val = e == '+' ? a + b : e == '-' ? a - b : e == '*' ? a * b : e == '/' ? a / b : e == '^' ? pow(a, b) : 0;
	        operandStack.push(val);
	    }
	}

	cout<<operandStack.pop_back()<<endl;

}