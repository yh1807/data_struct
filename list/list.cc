#include "list.h"

List l;

void set_up()
{
    std::cout << "Hello to my List...\n";
    std::cout << "----input the length you need: ";
    int length;
    std::cin >> length;
    std::cout << "----please input the numbers...\n";
    int number;
    for (int i = 0; i < length; ++i) {
        std::cin >> number;
        ListInsert(l, i + 1, number);
    }
    std::cout << "your numbers in List is: \n";
    TraverseList(l);

    bool condition = true;
    char choosen; 
    while (condition)
    {
        std::cout << std::endl;
        std::cout << "----would you want to add a number? (y) or (n)\n";
        std::cin>> choosen;
        switch (choosen)
        {
        case 'y':
        case 'Y':
            std::cout << "----input a index and the number\n";
            int index;
            std::cin >> index >> number;
            ListInsert(l, index, number);
            printf("you add the number %d to the index %d\n", number, index);
            std::cout << "now your numbers in List: \n";
            TraverseList(l);
            break;
        case 'n':
        case 'N':
            std::cout << "thanks to you, good bye!\n";
            condition = false;
            break;
        default:
            std::cout << "----input error, please input again!\n";
            break;
        }
    }
    
    
}

void work_func()
{
    std::cout << "----please input the index for get the number\n";
    int index;
    Elem get_elem = 0;
    std::cin >> index;
    GetElem(l, index, get_elem);  
    printf("the number with index %d is %d\n", index, get_elem);
     
    std::cout << "----to find if the number in the List or not: \n";
    Elem locate_elem;
    std::cin >> locate_elem;
    int return_value = LocateElem(l, locate_elem);
    switch (return_value)
    {
    case 0:
        printf("the number %d is not in it\n", locate_elem);
        break;
    default:
        printf("the number %d is in it, index: %d\n", locate_elem, return_value);
        break;
    }

    std::cout << "find the number's pre_elem\n";
    Elem prior_elem, prior_elem_pre;
    std::cin >> prior_elem;
    return_value =  PriorElem(l, prior_elem, prior_elem_pre);
    if (return_value)
        printf("the number %d's pre_e is %d\n", prior_elem, prior_elem_pre);
}

int main()
{   
    InitList(l);
    set_up();
    work_func();

    return 0;
}