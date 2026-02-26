#include "list.hpp"

int main()
{
    List<int> l1(2, 1);
    List<int> l2(3, 4);
    
    l2 = l1;
    l2.print_list();
    return 0;
}