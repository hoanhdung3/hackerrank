#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'alternate' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int alternate(string s) {
    string a = "abcdefghijklmnopqrstuvwxyz";
    int ans = 0;
    for(int i=0;i<26;i++){
        for(int j=i+1;j<26;j++){
            char x = a[i];
            char y = a[j];
            string t = "";
            for(int k=0;k<s.length();k++)
                if(s[k]==x || s[k]==y)
                    t+=s[k];
            int check = 1;
            for(int f=0;f<t.length()-1;f++)
                if(t[f]==t[f+1]){
                    check=0;
                    break;
                }
            int ts = t.length();
            if(check==1 && ts>1)
                ans = max(ans,ts);
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
