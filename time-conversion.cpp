#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    int h = ((s[0]-'0')*10) + (s[1]-'0');
    stringstream st;
    if(s[8]=='A' && h==12) st<<"00";
    else if(s[8]=='P' && h==12) st<<"12";
    else if(s[8]=='P' && h!=12) st<<h+12;
    else st<<'0'<<h;
    for(int i=2;i<8;i++){
        st<<s[i];
    }
    string a;
    st>>a;
    return a;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
