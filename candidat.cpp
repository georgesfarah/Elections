#include "candidat.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QTextStream>

candidat::candidat()
    : candidatsId(0),candidatsName(0), candidatsVotes(0) {

}

void candidat::saveConfigs()
{
    QFile keysfile("candidats.txt");

    if (keysfile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&keysfile);

    for (size_t i(0); i < candidatsName.size() ; ++i)
    {
        QString qstr1 = QString::fromStdString(candidatsId[i]);
        QString qstr2 = QString::fromStdString(candidatsName[i]);
        QString qstr3 = QString::fromStdString(candidatsVotes[i]);

        stream << "candidatId_" << qstr1 << '\n';
        stream << "candidatName_" << qstr2 << '\n';
        stream << "candidatVotes_" << qstr3 << '\n';
        stream<<'\n';
  }

    keysfile.close();
}

}

void candidat::getConfigs(){ // import de la configuration des fichiers txt
    QFile file("candidats.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        candidatsId={};
        candidatsName={};
        candidatsVotes={};
    }
    else{
        vector<vector<string>> out({{},{},{}});//id names vote

        while (!file.atEnd()) {
            QString line = file.readLine();
            string parsedLine=line.toStdString();
            parsedLine.pop_back();
            if(line.contains("candidatId_")==true){out[0].push_back(parsedLine.substr(11));}
            if(line.contains("candidatName_")==true){out[1].push_back(parsedLine.substr(13));}
            if(line.contains("candidatVotes_")==true){out[2].push_back(parsedLine.substr(14));}

        }
        candidatsId=out[0];
        candidatsName=out[1];
        candidatsVotes=out[2];
}

}

void candidat::updateConfigs(vector<string> candidatsName){ //mise a jour de la config

    candidatsId={};

    for(size_t i=0;i<candidatsName.size();++i){
        string str= to_string(i);
        candidatsId.push_back(str);
    }

    this->candidatsName=candidatsName;
    candidatsVotes=vector<string>(candidatsName.size(),"0");
}

void candidat::addVote(string id) //ajout d'un vote
{
    for(size_t i=0;i<candidatsId.size();++i){
        if(id==candidatsId[i]){
            int oldVote=stoi(candidatsVotes[i]);
            candidatsVotes[i] = to_string(oldVote+1);
            break;
        }
    }

}



vector<string> candidat::getId(){return candidatsId;}
vector<string> candidat::getName(){return candidatsName;}
vector<string> candidat::getVotes(){return candidatsVotes;}
