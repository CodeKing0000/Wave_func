#include <iostream>
#include <string>
#include <regex>
#include <boost/regex.hpp>


// example@mail.com

bool func(std::string email) {
    boost::regex pattern("^[a-zA-Z0-9_.-]+@[a-zA-Z0-9]+\.[a-zA-Z]{2,}$");
    std::cout << boost::regex_match(email, pattern) << std::endl;
    return boost::regex_match(email, pattern);
}

BOOST_AUTO_TEST_CASE(test_normal_division) {
    BOOST_CHECK_EQUAL(func("rwfds-fsdd@dsfdfs.ru"), true);
    BOOST_CHECK_EQUAL(func("rwfds_fsdd@dsfdfs.ru"), true);
    BOOST_CHECK_EQUAL(func("rwfds.fsdd@dsfdfs.ru"), true);
}

int main() {
    std::string email;
    std::boolalpha;
    std::cout << std::boolalpha << "Email:";
    std::cin >> email;
    std::cout << std::endl;

    func(email);
}