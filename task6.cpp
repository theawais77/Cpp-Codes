#include <iostream>
using namespace std;
class Container
{
    int *values;
    int capacity;
    int counter;

public:
    Container()
    {
        values = 0;
        capacity = 0;
        counter = 0;
    }

    Container(int c)
    {
        capacity = c;
        values = new int[capacity];
        counter = 0;
    }

    bool isFull()
    {
        if (counter == capacity)
        {
            return true;
        }
        return false;
    }

    void insert(int val)
    {
        if (!isFull())
        {
            values[counter] = val;
            counter++;
        }
    }

    bool search(int val)
    {
        for (int i = 0; i < counter; i++)
        {
            if (values[i] == val)
            {
                return true;
            }
        }
        return false;
    }

    void remove(int val)
    {
        int size = -1;

        for (int i = 0; i < counter; i++) 
        {                                 
            if (values[i] == val)         
            {                             
                size = i;
                break;
            }
        }
        if (size != -1)
        {
            for (int i = size; i < counter - 1; i++)
            {
                values[i] = values[i + 1];
            }
            counter--;
        }
    }

    void Print()
    {
        for (int i = 0; i < counter; i++)
        {
            cout << values[i] << " ";
        }
    }

    ~Container()
    {
        delete[] values;
    }
};
int main()
{
    Container c1;
    int size;
    cout << "Enter The Size of The Array : ";
    cin >> size;
    c1 = Container(size);
    int element;

    for (int i = 0; i < 4; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> element;
        c1.insert(element);
        element = 0;
    }

    cout << "Enter Your Element You Want To Search : ";
    cin >> element;

    if (c1.search(element))
    {
        cout << "Your Element " << element << " exist in Array\n";
    }
    else
    {
        cout << "Your Element " << element << " does not exist in Array\n";
    }

    cout << "Enter Your Element you want To Remove : \n";
    cin >> element;
    c1.remove(element);

    cout << "You Want to Check That Array is Full OR Not\n";
    char is_Array_Full;
    cin >> is_Array_Full;
    if (is_Array_Full == 'Y' || is_Array_Full == 'y')
    {
        if (c1.isFull())
        {
            cout << "Array is Full\n";
        }
        else
        {
            cout << "Array is Not Full\n";
        }
    }
    c1.Print();
}