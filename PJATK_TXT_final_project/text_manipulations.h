//
// Created by Bruno on 05.06.2021.
//
#include <fstream>
#include <algorithm>
#include <ios>
#include <set>
#include <sstream>
#include "legal_flags.h"
#include <iomanip>
#include "chrono"

#ifndef PJATXT2_TEXT_MANIPULATIONS_H
#define PJATXT2_TEXT_MANIPULATIONS_H


namespace pjatxt_driver {

/**
 * Checks if a string contains another string
 * @param line -string to look in.
 * @param word -string to look for
 * @return true if found else false.
 */
    bool line_contains_word(const std::string &line, const std::string &word) {
        return line.find(word) != std::string::npos;
    }

/**
 * Returns a copy of a string with all letters in upper case
 * @param s1 -string to copy and modify.
 * @return returns a copy of the given string.
 */
    std::string to_upper_case(std::string s1) {

        for_each(s1.begin(), s1.end(),
                 [](char &c1) {

                     c1 = std::toupper(c1);

                 });

        return s1;


    }

/**
 * Checks if a string is a palindrome
 * @param s1 - string to be checked
 * @return true if string is palindrome else false.
 */
    bool is_palindrome(std::string s1) {

        if (std::equal(s1.begin(), s1.begin() + s1.size() / 2, s1.rbegin()))
            return true;
        else
            return false;
    }


/**
 * Gets all unique words form from an ifstream ( words separated by whitespace)
 * @param file - reference to a ifstream
 * @return set of unique words.
 */
    std::set<std::string> get_uniqe_set_from_file(std::ifstream &file) {

        auto uniq_words = std::set<std::string>();
        for (std::string s = std::string(); file >> s;) {

            uniq_words.insert(s);

        }

        return uniq_words;


    }

/**
 * checks if two string are anagrams
 * @param s1 - first string to be checked
 * @param s2 - second string
 * @return true if string are anagrams else false.
 */

    bool is_anagram(std::string s1, std::string s2) {

        if (s1.length() != s2.length())
            return false;

        std::sort(s1.begin(), s1.end());
        std::sort(s2.begin(), s2.end());

        return s1 == s2;


    }

/**
 * Resets ifstream index so that it points to the begining of the file
 * @param file - reference to an ifstream
 * @return void
 */
    void reset_read_index(std::ifstream &file) {
        file.clear();
        file.seekg(0, std::ios::beg);


    }

/**
 * Compares two characters ignoring thier case size
 * @param c1 - first char
 * @param c2 - second char
 * @return true if c1 jest before c2 else false
 */
    bool ignore_case_comparator(char c1, char c2) {

        return std::tolower(c1) < std::tolower(c2);

    }

/**
 * Sorts vector of string based on an case insenstive comparator
 * @param v - refernce to vector that is to be sorted
 * @return void
 */
    void case_insensitive_string_vector_sort(std::vector<std::string> &v) {

        std::sort(v.begin(), v.end(), [](auto c1, auto c2) {

            return std::lexicographical_compare(c1.begin(), c1.end(), c2.begin(), c2.end(), ignore_case_comparator);

        });

    }

/**
 * Compares two words based on thier length
 * @param s1 - first string to compare
 * @param s2 - second string to compare
 * @return true if s1 is shorter than s2 else false
 */

    bool word_lenght_comparator(const std::string &s1, const std::string &s2) {

        return s1.length() < s2.length();

    }

/**
 * Sorts vector of strings by lenght
 * @param v - reference to vector
 * @return void
 */
    void string_lenght_sort(std::vector<std::string> &v) {

        std::sort(v.begin(), v.end(), [](auto c1, auto c2) {

            return word_lenght_comparator(c1, c2);

        });


    }

/**
 * Checks if char is a digit
 * @param c - char to be checked
 * @return true if c is a digit else false
 */
    bool is_digit(const char c) {

        if ((int) c >= 48 && (int) c <= 57) {
            return true;
        } else
            return false;

    }

/**
 * Counts number of lines ina file and sends the count to ostream
 * @param file - reference to ifstream to read from
 * @param out - reference to ostream to send output to
 * @return void
 */
    void count_lines(std::ifstream &file, std::ostream &out) {

        int counter = 0;

        for (std::string s = std::string(); std::getline(file, s);) {
            counter++;
        }
        std::cout << "Lines: ";
        out << counter << "\n";
        reset_read_index(file);
    }

/**
 * Counts numbers in a file and sends the count to ostream
 * @param file - reference to ifstream to read from
 * @param out - reference to ostream to send output to
 * @return void
 */
    void count_numbers(std::ifstream &file, std::ostream &out) {

        int counter = 0;

        for (std::string s = std::string(); file >> s;) {

            if (s[0] == '.')
                continue;
            if (s[0] == '-')
                s.erase(s.begin());


            auto iter = std::find(s.begin(), s.end(), '.');
            if (iter != s.end()) {
                s.erase(iter);
            }


            auto flag = std::all_of(s.begin(), s.end(),
                                    [](const char c) {

                                        return is_digit(c);

                                    });

            if (flag) {
                counter++;

            }

        }
        out << "Numbers: ";
        out << counter << "\n";
        reset_read_index(file);
    }


/**
 * Counts words in a file and sends the count to ostream
 * @param file - reference to ifstream to read from
 * @param out - reference to ostream to send output to
 * @return void
 */
    void count_words(std::ifstream &file, std::ostream &out) {

        int counter = 0;
        for (std::string s = std::string(); file >> s;) {
            counter++;
        }
        out << "Words: ";
        out << counter << "\n";
        reset_read_index(file);

    }

/**
 * Counts characters in a file and sends the count to ostream
 * @param file - reference to ifstream to read from
 * @param out - reference to ostream to send output to
 * @return void
 */

    void count_characters(std::ifstream &file, std::ostream &out) {


        int counter = 0;
        char c;
        while (file.get(c)) {

            counter++;

        }
        out << "Characters: ";
        out << counter << "\n";

        reset_read_index(file);


    }

/**
 * Prints ordered list of words from a file to ostream
 * @param file - reference to ifstream to read from
 * @param out - reference to ostream to send output to
 * @param lenght - if true sorts by lenght
 * @param reversed - if true the sort is reversed
 * @return void
 */
    void show_ordered_words(std::ifstream &file, bool lenght, bool reversed, std::ostream &out) {
        auto words = std::vector<std::string>();
        for (std::string s = std::string(); file >> s;) {
            words.push_back(s);
        }


        if (lenght) {
            string_lenght_sort(words);
        } else
            case_insensitive_string_vector_sort(words);


        if (reversed) {
            std::reverse(words.begin(), words.end());
        }
        out << "Ordered words: ";
        for (const auto &word : words) {

            out << word << " ";

        }
        out << "\n";
        reset_read_index(file);


    }


/**
 * Counts digits in a file and sends the count to ostream
 * @param file - reference to ifstream to read from
 * @param out - reference to ostream to send output to
 * @return void
 */
    void count_digits(std::ifstream &file, std::ostream &out) {
        int counter = 0;
        char c;
        while (file.get(c)) {
            if (is_digit(c)) {
                counter++;
            }

        }
        out << "Digits: ";
        out << counter << "\n";
        reset_read_index(file);

    }

/**
 * Prints these words passed to the function, that are anagrams
 * of the words in the file
 * @param file - reference to ifstream to read from
 * @param out - reference to ostream to send output to
 * @param words - string containing words to check
 * @return void
 */
    void show_anagrams(std::ifstream &file, std::ostream &out, std::string &words) {

        auto uniq_words = get_uniqe_set_from_file(file);

        auto ss = std::stringstream(words);
        out << "Anagrams: ";
        for (std::string word_line; ss >> word_line;) {

            for (const auto &el: uniq_words) {

                if (is_anagram(el, word_line)) {
                    out << el << " ";

                }

            }

        }
        out << "\n";

        reset_read_index(file);

    }

/**
 * Prints these words passed to the function, that are palindromes
 * and are present in the file
 * @param file - reference to ifstream to read from
 * @param out - reference to ostream to send output to
 * @param words - string containing words to check
 * @return void
 */
    void show_palindromes(std::ifstream &file, std::ostream &out, std::string &words) {

        auto uniq_words = get_uniqe_set_from_file(file);
        std::for_each(uniq_words.begin(), uniq_words.end(),
                      [&out, &words](auto &str) {
                          out << "Palindromes: ";
                          if (is_palindrome(str) && line_contains_word(words, str))
                              out << str << " ";

                      });
        out << "\n";
        reset_read_index(file);
    }


/**
 * Prints all words from file in upper case
 * @param file - reference to ifstream to read from
 * @param out - reference to ostream to send output to
 * @return void
 */
    void show_upper_case(std::ifstream &file, std::ostream &out) {
        out << "Words in upper case:";
        for (std::string s = std::string(); file >> s;) {
            auto upper = to_upper_case(s);

            out << " " << upper;
        }
        out << "\n";
        reset_read_index(file);

    }

/**
 * Print the manual for the program
 */
    void print_help() {

        std::cout << "                   PJAtxt2 Help                " << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << std::left << std::endl;
        std::cout << std::setw(15) << "-f <--file> [path]" << "             " << std::setw(15) << "file read path"
                  << std::endl;
        std::cout << std::setw(15) << "-n <--newlines>" << "                " << std::setw(15) << "number of lines"
                  << std::endl;
        std::cout << std::setw(15) << "-c <--chars>" << "                " << std::setw(15) << "number of characters"
                  << std::endl;
        std::cout << std::setw(15) << "-d <--digits>" << "                " << std::setw(15) << "number of digits"
                  << std::endl;
        std::cout << std::setw(15) << "-dd <--numbers>" << "                " << std::setw(15) << "number of  numbers"
                  << std::endl;
        std::cout << std::setw(15) << "-w <--words>" << "                " << std::setw(15) << "number of  words"
                  << std::endl;
        std::cout << std::setw(15) << "-s <--sorted>" << "                " << std::setw(15) << "show sorted words"
                  << std::endl;
        std::cout << std::setw(15) << "-l <--by-lenght>" << "               " << std::setw(15) << "sort by lenght"
                  << std::endl;
        std::cout << std::setw(15) << "-a <--anagrams> [string]" << "       " << std::setw(15) << "show anagrams"
                  << std::endl;
        std::cout << std::setw(15) << "-p <--palindromes>[string]" << "     " << std::setw(15) << "show palindromes"
                  << std::endl;
        std::cout << std::setw(15) << std::left << "-o <--output> [path]" << "           " << std::setw(15)
                  << "redirect output to file" << std::endl;
        std::cout << std::setw(15) << std::left << "--help" << "                " << std::setw(15) << "show help"
                  << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;


    }
}
#endif //PJATXT2_TEXT_MANIPULATIONS_H
