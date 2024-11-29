#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <locale>
using namespace std;



vector<string> split(string s){
    vector<string> res;
    stringstream ss(s);
    string w;
    
    while (ss >> w) {
        size_t pos = 0;
        while (pos < w.size()) {
            if (w[pos] == '*' ||  w[pos] == '/' ||  w[pos] == '+' || w[pos] == '-') {     
                if (pos > 0) {
                    res.push_back(w.substr(0, pos));
                }             
                res.push_back(std::string(1, w[pos]));             
                w = w.substr(pos + 1);
                pos = 0; 
            } else {
                pos++;
            }
        }       
        if (!w.empty()) {
            res.push_back(w);
        }
    }
    return res;    
}

string schet1(vector<string> s){
    string r;
    string f;
    if(s[0]=="-"){
            if(s[2]=="*"){
                r=to_string((-1)*stod(s[1])*stod(s[3]));
                s.erase(s.begin(),s.begin()+3);
                s.insert(s.begin(),r);
            }
            if(s[2]=="/"){
                r=to_string((-1)*stod(s[1])/stod(s[3]));
                s.erase(s.begin(),s.begin()+3);
                s.insert(s.begin(),r);
            }
        }
    for(int i=0;i<s.size();++i){
        
        if(s[i] == "*" and s[i+1]=="-"){
            r=to_string((-1)*stod(s[i-1])*stod(s[i+2]));
            s.erase(s.begin()+i-1,s.begin()+i+3);
            s.insert(s.begin()+i-1,r);
            
            
        }else if(s[i] == "*" and s[i+1] !="-"){
            r=to_string(stod(s[i-1])*stod(s[i+1]));
            s.erase(s.begin()+i-1,s.begin()+i+2);
            s.insert(s.begin()+i-1,r);
            i=i-1;
        }
        if(s[i] == "/" and s[i+1]=="-"){
            r=to_string((-1)*stod(s[i-1])/stod(s[i+2]));
            s.erase(s.begin()+i-1,s.begin()+i+3);
            s.insert(s.begin()+i-1,r);
            
        }else if(s[i] == "/" and s[i+1] !="-"){
            r=to_string(stod(s[i-1])/stod(s[i+1]));
            s.erase(s.begin()+i-1,s.begin()+i+2);
            s.insert(s.begin()+i-1,r);
            i=i-1;
        }
    }
    
    if(s[0]=="-"){
            if(s[2]=="+"){
                r=to_string(stod(s[3])-stod(s[1]));
                s.erase(s.begin(),s.begin()+3);
                s.insert(s.begin(),r);
            }
            if(s[2]=="-"){
                r=to_string((-1)*stod(s[1])+stod(s[3]));
                s.erase(s.begin(),s.begin()+3);
                s.insert(s.begin(),r);
            }
        }
    for(int i=0;i<s.size();++i){
        
        
        
        if(s[i] == "+" and s[i+1]=="-"){
            r=to_string(stod(s[i-1])-stod(s[i+2]));
            s.erase(s.begin()+i-1,s.begin()+i+3);
            s.insert(s.begin()+i-1,r);
            
            
        }else if(s[i] == "+" and s[i+1] !="-"){
            r=to_string(stod(s[i-1])+stod(s[i+1]));
            s.erase(s.begin()+i-1,s.begin()+i+2);
            s.insert(s.begin()+i-1,r);
            i=i-1;
            
        }
        if(s[i] == "-" and s[i+1]=="-"){
            r=to_string(stod(s[i-1])+stod(s[i+2]));
            s.erase(s.begin()+i-1,s.begin()+i+3);
            s.insert(s.begin()+i-1,r);
        }else if(s[i] == "-" and s[i+1] !="-"){
            r=to_string(stod(s[i-1])-stod(s[i+1]));
            s.erase(s.begin()+i-1,s.begin()+i+2);
            s.insert(s.begin()+i-1,r);
            i=i-1;
            
        }
    }
    f=s[0];
    
    return f;
    }


string Skobki(string v){
    std::vector<std::map<int, int>> a;
    std::vector<std::map<int, int>> b;
    int r = 1;
    int f =1;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == '(') {
            a.push_back({{r, i}});
            r++;
        } 
    }
    
    r=1;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == '(') {
            
            for (int j = i; j < v.size(); ++j) {
                if (v[j] == '(') {
                    r++;
                }
                if(v[j] == ')' and r!=f){
                    r--;
                }
                if(v[j] == ')' and r==f){
                    b.push_back({{f, j}});
                    f++;
                    r=f;
                    break;
                }
            }       
        } 
    }
    
    
  
    string d;
    int w,q;
    for (int i = a.size(); i >0; --i) {
        w=a[i-1][i];
        q=b[i-1][i];
        
        d=schet1(split(v.substr(w+1,q-w-1)));
       
        v.erase(w,q-w+1);
        
        v.insert(w,d);
       
        break;
    }
    return v;
}


int main()
{
    
    vector<string> res;
    string v,nv;
    int kol=0;
    getline(cin, v);
    for(int i=0;i<v.size();++i){ 
        if(v[i]=='('){
            kol++;
        }
    }
    string b;
    
    for(int i=0;i<kol;++i){
        b=Skobki(v);
        
        v=b;
    }
    cout<<schet1(split(v));
}
