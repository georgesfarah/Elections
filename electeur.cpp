#include "electeur.h"

#include <vector>
#include <string>

#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QTextStream>

using namespace std;
#include <iostream>

electeur::electeur() :electeurId(0,""), electeurPass(0,""),electeurVoted(0,"0") {

};

string generateKey(int length=15){
    string s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    string out="";

    int r;

    int i(0);

    while (i < length)
    {
        r = rand() % 61 + 1;
        out += s[r];
        ++i;
    }

    return out;
}

bool haskey(string key,vector<string> arr){
    for(auto elm:arr){
        if(elm==key){return true;}
    }
    return false;
}


vector<string> generateKeys(int usersN)
{
    vector<string> vect;

    int i(0);

    while(i < usersN) // cette boucle genere le nombre necessaire de codes en choisissant n fois un char au hasard du string s
    {
       string key=generateKey();
       if(haskey(key,vect)==false){
           vect.push_back(key);
           ++i;
       }
    }

    return vect;
}

void electeur::saveConfigs() // sauvegarde les codes dans un fichier txt
{
    QFile keysfile("users.txt");

    if (keysfile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&keysfile);

        for(size_t i=0;i<electeurId.size();++i){
            QString qstr1 = QString::fromStdString(electeurId[i]);
            QString qstr2 = QString::fromStdString(electeurPass[i]);
            QString qstr3= QString::fromStdString(electeurVoted[i]);

            stream<<"electeurId_"<<qstr1<<'\n';
            stream<<"electeurPass_"<<qstr2<<'\n';
            stream<<"electeurVoted_"<<qstr3<<'\n';
            stream<<'\n';
        }

        keysfile.close();
    }

}

void electeur::getConfigs(){
    QFile file("users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
     {
        electeurId={};
        electeurPass={};
        electeurVoted={};
    }
    else{
    vector<vector<string>> out({{},{},{}});

    while (!file.atEnd()) {
        QString line = file.readLine();
            string parsedLine=line.toStdString();
            parsedLine.pop_back();
            if(line.contains("electeurId_")==true){out[0].push_back(parsedLine.substr(11));}
            if(line.contains("electeurPass_")==true){out[1].push_back(parsedLine.substr(13));}
            if(line.contains("electeurVoted_")==true){out[2].push_back(parsedLine.substr(14));}

        }
    electeurId=out[0];
    electeurPass=out[1];
    electeurVoted=out[2];
    }

}

void electeur::updateConfigs(int usersN){
    electeurId = {};
    for(int i=0;i<usersN;++i){
        string str= to_string(i);
        electeurId.push_back(str);
    }

electeurVoted=vector<string>(usersN,"0");
electeurPass=generateKeys(usersN);

}


vector<string> electeur::getId(){
    return electeurId;
}

vector<string> electeur::getPass(){
    return electeurPass;
}

std::vector<std::string> electeur::getCanVote(){
    return electeurVoted;
}

void electeur::setVoted(string id){
    for(size_t i=0;i<electeurId.size();++i){
        if(id==electeurId[i]){
            electeurVoted[i]="1";
            break;
        }
    }

}


