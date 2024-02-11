/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:32:04 by gcavanna          #+#    #+#             */
/*   Updated: 2024/02/11 20:03:31 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        _operands = other._operands;
    return *this;
}

bool RPN::isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

double RPN::applyOperator(double a, double b, char tt)
{
    switch (tt)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
            throw std::invalid_argument("Division by zero");
        return a / b;
    
    default:
        throw std::invalid_argument("Incalid operator");
    }
}

double RPN::calculate(const std::string &expression)
{
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (isdigit(token[0]))
            _operands.push(std::stod(token));
        else if (isOperator(token[0]))
        {
            double operands2 = _operands.top();
            _operands.pop();
            double operands1 = _operands.top();
            _operands.pop();

            double result = applyOperator(operands1, operands2, token[0]);
            _operands.push(result);
        }
        else
            throw std::invalid_argument("Invalid token");
    }

    if (_operands.size() != 1)
        throw std::invalid_argument("Invalid expression");

    return _operands.top();
}
