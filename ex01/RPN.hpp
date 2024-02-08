/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:23:04 by gcavanna          #+#    #+#             */
/*   Updated: 2024/02/08 18:30:52 by gcavanna         ###   ########.fr       */
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

        RPN& operator= (const RPN &other);
        
        static double evaluate(const std::string& expression);

    private:
        std::stack<double> _operands;

        static bool isOperator(char c);
        static double calulate(double a, double b, char op);
};

#endif