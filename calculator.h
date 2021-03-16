#pragma once
#include <string>
#include <iostream>
#include <cmath>
#include "Stack.h"

using namespace std;

class Calculator {
 public:
  void ReadExpression() { 
	  getline(cin, tokens);
  }

  int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
  }

  int action(int a, int b, char op) {
    switch (op) {
      case '+':
        return a + b;
      case '-':
        return a - b;
      case '*':
        return a * b;
      case '/':
        return a / b;
      case '^':
        return pow(a, b);
    }
  }
  
  int calculate() {
    int i;
    Stack<int> values;
    Stack<char> ops;
    string operators = "*/+-^()";
    for (int i = 0; i < tokens.size(); ++i) {
      if (operators.find(tokens[i]) != string::npos) {
        tokens.insert(i, " ");
        tokens.insert(i + 2, " ");
        i += 2;
      }
    }

    for (i = 0; i < tokens.length(); i++) {
      if (tokens[i] == ' ')
        continue;
      else if (tokens[i] == '(') {
        ops.push(tokens[i]);
      } else if (isdigit(tokens[i])) {
        int val = 0;
        while (i < tokens.length() && isdigit(tokens[i])) {
          val = (val * 10) + (tokens[i] - '0');
          i++;
        }

        values.push(val);
      }

      else if (tokens[i] == ')') {
        while (!ops.empty() && ops.top() != '(') {
          int val2 = values.top();
          values.pop();

          int val1 = values.top();
          values.pop();

          char op = ops.top();
          ops.pop();

          values.push(action(val1, val2, op));
        }
        if (!ops.empty()) ops.pop();
      } else if (operators.find(tokens[i]) != string::npos) {
        while (!ops.empty() && priority(ops.top()) >= priority(tokens[i])) {
          int val2 = values.top();
          values.pop();

          int val1 = values.top();
          values.pop();

          char op = ops.top();
          ops.pop();

          values.push(action(val1, val2, op));
        }
        ops.push(tokens[i]);
      } else {
        cout << "Incorrect expression\n";
        return 0;
      }
    }
    while (!ops.empty()) {
      int val2 = values.top();
      values.pop();

      int val1 = values.top();
      values.pop();

      char op = ops.top();
      ops.pop();

      values.push(action(val1, val2, op));
    }
    return values.top();
  }

  string get_expression() const { return tokens; }
  void set_expression(string str) { tokens = str; }

 private:
   string tokens;
};
