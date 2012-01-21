#ifndef SAYAYINSHELL_H
#define SAYAYINSHELL_H

#include <kparts/mainwindow.h>

#include "ui_frmprincipal.h"

class Konsole;
class CentralView;

namespace KParts
{
	class ReadOnlyPart;
}

/**
 * This is the application "Shell".  It has a menubar, toolbar, and
 * statusbar but relies on the "Part" to do all the real work.
 *
 * @short Application Shell
 * @author ${AUTHOR} <${EMAIL}>
 * @version ${APP_VERSION}
 */
class SayayinShell : public KParts::MainWindow
{
    Q_OBJECT
public:
    SayayinShell();
    virtual ~SayayinShell();

    /**
     * Metodo para cargar el archivo para personalizar el entorno
     */
    void load(const KUrl& url);

protected:
    /**
     * This method is called when it is time for the app to save its
     * properties for session management purposes.
     */
    void saveProperties(KConfigGroup &);

    /**
     * This method is called when this app is restored.  The KConfig
     * object points to the session management config file that was saved
     * with @ref saveProperties
     */
    void readProperties(const KConfigGroup &);
    Konsole* addPart(Konsole* part=0);

private slots:
    void fileNew();
    void fileOpen();
    void optionsConfigureKeys();
    void optionsConfigureToolbars();

    void applyNewToolbarConfig();
    void optionsPreferences();
    void settingsChanged();

private:
    void setupUi();
    void setupActions();
    //CentralView *m_view;
    KParts::ReadOnlyPart *m_part;
    Ui::frmPrincipal *ui;
    
};

#endif // SAYAYINSHELL_H
