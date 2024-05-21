#define _CRT_SECURE_NO_WARNINGS
#include "Node.h"
#include <algorithm>
#include<sstream>
using std::ifstream;


int main() {
    try {
        srand(time(nullptr));

        bool stop = false;
        int option;
        int subcase;
        while (!stop) {
            std::cout << "Option: ";
            std::cin >> option;
            switch (option) {
            case 0:
                stop = true;
                break;
            case 1:
            {
                string start, end;
                std::cout << "Enter start word: ";
                std::cin >> start;
                std::cout << "Enter target word: ";
                std::cin >> end;
                form_n_letters_map(start.length(), "english_words.txt");
                Graph<string> g1;
                vector<string> path = find_transformation(start, end, g1);
                std::cout << "Shortest transformation from " << start << " to " << end << ":" << std::endl;
                for (const auto& word : path)
                    std::cout << word << " ";
                std::cout << std::endl;
            }
            break;

            default:
                std::cout << "Invalid choice";
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
