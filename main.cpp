#include <iostream>
#include <string>
#include <vector>

const std::vector<std::string> &getValidState()
{
    static const std::vector<std::string> global_vec({"on", "off"});
    return global_vec;
}

int main()
{
    if (!getValidState().empty())
        std::cout << getValidState().front();
    for (auto it = 1u; it<getValidState().size(); ++it)
    {
        std::cout << ", " << getValidState().at(it);
    }
    std::cout << std::endl;
    return 0;
}