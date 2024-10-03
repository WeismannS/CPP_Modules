#include <iostream>
#include <fstream>

void replace(std::string &text, const std::string &to_find, const std::string &replace_with)
{
    int pos;
    if (to_find == replace_with)
        return;
    while ((pos = text.find(to_find)) != std::string::npos)
    {
        int end = pos + to_find.size();
        std::string test = text.substr(0, pos);
        std::string full_text = test + replace_with + text.substr(end);
        text = full_text;
    }
}

int main(int ac, char **av)
{
    std::ifstream file(av[1], std::fstream::out | std::fstream::in);
    std::string buffer;
    std::string text = "";
    std::string &s_ref = text;
    if (ac != 4) 
        return (std::cout << "Insert Valid arguments\n",1);
    const std::string &to_find = av[1];
    const std::string &replace_with = av[2];
    while (getline(file, buffer))
    {
        text += buffer + (file.peek() != EOF ? "\n" : "");
        replace(s_ref, to_find, replace_with);
    }
    file.clear();
    std::ofstream write("file.txt");
    write << text;
}