#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){
    const char *filename = "/opt/slope_parquet_meta.csv";
    ifstream operator_file(filename);

    if (!operator_file.is_open()){
        cout << "Error opening file.";
        exit(1);
    }

    char buffer[512];
    while (!operator_file.eof())
    {
        operator_file.getline(buffer, 512);
        char *p = buffer;
        printf("%s\n", p);
    }
    return 0;
}
