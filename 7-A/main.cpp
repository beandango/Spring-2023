/*
   COPYRIGHT (C) 2023 Sarah Hughes (4724822) All rights reserved.
   CSII assignment 7 A
   Author.  Sarah Hughes
            sch62@uakron.edu
   Version. 1.01 04.03.2023
   Purpose. The purpose of this assignment is to make sure that you know how to 
            write a program that uses containers, algorithms, iterators or binary trees.

*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>

int main() {
    std::string input_file_name = "ratings.txt";
    std::ifstream input_file(input_file_name);

    if (!input_file.is_open()) {
        std::cerr << "Error opening the file: " << input_file_name << std::endl;
        return 1;
    }

    int num_ratings;
    input_file >> num_ratings;
    input_file.ignore(); // Ignore the newline character after the number of ratings

    std::map<std::string, std::pair<int, int>> movie_ratings;

    for (int i = 0; i < num_ratings; ++i) {
        std::string movie_title;
        int rating;

        std::getline(input_file, movie_title);
        input_file >> rating;
        input_file.ignore(); // Ignore the newline character after the rating

        movie_ratings[movie_title].first++; // Increment the number of reviews
        movie_ratings[movie_title].second += rating; // Increment the sum of the ratings
    }

    input_file.close();

    std::cout << std::fixed << std::setprecision(1);
    for (const auto &entry : movie_ratings) {
        const std::string &movie_title = entry.first;
        const std::pair<int, int> &rating_data = entry.second;
        int num_reviews = rating_data.first;
        double avg_rating = static_cast<double>(rating_data.second) / num_reviews;

        std::cout << movie_title << ": " << num_reviews << " review";
        if (num_reviews > 1) {
            std::cout << "s";
        }
        std::cout << ", average of " << avg_rating << " / 5" << std::endl;
    }

    return 0;
}
