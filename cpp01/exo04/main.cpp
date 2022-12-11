/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 22:50:56 by skhali            #+#    #+#             */
/*   Updated: 2022/12/07 22:50:57 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(int argc, char **argv)
{
    std::fstream file;
    std::fstream new_file;
    std::string filename;
    std::string line;
    std::string text = "";
    std::size_t pos;

    if (argc != 4)
        return (std::cout << "Wrong number of arguments." << std::endl, 0);
    filename = std::string(argv[1]) + ".replace";
    file.open(argv[1], std::ios::in);
    if (!file.is_open())
        return (std::cout << "No such file." << std::endl, 0);
    else
    {
        while(getline(file, line))
        {
            pos = (line.find(argv[2], 0, std::string(argv[2]).length()));
            while (pos != std::string::npos)
                {
                    line.erase(pos, std::string(argv[2]).length());
                    line.insert(pos, argv[3]);
                    pos = (line.find(argv[2], pos + std::string(argv[3]).length(), std::string(argv[2]).length()));
                }
            text = text + line + "\n";
        }
    }
    file.close();
    new_file.open(filename.c_str(), std::ios::out);
    if (!new_file.is_open())
        return (std::cout << "No such file." << std::endl, 0);
    else
        new_file << text;
    new_file.close();
    return (0);
}