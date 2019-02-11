#include <iostream>
#include <string>
#include <vector>

struct Action1{};
struct Action2{};
struct Action3{};

template <typename ActionType>
inline
typename std::enable_if<std::is_same<ActionType, Action1>::value, const std::vector<std::string> &>::type
getValidState()
{
    static const std::vector<std::string> global_vec({"on", "off"});
    return global_vec;
}

template <typename ActionType>
inline
typename std::enable_if<std::is_same<ActionType, Action2>::value, const std::vector<std::string> &>::type
getValidState()
{
    static const std::vector<std::string> validMode = {"off", "manual", "boost"};
    return validMode;
}

template <typename ActionType>
inline
typename std::enable_if<std::is_same<ActionType, Action3>::value, const std::vector<int> &>::type
getValidState()
{
    static const std::vector<int> validMode = {0,1,2};
    return validMode;
}


int main()
{
    if (!getValidState<Action1>().empty())
        std::cout << getValidState<Action1>().front();
    for (auto it = 1u; it<getValidState<Action1>().size(); ++it)
    {
        std::cout << ", " << getValidState<Action1>().at(it);
    }
    std::cout << std::endl;

    if (!getValidState<Action2>().empty())
        std::cout << getValidState<Action2>().front();
    for (auto it = 1u; it<getValidState<Action2>().size(); ++it)
    {
        std::cout << ", " << getValidState<Action2>().at(it);
    }
    std::cout << std::endl;

    if (!getValidState<Action3>().empty())
        std::cout << getValidState<Action3>().front();
    for (auto it = 1u; it<getValidState<Action3>().size(); ++it)
    {
        std::cout << ", " << getValidState<Action3>().at(it);
    }
    std::cout << std::endl;
    return 0;
}