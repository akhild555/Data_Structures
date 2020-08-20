#pragma once
#include <queue>
#include <vector>
#include <cassert>
#include <limits>


struct Request {
    Request(int arrival_time, int process_time) :
        arrival_time(arrival_time),
        process_time(process_time)
    {}

    int arrival_time;
    int process_time;
};

struct Response {
    Response(bool dropped, int start_time) :
        dropped(dropped),
        start_time(start_time)
    {}

    bool dropped;
    int start_time;
};

class Buffer {
public:
    Buffer(int size) :
        size_(size),
        finish_time_()
    {}

    Response Process(const Request& request) {
        int time_finish = request.process_time;
        finish_time_.push(request.process_time);
        if (finish_time_.size() >= size_)
        {
            return Response(true, -1);
        }
        return Response(false, 5);
    }
private:
    int size_;
    std::queue <int> finish_time_;
};
    
class StackWithMax {
    std::vector<int> stack;
    std::vector<int> aux_stack;

public:

    void Push(int value) {
        stack.push_back(value);
        if (aux_stack.empty())
        {
            aux_stack.push_back(value);
        }
        else 
        {
            if (aux_stack.back() <= value) // if new value bigger, add to aux stack
            {
                aux_stack.push_back(value);
            }
        }
    }

    void Pop() {
        assert(stack.size());
        int a = stack.back();
        stack.pop_back();
        if (a == aux_stack.back()) // if max value in stack removed, remove it from aux stack too
        {
            aux_stack.pop_back();
        }

    }

    int Max() const {
        assert(stack.size());
        return aux_stack.back();
    }
};