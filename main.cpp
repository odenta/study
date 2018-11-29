#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;
using umap = unordered_map<string, string>;

void text_transform (ifstream &map_file, ifstream & input);
umap build_map(ifstream &mapfile);
const string& word_transform(const string &input, const umap &rules);


int main(int argc, char* argv[])
{
    if (argc < 3) {
        cout << "Error, usage: "<< "\n" <<
                "  prgm rules.file input.file" << "\n";
        return 1;
    }

    ifstream rules_stream(argv[1]), input_stream(argv[2]);
    if (!rules_stream || !input_stream) {
        cerr << "can't open input files" << endl;
        return -1;
    }
    text_transform(rules_stream, input_stream);

    return 0;
}

const string& word_transform(const string &input, const umap &rules)
{
    auto map_it = rules.find(input);
    if (map_it == rules.end()) {
        return input;
    }
    return map_it->second;
}


umap build_map(ifstream &mapFile)
{
    umap transform_map;
    string key, value;
    while (mapFile >> key && getline(mapFile, value)) {
        if (value.size() > 1) {
            transform_map[key] = value.substr(1);
        } else {
            throw runtime_error("no value for the key " + key);
        }
    }
    return transform_map;
}

void text_transform (ifstream &map_file, ifstream & input)
{
    auto rules = build_map(map_file);

    for (uint n = 0; n < rules.bucket_count(); n++) {
        
    }

    string line;
    while (getline(input, line)) {
        istringstream stream(line);
        string word;
        bool isFirstWord = true;
        while (stream >> word) {
            if (isFirstWord) {
                isFirstWord = false;
            } else {
                cout << " ";
            }
            cout << word_transform(word, rules);
        }
        cout << "\n";
    }
}
