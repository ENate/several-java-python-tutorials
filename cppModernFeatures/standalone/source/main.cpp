#include "baseclass/BaseClass.h"
#include "baseclass/version.h"
#include "baseclass/DerivedClass.h"

#include <cxxopts.hpp>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace baseclass;
using namespace derivedclass;

auto main(int argc, char** argv) -> int {
  const std::unordered_map<std::string, baseclass::LanguageCode> languages{
      {"en", baseclass::LanguageCode::EN},
      {"de", baseclass::LanguageCode::DE},
      {"es", baseclass::LanguageCode::ES},
      {"fr", baseclass::LanguageCode::FR},
  };

  cxxopts::Options options(*argv, "A program to welcome the world!");

  std::string language;
  std::string name;

  // clang-format off
  options.add_options()
    ("h,help", "Show help")
    ("v,version", "Print the current version number")
    ("n,name", "Name to greet", cxxopts::value(name)->default_value("World"))
    ("l,lang", "Language code to use", cxxopts::value(language)->default_value("en"))
  ;
  // clang-format on

  auto result = options.parse(argc, argv);

  if (result["help"].as<bool>()) {
    std::cout << options.help() << std::endl;
    return 0;
  }

  if (result["version"].as<bool>()) {
    std::cout << "BASECLASS, version " << BASECLASS_VERSION << std::endl;
    return 0;
  }

  auto langIt = languages.find(language);
  if (langIt == languages.end()) {
    std::cerr << "unknown language code: " << language << std::endl;
    return 1;
  }

  baseclass::BaseClass baseClass(name);
  std::cout << baseClass.printMessage(langIt->second) << std::endl;

  //
  derivedclass::DerivedClass dclass(4.5, 3.4);
  derivedclass::DerivedClass dclass1(1.2, 3.4);
  derivedclass::DerivedClass resClass= dclass + dclass1;
  std::cout << "The result is " << resClass << '\n';
  derivedclass::DerivedClass subClass = dclass - dclass1;
  std::cout << "The subtraction is: " << subClass << '\n';
  derivedclass::DerivedClass dclass3(4, 3);
  derivedclass::DerivedClass dclass13(1, 3);
  derivedclass::DerivedClass mulCplx = dclass3 * dclass13;
  std::cout << "Product of 2 complex numbers " << dclass << "and " << dclass13 <<"  is: " << mulCplx << '\n';
  return 0;
}
