#ifndef BASECLASS_H
#define BASECLASS_H

#include <iostream>
#include <string>

namespace baseclass {

  /**  Language codes to be used with the BaseClass class */
  enum class LanguageCode { EN, DE, ES, FR };

  /**
   * @brief A class for saying hello in multiple languages
   */
  class BaseClass {
    std::string name;

  public:
    /**
     * @brief Creates a new greeter
     * @param name the name to greet
     */
    // No args constructor
    BaseClass();
    BaseClass(std::string& name);
    BaseClass(const BaseClass& rhs);
    BaseClass& operator=(const BaseClass& rhs);

    // Move semantis
    BaseClass(BaseClass&& mrhs);
    BaseClass& operator=(BaseClass&& mrhs);

    /**
     * @brief Creates a localized string containing the greeting
     * @param lang the language to greet in
     * @return a string containing the greeting
     */
    std::string printMessage(LanguageCode lang = LanguageCode::EN) const;
  };

}  // namespace inheritance
#endif
