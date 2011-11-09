#ifndef CONFSETTINGS_H
#define CONFSETTINGS_H

#include "config.h"
class confSettings : public config
{    

    private:

    bool _noScriptName;
    bool _loggingEnabled;
    QString _errorReporting;
    bool _webDebug;
    bool _cache;
    bool _etag;
    QString _loginModule;
    QString _loginAction;
    QString _secureModule;
    QString _secureAction;

    QList<QString> _enabledModules;

    QString _csrfSecret;
    bool _escapingStrategy;
    QString _escapingMethod;
    bool _i18n;
    QString _richTextJsDir;
    QString _richTextFCKJsDir;
    QString _defaultCulture;
    QString _error404Module;
    QString _error404Action;
    QString _moduleDisabledModule;
    QString _moduleDisabledAction;
    bool _useDatabase;
    bool _checkSymfonyVersion;
    bool _compressed;
    bool _checkLock;
    QString _validationErrorPrefix;
    QString _validationErrorSuffix;
    QString _validationErrorClass;
    QString _validationErrorIdPrefix;
    QString _adminWebDir;
    QString _webDebugWebDir;
    QString _calendarWebDir;

    QList <QString> _standardHelpers;
    QString _charset;
    bool _stripComments;
    int _maxForwards;



public:
    //confSettings();
    confSettings(const QString);

    bool NoScriptName(){
        //QMap <QString,QString> entorno=propiedades["all"];
        return  getBoolPropiedad("no_script_name","prod");
    }//get
    bool NoScriptName(bool v){_noScriptName=v;return v;}//set

    bool LoggingEnabled(){return getBoolPropiedad("logging_enabled");}//get
    bool LoggingEnabled(bool v){_loggingEnabled=v;return v;}//set

    QString ErrorReporting(){return  getStringPropiedad("error_reporting"); ;}//get
    QString ErrorReporting(QString v){_errorReporting=v;return v;}//set

    bool WebDebug(){return getBoolPropiedad("web_debug"); ;}//get
    bool WebDebug(bool v){_webDebug=v;return v;}//set

    bool Etag(){return getBoolPropiedad("etag"); _etag;}//get
    bool Etag(bool v){_etag=v;return v;}//set

    QString LoginModule(){return getStringPropiedad("login_module");;}//get
    QString LoginModule(QString v){_loginModule=v;return _loginModule;}//set

    QString LoginAction(){return getStringPropiedad("login_action");;}//get
    QString LoginAction(QString v){_loginAction=v;return _loginAction;}//set

    QString SecureModule(){return getStringPropiedad("secure_module");;}//get
    QString SecureModule(QString v){_secureModule=v;return _secureModule;}//set

    QString SecureAction(){return getStringPropiedad("secure_action");}//get
    QString SecureAction(QString v){_secureAction=v;return _secureAction;}//set

    QList<QString> EnabledModules(){return _enabledModules;}//get
    QList<QString> EnabledModules(QList<QString> v){_enabledModules=v;return _enabledModules;}//set

    QString CsrfSecret(){return getStringPropiedad("csrf_secret");}//get
    QString CsrfSecret(QString v){_csrfSecret=v;return _csrfSecret;}//set


    bool EscapingStrategy(){return getBoolPropiedad("escaping_strategy");}//get
    bool EscapingStrategy(bool v){_escapingStrategy=v;return _escapingStrategy;}//set

    bool I18n(){return getBoolPropiedad("i18n");_i18n;}//get
    bool I18n(bool v){_i18n=v;return _i18n;}//set

     QString RichTextJsDir(){return getStringPropiedad("rich_text_js_dir");}//get
    QString RichTextJsDir(QString v){_richTextJsDir=v;return _richTextJsDir;}//set

    QString RichTextFCKJsDir(){return getStringPropiedad("rich_text_js_dir");}//get
    QString RichTextFCKJsDir(QString v){_richTextFCKJsDir=v;return _richTextFCKJsDir;}//set

    QString DefaultCulture(){return getStringPropiedad("default_culture");}//get
    QString DefaultCulture(QString v){_defaultCulture=v;return _defaultCulture;}//set

    QString Error404Module(){return getStringPropiedad("error_404_Module");}//get
    QString Error404Module(QString v){_error404Module=v;return _error404Module;}//set

    QString Error404Action(){return getStringPropiedad("error_404_action");}//get
    QString Error404Action(QString v){_error404Action=v;return _error404Action;}//set

    QString ModuleDisabledModule(){return getStringPropiedad("module_disabled_module");}//get
    QString ModuleDisabledModule(QString v){_moduleDisabledModule=v;return _moduleDisabledModule;}//set

    QString ModuleDisabledAction(){return getStringPropiedad("module_disabled_action");}//get
    QString ModuleDisabledAction(QString v){_moduleDisabledAction=v;return _moduleDisabledAction;}//set

    bool UseDatabase(){return getBoolPropiedad("use_database");}//set
    bool UseDatabase(bool v){_useDatabase=v;return _useDatabase;}//get

    bool CheckSymfonyVersion(){return getBoolPropiedad("check_symfony_version");}//get
    bool CheckSymfonyVersion(bool v){_checkSymfonyVersion=v;return _checkSymfonyVersion;}//set

    bool Compressed(){return getBoolPropiedad("compress");}//get
    bool Compressed(bool v){_compressed=v;return _compressed;}//set_checkLock

    bool CheckLock(){return getBoolPropiedad("check_lock");}//get
    bool CheckLock(bool v){_checkLock=v;return _checkLock;}//set

    QString ValidationErrorPrefix(){return getStringPropiedad("validation_error_prefix");}//get
    QString ValidationErrorPrefix(QString v){_validationErrorPrefix=v;return _validationErrorPrefix;}//set

    QString ValidationErrorSuffix(){return getStringPropiedad("validation_error_suffix");}//get
    QString ValidationErrorSuffix(QString v){_validationErrorSuffix=v;return _validationErrorSuffix;}//set

    QString ValidationErrorClass(){return getStringPropiedad("validation_error_class");}//get
    QString ValidationErrorClass(QString v){_validationErrorClass=v;return _validationErrorClass;}//set

    QString ValidationErrorIdPrefix(){return getStringPropiedad("validation_error_id_prefix");}//get
    QString ValidationErrorIdPrefixValidationSettings(QString v){_validationErrorIdPrefix=v;return _validationErrorIdPrefix;}//set

    //Assets
    QString AdminWebDir(){return getStringPropiedad("admin_web_dir");}//get
    QString AdminWebDir(QString v){_adminWebDir=v;return _adminWebDir;}//set

    QString WebDebugWebDir(){return getStringPropiedad("web_debug_web_dir");;}//get
    QString WebDebugWebDir(QString v){_webDebugWebDir=v;return _webDebugWebDir;}//set

    QString CalendarWebDir(){return getStringPropiedad("calendar_web_dir");}//get
    QString CalendarWebDir(QString v){_calendarWebDir=v;return _calendarWebDir;}//set


    bool Cache(){return getBoolPropiedad("cache");_cache;}//get
    bool Cache(bool v){_cache=v;return _cache;}//set_checkLock


    QList<QString> StandardHelpers(){return _standardHelpers;}//get
    QList<QString> StandardHelpers(QList<QString> v){_standardHelpers=v;return _standardHelpers;}//set

    QString Charset(){return getStringPropiedad("charset");_charset;}//get
    QString Charset(QString v){_charset=v;return _charset;}//set


    bool StripComments(){return getBoolPropiedad("strip_comments");}//get
    bool StripComments(bool v){_stripComments=v;return _stripComments;}//set



    int MaxForwards(){return _maxForwards;}//get
    int MaxForwards(bool v){_maxForwards=v;return _maxForwards;}//set

    bool Guardar();
    void cargar(const YAML::Node & );
};

#endif // CONFSETTINGS_H
