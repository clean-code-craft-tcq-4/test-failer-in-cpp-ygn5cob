#include <iostream>
#include <assert.h>
#include <string.h>
#include <map>

std::map<std::pair<std::string, std::string>, int> colorPairManual;
std::map<std::pair<std::string, std::string>, int> colorPair;

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
            colorPair.insert(std::make_pair(std::make_pair(majorColor[i], minorColor[j]),(i * 5 + j)));
        }
    }
    return i * j;
}

int printColorMapManual() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j+1 << " | " << majorColor[i] << " | " << minorColor[j] << "\n";
            colorPairManual.insert(std::make_pair(std::make_pair(majorColor[i], minorColor[j]),(i * 5 + j+1)));  
        }
    }
    return i * j;
}

bool testColorAlignment()
{
   std::map<std::pair< std::string, std::string >, int >::const_iterator itrm = colorPairManual.begin();
   std::map<std::pair< std::string, std::string >, int >::const_iterator itr = colorPair.begin();
   for(;itr != colorPair.end(); ++itr,++itrm)
   {
    if(itr->second == itrm->second)
        {
            if((itr->first.first).compare(itrm->first.first)== 0)  
            {
                if((itr->first.second).compare(itrm->first.second)== 0){

                    return true;

                }
                else return false;
            
            }
            else return false;

        }
        else return false;

   }
   return true;    
}

int main() {

    std::cout << "Printing colormap manual";
    printColorMapManual();
    std::cout << "Testing the actual implementation";
    int result = printColorMap();
    assert(result == 25);
    bool output = testColorAlignment();
    assert(true == output);
    
    std::cout << "All is well (maybe!)\n";
    return 0;
}