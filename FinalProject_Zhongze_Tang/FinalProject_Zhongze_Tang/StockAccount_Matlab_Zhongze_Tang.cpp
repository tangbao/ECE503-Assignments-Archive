#include"HelperFunc.h"
#include"StockAccount.h"
#include<yvals.h>
#if(_MSC_VER >= 1600)
#define __STDC_utf_16__
#endif

#include"mex.h"
#include<engine.h>
#include<iostream>

#pragma comment(lib, "libmx.lib")
#pragma comment(lib, "libmex.lib")
#pragma comment(lib, "libeng.lib")

using namespace std;

//the body of the code is from class

void StockAccount::printGraph() {
	Engine *ep;
	ep = engOpen(NULL);
	if (ep == NULL) {
		cout << "Error: engine open failed" << endl;
		exit(1);
	}

	//only draw the graph of the first 100 points(if less than 100, then draw the graph of all points)

	int num = hf.getLineNum(PORTFOLIO_FILE); //get the number of lines in PORTFOLIO_FILE
	long time_first; //get the time of the first data
	double time[100]; //the time when the portfolio value is stored - time_first
	double value[100]; //the portfolio value
	
	ifstream ifs;
	int j = 0;
	ifs.open(PORTFOLIO_FILE);
	if (ifs.fail()) {
		cout << "Error: " << PORTFOLIO_FILE << " cannot open" << endl;
		return;
	}
	else {
		string line;
		while (getline(ifs, line) && j < 100) { //while not reach the end of the file and while havn't read in 100 pairs of data
			if (j == 0) {
				time_first = atof(hf.getSplit(line, 2).c_str()); // get the time of the first data
			}
			time[j] = (atof(hf.getSplit(line, 2).c_str()) - time_first) / 60.0; //  /60.0 to get the minute
			value[j] = atof(hf.getSplit(line, 1).c_str()); //get the value
			j++;
		}
		ifs.close();
	}

	for (int i = 0; i < 100; ++i) {
		if (i >= j) { //if the number of value is less than 100, then the rest value and time in the array will equal to the last one
			time[i] = time[i - 1];
			value[i] = value[i - 1];
		}
	}

	mxArray *X;
	X = mxCreateDoubleMatrix(1, 100, mxREAL);
	memcpy((void *)mxGetPr(X), (void *)time, sizeof(double) * 100);
	mxArray *Y;
	Y = mxCreateDoubleMatrix(1, 100, mxREAL);
	memcpy((void *)mxGetPr(Y), (void *)value, sizeof(double) * 100);

	engPutVariable(ep, "x", X); 
	engPutVariable(ep, "y", Y);
	engEvalString(ep, "plot(x, y)");

	system("pause");

	mxDestroyArray(X);
	mxDestroyArray(Y);
	engEvalString(ep, "close;");
	engClose(ep);
}