#include "Test.h"
#include "SA.h"
#include "Data.h"
#include <iostream>
#include "TS.h"
using namespace std;
void Test::testSW() {
	Data data = Data();
	data.readFile("ftv55.xml");
	int best = INT32_MAX;
	double a[6] = { 0.85, 0.88, 0.92, 0.95, 0.999, 0.999999 };
	
	for (int i = 0; i < 6; i++) {
		cout << a[i] << endl;
		for (int j = 0; j < 10; j++) {
			SA sa = SA();
			
			sa.annealingIns(data.matrix, data.size, 30, a[i], 100);
			if (best > sa.bestCost && sa.times[2] != 0) {
				data.savePath(sa.bestPath,"SA_", "ftv55.xml");
				data.saveTestResult(sa.times, sa.costs, a[i], 11);
			}
			sa.annealingLine(data.matrix, data.size, 30, a[i], 100);
			if (best > sa.bestCost && sa.times[2] != 0) {
				data.savePath(sa.bestPath, "SA_", "ftv55.xml");
				data.saveTestResult(sa.times, sa.costs, a[i], 12);
			}
			sa.annealingLog(data.matrix, data.size, 30, a[i], 100);
			if (best > sa.bestCost && sa.times[2] != 0) {
				data.savePath(sa.bestPath, "SA_", "ftv55.xml");
				data.saveTestResult(sa.times, sa.costs, a[i], 13);
			}
		}

	}
	
	data.readFile("ftv170.xml");
	best = INT32_MAX;

	for (int i = 0; i < 5; i++) {
		cout << a[i] << endl;
		for (int j = 0; j < 10; j++) {
			SA sa = SA();
			sa.annealingIns(data.matrix, data.size, 60, a[i], 100);
			if (best > sa.bestCost && sa.times[2] != 0) {
				data.savePath(sa.bestPath, "SA_", "ftv170.xml");
				data.saveTestResult(sa.times, sa.costs, a[i], 21);
			}
			sa.annealingLine(data.matrix, data.size, 60, a[i], 100);
			if (best > sa.bestCost && sa.times[2] != 0) {
				data.savePath(sa.bestPath, "SA_", "ftv170.xml");
				data.saveTestResult(sa.times, sa.costs, a[i], 22);
			}
			sa.annealingLog(data.matrix, data.size, 60, a[i], 100);
			if (best > sa.bestCost && sa.times[2] != 0) {
				data.savePath(sa.bestPath, "SA_", "ftv170.xml");
				data.saveTestResult(sa.times, sa.costs, a[i], 23);
			}
		}

	}
	
	data.readFile("rbg358.xml");
	best = INT32_MAX;

	for (int i = 0; i < 5; i++) {
		cout << a[i] << endl;
		for (int j = 0; j < 10; j++) {
			SA sa = SA();
			sa.annealingIns(data.matrix, data.size, 90, a[i], 100);
			if (best > sa.bestCost && sa.times[2] != 0) {
				data.savePath(sa.bestPath, "SA_", "rgb358.xml");
				data.saveTestResult(sa.times, sa.costs, a[i], 31);
			}
			sa.annealingLine(data.matrix, data.size, 90, a[i], 100);
			if (best > sa.bestCost && sa.times[2] != 0) {
				data.savePath(sa.bestPath, "SA_", "rgb358.xml");
				data.saveTestResult(sa.times, sa.costs, a[i], 32);
			}
			sa.annealingLog(data.matrix, data.size, 90, a[i], 100);
			if (best > sa.bestCost && sa.times[2] != 0) {
				data.savePath(sa.bestPath, "SA_", "rgb358.xml");
				data.saveTestResult(sa.times, sa.costs, a[i], 33);
			}
		}

	}
}
void Test::testTS() {
	Data data = Data();
	int best = INT32_MAX;
	data.readFile("ftv55.xml");

	for (int j = 0; j < 10; j++) {
		TS ts = TS();
		ts.TabuSearch(data.matrix, data.size, 30, 3);
		if (best > ts.bestCost ) {
			data.savePathTS(ts.bestPath, "TS_1", "ftv55.xml");
			data.saveTestResult(ts.times, ts.costs, 0.0, 13);
			best = ts.bestCost;
		}
	}
	data.readFile("ftv170.xml");
	best = INT32_MAX;

	for (int j = 0; j < 10; j++) {
		TS ts = TS();
		ts.TabuSearch(data.matrix, data.size, 60, 3);
		if (best > ts.bestCost) {
			data.savePathTS(ts.bestPath, "TS_2", "ftv170.xml");
			data.saveTestResult(ts.times, ts.costs, 0.0, 23);
			best = ts.bestCost;
		}
	}
	
	data.readFile("rbg358.xml");
	best = INT32_MAX;

	for (int j = 0; j < 10; j++) {
		cout << j << endl;
		TS ts = TS();
		ts.TabuSearch(data.matrix, data.size, 90, 3);
		if (best > ts.bestCost) {
			data.savePathTS(ts.bestPath, "TS_3", "rgb358.xml");
			data.saveTestResult(ts.times, ts.costs, 0.0, 33);
			best = ts.bestCost;
		}
	}
}