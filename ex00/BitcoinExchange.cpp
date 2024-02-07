/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:16:56 by gcavanna          #+#    #+#             */
/*   Updated: 2024/02/07 14:46:59 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    _exchangeRates = other._exchangeRates;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _exchangeRates = other._exchangeRates;
    return *this;
}

bool BitcoinExchange::loadExchangeRates(const std::string& filename)
{
    std::ifstream file(filename.c_str());

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::istringstream iss(line);
            std::string date;
            std::string rateStr;
            if (std::getline(iss, date, ',') && std::getline(iss, rateStr))
            {
                try
                {
                    double rate = std::stod(rateStr);
                    _exchangeRates[date] = rate;
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
        }
        file.close();
        return true;
    }
    return false;
} 

bool BitcoinExchange::parseLine(const std::string& line, std::string& date, double& value)
{
    std::istringstream iss(line);
    std::string token;

    if (std::getline(iss, token, '|'))
    {
        date = token;
        if (std::getline(iss, token, '|'))
        {
            try
            {
                value = std::stod(token);
                return (value >= 0 && value <= 1000);
            }
            catch(const std::exception& e)
            {
                return false;
            }
            
        }
    }
    return false;
}

double BitcoinExchange::calculateBitcoinValue(const std::string& date, double value)
{
    std::string closestDate = findClosetDate(date);
    double exchangeRate = _exchangeRates[closestDate];

    if (exchangeRate != 0)
        return value * exchangeRate;
    return -1;
}

std::string BitcoinExchange::findClosetDate(const std::string& date)
{
    std::map<std::string, double>::iterator it = _exchangeRates.lower_bound(date);
    if (it == _exchangeRates.begin())
        return it -> first;
    else if (it == _exchangeRates.end())
        return std::prev(it)->first;
    else
    {
        std::map<std::string, double>::iterator prev = std::prev(it);
        return (date.compare(it->first) - date.compare(prev->first) < 0) ? it->first : prev->first;
    }
}