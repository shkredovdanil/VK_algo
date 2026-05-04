#include <string>

bool
isBalanced(const std::string &s)
{
    int balance = 0;
    for (char c : s) {
        if (c == '(') {
            balance++;
        } else if (c == ')') {
            balance--;
        }

        if (balance < 0) {
            return false;
        }
    }

    return balance == 0;
}

/*
Мы интерпретируем "(" как +1 и ")" как −1. Префиксная сумма в любой момент — это текущий баланс.
Условия корректности:

    Баланс никогда не должен становиться отрицательным (закрывающих скобок больше, чем открытых).

    Финальный баланс должен быть равен 0.
*/