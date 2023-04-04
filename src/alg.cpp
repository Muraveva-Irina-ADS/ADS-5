// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int getPrior(char c) {
    switch (c) {
    case '(':
        return 0;
    case ')':
        return 1;
    case '+':
        return 2;
    case '-':
        return 2;
    case '*':
        return 3;
    case '/':
        return 3;
    default:
        return -1;
    }
}

int len(std::string str) {
    char ch = str[0];
    int res = 0;
    while (ch != '\0')
        ch = str[++res];
    return res;
}

int toInt(char ch) {
    char key[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < 10; i++) {
        if (ch == key[i])
            return i;
    }
}

std::string infx2pstfx(std::string inf) {
    Tstack<char> st;
    std::string result;
    char tmp;
    int i = 0;
    char ch = inf[0];
    while (ch != '\0') {
        if (ch >= '0' && ch <= '9')
            result = result + ch + " ";
        else {
            if (ch == ')') {
                if (!st.isEmpty()) {
                    tmp = st.pop();
                    while (tmp != '(') {
                        result = result + tmp + " ";
                        tmp = st.pop();
                    }
                }
            }
            else if ((st.isEmpty()) || ch == '(' || getPrior(ch) > getPrior(st.get())) {
                st.push(ch);
            }
            else if ((!st.isEmpty()) && (getPrior(ch) <= getPrior(st.get()))) {
                while ((!st.isEmpty()) && (getPrior(ch) <= getPrior(st.get()))) {
                    tmp = st.pop();
                    result = result + tmp + " ";
                }
                st.push(ch);
            }
        }
        i++;
        ch = inf[i];
    }
    while (!st.isEmpty()) {
        tmp = st.pop();
        if (st.isEmpty()) result = result + tmp;
        else
            result = result + tmp + " ";
        }
    return result;
}

int eval(std::string pref) {
    Tstack <int> st1;
    char c = pref[0];
    int a, b, i = 0, count = len(pref);
    while (count) {
        if (c != ' ') {
            if ((c >= '0') && (c <= '9'))
                st1.push(toInt(c));
                else {
                    if (!st1.isEmpty()) {
                        a = st1.pop();
                        b = st1.pop();
                        if (c == '+') st1.push(a + b);
                        if (c == '-') st1.push(a - b);
                        if (c == '*') st1.push(a * b);
                        if (c == '/') st1.push(a / b);
                }
            }
        }
        i++;
        std::cout << c;
        c = pref[i];
        count--;
    }
    return(st1.get());
}
