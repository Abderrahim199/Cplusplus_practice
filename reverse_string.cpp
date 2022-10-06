
// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;


void swap(std::string& str, int index1,int index2){
    char holder = str[index1];
    str[index1]= str[index2];
    str[index2]=holder;
}
void reverse(string& str)
{
    int size = str.length();
    if (size <=1){
        return;
    }
    else {
        int lastIndex = (size%2) ? size/2 : (size-1)/2;
        for(int i=0;i<=lastIndex;i++){
            swap(str,i,size-i-1);
        }
    }
}



// here is a simpler and better way:
void reverse(string& str)
{
    if (str.empty()) {
        return;
    }

    size_t leftIndex = 0;
    size_t rightIndex = str.length() - 1;

    while (leftIndex < rightIndex) {
        // swap characters
        swap(str[leftIndex], str[rightIndex]);

        // move towards middle
        ++leftIndex;
        --rightIndex;
    }
}
















// tests

const lest::test tests[] = {
        {CASE("empty string") {
            const string expected;
            string actual;
            reverse(actual);
            EXPECT(actual == expected);
        }},
        {CASE("single character string") {
            const string expected("A");
            string actual("A");
            reverse(actual);
            EXPECT(actual == expected);
        }},
        {CASE("longer string") {
            const string expected("EDCBA");
            string actual("ABCDE");
            reverse(actual);
            EXPECT(actual == expected);
        }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}