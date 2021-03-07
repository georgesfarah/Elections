#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>

#include <QFile>
#include <QTextStream>
#include <QTextStream>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{

    QFile file(":/new/prefix1/lang.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        //error failed to load app
        QMessageBox messageBox;
        messageBox.critical(0,"Erreur fatale","Verifiez la presence du fichier lang.txt");
        messageBox.setFixedSize(500,200);
        return 0;
    }

        vector<vector<string>> langs(0);
        while (!file.atEnd()) {
            QString line = file.readLine();
            std::string parsedLine=line.toStdString();
            parsedLine.pop_back();
            if(line.contains("#")){langs.push_back({});langs[langs.size()-1].push_back(parsedLine.substr(1));}
            if(line.contains("_")){langs[langs.size()-1].push_back(parsedLine.substr(1));}
            }

        candidat candidats;
        electeur electeurs;
        candidats.getConfigs();
        electeurs.getConfigs();

    QApplication a(argc, argv);
    MainWindow w(candidats,electeurs,langs);
    w.show();
    return a.exec();
}
