//
// Created by bruno on 09.06.2021.
//

#ifndef PJATXT2_DRIVER_H
#define PJATXT2_DRIVER_H
#include <vector>
#include <algorithm>
#include <fstream>
#include <chrono>

namespace pjatxt_driver{

    /**
    * Looks for the fist occurance of a string in a vector of pairs
    * @param str - string to look for
    * @param arguments - refence to a vecotr of pairs of type <string,string>
    * @return returns itarator to found flag, if not present returns null pointer
    */
    std::vector<std::pair<std::string,std::string>>::iterator get_first_by_flag(std::string str,std::vector<std::pair<std::string,std::string>>& arguments){

        auto it = std::find_if( arguments.begin(), arguments.end(),
                                [&str](const auto & element){ return element.first == str;} );

        return it;


    }

    /**
    * Checks if string is a valid argument
    * @param st - string to check
    * @return 0 if the st is not a valid argument, 1 if it is a valid argument, 2 if it is an alias
    */
    int is_arg(const std::string& st){

        auto sub = st.substr(0, 2);

        if(sub == "--")
            return 2;
        else if(st[0] == '-' )
            return 1;

        return 0;

    }




    /**
    * Checks if a container of type T contains a string
    * @param container - container of type T
    * @param str - string to look for
    * @return true if str is present else false
    */
    bool pre_validate(int args_count, const char* args[]){

        const auto arguments = std::vector<std::string>(args + 1, args + args_count);

        if(arguments.empty() || arguments[0] == "--help") {
            print_help();
            return false;
        }
        else if (!is_arg(arguments[0])){
            std::cerr << "The arguments must start with either a flag or an empty string. Unrecoginzed command: " +arguments[0] +" was provided. The program will now exit.";
            return false;
        }
        return true;



    }

    /**
    * Parses arguments to vector of pairs of type <string,string>
    * @param args_count - number of arguments
    * @param args - array of arguments
    * @return vector of pairs of type <string,string>
    */
    std::vector<std::pair<std::string,std::string>>parse(int args_count, const char* args[]){

        const auto arguments = std::vector<std::string>(args + 1, args + args_count);


        auto full_args = std::vector<std::pair<std::string,std::string>>();



        for( int i = 0; i < arguments.size(); i++){
            auto pair = std::pair<std::string,std::string>();
            if(is_arg(arguments[i])) {
              pair.first = arguments[i];
                 if(is_arg(arguments[i]) == 2){
                    pair.first = (*alias_flags.find(arguments[i])).second;
                    }

              auto params = std::string();

                for( int j = i+1; j< arguments.size();j++){
                    if(! is_arg(arguments[j]))  {
                        if(j == i+1){
                        params += arguments[j];}
                        else
                            params += " " + arguments[j];


                    }
                    else
                        break;

                }

                pair.second = params;
                full_args.push_back(pair);
            }

     }

        return full_args;


    }

    /**
   * Checks if parsed flags have correct arguments
   * @param arguments - reference to vector of pairs of type <string,string> containig parsed flags
   * @return true if all checks are passed and arguments are valid
   */
    bool validate_args(std::vector<std::pair<std::string,std::string>>& arguments){

        for ( const auto& pair : arguments){

            if( is_in<std::set<std::string>>(valid_non_flags,pair.first)){

                if (!pair.second.empty()) {
                    std::cerr << "The flag " + pair.first
                              << " requires no parameters, but some where provided. The program will now exit" << "\n";
                    return false;
                }

            }
            else if (is_in<std::set<std::string>>(valid_arg_flags,pair.first)){

                if (pair.second.empty()) {
                    std::cerr<< "The flag " + pair.first
                             << " requires parameters but none where provided. The program will now exit" << "\n";
                    return false;
                }


            }


        }
        return true;
    }


    /**
    * Checks if flags passed in array args are valid
    * @param args_count - number of arguments
    * @param args - array of arguments
    * @return true if all checks are passed and flags are valid
    */
    bool validate_flags( int args_count, const char* args[]){
        const auto arguments = std::vector<std::string>(args + 1, args + args_count);
        if(arguments.empty() || arguments[0] == "--help") {
            print_help();
            return false;
        }
        else if (!is_arg(arguments[0])){
            std::cerr << "The arguments must start with either a flag or an empty string. Unrecoginzed command: " +arguments[0] +" was provided. The program will now exit.";
            return false;
        }

        auto parsed_flags= std::vector<std::string>();

        for( int i = 0; i < arguments.size(); i++){
            auto flag = arguments[i];

            auto is_argument = is_arg(flag);
            if(is_argument) {
                if(!is_in(valid_flags,flag)) {
                    std::cerr << "Unrecognized flag: " + flag << ". The program will now exit"<<"\n";
                    return false;
                }
                else if(is_argument == 2){
                    flag = (*alias_flags.find(flag)).second;

                }

               parsed_flags.push_back(flag);

            }

        }

        auto lenght = parsed_flags.size();


        if(!is_in(parsed_flags,"-f") && !is_in(parsed_flags,"-i")){
            std::cerr<< "No input file was specified. You need specify either a -f or -o flag for the program to run. The program will now exit" << "\n";
            return false;

        }



        for(int i = 0; i< lenght;i ++){
            auto flag = parsed_flags[i];
            if( (flag == "-i" )&& lenght != 1){
                std::cerr<< "The flag: " + flag <<  " has to be the only specified flag but more flags where passed. The program will now exit" << "\n";
                return false;

            }



            if(is_in_multiple<std::vector<std::string>>(parsed_flags, flag)
            && is_in<std::set<std::string>>(singular_flags,flag)){

                std::cerr<< "The flag: " + flag <<  " can only be specified once, multiple instances found. The program will now exit." << "\n";
                return false;
            }
            if( is_in(last_flags, flag) && i != lenght-1){

                std::cerr << "The flag: " + flag <<  " has to be the last flag but more flags where passed after. The program will now exit." << "\n";
                return false;
            }
            if((flag == "-l" ) && ( i + 1 == lenght || (parsed_flags[i+1] != "-s"  && parsed_flags[i+1] != "-rs"  &&parsed_flags[i+1] != "-l" ))){

                std::cerr << "The flag: " + flag <<  " has to be followed by an -s or -rs flag (or any alias). The program will now exit." << "\n";
                return false;
            }

        }


        return true;



    }
    /**
   * Function template of type D which runs flags specified in arguments vector
   * @param arguments - reference to vector of type <string,string> containing flags
   * @param out - reference tp destination to write to of type D
   * @param input - refernce to file to read from
   * @return void
   */
    template<typename D>
    void run_commands_cout(std::vector<std::pair<std::string,std::string>>& arguments, D& out, std::ifstream& input ){

        auto start_time = std::chrono::high_resolution_clock::now();
        bool lenght_modifier = false;

        for( const auto& pair : arguments){
            auto flag = pair.first;
            auto arg = pair.second;



            if(flag == "-c" )
            count_characters(input,out);
            else if(flag=="-n" )
                count_lines(input,out);
            else if (flag =="-d" )
                count_digits(input,out);
            else if (flag == "-dd" )
                count_numbers(input,out);
            else if (flag == "-w" )
                count_words(input,out);
            else if (flag == "-s" ) {
                show_ordered_words(input, lenght_modifier, 0, out);
                if(lenght_modifier)
                    lenght_modifier = false;
            }
            else if (flag =="-rs" ) {
                show_ordered_words(input, lenght_modifier, 1, out);
                if (lenght_modifier)
                    lenght_modifier = false;
            }
            else if (flag == "-l" ){
                lenght_modifier = true;
            }
            else if (flag == "-a" ){
                show_anagrams(input,out,arg);
            }
            else if ( flag == "-p" )
                show_palindromes(input,out,arg);
            //prints all words in upper case
            else if(flag == "-tu" )
                show_upper_case(input,out);

        }

    }

    /**
   * Sets output and input destinations for the program to run
   * @param args_count - vector of pairs of type <string,string> containing flags
   * @return void
   */
    void execute(std::vector<std::pair<std::string,std::string>>& arguments){

      auto out_it = get_first_by_flag("-o", arguments);
      auto in_it = get_first_by_flag("-f", arguments);
      auto input_stream = std::ifstream((*in_it).second);

      if(!input_stream.is_open()) {
          std::cerr << "File not found. The program will now exit" << std::endl;
          return ;
      }

      if(out_it != arguments.end()){

          std::ofstream out = std::ofstream((*out_it).second);
          run_commands_cout<std::ofstream>(arguments,out,input_stream);



      } else {


          run_commands_cout<std::ostream>(arguments,std::cout,input_stream);

      }


    }








}
#endif //PJATXT2_DRIVER_H
