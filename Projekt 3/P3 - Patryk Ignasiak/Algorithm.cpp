#include "Algorithm.h"
#include <iostream>
#include <unordered_map>
using namespace std;
void Algorithm::genetic(const vector<vector<int>> matrix, int size, int stop, int populationSize, double mutationRate, double crossRate, bool oX) {
    // Inicjalizacja populacji
    std::vector<std::vector<int>> population;
    for (size_t i = 0; i < populationSize; i++) {
        
        population.push_back(generatePath(matrix, size));
    }

    // Oblicz wartoœci fitness dla ka¿dego osobnika
    std::vector<int> fitnessValues;
    for (const auto& individual : population) {
        int value = calculateFitness(individual, matrix, size);
        fitnessValues.push_back(value);
        if (bestResult > value) {
            bestResult = value;
            bestPath = individual;
        }
    }
    costs[0] = bestResult;
    int z = 1;
    time_t startTime = time(NULL);
    auto start = chrono::steady_clock::now();
    do {
        
        // Krzy¿owanie osobników
        for (int j = 0; j < populationSize; j++) {
            if (rand() / static_cast<double>(RAND_MAX) < crossRate) {
                int choose1, choose2;
                do {
                    choose1 = rand() % populationSize;
                    choose2 = rand() % populationSize;
                } while (choose1 == choose2);

                if (oX) {
                    population.push_back(orderCrossover(population[choose1], population[choose2], size));
                }
                else {
                    population.push_back(partiallyMappedCrossover(population[choose1], population[choose2], size));
                }
                
            }
        }
        // Mutacja osobników
        for (int j = 0; j < populationSize; j++) {
            if (rand() / static_cast<double>(RAND_MAX) < mutationRate) {
                int choose1;

                choose1 = rand() % populationSize;

                population.push_back(swapMutation(population[choose1], size));
            }
            
        }

        // Oblicz wartoœci fitness dla ka¿dego osobnika
        fitnessValues.clear();
        for (const auto& individual : population) {
            int value = calculateFitness(individual, matrix, size);
            fitnessValues.push_back(value);
            if (bestResult > value) {
                bestResult = value;
                bestPath = individual;

                auto end = chrono::steady_clock::now();
                auto duration = end - start;
                times[z] = chrono::duration_cast<chrono::microseconds>(duration).count();
                costs[z] = bestResult;
               
                z++;
            }
        }

        // Selekcja metod¹ turniejow¹
        population = tournament(population, fitnessValues, populationSize);

    } while (time(NULL) - startTime < stop);
}
std::vector<int> Algorithm::generatePath(std::vector<std::vector<int>> matrix, int size) {
    vector<int> path(size);
    vector<int> tmp(size);
    bool* visited = new bool[size] {false}; // Tablica do œledzenia, czy miasto zosta³o odwiedzone
    // Losowy wybór startowego miasta
    int firstCity = rand() % size;
    path[0] = firstCity;
    visited[firstCity] = true;

    // Wybór kolejnych miast
    for (int i = 1; i < size; ++i) {
        int lastCity = path[i - 1];
        int nextCity = -1;
        int bCost = INT32_MAX;

        // Wybór najbli¿szego miasta spoœród nieodwiedzonych
        for (int j = 0; j < size; ++j) {
            if (!visited[j] && matrix[lastCity][j] < bCost) {
                bCost = matrix[lastCity][j];
                nextCity = j;
            }
        }
        // Zaznaczenie miasta jako odwiedzonego
        visited[nextCity] = true;
        path[i] = nextCity;
    }

    return path;
}
std::vector<std::vector<int>> Algorithm::tournament( std::vector<std::vector<int>>& population, const std::vector<int>& fitnessValues, int populationSize) {
    std::vector<vector<int>> parents;
    int tournamentSize = 2;
    
    for (int i = 0; i < populationSize; i++) {
        // Wybór grupy turniejowej
        std::vector<int> tournament_group, indexes;
        for (int j = 0; j < tournamentSize; ++j) {
            int randomIndex = rand() % population.size();
            tournament_group.push_back(fitnessValues[randomIndex]);
            indexes.push_back(randomIndex);
        }
        // Wybór najlepszego kandydata
        auto bestIndex = std::min_element(tournament_group.begin(), tournament_group.end()) - tournament_group.begin();
        parents.push_back(population[indexes[bestIndex]]);
    }
    population.clear();
    return parents;
}
int Algorithm::calculateFitness(const std::vector<int>& route, const std::vector<std::vector<int>>& matrix, int size) {
    int totalDistance = 0;
    for (int i = 0; i < size - 1; ++i) {
        
        if (i < size - 1 && route[i] < size && route[i + 1] < size) {
            totalDistance += matrix[route[i]][route[i + 1]];
        }
        else {
            cout << i << " " << route[i] << " " << route[i + 1] << endl;
        }
        

    }
    totalDistance += matrix[route.back()][route.front()];  
    return totalDistance;  
}

int Algorithm::rouletteWheelSelection(std::vector<int>& fitnessValues) {
    int totalFitness = std::accumulate(fitnessValues.begin(), fitnessValues.end(), 0.0);
    int randomValue = (int)(rand() / static_cast<double>(RAND_MAX) * (double)totalFitness);

    int cumulativeFitness = 0;
    for (size_t i = 0; i < fitnessValues.size(); i++) {
        cumulativeFitness += fitnessValues[i];
        if (cumulativeFitness >= randomValue) {
            fitnessValues[i] = 0;
            return i;
        }
    }

    return -1;
}

std::vector<int> Algorithm::orderCrossover(const std::vector<int>& parent1, const std::vector<int>& parent2, int size) {
    size_t start = rand() % size;
    size_t end = rand() % size;
    if (start > end) {
        std::swap(start, end);
    }

    std::vector<int> child(size, -1);

    // Przekopiuj fragment trasy od rodzica1 do potomka
    for (size_t i = start; i <= end; i++) {
        child[i] = parent1[i];
    }

    // Uzupe³nij resztê trasy potomka u¿ywaj¹c miast z rodzica2
    size_t index = 0;
    for (size_t i = 0; i < size; i++) {
        if (child[i] == -1) {
            while (std::find(child.begin(), child.end(), parent2[index]) != child.end()) {
                index++;
            }
            child[i] = parent2[index];
        }
    }

    return child;
}
std::vector<int> Algorithm::swapMutation(std::vector<int> route, int size) {
    size_t i, j;
    do {
        i = rand() % size;
        j = rand() % size;
    } while (i == j);
    std::swap(route[i], route[j]);

    return route;
}

std::vector<int> Algorithm::partiallyMappedCrossover(const std::vector<int>& parent1, const std::vector<int>& parent2, int size) {
    size_t start = rand() % size;
    size_t end = rand() % size;
    while (start == end) {
        end = rand() % size;
    }
    if (start > end) {
        std::swap(start, end);
    }

    // Zainicjuj potomka jako kopiê jednego z rodziców
    std::vector<int> child(parent1.begin(), parent1.end());

    // Mapa do œledzenia przyporz¹dkowañ
    std::unordered_map<int, int> assignmentMap;

    // Skopiuj fragment miêdzy punktami krzy¿owania z drugiego rodzica do potomka
    for (int i = start; i <= end; ++i) {
        assignmentMap[parent2[i]] = parent1[i];
        child[i] = parent2[i];
    }

    // Zast¹p duplikaty w potomku przy u¿yciu przyporz¹dkowañ
    for (int i = 0; i < size; ++i) {
        if (i < start || i > end) {
            int currentValue = child[i];
            while (assignmentMap.find(currentValue) != assignmentMap.end()) {
                currentValue = assignmentMap[currentValue];
            }
            child[i] = currentValue;
        }
    }

    return child;
}

