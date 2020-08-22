#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include "classes.h"




int isBalanced(std::string text);

int main_with_large_stack_space();

std::vector <Request> ReadRequests();

std::vector <Response> ProcessRequests(const std::vector <Request>& requests, Buffer* buffer);

void PrintResponses(const std::vector <Response>& responses);

void stackMax();

void max_sliding_window_naive(std::vector<int> const& A, int w);

void max_sliding_window_fast(std::vector<int> const& A, int w);