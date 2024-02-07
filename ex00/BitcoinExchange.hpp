/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:06:18 by gcavanna          #+#    #+#             */
/*   Updated: 2024/02/07 14:46:58 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        ~BitcoinExchange();

        BitcoinExchange& operator=(const BitcoinExchange &other);

        bool loadExchangeRates(const std::string& filename);
        bool parseLine(const std::string& line, std::string& date, double& value);
        double calculateBitcoinValue(const std::string& date, double value);

    private:
        std::map<std::string, double> _exchangeRates;
        std::string     findClosetDate(const std::string& date);
};

#endif 