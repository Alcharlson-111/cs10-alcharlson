// Take 5 numbers 
#ifndef HEAD_H  // Include guard
#define HEAD_H
#include <vector>
#include <string> 
using namespace std;


void greetUser();
void printResults(string, double, vector<double>, int);
void menuChoice(bool&);
void printBreak();
vector<double> inputNum();
double outSum(vector<double>&); 
double outPro(vector<double>&); 
double outAvg(vector<double>&);
double outMax(vector<double>&);
double outMin(vector<double>&);
int outEOZ(vector<double>&); 
void program(); 
void testOperations();


#endif