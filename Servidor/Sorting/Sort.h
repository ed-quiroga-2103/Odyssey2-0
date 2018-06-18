//
// Created by estebandcg1999 on 12/06/18.
//

#ifndef ODYSSEY_SERVER_ESTEBAN_SORT_H
#define ODYSSEY_SERVER_ESTEBAN_SORT_H

#include<stdio.h>
#include <string>
#include <vector>


class Sort {

public:

    void swap(std::string* a, std::string* b);

    int partition (std::string arr[], int low, int high);

    void quickSort(std::string arr[], int low, int high);

    template <size_t R, typename C>
    std::vector<size_t> radix_sort(const C& data);
    template <size_t R, typename C, typename P>
    void radix_sort(P& pos, const C& data, size_t digit);
    template <typename E>
    size_t bin(const E& elem, size_t digit);
    std::vector<size_t> radixSort(std::vector<std::string> vector);

    void bubbleSort(std::string arr[], int n);

};


#endif //ODYSSEY_SERVER_ESTEBAN_SORT_H
