#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

void max_sliding_window_naive(std::vector<int> const& A, int w) {
    for (size_t i = 0; i < A.size() - w + 1; ++i) {
        int window_max = A.at(i);
        for (size_t j = i + 1; j < i + w; ++j)
            window_max = std::max(window_max, A.at(j));

        std::cout << window_max << " ";
    }

    return;
}

void max_sliding_window_fast(std::vector<int> const& A, int w)
{
    std::deque<int> q;

    //get max elements for first window
    for (int i = 0; i < w; i++)
    {
        while ((!q.empty()) && A[q.back()] <= A[i])
        {
            q.pop_back();
        }        
        q.push_back(i);
    }
    
    //get max elements for remaining windows 
    for (size_t i = w; i < A.size(); i++)
    {        
        std::cout << A[q.front()] << std::endl;
        
        while ((!q.empty()) && q.front() <= i - w)
        {
            q.pop_front();
        }

        while ((!q.empty()) && A[q.back()] <= A[i])
        {
            q.pop_back();
        }
        q.push_back(i);   
    }
    std::cout << A[q.front()] << std::endl;
}