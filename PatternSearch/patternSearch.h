#include <math.h>
#include <string>
#include <iostream>

void naiveStringMatching(std::string text,std::string pattern)
{
    for (int s = 0; s <= text.length() - pattern.length(); s++)
    {
        int i = 0;

        while (text[s+i]==pattern[i] && i<pattern.length())
        {
            i++;
        }
        
        if (i == pattern.length())
        {
            std::cout<<"Znaleziono wzorzec z przesunieciem: "<<s<<"\n";
        }
        
    }
    
}


void RabinKarp(std::string text,std::string pattern)
{
    int textHash = 0;
    int patternHash=0;
    int power = pattern.size()-1;

    for (int i = 0; i < pattern.size(); i++)
    {
        textHash    += pow(2,power) * text[i];
        patternHash +=pow(2,power)*pattern[i];
        power--;
    }
    
    for (int s = 0; s <= text.size()-pattern.size(); s++)
    {
        if (textHash == patternHash)
        {
            int i=0;

            while (i<pattern.size() && text[i+s]==pattern[i])
            {
                i++;
            }
            
            if (i==pattern.size())
            {
                std::cout<<"Znaleziono wzorzec z przesunieciem: "<<s<<"\n";
            }
            
        }
        else if (s < text.size()-pattern.size())
        {
            textHash = (textHash - text[s] * pow(2,pattern.size()-1)) * 2 + text[s+pattern.size()]; 
        }
        
        
    }
    
}

void BoyerMoore(std::string text,std::string pattern)
{
    int *bc = new int[256];
    
    for (int i = 0; i < 256; i++)
    {
        bc[i]=-1;
    }
    
    for (int i = 0; i < pattern.size(); i++)
    {
        int index = pattern[i];
        bc[index] = i;
    }
    

    int s = 0;
    while (s <= text.size() - pattern.size() )
    {
        int j = pattern.size() - 1;

        for (int i = 0; i < pattern.size(); i++)
        {
            if (text[i+s]==pattern[i])
            {
                j--;
            }
        }

        if (j==-1)
        {
            std::cout<<"Znaleziono wzorzec z przesunieciem: "<<s<<"\n";
            s++;
        }
        else
        {
            int nextLetter=text[s+j];

            if (bc[nextLetter]==-1)
            {
                s = s + j + 1;
            }
            else if (bc[nextLetter] < j)
            {
                s = s + j - bc[nextLetter];
            }
            else
            {
                s++;
            }
        }        
    }
}