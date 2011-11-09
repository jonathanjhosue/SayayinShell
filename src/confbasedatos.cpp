#include "confbasedatos.h"
#include <QProcess>

confBaseDatos::confBaseDatos()
{

}

confBaseDatos::confBaseDatos(const QString vdir)
{
   //QProcess::setWorkingDirectory(vdir);
    //propiedades

    std::ifstream fin("/home/jonathan/Proyectos/NaivivSymfony/nuevoProyecto/config/databases2.yml");
   YAML::Parser parser(fin);
   YAML::Node doc;
   parser.GetNextDocument(doc);
   cargar(doc);
traverse(doc,0);


/*

   std::ifstream fin("/home/jonathan/Proyectos/NaivivSymfony/nuevoProyecto/config/databases2.yml");
   YAML::Parser parser(fin);
   YAML::Node doc;
   parser.GetNextDocument(doc);

    if(const YAML::Node *pName = doc.FindValue("all")) {
        QMap<QString,QString> all;
        const YAML::Node *propel=pName->FindValue("propel");
        const YAML::Node *clase=propel->FindValue("class");
        const YAML::Node *param=propel->FindValue("param");

        const YAML::Node *nodoClassName=param->FindValue("classname");
        const YAML::Node *nodoDsn=param->FindValue("dsn");
        const YAML::Node *nodoUsername=param->FindValue("username");
        const YAML::Node *nodoPassword=param->FindValue("password");
        const YAML::Node *nodoEncoding=param->FindValue("encoding");
        const YAML::Node *nodoPersistent=param->FindValue("persistent");
        const YAML::Node *nodoPooling=param->FindValue("pooling");

        std::string valor;
        //clase >> _class;

        *nodoClassName >> valor;
        _classname=QString::fromUtf8(valor.c_str());
        *nodoUsername >> valor;_username=QString::fromUtf8(valor.c_str()); all.insert("username","ss");
        *nodoPassword >> valor,_password=QString::fromUtf8(valor.c_str());
        *nodoEncoding >> valor,_encoding=QString::fromUtf8(valor.c_str());
        *nodoPersistent >>_persistent;
        *nodoPersistent >> _pooling;

        propiedades.insert("all",all);
        _persistent=true;


  }*/
}



bool confBaseDatos::Guardar(){
    QString textoSalida="";

    YAML::Emitter out;
    /*
    out << YAML::BeginMap;
out << YAML::Key << "name";
out << YAML::Value << "Barack Obama";
out << YAML::Key << "children";
out << YAML::Value << YAML::BeginSeq << "Sasha" << "Malia" << YAML::EndSeq;
out << YAML::EndMap;
    */
    QMap <QString,QString> all=propiedades["all"];
    out << YAML::BeginMap;
    out << YAML::Key << "all";
    out << YAML::Value << YAML::BeginMap;
        out << YAML::Key << "propel";
        out << YAML::Value << YAML::BeginMap;
            out << YAML::Key << "class";out << YAML::Value << "jojojo";
            out << YAML::Key << "param";
                out << YAML::Value << YAML::BeginMap;
                   out << YAML::Key << "classname";out << YAML::Value << "prope";
                   out << YAML::Key << "dsn";out << YAML::Value << "xxx";
                   out << YAML::Key << "username";out << YAML::Value << all["username"].toStdString();
                   out << YAML::Key << "password";out << YAML::Value << "ketepensa";
                   out << YAML::Key << "encoding";out << YAML::Value << Encoding().toStdString();
                   out << YAML::Key << "persistent";out << YAML::Value << Persistent();
                   out << YAML::Key << "pooling";out << YAML::Value << "false";
                out << YAML::EndMap;
            out << YAML::EndMap;
        out << YAML::EndMap;
    out << YAML::EndMap;

//out.c_str();
textoSalida=QString::fromUtf8(out.c_str());

     QFile file("/home/jonathan/Proyectos/NaivivSymfony/nuevoProyecto/config/databases.yml");

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        /*
        QMessageBox::warning(this, tr("MDI"),
                             tr("No se puede guardar el archivo %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
                             */

        return false;
    }

    QTextStream salida(&file);


    //QApplication::setOverrideCursor(Qt::WaitCursor);
    salida << textoSalida;
    //QApplication::restoreOverrideCursor();
return true;

}

void confBaseDatos::cargar(const YAML::Node & node) {

        //recorre los entornos
      for (YAML::Iterator i = node.begin(); i != node.end(); ++i) {
           const YAML::Node & key   = i.first();
                //const YAML::Node & value = i.second();
                string nombreentorno;
                key>>nombreentorno;

        if(const YAML::Node *pName = node.FindValue(nombreentorno)) {
            QMap<QString,QString> entorno;
                         std::string valor;

            if(const YAML::Node *propel=pName->FindValue("propel")){
                //if(const YAML::Node *clase=propel->FindValue("class")){}

                if(const YAML::Node *param=propel->FindValue("param")){

                    if(const YAML::Node *nodoClassName=param->FindValue("classname")){  *nodoClassName >> valor;_classname=QString::fromUtf8(valor.c_str());}
                    //if(const YAML::Node *nodoDsn=param->FindValue("dsn")){}
                    if(const YAML::Node *nodoUsername=param->FindValue("username")){*nodoUsername >> valor;_username=QString::fromUtf8(valor.c_str());}
                    if(const YAML::Node *nodoPassword=param->FindValue("password")){
                          const YAML::NodeType::value type =nodoPassword->Type();
                          if(YAML::NodeType::Scalar==type) {
                              *nodoPassword >> valor,_password=QString::fromUtf8(valor.c_str());}
                    }
                    if(const YAML::Node *nodoEncoding=param->FindValue("encoding")){*nodoEncoding >> valor,_encoding=QString::fromUtf8(valor.c_str());}
                    if(const YAML::Node *nodoPersistent=param->FindValue("persistent")){*nodoPersistent >>_persistent;}
                    if(const YAML::Node *nodoPooling=param->FindValue("pooling")){ *nodoPooling >> _pooling;}

                }

                propiedades.insert(QString::fromStdString(nombreentorno),entorno);
                _persistent=true;

          }
            }

    }
     // std::cout<<(propiedades["all"])["username"].toStdString();

}

void confBaseDatos::traverse(const YAML::Node & node, unsigned int depth = 0) {
   //cout<<"\n";
    // recursive depth first
    const YAML::NodeType::value type = node.Type();
    string indent((size_t)depth, '\t');
    string out;
    switch (type)
    {
        case YAML::NodeType::Scalar:
            node >> out;
            cout << indent << "SCALAR: " << out << std::endl;
            break;
        case YAML::NodeType::Sequence:
            cout << indent << "SEQUENCE:" << std::endl;
            for (unsigned int i = 0; i < node.size(); i++) {
                const YAML::Node & subnode = node[i];
                cout << indent << "[" << i << "]:" << std::endl;
                traverse(subnode, depth + 1);
            }
            break;
        case YAML::NodeType::Map:
            cout << indent << "MAP:" << std::endl;
            for (YAML::Iterator i = node.begin(); i != node.end(); ++i) {
                const YAML::Node & key   = i.first();
                const YAML::Node & value = i.second();
                key >> out;
                cout << indent << "KEY: " << out;
                cout << indent << "VALUE:";
                traverse(value, depth + 1);
            }
            break;
        case YAML::NodeType::Null:
            cout << indent << "(empty)" << std::endl;
            break;
        default:
            cerr << "Warning: traverse: unknown/unsupported node type" << std::endl;
    }
}

