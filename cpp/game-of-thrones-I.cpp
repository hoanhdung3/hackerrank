#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'gameOfThrones' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string gameOfThrones(string s) {
    array<int,26> arr = {};
    int c = 0;
    for(auto i : s) arr[i-97]++;
    for(int i=0;i<26;i++){
        if(arr[i]!=0 && arr[i]%2!=0) c++;
        if(c>1) return "NO";
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
