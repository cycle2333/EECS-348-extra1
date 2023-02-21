/*
 * main.cpp
 *
 *  Created on: Feb 20, 2023
 *      Author: Cycle
 */
#include <iostream>
#include <fstream>
#include "department.h"

int main() {
    const int dept_num = 5;
    const int prog_num = 5;

    std::ifstream input_file("data.txt");

    // Read department preferences
    int dept_pref[prog_num][dept_num];
    for (int i = 0; i < dept_num; i++) {
        for (int j = 0; j < prog_num; j++) {
            input_file >> dept_pref[j][i];
        }
    }

    // Read programmer preferences
    int prog_pref[prog_num][dept_num];
    for (int i = 0; i < prog_num; i++) {
        for (int j = 0; j < dept_num; j++) {
            input_file >> prog_pref[i][j];
        }
    }
    input_file.close();

    // Assign programmers to departments
    int dept_preference;
    int prog[prog_num] = {0};
    for (int i = 0; i < dept_num; i++) {// Get the department's first preference programmer
        dept_preference = dept_pref[0][i] - 1;
        // Iterate over all departments that have a preference
        for (int j = i + 1; j < dept_num; j++) {
            if (dept_pref[0][i] == dept_pref[0][j]) {
                // Check the programmer's preferences
                for (int conf = 0; conf < prog_num; conf++) {
                    if (prog_pref[conf][dept_preference] == i + 1) {
                        // If the programmer prefers the current department over the other one,
                        // remove the other department's first preference and assign the programmer to the current department
                        prog_out(dept_pref, j, prog);
                        break;
                    }
                    if (prog_pref[conf][dept_preference] == j + 1) {
                        prog_out(dept_pref, i, prog);
                        j = i;
                        dept_preference = dept_pref[0][i] - 1;// Get the new first preference for the current department
                        break;
                    }
                }
            }
        }
        std::cout << "Department #" << i + 1 << " will get Programmer #" << dept_preference + 1 << std::endl;
    }

    return 0;
}
