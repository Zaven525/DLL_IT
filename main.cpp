#include <iostream>
#include <cassert>
#include "list.hpp"

int main()
{
    std::cout << "===== Constructor + push_back =====\n";
    List<int> lst;

    for(int i = 1; i <= 5; i++)
        lst.push_back(i);

    for(auto x : lst)
        std::cout << x << " ";
    std::cout << "\n";

    assert(lst.Size() == 5);
    assert(lst.front() == 1);
    assert(lst.back() == 5);

    std::cout << "===== push_front =====\n";
    lst.push_front(100);
    lst.push_front(200);

    for(auto x : lst)
        std::cout << x << " ";
    std::cout << "\n";

    std::cout << "===== insert single =====\n";
    auto it = lst.begin();
    ++it; // second position
    lst.insert(it, 999);

    for(auto x : lst)
        std::cout << x << " ";
    std::cout << "\n";

    std::cout << "===== insert multiple =====\n";
    lst.insert(lst.begin(), 3, 7);

    for(auto x : lst)
        std::cout << x << " ";
    std::cout << "\n";

    std::cout << "===== erase single =====\n";
    auto er = lst.begin();
    ++er;
    lst.erase(er);

    for(auto x : lst)
        std::cout << x << " ";
    std::cout << "\n";

    std::cout << "===== erase range =====\n";
    auto first = lst.begin();
    auto last = lst.begin();
    ++last; ++last;

    lst.erase(first, last);

    for(auto x : lst)
        std::cout << x << " ";
    std::cout << "\n";

    std::cout << "===== Iterators test =====\n";
    for(List<int>::iterator i = lst.begin(); i != lst.end(); ++i)
        std::cout << *i << " ";
    std::cout << "\n";

    std::cout << "===== Const iterator test =====\n";
    const List<int>& cref = lst;

    for(List<int>::const_iterator i = cref.cbegin(); i != cref.cend(); ++i)
        std::cout << *i << " ";
    std::cout << "\n";

    std::cout << "===== Reverse iterator =====\n";
    for(auto it2 = lst.rbegin(); it2 != lst.rend(); ++it2)
        std::cout << *it2 << " ";
    std::cout << "\n";

    std::cout << "===== Pop tests =====\n";
    lst.pop_back();
    lst.pop_front();

    for(auto x : lst)
        std::cout << x << " ";
    std::cout << "\n";

    std::cout << "===== Copy constructor =====\n";
    List<int> copy_lst = lst;

    for(auto x : copy_lst)
        std::cout << x << " ";
    std::cout << "\n";

    std::cout << "===== Assignment operator =====\n";
    List<int> assign_lst;
    assign_lst.push_back(555);
    assign_lst = lst;

    for(auto x : assign_lst)
        std::cout << x << " ";
    std::cout << "\n";

    std::cout << "===== Move constructor =====\n";
    List<int> move_lst = std::move(assign_lst);

    for(auto x : move_lst)
        std::cout << x << " ";
    std::cout << "\n";

    std::cout << "===== Clear =====\n";
    move_lst.clear();
    std::cout << "Empty? " << move_lst.empty() << "\n";

    std::cout << "All tests passed!\n";

    return 0;
}