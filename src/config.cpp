#include "config.h"

config::config()
{
  
}

bool config::getBoolPropiedad(const QString p, QString ent){
    QMap <QString,QString> entorno= propiedades[ent];
    if(ent!="all" && entorno.contains(p)){
        return   (entorno.value(p)=="True")?true:false;
    }else if(entorno.contains(p)){
        return   (entorno.value(p)=="True")?true:false;
    }
    else return false;
}

QString config::getStringPropiedad(const QString p, QString ent){
    QMap <QString,QString> entorno= propiedades[ent];
    if(ent!="all" && entorno.contains(p)){
        return   entorno.value(p);
    }else if(entorno.contains(p)){
        return   entorno.value(p);
    }
    else return "";
}

QString config::setPropiedad(const QString p,  const QString valor,QString ent){
    QMap <QString,QString> *entorno= &propiedades[ent];
    return   entorno->value(p,valor);

}

QString config::setPropiedad(const QString p,  const bool valor,QString ent){
    QString v=(valor)?"True":"False";
    QMap <QString,QString> *entorno= &propiedades[ent];
    return   entorno->value(p,v);

}



