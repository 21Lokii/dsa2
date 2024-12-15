#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

int precedence(char op) {
if (op == '+' || op == '-')
return 1;
if (op == '*' || op == '/')
return 2;
return 0;
}

int applyOp(int a, int b, char op) {
switch (op) {
case '+': return a + b;
case '-': return a - b;
case '*': return a * b;
case '/': return a / b;
}
return 0;
}


string infixToPostfix(string infix) {
stack<char> operators;
string postfix = "";

for (int i = 0; i < infix.length(); i++) {
char c = infix[i];

if (isdigit(c)) {
postfix += c;
}
else if (c == '(') {
operators.push(c);
}
else if (c == ')') {
while (!operators.empty() && operators.top() != '(') {
postfix += operators.top();
operators.pop();
}
operators.pop();
}
       
else {
while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
postfix += operators.top();
operators.pop();
}
operators.push(c);
}
}

while (!operators.empty()) {
postfix += operators.top();
operators.pop();
}

return postfix;
}


int evaluatePostfix(string postfix) {
stack<int> values;

for (int i = 0; i < postfix.length(); i++) {
char c = postfix[i];

        
if (isdigit(c)) {
values.push(c - '0');
}
else {
int val2 = values.top();
values.pop();
int val1 = values.top();
values.pop();
values.push(applyOp(val1, val2, c));
}
}

return values.top();
}

int main() {
string infix;
cout << "Enter an infix expression: ";
cin >> infix;

string postfix = infixToPostfix(infix);
cout << "Postfix expression: " << postfix << endl;

int result = evaluatePostfix(postfix);
cout << "Result of postfix expression: " << result << endl;

return 0;
}
