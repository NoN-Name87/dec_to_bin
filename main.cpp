#include <iostream>
#include <cstring>
#include <regex>

constexpr int NUM_OFFSET = 48;
constexpr int ODD_OFFSET = 5;

std::string dec_to_bin(std::string & n) // for large numbers
{
    std::string binary;
    int odd_previous{0};
    while(!n.empty())
    {
        odd_previous = 0;
        binary += std::to_string((n.back() - NUM_OFFSET) % 2);
        for(auto & i : n)
        {
            char temp = ((i - NUM_OFFSET) / 2 + odd_previous) + NUM_OFFSET;
            odd_previous = ((i - NUM_OFFSET) % 2) * ODD_OFFSET;
            i = temp; 
        }
        if(n.front() == NUM_OFFSET)
            n.erase(n.begin());
    }
    return binary.assign(binary.rbegin(), binary.rend());
}

std::string convert(const std::string & expr)
{
    std::regex regex("([0-9]+)|([^0-9]+)");
    std::sregex_token_iterator token(expr.cbegin(), expr.cend(), regex, 0);
    std::sregex_token_iterator end;
    std::string result;
    while(token != end)
    {
        std::string val = token->str();
        if(std::regex_match(val, std::regex("(-?[0-9]+)")))
        {
            val = dec_to_bin(val); 
        }
        result += val;
        token++;
    }
    return result;
}

int main(int argc, char **argv) //cmd: ./dec_to_bin '<expression>' or ./dec_to_bin '<expr>' '<expr>'...
{
    try
    {
        if(argc > 1)
        {
            std::string expr;
            for(int i = 1; i < argc; i++)
            {
                expr += argv[i];
            }
            std::string result = convert(expr);
            std::cout << result << "\n";
        }
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
}