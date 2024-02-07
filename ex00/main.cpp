/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:05:12 by gcavanna          #+#    #+#             */
/*   Updated: 2024/02/07 14:46:57 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Utilizzo: " <<  av[0] << " file_input\n";
        return 1;
    }

    std::ifstream inputFile(av[1]);
    if (!inputFile.is_open())
    {
        std::cerr << "Errore: impossibile aprire il file.\n";
        return 1;
    }

    BitcoinExchange btc;

    if (!btc.loadExchangeRates("exchange_rates.csv"))
    {
        std::cerr << "Errore: impossibile caricare i tassi di cambio. \n";
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::string date;
        double value;
        if (btc.parseLine(line, date, value)) {
            // Calcoliamo il valore dei bitcoin
            double bitcoinValue = btc.calculateBitcoinValue(date, value);
            if (bitcoinValue >= 0) {
                std::cout << date << " => " << value << " = " << bitcoinValue << std::endl;
            } else {
                std::cerr << "Errore: valore non valido.\n";
            }
        } else {
            std::cerr << "Errore: formato di input non valido.\n";
        }
    }

    inputFile.close();
    return 0;
}
 