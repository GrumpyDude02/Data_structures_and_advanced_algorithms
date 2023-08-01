#include <iostream>
#include "linked_list.h"


int main(int argc, char** argv)
{
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    std::cout << list[1];
    return 0;
}