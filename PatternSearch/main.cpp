#include <string>
#include "patternSearch.h"

using namespace std;


int main()
{
    string t = "abcabcaaaaabc";
    string p = "abc";

    std::cout<<"Naive: \n";
    naiveStringMatching(t,p);
    std::cout<<"\nRabinKarp: \n";
    RabinKarp(t,p);
    std::cout<<"\nBoyerMoore: \n";
    BoyerMoore(t,p);
}