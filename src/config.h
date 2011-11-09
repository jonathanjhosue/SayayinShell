#ifndef CONFIG_H
#define CONFIG_H
#include <QObject>
#include <QMap>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <string>
#include <fstream>
#include "yaml-cpp/yaml.h"

using std::string;using std::cout;using std::cerr;
class config : public QObject
{
public:
    config();
        bool getBoolPropiedad(const QString,const QString="all" );
        QString getStringPropiedad(const QString,const QString="all" );

        QString setPropiedad(const QString,const QString,const QString="all" );
        QString setPropiedad(const QString,const bool,const QString="all" );
        virtual bool Guardar()=0;
        virtual void Cargar() {}


    private:
        QFile *archivo;
        QString *texto;


    protected:
         QMap<QString, QMap<QString,QString> > propiedades;



};

#endif // CONFIG_H
