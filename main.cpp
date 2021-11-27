#include <iostream>
#include <iterator>
#include <set>


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
    
    for (long long i = 0; i < ins; i++){
        // run
        string s = getString();

        // empty set container
        set<int, greater<int> > rem;
 
        
        
        size_t last_ntarsisus = s.find("ntarsisus");
        // account for ntarsisus
        while (last_ntarsisus != string::npos){
            
            rem.insert(last_ntarsisus + 6);  // to remove the second s in ntarsisus
            s.replace(last_ntarsisus, 9,"jjjjjjjjj"); // so the sus inside ntarsisus is not found later on

            last_ntarsisus = s.find("ntarsisus", last_ntarsisus + 9); // 9 bc natrsisus is 9 chars long
        }

        

        size_t last_sus = s.find("sus");
        size_t last_ntarsis = s.find("ntarsis");
        // find all occurences
        while (last_sus != string::npos){
            rem.insert(last_sus + 1); // to remove the u in sus
            last_sus = s.find("sus", last_sus + 3); // 3 bc sus is 3 chars long
        }
        while (last_ntarsis != string::npos){
            rem.insert(last_ntarsis + 6);  // to remove the last s in ntarsis
            last_ntarsis = s.find("ntarsis", last_ntarsis + 7); // 7 bc natrsis is 7 chars long
        }
        

        cout << rem.size() << endl;

        set<int >::iterator it ;
        for (it = rem.begin() ; it != rem.end() ; it++ ) {
            cout << *it<<" ";
        }

        cout << endl;
    
    }
    return 0;

}
