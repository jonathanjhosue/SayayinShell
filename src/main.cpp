#include "sayayinshell.h"
#include <kapplication.h>
#include <kaboutdata.h>
#include <kcmdlineargs.h>
#include <klocale.h>
#include "settings.h"

static const char description[] =
    I18N_NOOP("La consola para los que no nos gusta");

static const char version[] = "0.1";

int main(int argc, char **argv)
{
    KAboutData about("sayayinshell", 0, ki18n("SayayinShell"), version, ki18n(description), KAboutData::License_GPL, ki18n("(C) 2011 Jonathan J. Sánchez Ugalde"), KLocalizedString(), 0, "sayayinshell@desarrollo-libre.org");
    about.addAuthor( ki18n("Jonathan Sánchez Ugalde"), KLocalizedString(), "jonathan@desarrollo-libre.org" );
    KCmdLineArgs::init(argc, argv, &about);

    KCmdLineOptions options;
    options.add("+[entorno]", ki18n( "Entorno a configurar" ));
    KCmdLineArgs::addCmdLineOptions( options );
    KApplication app;

    // see if we are starting with session management
    if (app.isSessionRestored())
        kRestoreMainWindows<SayayinShell>();
    else
    {
        // no session.. just start up normally
        KCmdLineArgs *args = KCmdLineArgs::parsedArgs();
	SayayinShell *ventaPrincipal = new SayayinShell;
        ventaPrincipal->show();
	/*
        if ( args->count() == 0 )
        {
        SayayinShell *widget = new SayayinShell;
        widget->show();
        }
        else
        {
            int i = 0;
            for (; i < args->count(); i++ )
            {
                SayayinShell *widget = new SayayinShell;
                widget->show();
                widget->load( args->url( i ) );
            }
        }
        */
	app.setTopWidget(ventaPrincipal);
	
	if (Settings::startMaximized())
		ventaPrincipal->showMaximized();
	else
		ventaPrincipal->show();
	
        args->clear();
    }

    return app.exec();
}
