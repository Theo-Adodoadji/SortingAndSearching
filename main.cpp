// Homework 3- Sorting and Searching
// CS 1337.010
// This code will generate some number of random numbers. It will ask the user how many numbers to generate, then ask the user how large the random numbers should be,
// March 6th, 2022

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool myvecsort (int i,int j) { return (i<j); }

void showVector(vector<int> v, string s)
{
    cout << s << endl;
    for(int i=0; i < v.size(); i++)
        std::cout << v.at(i) << ' ';
    cout << endl;
    int vsize = v.size();
    int vcapacity = v.capacity();
    cout << "size: " << vsize << endl;
    cout << "capacity: " << vcapacity << endl;
}

int binary_search(vector<int> v, int left, int right, int num)
{
    if(left <= right)
    {
        int pivot = (left + right)/2;
        if(v.at(pivot) == num)
            return pivot;
        if(v.at(pivot) > num)
            return binary_search(v, left, pivot-1, num);
        if(v.at(pivot) < num)
            return binary_search(v, pivot+1, right, num);
    }
    return -1;
}

vector<int> sortedvec2(vector<int> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        for(int j=i+1; j<v.size(); j++)
        {
            if(v.at(j)<v.at(i))
            {
                int temp = v.at(i);
                v.at(i) = v.at(j);
                v.at(j) = temp;
            }
        }
    }
    return v;
}

//create function that stores the number of occurrences of said number
int count(vector<int> v, int num, int idx)
{
    if(idx == -1)
        return 0;
    else
    {
        int ct = 0;
        for(int i = idx; i < v.size(); i++)
        {
            if(v.at(i) == num)
                ct+=1;
        }
        return ct;
    }
   
}

int main()

{

//Asking user for generated random list of numbers.

    cout << "How many numbers do you want to generate:";
    int randomo;
    cin >> randomo;
    cout << "How many large do you want the numbers to be:";
    int maxnum;
    cin >> maxnum;
    if (maxnum < 0 || maxnum > 20)
    {
        cout << "Error. Generate a number more than 0 and less than or equal to 20.\n";
        cin >> maxnum;

    }

// Create an array that create the size of the random numbers.

    int array[randomo];
    for (int i = 0; i < randomo; i++)
        array[i]=1+(rand()%maxnum);

    vector<int> nums;
    for (int i = 0; i < randomo; i++)
        nums.push_back(array[i]);
    string message = "Printing the vector properties";
    showVector(nums, message);

    //copy of vector
    vector<int> nums_copy;
    nums_copy = nums;
    for (int i = 0; i < nums_copy.size(); i++)
        cout << nums_copy.at(i) << ' ';
    cout << endl;
    //sort nums
    sort(nums.begin(), nums.end(), myvecsort);
    for (int i = 0; i < nums.size(); i++)
        cout << nums.at(i) << ' ';
    cout << endl;
    sortedvec2(nums_copy);
    //bubble sorted nums_copy
    for (int i=0; i<nums_copy.size(); i++)
        cout << nums.at(i) << ' ';
    cout << endl;
    for(int i = 1; i <= 3; i++)
    {
        cout << "Enter number to be searched in vector nums: ";
        int num_search;
        cin >> num_search;
        int index = binary_search(nums, 0, nums.size()-1, num_search);
        cout << num_search << " at index " << index << endl;
        int number_occurrences = count(nums, num_search, index);
        cout << num_search << " count: " << number_occurrences;
        cout << endl;
    }
    //search two numbers not in vector so let's do 100 and above
    int num1 = 100;
    int num2 = 200;
    int index1 = binary_search(nums, 0, nums.size()-1, num1);
    int index2 = binary_search(nums, 0, nums.size()-1, num2);
    cout << num1 << " at " << index1 << ' ' << num2 << " at " << index2 << endl;
    //delete duplicates from sorted vectors
    
    return 0;
}

