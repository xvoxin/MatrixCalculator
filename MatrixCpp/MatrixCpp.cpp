// MatrixCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::MatrixXf;
using Eigen::VectorXd;
using Eigen::VectorXf;
using namespace std;


ofstream firstMatrixDouble;
ofstream secMatrixDouble;
ofstream thrdMatrixDouble;
ofstream vectorDouble;
ofstream res1Double;
ofstream res2Double;
ofstream res3Double;
ofstream partialDouble;
ofstream fullDouble;

void CreateFillMatrixAndWriteToFileDouble(int size);
void WriteDoubleFile(string name, MatrixXd doubleMatrix, int size, ofstream &file);
void WriteDoubleVectorFile(string name, VectorXd doubleVector, int size, ofstream &file);

int main(int argc, char** argv)
{
	firstMatrixDouble.open("../FirstMatrixDataDouble.txt");
	secMatrixDouble.open("../SecondMatrixDataDouble.txt");
	thrdMatrixDouble.open("../ThirdMatrixDataDouble.txt");
	vectorDouble.open("../VectorDataDouble.txt");
	res1Double.open("../Res1DataDouble.txt");
	res2Double.open("../Res2DataDouble.txt");
	res3Double.open("../Res3DataDouble.txt");
	partialDouble.open("../PartialDataDouble.txt");
	fullDouble.open("../FullDataDouble.txt");

	CreateFillMatrixAndWriteToFileDouble(5);
	CreateFillMatrixAndWriteToFileDouble(10);

	//for (int i = 5; i < 400; i += 5)
	//{
	//
	//}
	firstMatrixDouble.close();
	secMatrixDouble.close();
	thrdMatrixDouble.close();
	vectorDouble.close();
	res1Double.close();
	res2Double.close();
	res3Double.close();
	partialDouble.close();
	fullDouble.close();

	int x;

	cin >> x;
	
	return 0;
}

void CreateFillMatrixAndWriteToFileDouble(int size)
{
	MatrixXd matrixA = MatrixXd::Random(size, size);
	MatrixXd matrixB = MatrixXd::Random(size, size);
	MatrixXd matrixC = MatrixXd::Random(size, size);
	VectorXd vector = VectorXd::Random(size);

	VectorXd res1 = matrixA * vector;
	VectorXd res2 = (matrixA + matrixB + matrixC) * vector;
	MatrixXd res3 = matrixA * (matrixB * matrixC);

	WriteDoubleFile("matrixA", matrixA, size, firstMatrixDouble);
	WriteDoubleFile("matrixB", matrixB, size, secMatrixDouble);
	WriteDoubleFile("matrixC", matrixC, size, thrdMatrixDouble);

	WriteDoubleFile("res3", res3, size, res1Double);
	WriteDoubleVectorFile("res1", res1, size, res2Double);
	WriteDoubleVectorFile("res2", res2, size, res3Double);
}

void WriteDoubleFile(string name, MatrixXd doubleMatrix, int size, ofstream &file)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			file << setprecision(2) << doubleMatrix(i, j);
			file << " ";
		}
		file << "\n";
	}
}

void WriteDoubleVectorFile(string name, VectorXd doubleVector, int size, ofstream &file)
{
	for (int i = 0; i < size; i++)
	{
		file << doubleVector(i);
		file << " ";
	}
	file << "\n";
}

