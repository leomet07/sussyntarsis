#include <iostream>
#include <vector>

using namespace std;
 
int getInt(){
    int i;
    cin >> i;
    return i; 
}

long long getLongLong(){
    long long l; // always have a 64bit num
    cin >> l;
    return l;
}

string getString(){
    string s;
    cin >> s;
    return s;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0); // unsync stdin and stdout, is fine for comp bc no input prompts are printed

    long long ins = getLongLong();
    
    for (long long i = 0; i < 1; i++){
        // run
        string s = getString();

        vector<size_t> suses;
        vector<size_t> ntarsises;

        size_t last_sus = s.find("sus");
        size_t last_ntarsis = s.find("ntarsis");

        // find all occurences

        while (last_sus != string::npos){
            cout << "Occurence of sus: " << last_sus + 1 << endl;
            suses.push_back(last_sus);
            last_sus = s.find("sus", last_sus + 3); // 3 bc sus is 3 chars long
        }
        while (last_ntarsis != string::npos){
            cout << "Occurence of ntarsis: " << last_ntarsis << endl;
            ntarsises.push_back(last_ntarsis);
            last_ntarsis = s.find("ntarsis", last_ntarsis + 7); // 7 bc natrsis is 7 chars long
        }

        long long sus_occurences = suses.size();
        long long ntarsis_occurences = ntarsises.size();

        cout << sus_occurences + ntarsis_occurences << endl;
        
        for (int i = 0; i < sus_occurences; i++){
            cout << suses[i] + 1 << " ";
        }
        for (int i = 0; i < ntarsis_occurences; i++){
            cout << ntarsises[i] + 6 << " ";
        }

        cout << endl;
        
        
    
    }
    return 0;

}
