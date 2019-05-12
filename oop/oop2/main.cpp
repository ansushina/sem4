#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    List<int> list1;
    int arr[10] = {1,2,3,4,5,6,7};
    List<int> list2(arr,10);
    List<int> list3(list2);
    if (list2 == list3)
        std::cout<<"==";
    if (list1 != list3)
        std::cout<<"!=";
    list1 = list3;
    if (list1 == list3)
        std::cout<<"==";
    list1 += 1;
    list3 = list2 + 2;

    if (list3.is_empty())
        cout<<"empty";
    else
        cout<<"notempty";
    cout<<list3.first();
    cout<<list3.last();
    cout<<list3.pop_front();
    list3.push_back(3);
    list3.push_front(2);

    auto end = list3.end();
    for(auto it = list3.begin(); it != list3.end(); ++it)
    {
        int i = *it;
        auto is = it.operator ->();
        cout << i << endl;
    }
    list_iterator<int> is = list3.begin();

    return 0;
}
