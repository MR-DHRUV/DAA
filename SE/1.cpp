#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int countLinesOfCode(const string &filename)
{
    ifstream file(filename);
    string line;
    int count = 0;
    bool insideSingleLineComment = false;
    bool insideMultiLineComment = false;
    while (getline(file, line))
    {
        bool lineContainsCode = false;
        // Check for lines starting with '#'
        if (!line.empty() && line[0] == '#')
        {
            continue;
        }
        for (int i = 0; i < line.size(); i++)
        {
            if (!insideSingleLineComment && !insideMultiLineComment)
            {
                // Check for single-line comment
                if (line[i] == '/' && i + 1 < line.size() && line[i + 1] == '/')
                {
                    break;
                }
                // Check for multi-line comment start
                if (line[i] == '/' && i + 1 < line.size() && line[i + 1] == '*')
                {
                    insideMultiLineComment = true;
                    i++;
                    continue;
                }
            }
            else if (insideMultiLineComment)
            {
                // Check for multi-line comment end
                if (line[i] == '*' && i + 1 < line.size() && line[i + 1] == '/')
                {
                    insideMultiLineComment = false;
                    i++;
                    continue;
                }
            } // Check if the character is a code character
            if (!insideSingleLineComment && !insideMultiLineComment && line[i] != ' ' &&
                line[i] != '\t')
            {
                lineContainsCode = true;
                break;
            }
        }
        if (lineContainsCode)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    string filename = "SampleProgram.cpp";
    int lineCount = countLinesOfCode(filename);
    cout << "The Program contains " << lineCount << "lines of code." << endl;
    return 0;
}