#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char **argv)
{
    fstream file;
    fstream new_file;
    string filename;
    string line;
    string text = "";
    size_t pos;

    if (argc != 4)
        return (cout << "Wrong number of arguments." << endl, 0);
    filename = string(argv[1]) + ".replace";
    file.open(argv[1], ios::in);
    if (!file.is_open())
        return (cout << "No such file." << endl, 0);
    else
    {
        while(getline(file, line))
        {
            pos = (line.find(argv[2], 0, string(argv[2]).length()));
            while (pos != string::npos)
                {
                    line.erase(pos, string(argv[2]).length());
                    line.insert(pos, argv[3]);
                    pos = (line.find(argv[2], pos + string(argv[3]).length(), string(argv[2]).length()));
                }
            text = text + line + "\n";
        }
    }
    file.close();
    new_file.open(filename.c_str(), ios::out);
    if (!new_file.is_open())
        return (cout << "No such file." << endl, 0);
    else
        new_file << text;
    new_file.close();
    return (0);
}