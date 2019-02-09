#include <iostream>


#include <exception>
#include <string>
#include <vector>

namespace my
{
    struct string : std::string
    {
        explicit string(const char *msg,
                        const std::string::allocator_type &alloc = std::string::allocator_type{}) noexcept try :
                std::string(msg, alloc)
        {
            std::puts(__PRETTY_FUNCTION__);
        } catch (...)
        {
            std::puts(__PRETTY_FUNCTION__);
            std::puts("std::string constructor threw an exception");
            std::terminate();
        }
    };

    template<typename _Tp, typename _Alloc = std::allocator<_Tp> >
    struct vector : std::vector<_Tp, _Alloc>
    {
        explicit vector(std::vector<_Tp> const &v_Tp, const _Alloc &alloc = _Alloc{}) noexcept try :
                std::vector<_Tp>(v_Tp, alloc)
        {
            std::puts(__PRETTY_FUNCTION__);
        } catch (...)
        {
            std::puts(__PRETTY_FUNCTION__);
            std::puts("std::vector<_Tp> constructor threw an exception");
            std::terminate();
        }
    };
}

static const my::string global_string("...");
static const my::vector<std::string> global_vec({"on", "off"}); // still creates issues

int main()
{
    std::cout << global_string << std::endl;
    for (auto const &s : global_vec)
    {
        std::cout << s << ", ";
    }
    std::cout << std::endl;
    return 0;
}