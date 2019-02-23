#include <iostream>
#include <chrono>
#include <windows.h>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <string>


#include "device_launch_parameters.h"


typedef std::chrono::high_resolution_clock Clock;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int algMax = 4;	//maximum length of algorithm outputted
int core = 1;	//amount of cores used
long long int algTotal = std::pow(14, algMax);




void pOutArr(int a, char * b) {
	for (int i = 0; i < a; i++) {
		std::cout << b[i];
	}
}


void lltoa2(long long val, int base, char *buf) {

	if (val == 0) {
		return;
	}

	for (int i = 0; val; ++i, val /= base) {	//for until either val or i are untrue, and on each iteration: (val = val / base) and (i = i - 1)
		buf[i] = "0123456789abcdef"[val % base];
	}

	return;
}


std::vector<std::vector<int>> test = {	//16 by 6
	{0,0,0,0,0,0},	//m - 0

	{1,1,1,1,1,-1},	//abm - 1
	{2,2,2,2,2,-1},	//acm - 2
	{3,3,3,3,3,-1},	//bcm - 3

	{4,4,4,4,4,4},	//a - 4
	{5,5,5,5,5,5},	//b - 5
	{6,6,6,6,6,6},	//c - 6

	{7,7,7,7,7,7},	//ab - 7
	{8,8,8,8,8,8},	//ac - 8
	{9,9,9,9,9,9},	//am - 9

	{10,10,10,10,10,10},	//ba - 10
	{11,11,11,11,11,11},	//bc - 11
	{12,12,12,12,12,12},	//bm - 12

	{13,13,13,13,13,13},	//ca - 13
	{14,14,14,14,14,14},	//cb - 14
	{15,15,15,15,15,15}	//cm - 15
};

std::vector<std::vector<int>> solved = {	//16 by 6
	{0,0,0,0,0,0},	//m - 0

	{1,1,1,1,1,-1},	//abm - 1
	{2,2,2,2,2,-1},	//acm - 2
	{3,3,3,3,3,-1},	//bcm - 3

	{4,4,4,4,4,4},	//a - 4
	{5,5,5,5,5,5},	//b - 5
	{6,6,6,6,6,6},	//c - 6

	{7,7,7,7,7,7},	//ab - 7
	{8,8,8,8,8,8},	//ac - 8
	{9,9,9,9,9,9},	//am - 9

	{10,10,10,10,10,10},	//ba - 10
	{11,11,11,11,11,11},	//bc - 11
	{12,12,12,12,12,12},	//bm - 12

	{13,13,13,13,13,13},	//ca - 13
	{14,14,14,14,14,14},	//cb - 14
	{15,15,15,15,15,15}	//cm - 15
};

std::vector<std::vector<int>> solved2 = {	//16 by 6
	{0,0,0,0,0,0},	//m - 0

	{1,1,3,2,1,-1},	//abm - 1
	{2,1,2,2,2,-1},	//acm - 2
	{3,3,3,3,1,-1},	//bcm - 3

	{4,4,6,4,4,4},	//a - 4
	{5,5,5,5,5,6},	//b - 5
	{4,5,6,6,6,6},	//c - 6

	{7,7,7,7,7,7},	//ab - 7
	{8,8,8,8,8,8},	//ac - 8
	{9,9,9,9,9,9},	//am - 9

	{10,10,10,10,10,10},	//ba - 10
	{11,11,11,11,11,11},	//bc - 11
	{12,12,12,12,12,12},	//bm - 12

	{13,13,13,13,13,13},	//ca - 13
	{14,14,14,14,14,14},	//cb - 14
	{15,15,15,15,15,15}	//cm - 15
};

void m(std::vector< std::vector<int>>(*cube)) {



	int temp1 = (*cube)[0][0];	//m
	int temp2 = (*cube)[0][1];

	int temp3 = (*cube)[4][2];	//a
	int temp4 = (*cube)[4][3];

	int temp5 = (*cube)[1][2];	//abm
	int temp6 = (*cube)[1][3];

	(*cube)[0][0] = (*cube)[0][2];
	(*cube)[0][2] = (*cube)[0][4];
	(*cube)[0][4] = temp1;

	(*cube)[0][1] = (*cube)[0][3];
	(*cube)[0][3] = (*cube)[0][5];
	(*cube)[0][5] = temp2;

	(*cube)[4][2] = (*cube)[5][4];
	(*cube)[5][4] = (*cube)[6][0];
	(*cube)[6][0] = temp3;

	(*cube)[4][3] = (*cube)[5][5];
	(*cube)[5][5] = (*cube)[6][1];
	(*cube)[6][1] = temp4;

	(*cube)[1][2] = (*cube)[3][4];
	(*cube)[3][4] = (*cube)[2][0];
	(*cube)[2][0] = temp5;

	(*cube)[1][3] = (*cube)[3][0];
	(*cube)[3][0] = (*cube)[2][1];
	(*cube)[2][1] = temp6;

	//solved = (*cube);
}

void mi(std::vector< std::vector<int>>(*cube)) {
	int temp1 = (*cube)[0][0];	//m
	int temp2 = (*cube)[0][1];

	int temp3 = (*cube)[4][2];	//a
	int temp4 = (*cube)[4][3];

	int temp5 = (*cube)[1][2];	//abm
	int temp6 = (*cube)[1][3];


	(*cube)[0][0] = (*cube)[0][4];
	(*cube)[0][4] = (*cube)[0][2];
	(*cube)[0][2] = temp1;

	(*cube)[0][1] = (*cube)[0][5];
	(*cube)[0][5] = (*cube)[0][3];
	(*cube)[0][3] = temp2;

	(*cube)[4][2] = (*cube)[6][0];
	(*cube)[6][0] = (*cube)[5][4];
	(*cube)[5][4] = temp3;

	(*cube)[4][3] = (*cube)[6][1];
	(*cube)[6][1] = (*cube)[5][5];
	(*cube)[5][5] = temp4;

	(*cube)[1][2] = (*cube)[2][0];
	(*cube)[2][0] = (*cube)[3][4];
	(*cube)[3][4] = temp5;

	(*cube)[1][3] = (*cube)[2][1];
	(*cube)[2][1] = (*cube)[3][0];
	(*cube)[3][0] = temp6;

	//solved = (*cube);
}

void a(std::vector< std::vector<int>>(*cube)) {
	int temp1 = (*cube)[4][0];	//a
	int temp2 = (*cube)[4][1];

	int temp3 = (*cube)[7][3];	//ab
	int temp4 = (*cube)[7][4];

	int temp5 = (*cube)[9][2];	//am
	int temp6 = (*cube)[9][3];


	(*cube)[4][0] = (*cube)[4][2];
	(*cube)[4][2] = (*cube)[4][4];
	(*cube)[4][4] = temp1;

	(*cube)[4][1] = (*cube)[4][3];
	(*cube)[4][3] = (*cube)[4][5];
	(*cube)[4][5] = temp2;

	(*cube)[7][3] = (*cube)[0][5];
	(*cube)[0][5] = (*cube)[8][1];
	(*cube)[8][1] = temp3;

	(*cube)[7][4] = (*cube)[0][0];
	(*cube)[0][0] = (*cube)[8][2];
	(*cube)[8][2] = temp4;

	(*cube)[9][2] = (*cube)[1][3];
	(*cube)[1][3] = (*cube)[2][4];
	(*cube)[2][4] = temp5;

	(*cube)[9][3] = (*cube)[1][4];
	(*cube)[1][4] = (*cube)[2][0];
	(*cube)[2][0] = temp6;

	//solved = (*cube);
}

void ai(std::vector< std::vector<int>>(*cube)) {
	int temp1 = (*cube)[4][0];	//a
	int temp2 = (*cube)[4][1];

	int temp3 = (*cube)[7][3];	//ab
	int temp4 = (*cube)[7][4];

	int temp5 = (*cube)[9][2];	//am
	int temp6 = (*cube)[9][3];


	(*cube)[4][0] = (*cube)[4][4];
	(*cube)[4][4] = (*cube)[4][2];
	(*cube)[4][2] = temp1;

	(*cube)[4][1] = (*cube)[4][5];
	(*cube)[4][5] = (*cube)[4][3];
	(*cube)[4][3] = temp2;

	(*cube)[7][3] = (*cube)[8][1];
	(*cube)[8][1] = (*cube)[0][5];
	(*cube)[0][5] = temp3;

	(*cube)[7][4] = (*cube)[8][2];
	(*cube)[8][2] = (*cube)[0][0];
	(*cube)[0][0] = temp4;

	(*cube)[9][2] = (*cube)[2][4];
	(*cube)[2][4] = (*cube)[1][3];
	(*cube)[1][3] = temp5;

	(*cube)[9][3] = (*cube)[2][0];
	(*cube)[2][0] = (*cube)[1][4];
	(*cube)[1][4] = temp6;

	//solved = (*cube);
}

void b(std::vector< std::vector<int>>(*cube)) {
	int temp1 = (*cube)[5][0];	//b
	int temp2 = (*cube)[5][1];

	int temp3 = (*cube)[10][3];	//ba
	int temp4 = (*cube)[10][4];

	int temp5 = (*cube)[12][4];	//bm
	int temp6 = (*cube)[12][0];

	(*cube)[5][0] = (*cube)[5][2];
	(*cube)[5][2] = (*cube)[5][4];
	(*cube)[5][4] = temp1;

	(*cube)[5][1] = (*cube)[5][3];
	(*cube)[5][3] = (*cube)[5][5];
	(*cube)[5][5] = temp2;

	(*cube)[10][3] = (*cube)[11][5];
	(*cube)[11][5] = (*cube)[0][1];
	(*cube)[0][1] = temp3;

	(*cube)[10][4] = (*cube)[11][0];
	(*cube)[11][0] = (*cube)[0][2];
	(*cube)[0][2] = temp4;

	(*cube)[12][4] = (*cube)[3][0];
	(*cube)[3][0] = (*cube)[1][1];
	(*cube)[1][1] = temp5;

	(*cube)[12][0] = (*cube)[3][1];
	(*cube)[3][1] = (*cube)[1][2];
	(*cube)[1][2] = temp6;

	//solved = (*cube);
}

void bi(std::vector< std::vector<int>>(*cube)) {
	int temp1 = (*cube)[5][0];	//b
	int temp2 = (*cube)[5][1];

	int temp3 = (*cube)[10][3];	//ba
	int temp4 = (*cube)[10][4];

	int temp5 = (*cube)[12][4];	//bm
	int temp6 = (*cube)[12][0];

	(*cube)[5][0] = (*cube)[5][4];
	(*cube)[5][4] = (*cube)[5][2];
	(*cube)[5][2] = temp1;

	(*cube)[5][1] = (*cube)[5][5];
	(*cube)[5][5] = (*cube)[5][3];
	(*cube)[5][3] = temp2;

	(*cube)[10][3] = (*cube)[0][1];
	(*cube)[0][1] = (*cube)[11][5];
	(*cube)[11][5] = temp3;

	(*cube)[10][4] = (*cube)[0][2];
	(*cube)[0][2] = (*cube)[11][0];
	(*cube)[11][0] = temp4;

	(*cube)[12][4] = (*cube)[1][1];
	(*cube)[1][1] = (*cube)[3][0];
	(*cube)[3][0] = temp5;

	(*cube)[12][0] = (*cube)[1][2];
	(*cube)[1][2] = (*cube)[3][1];
	(*cube)[3][1] = temp6;

	//solved = (*cube);
}

void c(std::vector< std::vector<int>>(*cube)) {
	int temp1 = (*cube)[6][0];	//c
	int temp2 = (*cube)[6][1];

	int temp3 = (*cube)[0][3];	//m
	int temp4 = (*cube)[0][4];

	int temp5 = (*cube)[2][1];	//acm
	int temp6 = (*cube)[2][2];

	(*cube)[6][0] = (*cube)[6][2];
	(*cube)[6][2] = (*cube)[6][4];
	(*cube)[6][4] = temp1;

	(*cube)[6][1] = (*cube)[6][3];
	(*cube)[6][3] = (*cube)[6][5];
	(*cube)[6][5] = temp2;

	(*cube)[0][3] = (*cube)[14][5];
	(*cube)[14][5] = (*cube)[13][1];
	(*cube)[13][1] = temp3;

	(*cube)[0][4] = (*cube)[14][0];
	(*cube)[14][0] = (*cube)[13][2];
	(*cube)[13][2] = temp4;

	(*cube)[2][1] = (*cube)[3][3];
	(*cube)[3][3] = (*cube)[15][0];
	(*cube)[15][0] = temp5;

	(*cube)[2][2] = (*cube)[3][4];
	(*cube)[3][4] = (*cube)[15][1];
	(*cube)[15][1] = temp6;

	//solved = (*cube);
}

void ci(std::vector< std::vector<int>>(*cube)) {
	int temp1 = (*cube)[6][0];	//c
	int temp2 = (*cube)[6][1];

	int temp3 = (*cube)[0][3];	//m
	int temp4 = (*cube)[0][4];

	int temp5 = (*cube)[2][1];	//acm
	int temp6 = (*cube)[2][2];

	(*cube)[6][0] = (*cube)[6][4];
	(*cube)[6][4] = (*cube)[6][2];
	(*cube)[6][2] = temp1;

	(*cube)[6][1] = (*cube)[6][5];
	(*cube)[6][5] = (*cube)[6][3];
	(*cube)[6][3] = temp2;

	(*cube)[0][3] = (*cube)[13][1];
	(*cube)[13][1] = (*cube)[14][5];
	(*cube)[14][5] = temp3;

	(*cube)[0][4] = (*cube)[13][2];
	(*cube)[13][2] = (*cube)[14][0];
	(*cube)[14][0] = temp4;

	(*cube)[2][1] = (*cube)[15][0];
	(*cube)[15][0] = (*cube)[3][3];
	(*cube)[3][3] = temp5;

	(*cube)[2][2] = (*cube)[15][1];
	(*cube)[15][1] = (*cube)[3][4];
	(*cube)[3][4] = temp6;

	//solved = (*cube);
}

void abm(std::vector< std::vector<int>>(*cube)) {
	int temp1 = (*cube)[7][2];	//ab
	int temp2 = (*cube)[7][3];	//ab
	int temp3 = (*cube)[1][0];	//abm

	(*cube)[7][2] = (*cube)[10][4];
	(*cube)[10][4] = (*cube)[5][5];
	(*cube)[5][5] = (*cube)[0][0];
	(*cube)[0][0] = (*cube)[4][1];
	(*cube)[4][1] = temp1;

	(*cube)[7][3] = (*cube)[10][5];
	(*cube)[10][5] = (*cube)[5][0];
	(*cube)[5][0] = (*cube)[0][1];
	(*cube)[0][1] = (*cube)[4][2];
	(*cube)[4][2] = temp2;

	(*cube)[1][0] = (*cube)[1][1];
	(*cube)[1][1] = (*cube)[1][2];
	(*cube)[1][2] = (*cube)[1][3];
	(*cube)[1][3] = (*cube)[1][4];
	(*cube)[1][4] = temp3;

	//solved = (*cube);
}

void abmi(std::vector< std::vector<int>>(*cube)) {
	int temp1 = (*cube)[7][2];	//ab
	int temp2 = (*cube)[7][3];	//ab
	int temp3 = (*cube)[1][0];	//abm

	(*cube)[7][2] = (*cube)[4][1];
	(*cube)[4][1] = (*cube)[0][0];
	(*cube)[0][0] = (*cube)[5][5];
	(*cube)[5][5] = (*cube)[10][4];
	(*cube)[10][4] = temp1;

	(*cube)[7][3] = (*cube)[4][2];
	(*cube)[4][2] = (*cube)[0][1];
	(*cube)[0][1] = (*cube)[5][0];
	(*cube)[5][0] = (*cube)[10][5];
	(*cube)[10][5] = temp2;

	(*cube)[1][0] = (*cube)[1][4];
	(*cube)[1][4] = (*cube)[1][3];
	(*cube)[1][3] = (*cube)[1][2];
	(*cube)[1][2] = (*cube)[1][1];
	(*cube)[1][1] = temp3;

	//solved = (*cube);
}

void acm(std::vector< std::vector<int>>(*cube)) {
	int temp1 = (*cube)[4][3];	//a
	int temp2 = (*cube)[4][4];	//a
	int temp3 = (*cube)[2][0];	//acm

	(*cube)[4][3] = (*cube)[0][4];
	(*cube)[0][4] = (*cube)[6][5];
	(*cube)[6][5] = (*cube)[13][0];
	(*cube)[13][0] = (*cube)[8][2];
	(*cube)[8][2] = temp1;

	(*cube)[4][4] = (*cube)[0][5];
	(*cube)[0][5] = (*cube)[6][0];
	(*cube)[6][0] = (*cube)[13][1];
	(*cube)[13][1] = (*cube)[8][3];
	(*cube)[8][3] = temp2;

	(*cube)[2][0] = (*cube)[2][1];
	(*cube)[2][1] = (*cube)[2][2];
	(*cube)[2][2] = (*cube)[2][3];
	(*cube)[2][3] = (*cube)[2][4];
	(*cube)[2][4] = temp3;

	//solved = (*cube);
}

void acmi(std::vector< std::vector<int>>(*cube)) {
	int temp1 = (*cube)[4][3];	//a
	int temp2 = (*cube)[4][4];	//a
	int temp3 = (*cube)[2][0];	//acm

	(*cube)[4][3] = (*cube)[8][2];
	(*cube)[8][2] = (*cube)[13][0];
	(*cube)[13][0] = (*cube)[6][5];
	(*cube)[6][5] = (*cube)[0][4];
	(*cube)[0][4] = temp1;

	(*cube)[4][4] = (*cube)[8][3];
	(*cube)[8][3] = (*cube)[13][1];
	(*cube)[13][1] = (*cube)[6][0];
	(*cube)[6][0] = (*cube)[0][5];
	(*cube)[0][5] = temp2;

	(*cube)[2][0] = (*cube)[2][4];
	(*cube)[2][4] = (*cube)[2][3];
	(*cube)[2][3] = (*cube)[2][2];
	(*cube)[2][2] = (*cube)[2][1];
	(*cube)[2][1] = temp3;

	//solved = (*cube);
}

void bcm(std::vector< std::vector<int>>(*cube)) {
	int temp1 = (*cube)[0][2];	//m
	int temp2 = (*cube)[0][3];	//m
	int temp3 = (*cube)[3][0];	//bcm

	(*cube)[0][2] = (*cube)[5][3];
	(*cube)[5][3] = (*cube)[11][4];
	(*cube)[11][4] = (*cube)[14][0];
	(*cube)[14][0] = (*cube)[6][1];
	(*cube)[6][1] = temp1;

	(*cube)[0][3] = (*cube)[5][4];
	(*cube)[5][4] = (*cube)[11][5];
	(*cube)[11][5] = (*cube)[14][1];
	(*cube)[14][1] = (*cube)[6][2];
	(*cube)[6][2] = temp2;

	(*cube)[3][0] = (*cube)[3][1];
	(*cube)[3][1] = (*cube)[3][2];
	(*cube)[3][2] = (*cube)[3][3];
	(*cube)[3][3] = (*cube)[3][4];
	(*cube)[3][4] = temp3;

	//solved = (*cube);
}

void bcmi(std::vector< std::vector<int>>(*cube)) {
	int temp1 = (*cube)[0][2];	//m
	int temp2 = (*cube)[0][3];	//m
	int temp3 = (*cube)[3][0];	//bcm

	(*cube)[0][2] = (*cube)[6][1];
	(*cube)[6][1] = (*cube)[14][0];
	(*cube)[14][0] = (*cube)[11][4];
	(*cube)[11][4] = (*cube)[5][3];
	(*cube)[5][3] = temp1;

	(*cube)[0][3] = (*cube)[6][2];
	(*cube)[6][2] = (*cube)[14][1];
	(*cube)[14][1] = (*cube)[11][5];
	(*cube)[11][5] = (*cube)[5][4];
	(*cube)[5][4] = temp2;

	(*cube)[3][0] = (*cube)[3][4];
	(*cube)[3][4] = (*cube)[3][3];
	(*cube)[3][3] = (*cube)[3][2];
	(*cube)[3][2] = (*cube)[3][1];
	(*cube)[3][1] = temp3;

	//solved = (*cube);
}

void drawCube(std::vector< std::vector<int>> cube) {
	for (int i = 0; i < cube.size(); i++)
	{
		if (i % 2 == 0)
		{
			SetConsoleTextAttribute(hConsole, 12);
		}
		else {
			SetConsoleTextAttribute(hConsole, 14);
		}


		for (int j = 0; j < cube[i].size(); j++)
		{
			std::cout << cube[i][j] << std::endl;
		}
	}




	SetConsoleTextAttribute(hConsole, 11);
}

bool twoDVecCheckSame(std::vector<std::vector<int>> vec1, std::vector<std::vector<int>> vec2) {
	for (int i = 0; i < vec1.size(); i++) {
		for (int j = 0; j < vec1[0].size(); j++) {
			if (vec1[i][j] != vec2[i][j]) {
				//std::cout << "Inequality at i,j:  " << i << "," << j << "  |  "
				//	<< vec1[i][j] << " != " << vec2[i][j] << std::endl;

				return false;
			}
		}
	}
	return true;
}

void numToAlg(long long int num, char *algStr) {
	for (int i = 0; i < algMax; i++) {
		algStr[i] = '0';
	}


	lltoa2(num, 14, algStr);

}

void initSim(int coreNum, std::vector<std::vector<long long int>> range, std::vector<std::vector<int>> scramble) {
	char *algStr;
	algStr = new char[algMax + 1];

	SetConsoleTextAttribute(hConsole, 15);

	for (long long int i = range[coreNum][0]; i < range[coreNum][1]; i++) {
		numToAlg(i, algStr);	//fills algStr with new algorithm
		//std::cout << "algStr post numToAlg:" << algStr << std::endl;
		scramble = solved2;
		for (int j = 0; j < algMax; j++) {

			//std::cout << "Current alg number:  " << i << std::endl;
			//std::cout << "Current char in alg: " << j << std::endl;
			//std::cout << "Current Algorithm:   " << algStr << std::endl;	
			//numbers that have zero before a number (as a filler number like "01" or like "0a") do not get recognized as a number".
			switch (algStr[j]) {
			case '0':
				a(&scramble);
				break;
			case '1':
				ai(&scramble);
				break;
			case '2':
				b(&scramble);
				break;
			case '3':
				bi(&scramble);
				break;
			case '4':
				c(&scramble);
				break;
			case '5':
				ci(&scramble);
				break;
			case '6':
				abm(&scramble);
				break;
			case '7':
				abmi(&scramble);
				break;
			case '8':
				acm(&scramble);
				break;
			case '9':
				acmi(&scramble);
				break;
			case 'a':
				bcm(&scramble);
				break;
			case 'b':
				bcmi(&scramble);
				break;
			case 'c':
				m(&scramble);
				break;
			case 'd':
				mi(&scramble);
				break;
			default:
				SetConsoleTextAttribute(hConsole, 12);
				std::cout << "ALGORITHM NOT FOUND" << std::endl;
				SetConsoleTextAttribute(hConsole, 15);
				break;
			}
		}
		if (twoDVecCheckSame(scramble, test)) {
			SetConsoleTextAttribute(hConsole, 10);
			pOutArr(algMax, algStr);
			std::cout << ", SLVE, ";
			SetConsoleTextAttribute(hConsole, 15);
		}
	}

	delete[] algStr;
}
/*
void initSim2(long long int algTotal, int algMax, std::vector<std::vector<int>> scramble, std::vector<std::vector<int>> test) {
	cudaMalloc()
	thread<<<(algTotal + 511)/512, 512 >>>(algTotal, algMax, scramble, test );
}
*/
int main() {


	auto t1 = Clock::now(); //start timer --------


	//initSim(0, rangeGen(), solved2);
	initSim2(algTotal, algMax, solved2, test);


	//drawCube(solved);



	auto t2 = Clock::now(); //end timer --------

	std::cout << std::endl << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;
	std::cout << std::endl << std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count() << " seconds" << std::endl;


	SetConsoleTextAttribute(hConsole, 13);
	if (solved2 == test) {
		std::cout << "true" << std::endl;
	}
	else {
		std::cout << "false" << std::endl;
	}
	if (twoDVecCheckSame(solved2, test)) {
		std::cout << "true" << std::endl;
	}
	else {
		std::cout << "false" << std::endl;
	}




	SetConsoleTextAttribute(hConsole, 15);

	system("pause");



	return 0;
}

