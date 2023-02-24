#include <stdio.h>
#include <iostream>
#include <fstream>
#include "matrix.h"

void matrix::createMatrix()
{
	std::ifstream inFile;
	inFile.open("input.txt");
	inFile>>rows;
	inFile>>cols;
	grid = new double*[rows];
	grid_temp = new double*[rows];
	for(int i = 0; i<rows; i++){
		grid[i] = new double[cols];
		grid_temp[i] = new double[cols];
	}
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
			inFile>>grid[i][j];
		}
	}
	return;
}

void matrix::printMatrix(){
        for(int i = 0; i<rows; i++){
                for(int j = 0; j<cols; j++){
                        std::cout<<grid[i][j]<<"\t";
                }
                std::cout<<"\n";
        }
}

void matrix::addMatrix(){
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
			grid_temp[i][j] = grid[i][j]+grid[i][j];
		}
	}
        for(int i = 0; i<rows; i++){
                for(int j = 0; j<cols; j++){
			std::cout<<grid_temp[i][j]<<"\t";
                }
		std::cout<<"\n";
        }
}

double matrix::getMax(){
	//TO DO
	double max_element = 0;
	for (int i=0; i < rows; i++)
	{
		for (int j=0; j < cols, j++) {
			if (grid[i][j] > max_element)
			{
				max_element = grid[i][j];
			}
		}
	}
	return max_element;
}

bool matrix::findElement(int no){
	//TO DO
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols, j++) {
			if (no = grid[i][j]) {
				std::cout << "Element Found at: " << i << "," << j << endl;
				return true;
			}
		}
	}
	std::cout<<"\nElement not found\n";
	return false;
}

void matrix::changeElement(int r, int c, int no){
	//TO DO
	if (r >= 0 && r < rows && c >= 0 && c < cols) {
		grid[r][c] = no;

	}
	else
	{
		std::cout << "It's not valid.\n" << endl;
	}
	return;
}
void matrix::multiplyMatrix(){
	//TO DO
	//Hint: May want to store the new result in grid_temp and print that matrix
	for (int i = 0; i < rows;  i++) {
		for (int j = 0; j < cols; j++) {
			for (int t = 0; t < cols && t < rows; t++) {
				grid_temp[i][j] += grid[i][t] * grid[t][j];
			}
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << grid_temp[i][j] << "\n" << endl;
		}
	}
	return;
}

void matrix::transposeMatrix(){
	//TO DO
	//Hint: May want to store the new results in grid_temp and print that matrix
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << grid[j][i] << "\n" << endl;
		}
	}



	return;
}
matrix::~matrix(){
        for(int i = 0; i<rows; i++){
                delete[] grid[i];
                delete[] grid_temp[i];
        }
        delete[] grid;
        delete[] grid_temp;
}
