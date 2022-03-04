#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'separateNumbers' function below.
 *
 * The function accepts STRING s as parameter.
 */

void separateNumbers(string s) {
    long long int a,b,c;
    a=b=c=0;
    int f=0;
    for(int i=0;i<=s.size()/2;i++){
        a=a*10+((int)s[i]-'0');
        c=a;
        f=0;
        b=0;
        for(int j=i+1;j<s.size();j++){
            b=b*10+((int)s[j]-'0');
            if(b==0 || (b-a)>1){
                f=0;
                break;
            }
            if((b-a)==1){
                f=1; 
                a=b;
                b=0;
            }
            else f=0;
        }
        if(f){
            cout<<"YES"<<" "<<c<<endl; 
            break;
        }
        a=c;
    }
    if(!f) cout<<"NO"<<endl;
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

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
