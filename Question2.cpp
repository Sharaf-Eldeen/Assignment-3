// File: A3_S18_20220323_2.cpp
// Purpose: Document Similarity
// Author: Mahmoud Mustafa Anas
// Section: S18
// ID:20220323
// TA:Eng.Rana Abdelkader
// Date: 5 Dec 2023

#include <bits/stdc++.h>
using namespace std;
class stringSet{
private:
    vector<string>Dwords;
    string returnlower(string word_){

        for (int i = 0; i < word_.size(); ++i) {

            word_[i]= ::tolower(word_[i]);
        }
        return word_;
    }
    string returnunpunctuation(string word2){
        string word2s="";
        for (int i = 0; i < word2.size(); ++i) {
            if(!ispunct(word2[i])){
                word2s+=word2[i];
            }
        }
        return word2s;
    }
public:
    stringSet(){

    }
    stringSet(string fileName){
        fstream infile(fileName,ios::in);
        if (infile.is_open()){
            string word;
            while (infile>>word){
                Dwords.push_back(returnunpunctuation(returnlower(word)));

            }
        }

    }
    void addString(string s){
        Dwords.push_back(s);
    }
    void removeString(string s){
        auto it = std::find(Dwords.begin(),Dwords.end(),s);
        Dwords.erase(it);
//        for (int i = 0; i < Dwords.size(); ++i) {
//            if (Dwords[i]==s){
//                Dwords[i].erase();
//                Dwords.erase();
//            }
//        }

    }
    void clearAllStrings(){
        Dwords.clear();
    }
    int numberOfStrings(){
        return Dwords.size();
    }
    void display(){
        for (int i = 0; i < Dwords.size(); ++i) {
            cout<<Dwords[i]<<endl;
        }
    }
    stringSet operator+( stringSet& other)  {
        stringSet res;
        unordered_set<string> unionn;
        for (string word :Dwords) {
            unionn.insert(word);
        }
        for (string word :other.Dwords) {
            unionn.insert(word);
        }

        for (string uni : unionn){
            res.Dwords.push_back(uni);
        }
        return res;
    }
    stringSet operator*(const stringSet& other)  {
        stringSet res;
        unordered_set <string> intersection;
        for (string word : Dwords) {
            auto it = std::find(other.Dwords.cbegin(),other.Dwords.cend(),word);

            if (it != other.Dwords.end()){
                intersection.insert(*it);
            }
            else
                continue;
        }
        for (string intr : intersection){
            res.Dwords.push_back(intr);
        }
             return res;
    }
    double similarity(stringSet& other){
        stringSet inter=other* (*this) ;
        int x,y,z;
        x= inter.numberOfStrings();
        y=other.numberOfStrings();
        z= this->numberOfStrings();
        return (double (x)/((double )::sqrt(z)* (double)::sqrt(y)));
    }
};
int main() {
    string fileName,fileName2;
    cout<<"enter the first file name (.txt)"<<endl;
    cin>>fileName;
    stringSet st1(fileName);
    cout<<"enter the word that you want to remove of the first file";
    string s;
    cin>>s;
    st1.removeString(s);
    st1.display();
//    stringSet st;
    cout<<"enter the second file name";
    cin>>fileName2;
    stringSet st2(fileName2);
    cout<<"enter the word that you want to add of the second file (.txt)";
    string s2;
    cin>>s2;
    st2.addString(s2);
    st2.display();
//    cout<<"<-st1->"<<"\n";
//    st1.display();
//    cout<<"<-st2->"<<"\n";
//    st2.display();
    stringSet st3=st1+st2;
    cout<<"<-st3->"<<"\n";
    st3.display();
    stringSet st4=st1*st2;
    cout<<"<-st4->"<<"\n";
    st4.display();
    cout<<st1.similarity(st2);
    return 0;
}
