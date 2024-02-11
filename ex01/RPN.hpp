/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:23:04 by gcavanna          #+#    #+#             */
/*   Updated: 2024/02/11 20:11:16 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

class RPN
{
    public:
        RPN();
        RPN(const RPN &other);
        ~RPN();

        RPN& operator=(const RPN &other);
        
        double calculate(const std::string& expression);

    private:
        std::stack<double> _operands;

        bool isOperator(char c);
        double applyOperator(double a, double b, char op);
};

#endif