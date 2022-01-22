#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'migratoryBirds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int migratoryBirds(vector<int> arr) {
    // int max=1;
    // vector<int> v;
    // sort(arr.begin(),arr.end());
    // int c = arr[0];
    
    // for(int i =1 ;i<arr.size();i++){
    //     if(arr[i] == c) max++;
    //     else{
    //         v.push_back(max);
    //         c = arr[i];
    //         max =1;
    //     }
    // }
    // for(int i=1;i<arr.size();){
    //     if(arr[i] == arr[i-1]) arr.erase(arr.begin()+i);
    //     else i++;
    // }
    // int t=0;
    // int m =0;
    // for(int i=0;i<v.size();i++){
    //     if(v[i]>m){
    //         m = v[i];
    //         t = i;
    //     }
    // }
    // return arr[t];
    map<int,int> m;
    for(auto &i : arr){
        m[i]++;
    }
    
    map<int,int>::iterator tracker = m.begin();
    for( map<int,int>::iterator itr = ++tracker; itr != m.end(); ++itr ){
        if(itr->second > tracker->second) tracker = itr;
        else if(itr->second == tracker->second){
            tracker = (tracker->first < itr->first) ? tracker : itr;
        }
    }
    return tracker->first;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = migratoryBirds(arr);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
