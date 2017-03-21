/* Alexander Lanthier
 * Northern Michigan University, Marquette MI 49855
 * Allows user to enter a file name and allow that file, if properly formatted, and records to be sorted alphabetically using Shell Sort
 * File format: First four characters will be read as a single int and will be the word length for each record.
 * File format: Each record will follow another with no spaces.
 * Test files: Test1: Basic test  Test2: Single char test  Test3: Large record test
 */
#include <fstream>
#include <iostream>
#include <string>
#include "main.h"
using namespace std;

int main(int argc, char **argv) {

	string x = "", y;
	cout << "Enter your file name.";
	cin >> y;
	fstream fl (y,ios::in|ios::out|ios::binary);
	for(int i = 0; i < 4; i++) x += fl.get();
	int a = atoi(x.c_str()); //Converting a string to an int

	fl.seekg (0,ios::end);  //how many bytes are in the file?
	int n = fl.tellg();
	n-=4;z
	int recs = n/a;  //how many records are in the file
	ShellSort (fl, a, recs);
	system("pause");
	return 0;
}


void ShellSort (fstream &fl, int recordLength, int numRecords) {
	int d = numRecords;
	while (d > 1) {
		if (d==2) d = 1;  //Computes a new smaller distance
		else if (d%2==1) d = (d+1)/2;
		else if (d%4==0) d = d/2+1;
		else d = d/2+2;
		for (int i=d; i < numRecords; i++) //Insertion Sort of elements d apart
			for (int j=i-d; j >= 0; j-=d) {

				string a = "", b = "";
				fl.seekg((j*recordLength)+4); //Find first record, get each character depending on record length
				for(int ii =0; ii<recordLength;ii++) a+=fl.get();

				fl.seekg(((j+d)*recordLength)+4); //Finding and getting second record to compare
				for(int ii =0; ii<recordLength;ii++) b+=fl.get();

				if (a<=b) break; //If already in order, do not swap them

				fl.seekp((j*recordLength)+4); //Seeks the position of second record, put each character at a time from first record
				for(int ii = 0; ii<recordLength;ii++) fl.put(b[ii]);

				fl.seekp(((j+d)*recordLength)+4);//Seeks position of first record, puts second in there
				for(int ii = 0; ii<recordLength;ii++) fl.put(a[ii]);
			}
	}
}
