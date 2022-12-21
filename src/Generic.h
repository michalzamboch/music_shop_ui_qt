#ifndef GENERIC_H
#define GENERIC_H

#include <vector>
#include <string>

std::vector<std::string> tokenize(std::string s, std::string del = " ")
{
    int start = 0;
    int end = s.find(del);

    std::vector<std::string> columns;

    while (end != -1) {
        columns.push_back(s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
    }
    columns.push_back(s.substr(start, end - start));

    return columns;
}

std::string addEnters(std::string s, unsigned long count)
{
    auto words = tokenize(s);
    std::string res = "";

    for (unsigned long i = 0; i < words.size(); i++)
    {
        res += words.at(i) + " ";
        if (((i + 1) % count) == 0)
        {
            res += "\n";
        }
    }

    words.clear();
    return res;
}

std::string connectVector(std::vector<std::string> vec)
{
    std::string result = "";
    for (auto &x : vec)
    {
        result += x + "\n";
    }
    return result;
}


#endif // GENERIC_H
