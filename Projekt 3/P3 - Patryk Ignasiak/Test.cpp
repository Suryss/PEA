#include "Test.h"
using namespace std;
void Test::test1() {
	Data data = Data();
	int globalBest = INT32_MAX, best = INT32_MAX;
	int populationSizes[3] = { 50, 500, 5000 };
	
	data.readFile("ftv47.xml");
	

	for (int i = 1; i < 2; i++) {
		best = INT32_MAX;
		cout << populationSizes[i] << endl;
		for (int j = 0; j < 10; j++) {
			Algorithm alg = Algorithm();

			alg.genetic(data.matrix, data.size, 30, populationSizes[i], 0.01, 0.8, false);
			if (best > alg.bestResult) {
				best = alg.bestResult;
				data.saveTestResult(alg.times, alg.costs, populationSizes[i], 4);
				if (globalBest > best) {
					globalBest = best;
					data.savePathTS(alg.bestPath, "GA_", "ftv47.xml");
				}
				
			}
		}

	}


	data.readFile("ftv170.xml");
	
	globalBest = INT32_MAX;

	for (int i = 0; i < 3; i+=2) {
		best = INT32_MAX;
		cout << populationSizes[i] << endl;
		for (int j = 0; j < 10; j++) {
			Algorithm alg = Algorithm();

			alg.genetic(data.matrix, data.size, 60, populationSizes[i], 0.01, 0.8, false);
			if (best > alg.bestResult) {
				best = alg.bestResult;
				data.saveTestResult(alg.times, alg.costs, populationSizes[i], 5);
				if (globalBest > best) {
					globalBest = best;
					data.savePathTS(alg.bestPath, "GA_", "ftv170.xml");
				}

			}
		}

	}
	
	data.readFile("rbg403.xml");
	

	globalBest = INT32_MAX;

	for (int i = 1; i < 3; i++) {
		best = INT32_MAX;
		cout << populationSizes[i] << endl;
		for (int j = 0; j < 10; j++) {
			Algorithm alg = Algorithm();

			alg.genetic(data.matrix, data.size, 90, populationSizes[i], 0.01, 0.8, false);
			if (best > alg.bestResult) {
				best = alg.bestResult;
				data.saveTestResult(alg.times, alg.costs, populationSizes[i], 6);
				if (globalBest > best) {
					globalBest = best;
					data.savePathTS(alg.bestPath, "GA_", "rbg403.xml");
				}

			}
		}

	}

}
void Test::test2() {
	Data data = Data();
	int globalBest = INT32_MAX, best = INT32_MAX;
	double mutationRate[3] = { 0.02, 0.05, 0.10 };

	data.readFile("ftv47.xml");


	for (int i = 0; i < 3; i++) {
		best = INT32_MAX;
		cout << mutationRate[i] << endl;
		for (int j = 0; j < 10; j++) {
			Algorithm alg = Algorithm();

			alg.genetic(data.matrix, data.size, 30, 5000,mutationRate[i], 0.8, false);
			if (best > alg.bestResult) {
				best = alg.bestResult;
				data.saveTestResult(alg.times, alg.costs, mutationRate[i], 4);
				if (globalBest > best) {
					globalBest = best;
					data.savePathTS(alg.bestPath, "GA_", "ftv47.xml");
				}

			}
		}

	}


	data.readFile("ftv170.xml");

	globalBest = INT32_MAX;

	for (int i = 0; i < 3; i ++) {
		best = INT32_MAX;
		cout << mutationRate[i] << endl;
		for (int j = 0; j < 10; j++) {
			Algorithm alg = Algorithm();

			alg.genetic(data.matrix, data.size, 60, 500,mutationRate[i], 0.8, false);
			if (best > alg.bestResult) {
				best = alg.bestResult;
				data.saveTestResult(alg.times, alg.costs, mutationRate[i], 5);
				if (globalBest > best) {
					globalBest = best;
					data.savePathTS(alg.bestPath, "GA_", "ftv170.xml");
				}

			}
		}

	}

	data.readFile("rbg403.xml");


	globalBest = INT32_MAX;

	for (int i = 0; i < 3; i++) {
		best = INT32_MAX;
		cout << mutationRate[i] << endl;
		for (int j = 0; j < 10; j++) {
			Algorithm alg = Algorithm();

			alg.genetic(data.matrix, data.size, 90, 5000,mutationRate[i], 0.8, false);
			if (best > alg.bestResult) {
				best = alg.bestResult;
				data.saveTestResult(alg.times, alg.costs, mutationRate[i], 6);
				if (globalBest > best) {
					globalBest = best;
					data.savePathTS(alg.bestPath, "GA_", "rbg403.xml");
				}

			}
		}

	}

}