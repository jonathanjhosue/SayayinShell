#include "confsettings.h"

/*confSettings::confSettings()
{

}*/

confSettings::confSettings(const QString vdir)
{
 std::ifstream fin("/home/jonathan/Proyectos/NaivivSymfony/nuevoProyecto/config/settings.yml");
   YAML::Parser parser(fin);
   YAML::Node doc;
   parser.GetNextDocument(doc);
   cargar(doc);
}

/*
confSettings::confSettings(const QString vdir)
{


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
//}

 void confSettings::cargar(const YAML::Node & node) {

        //recorre los entornos
      for (YAML::Iterator i = node.begin(); i != node.end(); ++i) {
           const YAML::Node & key   = i.first();
                const YAML::Node & value = i.second();
                string nombreentorno;
                key>>nombreentorno;

            if(const YAML::Node *pName = node.FindValue(nombreentorno)) {
            QMap<QString,QString> entorno;
                         std::string valor;

            //SETTINGS
            if(const YAML::Node *param=pName->FindValue(".settings")){

                    if(const YAML::Node *nodo=param->FindValue("no_script_name")){ entorno.insert("no_script_name",(nodo)?"True":"False");}
                    if(const YAML::Node *nodo=param->FindValue("logging_enabled")){ entorno.insert("logging_enabled",(nodo)?"True":"False");}
                    if(const YAML::Node *nodo=param->FindValue("error_reporting")){ *nodo >> valor;entorno.insert("error_reporting",QString::fromUtf8(valor.c_str()));}
                    if(const YAML::Node *nodo=param->FindValue("web_debug")){ entorno.insert("web_debug",(nodo)?"True":"False");}
                    if(const YAML::Node *nodo=param->FindValue("cache")){ entorno.insert("cache",(nodo)?"True":"False");}
                    if(const YAML::Node *nodo=param->FindValue("etag")){ entorno.insert("etag",(nodo)?"True":"False");}

                    if(const YAML::Node *nodo=param->FindValue("enabled_modules")){
                         YAML::NodeType::value type =nodo->Type();

                         if(YAML::NodeType::Sequence==type) {
                               /*for (unsigned int i = 0; i < nodo.size(); i++) {
                                    const YAML::Node & subnode = nodo[i];
                                    cout << i << "[" << subnode << "]:" << endl;
                                    //traverse(subnode, depth + 1);
                                }*/
                         }
                    }
                    //if(const YAML::Node *nodo=param->FindValue("csrf_secret")){ *nodo >> _csrfSecret;}

                    if(const YAML::Node *nodo=param->FindValue("csrf_secret")){ *nodo >> valor;entorno.insert("csrf_secret",QString::fromUtf8(valor.c_str()));}
                    if(const YAML::Node *nodo=param->FindValue("escaping_strategy")){ entorno.insert("escaping_strategy",(nodo)?"True":"False");}
                    if(const YAML::Node *nodo=param->FindValue("escaping_method")){ *nodo >> valor;entorno.insert("escaping_method",QString::fromUtf8(valor.c_str()));}

                    if(const YAML::Node *nodo=param->FindValue("i18n")){ entorno.insert("i18n",(nodo)?"True":"False");}
                    if(const YAML::Node *nodo=param->FindValue("rich_text_js_dir")){  *nodo >> valor;entorno.insert("rich_text_js_dir",QString::fromUtf8(valor.c_str()));}
                    if(const YAML::Node *nodo=param->FindValue("rich_text_fck_js_dir")){  *nodo >> valor;entorno.insert("rich_text_fck_js_dir",QString::fromUtf8(valor.c_str()));}
                    if(const YAML::Node *nodo=param->FindValue("default_culture")){  *nodo >> valor;entorno.insert("default_culture",QString::fromUtf8(valor.c_str()));}

                    if(const YAML::Node *nodo=param->FindValue("use_database")){ entorno.insert("use_database",(nodo)?"True":"False");}
                    if(const YAML::Node *nodo=param->FindValue("check_symfony_version")){ entorno.insert("check_symfony_version",(nodo)?"True":"False");}
                    if(const YAML::Node *nodo=param->FindValue("compressed")){ entorno.insert("compressed",(nodo)?"True":"False");}
                    if(const YAML::Node *nodo=param->FindValue("check_lock")){entorno.insert("check_lock",(nodo)?"True":"False");}
                    if(const YAML::Node *nodo=param->FindValue("no_script_name")){ entorno.insert("no_script_name",(nodo)?"True":"False");}
                    if(const YAML::Node *nodo=param->FindValue("validation_error_prefix")){  *nodo >> valor;entorno.insert("validation_error_prefix",QString::fromUtf8(valor.c_str()));}
                    if(const YAML::Node *nodo=param->FindValue("validation_error_suffix")){  *nodo >> valor;entorno.insert("validation_error_suffix",QString::fromUtf8(valor.c_str()));}
                    if(const YAML::Node *nodo=param->FindValue("validation_error_class")){  *nodo >> valor;entorno.insert("validation_error_class",QString::fromUtf8(valor.c_str()));}
                    if(const YAML::Node *nodo=param->FindValue("validation_error_id_prefix")){  *nodo >> valor;entorno.insert("validation_error_id_prefix",QString::fromUtf8(valor.c_str()));}

                    if(const YAML::Node *nodo=param->FindValue("admin_web_dir")){  *nodo >> valor;entorno.insert("admin_web_dir",QString::fromUtf8(valor.c_str()));}
                    if(const YAML::Node *nodo=param->FindValue("web_debug_web_dir")){  *nodo >> valor;entorno.insert("web_debug_web_dir",QString::fromUtf8(valor.c_str()));}
                    if(const YAML::Node *nodo=param->FindValue("calendar_web_dir")){  *nodo >> valor;entorno.insert("calendar_web_dir",QString::fromUtf8(valor.c_str()));}

                    if(const YAML::Node *nodo=param->FindValue("standard_helpers")){
                         //YAML::CONTENT_TYPE type =nodoPassword->GetType();
                          //if(YAML::CT_SCALAR==type) *nodoPassword >> valor,_password=QString::fromUtf8(valor.c_str());
                    }
                    if(const YAML::Node *nodo=param->FindValue("charset")){  *nodo >> valor;entorno.insert("charset",QString::fromUtf8(valor.c_str()));}
                     if(const YAML::Node *nodo=param->FindValue("strip_comments")){ entorno.insert("strip_comments",(nodo)?"True":"False");}

                    if(const YAML::Node *nodo=param->FindValue("max_forwards")){ *nodo >> valor;_maxForwards=QString::fromUtf8(valor.c_str()).toInt();}


                }



               //ACTIONS
               if(const YAML::Node *param=pName->FindValue(".actions")){

                  if(const YAML::Node *nodo=param->FindValue("error_404_module")){ *nodo >> valor;entorno.insert("error_404_module",QString::fromUtf8(valor.c_str()));}
                  if(const YAML::Node *nodo=param->FindValue("error_404_action")){ *nodo >> valor;entorno.insert("error_404_action",QString::fromUtf8(valor.c_str()));}
                  if(const YAML::Node *nodo=param->FindValue("login_module")){ *nodo >> valor;entorno.insert("login_module",QString::fromUtf8(valor.c_str()));}
                  if(const YAML::Node *nodo=param->FindValue("login_action")){*nodo >> valor;entorno.insert("login_action",QString::fromUtf8(valor.c_str()));}

                  if(const YAML::Node *nodo=param->FindValue("secure_module")){ *nodo >> valor;entorno.insert("secure_module",QString::fromUtf8(valor.c_str()));}
                  if(const YAML::Node *nodo=param->FindValue("secure_action")){ *nodo >> valor;entorno.insert("secure_action",QString::fromUtf8(valor.c_str()));}

                  if(const YAML::Node *nodo=param->FindValue("module_disabled_module")){ *nodo >> valor;entorno.insert("module_disabled_module",QString::fromUtf8(valor.c_str()));}
                  if(const YAML::Node *nodo=param->FindValue("module_disabled_action")){ *nodo >> valor;entorno.insert("module_disabled_action",QString::fromUtf8(valor.c_str()));}

                }

                propiedades.insert(QString::fromStdString(nombreentorno),entorno);
                //_persistent=true;

          }
     }
     // std::cout<<(propiedades["all"])["username"].toStdString();

}
bool confSettings::Guardar(){
return true;}
