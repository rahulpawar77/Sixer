// Problem Statement: Use a stack to check whether an expression has balanced parentheses and delimiters.
#include <iostream>
#include <string>
using namespace std;
 
char st[1000];
int top = -1;
 
void push(char ch) { st[++top] = ch; }
char pop() { return st[top--]; }
 
bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}
 
bool checkExpression(const string& exp) {
    top = -1;
    for (char ch : exp) {
        if (ch == '(' || ch == '{' || ch == '[') {
            if (top == 999) return false;
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1 || !isMatching(pop(), ch)) return false;
        }
    }
    return top == -1;
}
 
int main() {
    string exp;
    cout << "Enter expression: ";
    getline(cin, exp);
    if (checkExpression(exp))
        cout << "Expression is Well-Parenthesized\n";
    else
        cout << "Expression is Not Well-Parenthesized\n";
    return 0;
}
 
