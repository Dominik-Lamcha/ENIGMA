#ifndef PLUGBOARD_HPP
#define PLUGBOARD_HPP

#include <string>
#include <unordered_map>

class Plugboard {
public:
    explicit Plugboard(const std::string& settings);
    char swap(char in);
private:
    std::unordered_map<char, char> board;
    void validateSettings(const std::string& settings);
};

#endif // PLUGBOARD_HPP
