#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string superReducedString(string s) {
    for(int i=0;i<int(s.length())-1;i++){
        if(s[i] == s[i+1]){
            s.erase(s.begin()+i,s.begin()+i+2);
            i=-1;
        }
    }
    return (s.length()==0) ? "Empty String" : s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
