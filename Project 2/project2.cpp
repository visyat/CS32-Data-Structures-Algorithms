//  main.cpp
//  Project2 - Recursion
//
//  Created by Vishal Yathish on 10/14/23.
//

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

//Returns the remainder of two positive integers, m and n
int modulo( unsigned int m, unsigned int n )
{
    
    int div = m/n;
    if (div != 0)
    {
        m = m - div*n;
        modulo (m,n);
    }
    return m;
}

//Returns the number of occurrences of the value d (single-digit number) found in the parameter number.
int occurrences( int number, int d )
{
    //int output = 0;
    
    if (number == 0)
        return 0;
    else
    {
        int curr_digit = modulo(number, 10);
        if (curr_digit == d)
            return 1+occurrences(number/10, d);
        else
            return occurrences(number/10, d);
    }
}

//Returns a string where repeated matching characters in the value s get separated by the string "77".

/*bool checkMatch(string s)
{
    bool output = false;
    for (int i = 0; i < s.length()-1; i++)
    {
        if (s[i]==s[i+1])
            output = true;
    }
    return output;
}*/

string lucky7s( string s )
{
    //BASE CASE: if the function gets to the very end of the string
    if (s=="")
        return s;
    //RECURSIVE CASE
    else
    {
        string str0(1, s[0]); //takes the first char of the string & turns it into a string for concatenation
        if (s[0]==s[1])
            return str0+"77"+lucky7s(s.substr(1));
        else
            return str0+lucky7s(s.substr(1));
    }
}

//Returns true if the total of any combination of elements in the array parameter equals the target value.

/*bool targetInArr (int array[], int size, int target)
{
    bool output = false;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == target)
            output = true;
    }
    return output;
}

int sumOfArr (int array[], int size)
{
    int output = 0;
    for (int i = 0; i < size; i++)
        output += array[i];
    return output;
}
 
 void fillArr (int array1[], int array2[], int size, int index)
 {
     for (int i = 0; i < size; i++)
     {
         if (i == index)
             array2[i] = 0;
         else
             array2[i] = array1[i];
     }
 }
 */

/*void findAllSums (int array[], int size, vector<int> allSums, int counter = 0)
{
    cout << "counter = " <<  counter << endl;
    if (counter == size-1)
    {
        cout <<"sum = " << sumOfArr(array,size) << endl;
        allSums.push_back(sumOfArr(array, size));
    }
    else
    {
        int array2[size]; //Has a 0 in place of array[counter]
        fillArr(array, array2, size, counter);
        
        counter = counter + 1;
        
        findAllSums(array2, size, allSums, counter);
        findAllSums(array, size, allSums, counter);
    }
}

void printArr (vector<int> v)
{
    cout << "[";
    for (int i = 0; i < v.size(); i++)
        cout << v.at(i) << ",";
    cout << "]" << endl;
}*/

bool combinations (int array[], int size, int target)
{
    //BASE CASE #1: if the method reaches the front of the array
    if (size == 0)
    {
        if (target == 0)
            return true;
        else
            return false;
    }
    //BASE CASE #2: if the initial target is equal to 0, but no recursion has occurred
    else if (target == 0 && size == sizeof(array))
        return false;
    //RECURSIVE CASE
    else
    {
        //CALL 1: if the last element is included in the combination that has the target
        bool b1 = combinations(array, size-1, target-array[size-1]); //If the last element is part of the target
        //CALL 2: if the last element is not included in the combination
        bool b2 = combinations(array, size-1, target); //If the last element is not part of the target
        
        //if either of the results is true, then the function should return true.
        return (b1 || b2);
    }
}

int main()
{
    // test code
    assert( modulo( 100, 10 ) == 0 );
    assert( modulo( 1, 13 ) == 1 );
    assert( modulo( 12, 5 ) == 2 );
    assert( modulo( 33, 6 ) == 3 );
    
    assert( occurrences( 567, 2 ) ==  0 );
    assert( occurrences( 128874, 2 ) == 1 );
    assert( occurrences( 212121, 2 ) == 3 );
    assert( occurrences(123456789, 0) == 0);
    assert( occurrences(0, 0) == 0);
    
    assert( lucky7s( "cs32" ) == "cs32" );
    assert( lucky7s( "Apple Baseball" ) == "Ap77ple Basebal77l" );
    assert( lucky7s( "abbba" ) == "ab77b77ba" );
    assert( lucky7s("allloo") == "al77l77lo77o");

    int array[ 5 ] = { 2, 4, 6, 8, 10 };
    
    assert( combinations( array, 5, 10 ) == true );
    assert( combinations( array, 5, 18) == true );
    assert( combinations( array, 5, 15 ) == false );
    
    int array2[10] = {7,6,4,1,5,9,2,8,3,10};
    assert (!combinations(array2,8,0));
    
    assert (combinations(array2,10,8));
    assert (combinations(array2,10,13));
    assert (!combinations(array2,10,56));

    cout << "All tests passed!" << endl;
    return( 0 );
}

