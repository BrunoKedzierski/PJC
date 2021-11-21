//
// Created by bruno on 09.06.2021.
//

#include <set>
#include <algorithm>
#include <map>

#ifndef PJATXT2_LEGAL_FLAGS_H
#define PJATXT2_LEGAL_FLAGS_H


namespace pjatxt_driver{


    /**
    * global variable map containing aliases and their respective flags
    */
    const std::map<std::string, std::string> alias_flags = {{"--file","-f"},
                                                      {"--newlines","-n"},
                                                      {"--digits","-d",},
                                                      { "--numbers","-dd"},
                                                      { "--chars","-c"},
                                                      { "--words","-w"},
                                                      { "--sorted","-s"},
                                                      { "--reverse-sorted","-rs"},
                                                      { "--by-length","-l"},
                                                      { "--anagrams","-a"},
                                                      { "--output","-o"},
                                                      { "--palindromes","-p"},
                                                      { "--input","-i"},
                                                      { "--upper","-tu"},

                                                      };

    /**
    * Set of all accepted flags and aliases
    */
    std::set<std::string> valid_flags {"-f","--file",
                                       "-n","--newlines",
                                       "-d","--digits",
                                       "-dd","--numbers",
                                       "-c","--chars",
                                       "-w","--words",
                                       "-s","--sorted",
                                       "-rs","--reverse-sorted",
                                       "-l","--by-length",
                                       "-a","--anagrams",
                                       "-o","--output",
                                       "-p","--palindromes",
                                       "-i","--input",
                                       "--upper","-tu"};

    /**
   * Set of all flags that require arguments
   */
    std::set<std::string> valid_arg_flags {"-f","--file",
                                           "-a","--anagrams",
                                           "-p","--palindromes",
                                           "-o","--output",
                                           "-i","--input"};
    /**
   * Set of all flags that do not require arguments
   */
    std::set<std::string> valid_non_flags {"-n","--newlines",
                                           "-m","--maxchar",
                                           "-l","--by-length",
                                           "-d","--digits",
                                           "-dd","--numbers",
                                           "-c","--chars",
                                           "-w","--words",
                                           "-s","--sorted",
                                           "-rs","--reverse-sorted",
                                           "--upper","-tu"};
    /**
   * Set of all flags that should only occur once
   */
    std::set<std::string> singular_flags {"-f","--file",
                                          "-a","--anagrams",
                                          "-o","--output",
                                          "-i","--input"};
    /**
   * Set of all flags that should only occur at the end
   */
    std::set<std::string> last_flags {"-p","--palindromes",
                                      "-a","--anagrams",
                                      };


    /**
    * Checks if a container of type T contains a string
    * @param container - container of type T
    * @param str - string to look for
    * @return true if str is present else false
    */
    template<typename T>
    bool is_in(const T& container, std::string str){


        return std::find(container.begin(), container.end(), str) != container.end();

    }

    /**
    * Checks if a container of type T contains a string more than once
    * @param container - container of type T
    * @param str - string to look for
    * @return true if str is present more than once else false
    */
    template<typename T>
    bool is_in_multiple(const T& container, const std::string& str){

        int counter = 0;
        for( const auto& el : container){

            if(el == str)
                counter ++;
        }


      return counter> 1;

    }

}

#endif //PJATXT2_LEGAL_FLAGS_H
