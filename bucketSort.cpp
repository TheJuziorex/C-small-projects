#include <iostream>
#include <fstream>

using namespace std;

int main(){
    fstream input,output;
    int howMany = 0;
    string lines;

    input.open("input.txt",ios::in);
    output.open("output.txt",ios::out);

    while(getline(input,lines)){
        howMany++;
    }
    output << howMany;
    input.close();
    output.close();
}