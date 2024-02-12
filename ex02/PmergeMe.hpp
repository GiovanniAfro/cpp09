/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:53:27 by gcavanna          #+#    #+#             */
/*   Updated: 2024/02/11 22:01:34 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>
#include <ctime>

class PmergeMe {
private:
    std::vector<int> vec_container;
    std::list<int> list_container;
    double vec_time;
    double list_time;

public:
    PmergeMe(int argc, char **argv);
    void run();

private:
    void displaySequence(const std::vector<int>& sequence);
    void displaySequence(const std::list<int>& sequence);
    void displayTimeDifference(double elapsed_time_seconds);
    void mergeInsertSortVector();
    void mergeInsertSortList();
};

#endif // PMERGEME_HPP
