#include "infixToPostfix.h"


bool balanced(const string& expression) {
    stack<char> stk;
    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (stk.empty()) {
                return false;
            }
            else if ((c == ')' && stk.top() != '(') ||
                (c == ']' && stk.top() != '[') || (c == '}' && stk.top() != '{')) {
                return false;
            }
            else {
                stk.pop();
            }
        }
    }
    return stk.empty();
}

int getSymbol(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    else if (c == '*' || c == '/' || c == '%') {
        return 2;
    }
    return -1;
}

string InToPost(const string& expression) {
    string postfix;
    stack<char> stk;
    for (char c : expression) {
        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(' || c == '{' || c == '[') {
            stk.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            while (!stk.empty() && stk.top() != '(' && stk.top() != '{' && stk.top() != '[') {
                postfix += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else {
            while (!stk.empty() && stk.top() != '(' && stk.top() != '{' && stk.top() != '[' && getSymbol(c) <= getSymbol(stk.top())) {
                postfix += stk.top();
                stk.pop();
            }
            stk.push(c);
        }
    }
    while (!stk.empty()) {
        postfix += stk.top();
        stk.pop();
    }
    return postfix;
}
