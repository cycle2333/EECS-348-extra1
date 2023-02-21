/*
 * department.cpp
 *
 *  Created on: Feb 20, 2023
 *      Author: Cycle
 */


#include "department.h"

void prog_out(int dept_pref[prog_num][dept_num], int dept, int prog[prog_num]) {
    do {
        for (int i = 0; i < prog_num; i++) {
            dept_pref[i][dept] = dept_pref[i+1][dept];
        }
    } while (prog[dept_pref[0][dept]-1]);
}
