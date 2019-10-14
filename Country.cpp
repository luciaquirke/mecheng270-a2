
#include "Country.hpp"

Country::Country(const string &name, Language language) {
	countryName = name;
	countryLanguage = language;
}

Country::Language Country::getLanguage() const {
    return countryLanguage;
}

std::string Country::getName() const {
    return countryName;
}
