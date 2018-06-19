//
// Created by estebandcg1999 on 12/06/18.
//

#include "Sort.h"
#include <cstring>

#include<stdio.h>
#include <vector>
#include <numeric>
#include <algorithm>
#include <array>
#include <iostream>

///
/// Intercambia dos valores
///

void Sort::swap(std::string* a, std::string* b)
{
    std::string t = *a;
    *a = *b;
    *b = t;
}

int Sort::partition (std::string arr[], int low, int high)
{
    std::string pivot = arr[high];    // pivote
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (strcmp(arr[j].c_str(),pivot.c_str()) < 0) // Comparador de Strings
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

///
/// Realiza el QuickSort
///

void Sort::quickSort(std::string arr[], int low, int high)
{
    if (low < high)
    {
        //pi es el pivote donde se va a realizar el QuickSort por partes
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

template <typename E>
size_t Sort::bin(const E& elem, size_t digit)
{
    return elem.size() > digit ? size_t(elem[digit]) + 1 : 0;
}

template <size_t R, typename C, typename P>
void Sort::radix_sort(P& pos, const C& data, size_t digit)
{
    using A = std::array<size_t, R + 1>;
    A count = {};
    P prev(pos);

    for (auto i : prev)
        ++count[bin(data[i], digit)];

    A done = {}, offset = {{0}};
    std::partial_sum(count.begin(), count.end() - 1, offset.begin() + 1);

    for (auto i : prev)
    {
        size_t b = bin(data[i], digit);
        pos[offset[b] + done[b]++] = i;
    }
}

struct shorter
{
    template <typename A>
    bool operator()(const A& a, const A& b) { return a.size() < b.size(); }
};

template <size_t R, typename C>
std::vector<size_t> Sort::radix_sort(const C& data)
{
    std::vector<size_t> pos(data.size());
    std::iota(pos.begin(), pos.end(), 0);

    size_t width = std::max_element(data.begin(), data.end(), shorter())->size();

    for (long digit = long(width) - 1; digit >= 0; --digit)
        radix_sort<R>(pos, data, size_t(digit));

    return pos;
}
std::vector<size_t> Sort::radixSort(std::vector<std::string> vector){
    Sort* Sorter = new Sort();
    //std::vector<std::string> vector = {"Samu","Poncio","Xavi Alonso","Maroto","Carlitos","JoseManu46","Gerwin"};
    std::vector<size_t> pos = Sorter->radix_sort<128>(vector);
    return pos;
}

void Sort::bubbleSort(std::string arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (strcmp(arr[j].c_str(),arr[j+1].c_str()) > 0)
                swap(&arr[j], &arr[j+1]);
}