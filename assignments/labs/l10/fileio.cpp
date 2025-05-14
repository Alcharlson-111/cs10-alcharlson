/*
    CS1 - File IO Lab

    Updated by: Aubrey Charlson
    Date: 5/13

    The program reads numbers from a file and finds statistical values from those numbers.
    Lab demonstrates the file io and vector application. 
    Statistical value's definitions for mean, median, mode, etc. can be found here: https://www.purplemath.com/modules/meanmode.htm
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

const float EPSILON = 1e-4; //accuracy upto 4 decimal points

// function prototypes
void readData(vector<int> &, const string);
int findMax(const vector<int> &);
int findMin(const vector<int> &);
float findMean(const vector<int> &); // average
int findRange(const vector<int> &);
float findMedian(vector<int>);
// bonus implement findMode function
int findMode(const vector<int> &);

void writeData(const vector<int> & numbers);
void test();

int main(int argc, char* argv[]) {
    if (argc == 2 && string(argv[1]) == "test") {
        test();
        return 0;
    }
    vector<int> numbers;
    string inFile;
    cout << "Enter input file name: ";
    getline(cin, inFile);
    readData(numbers, inFile);
    writeData(numbers);
    cout << "All done. Enter to exit...";
    cin.get();
    return 0;
}

void readData(vector<int> & numbers, const string inputFileName) {
    ifstream inFile(inputFileName);
    string line;
    int n;
    while(getline(inFile,line))
    {
        istringstream in(line);
        in >> n;
        numbers.push_back(n);
    } 
    inFile.close();
    // FIXME3: Open inputFileName for reading data
    // read the data until eof marker and store each num into numbers vector
}

void writeData(const vector<int> & numbers) {
    // FIXME4
    /*
    Algorithm steps:
    1. Prompt user to enter output file name
    2. Store and use the file name to open the file in write mode
    3. Write output as shown in output.txt file with proper formatting using iomanip
    */
    string oName; 
    cout << "Enter the output file name: ";
    getline(cin, oName); 

    ofstream out(oName); 
    out << left 
        << setw(18)
        << "List of Numbers:";
    for (int number : numbers)
    {
        out << number << " ";

    }
    out << "\n\n" << string (40, '=')
        << endl
        << string(10, ' ') << "Statistical Results"
        << endl << string (40, '=')
        << endl
        << setw(8) << "Max"
        << setw(8) << "Min"
        << setw(9) << "Mean" 
        << right
        << setw(2) << "Median"
        << setw(9) <<  "Range"
        << endl << left
        << setw(8) << findMax(numbers)
        << setw(8) << findMin(numbers)
        << setw(9)  << setprecision(4) 
        << findMean(numbers) << right
        << setw(6) << findMedian(numbers)
        << setw(9) << findRange(numbers)
        << endl;

}

int findMax(const vector<int> & nums) {
    int max = nums[0];
    for(int n: nums)
        max = (n>max) ? n : max;
    return max;
}

int findMin(const vector<int> & nums) {
    // FIXME5 - implement function to find and return min value from nums vector
    int min = 100000; 
    for (int num : nums)
    {
        if(min > num) min = num;
    }
    return min; // FIXED
} 

float findMean(const vector<int> & nums) {
    // same as average
    long long int sum = 0;
    for(int n: nums)
        sum += n;
    return sum/float(nums.size());
}

int findRange(const vector<int> & nums) {
    // FIXME6 - implement function that finds and returns the range value
    int min = findMin(nums);
    int max = findMax(nums);
    int range = max - min;

    return range; //fixed
}

float findMedian(vector<int> nums) {
    sort(nums.begin(), nums.end());
    float median;
    if (nums.size() % 2 == 0) {  // even set
        median = (nums[nums.size()/2] + nums[nums.size()/2-1])/float(2);
    } else { // odd set
        median = nums[nums.size()/2];
    }
    return median;
}

void test() {
    vector<int> numbers = {100, 10, 5, 0, -99, 10, 99};
    //cout << findMean(numbers) << " " << findMean(numbers)-17.857142 << endl;
    assert(fabs(findMean(numbers)-17.857142) <= EPSILON );
    assert(findMax(numbers) == 100);
    assert(findMedian(numbers) == 10);
    vector<int> numbers1 = {10, 10, 10, 0, -10, -10};
    assert(fabs(findMean(numbers1) -1.6667) <= EPSILON  );
    assert(findMax(numbers1) == 10);
    assert(findMedian(numbers1) == 5);
    // FIXME7: Write at least two test cases for other functions
    assert(findMin(numbers) == -99);
    assert(findMin(numbers1) == -10);

    cerr << "all test cases passed!\n";
}