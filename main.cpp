#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
    
    void readFile(vector<string>& v, string fileName); //reads file and stores it in a vector
    void markSynonyms(vector<string>& v, vector<string> syn); //indicates if word is in synonym list and changes it to unique word
    int tupleNumber(vector<string> v, int tuple);   //finds number of tuples in a vector of strings
    int getTupleMatches(vector<string> v1, vector<string> v2, int tuple); //gets the number of tuple matches

    string synfile = "blank";
    string file1 = "blank";
    string file2 = "blank";
    int tuple = 3;
    vector<string> syn_vector;
    vector<string> file1_vector;
    vector<string> file2_vector;

    cout << "List of Synonyms File: ";      //RETRIEVES VARIABLES (WHAT IF INCORRECT INPUTS?)
    cin >> synfile;
    cout << endl;
    readFile(syn_vector, synfile);

    cout << "File 1 name: ";                
    cin >> file1;
    cout << endl;
    readFile(file1_vector, file1);

    cout << "File 2 name: ";
    cin >> file2;
    cout << endl;
    readFile(file2_vector, file2);

    cout << "Input tuple number: ";
    cin >> tuple;

    markSynonyms(file1_vector, syn_vector);
    markSynonyms(file2_vector, syn_vector);

    double matches = getTupleMatches(file1_vector, file2_vector, tuple);
    double totalTuples = tupleNumber(file1_vector, tuple);
    double percentage = (matches / totalTuples) * 100;

    cout << "Chance Percentage of Student CHEATING is: " << percentage << endl;

    if(percentage <= 50) {
        cout << "He/She good" << endl;
    }

    if(percentage >= 70) {
        cout << "HE/SHE CHEATIN' FAIL FAIL FAIL" << endl;
    } 

    return 0;
}

void readFile(vector<string>& v, string fileName) {
    
    ifstream infs;
    string word;
    infs.open(fileName);
    infs >> word;
    v.push_back(word);
    while(infs.good()) {
        infs >> word;
        v.push_back(word);
    }

    return;
}

void markSynonyms(vector<string>& v, vector<string> syn) {

    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < syn.size(); j++) {
            if(v.at(i) == syn.at(j)) {
                v.at(i) = "UwU";
            }
        }
    }
    return;
}

int tupleNumber(vector<string> v, int tuple) {

    int number_of_tuples = 0;

    if(tuple < v.size()) {
        number_of_tuples = (v.size() - tuple) + 1;
    }

    return number_of_tuples;
}

int getTupleMatches(vector<string> v1, vector<string> v2, int tuple) {
    
    int number_of_matches = 0;
    vector<string> sub_v1;
    vector<string> sub_v2;
    int temp_v1_size = v1.size();
    int temp_v2_size = v2.size();
    int matchCount = 0;
    int k = 0;

    tuple--;
    
    while((tuple < temp_v1_size)&&(tuple < temp_v2_size)) {
        for(int i = k; i <= tuple; i++) {
            sub_v1.push_back(v1.at(i));
            sub_v2.push_back(v2.at(i));
        }

        for(int j = 0; j < sub_v1.size(); j++) {
            if(sub_v1.at(j) == sub_v2.at(j)) {
                matchCount++;
            }
        }

        if(matchCount == sub_v1.size()) {
            number_of_matches++;
        }

        sub_v1.clear();
        sub_v2.clear();
        matchCount = 0;
        k++;
        tuple++;
    }

    return number_of_matches;
}