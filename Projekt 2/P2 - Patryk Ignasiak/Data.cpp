#include "Data.h"


using namespace std;
void Data::readFile(string filename) {
    // Otwórz plik XML
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Nie mo¿na otworzyæ pliku XML." << std::endl;
        return;
    }
    //policz wierzcho³ki
    std::string line;
    size = 0;
    while (std::getline(file, line)) {
        if (line.find("<vertex>") != std::string::npos) {
            size++;
        }
    }
    file.close();
   //utwórz macierz
    std::vector<std::vector<int>>tmpMatrix(size, std::vector<int>(size, INT32_MAX));
    this->matrix = tmpMatrix;
    //za³aduj dane
    std::ifstream f(filename);
    int numOfRow = -1;
    while (std::getline(f, line)) {
        if (line.find("<vertex>") != std::string::npos) {
            numOfRow++;
        }
        if (line.find("<edge") != std::string::npos) {
            double edge;
            double power;
            int index;
            size_t startPos = line.find("\"") + 1;
            size_t endPos = line.find("e", startPos);
            std::string numberStr = line.substr(startPos, endPos - startPos);
            std::istringstream iss(numberStr);
            iss >> edge;
            startPos = line.find("+") + 1;
            endPos = line.find("\"", startPos);
            numberStr = line.substr(startPos, endPos - startPos);
            numberStr = line.substr(startPos, endPos - startPos);
            std::istringstream iss2(numberStr);
            iss2 >> power;
            edge = edge * pow(10, power);
            startPos = line.find(">") + 1;
            endPos = line.find("<", startPos);
            numberStr = line.substr(startPos, endPos - startPos);
            numberStr = line.substr(startPos, endPos - startPos);
            std::istringstream iss3(numberStr);
            iss3 >> index;
            matrix[numOfRow][index] = edge;
        }
    }
   
    f.close();
    cout << "Dane zosta³y wczytane!!!" << endl;
}
void Data::showMatrix() {
    cout << endl << "Macierz s¹siedztwa" << endl << endl;
    cout << "      ";
    for (int i = 0; i < size; i++) {
        printf("%5d ", i);
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        printf("%5d ", i);
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] < INT32_MAX) {
                printf("%5d ", matrix[i][j]);
            }
            else {
                cout << "    ~ ";
            }

        }
        cout << endl;
    }
}
void Data::savePath(int* path, string alg, string filename) {
    if (size == 1) {
        cout << "Brak danych do zapisania!!!" << endl;
        return;
    }
    //Tworzymy plik i zapisujemy rozmiar
    size_t num = filename.find(".");
    string name = alg + filename.substr(0, num) + ".txt";
    ofstream file(name);

    file << size << endl;

    file.close();
    //otwieramy plik do nadpisania
    //i zapisujemy  dane
    file.open(name, ios_base::app);
    for (int i = 0; i < size; i++) {
        file << path[i];
        file << endl;
    }
    file.close();
}void Data::savePathTS(std::vector<int> path, string alg, string filename) {
    if (size == 1) {
        cout << "Brak danych do zapisania!!!" << endl;
        return;
    }
    //Tworzymy plik i zapisujemy rozmiar
    size_t num = filename.find(".");
    string name = alg + filename.substr(0, num) + ".txt";
    ofstream file(name);

    file << size << endl;

    file.close();
    //otwieramy plik do nadpisania
    //i zapisujemy dane
    file.open(name, ios_base::app);

    for (int i = 0; i < size; i++) {
        file << path[i];
        file << endl;
    }
    file.close();
}
void Data::loadPath(string filename) {
    // Otwórz plik 
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Nie mo¿na otworzyæ pliku." << std::endl;
    }

    std::string line;

    bool wasFirst = false;
    cout << "Œcie¿ka: ";
    int first = -1;
    int prev, sum = 0;
    while (std::getline(file, line)) {
        if (wasFirst) {      
            cout << line << " | ";
            int v;
            std::istringstream iss(line);
            iss >> v;
            if (first == -1) {
                first = v;
            }
            else {
                sum += matrix[prev][v];
            }
            prev = v;
        }
        wasFirst = true;
    }
    sum += matrix[prev][first];
    cout << "\nDroga: " << sum;
}
void Data::saveTestResult(long long times[100], int costs[100], double a, int type) {
    number++;
    ofstream file(to_string(type)+"rezult"+ to_string(a) + ".txt");

    for (int i = 0; i < 100; i++) {
        if (costs[i] != 0) {
            file << times[i];
            file << ",";
            file << costs[i];
            file << endl;
        }
        else {
            break;
        }
    }
    file.close();
}