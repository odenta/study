#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
using namespace std;

void transform(const map<string, string> &rules, istream &input, ostream &output);
const map<string, string> read_rules(istream &);

void text_transform (ifstream &map_file, ifstream & input);
map<string, string> build_map(ifstream &mapfile);


int main(int argc, char* argv[])
{
    if (argc < 3) {
        cout << "Error, usage: "<< endl <<
                "  prgm rules.file input.file" << endl;
        return 1;
    }

    ifstream rules_stream(argv[1]), input_stream(argv[2]);
    transform(read_rules(rules_stream), input_stream, cout);

    return 0;
}


void transform(const map<string, string> &rules, istream &input, ostream &output)
{

}

const map<string, string> read_rules(istream &strm)
{
    string line;
    istringstream tockens;
    map<string, string> rules;
    while (getline(strm, line)) {
        tockens = istringstream(line);
        string val_in, val_out;
        if (tockens >> val_in)
            if (tockens >> val_out)
                rules[val_in] = val_out;
    }
    return rules;
}


map<string, string> build_map(ifstream &mapFile)
{
    map<string, string> transform_map;
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
