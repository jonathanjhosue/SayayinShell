#ifndef CONFBASEDATOS_H
#define CONFBASEDATOS_H


#include "config.h"


class confBaseDatos : public config
{
    private:    
    QString _class;
    QString _classname;
    QString _dbname;
    QString _host;
    QString _username;
    QString _password;
    QString _encoding;
    bool _persistent;
    bool _pooling;


public:

    confBaseDatos();
    confBaseDatos(QString);
     void traverse(const YAML::Node & ,unsigned int);

    QString Class();//get
    QString Class(QString v){_class=v;return _class;}//set
    QString ClassName(){return _classname;}//get
    QString ClassName(QString v){_classname=v;return _class;}//set
    QString DbName(){return _dbname;}//get
    QString DbName(QString v){_dbname=v;return _dbname;}//set
    QString Host(){return _host;}//get
    QString Host(QString v){_host=v;return _host;}//set
    QString UserName(){return _username;}//get
    QString UserName(QString v){_username=v;return _username;}//set
    QString Password(){return _password;}//get
    QString Password(QString v){_password=v;return _password;}//set
    QString Encoding(){return _encoding;}//get
    QString Encoding(QString v){_encoding=v;return _encoding;}//set

    bool Persistent(){return _persistent;}//set
    bool Persistent(bool v){_persistent=v;return _persistent;}//get
    bool Pooling(){return _pooling;}//get
    bool Pooling(bool v){_pooling=v;return _pooling;}//set

    QString Dsn();

    bool Guardar();
    void cargar(const YAML::Node & );


};

#endif // CONFBASEDATOS_H
