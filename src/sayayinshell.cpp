/*
 * sayayinshell.cpp
 *
 * Copyright (C) 2004 $AUTHOR <$EMAIL>
 */
#include "sayayinshell.h"
#include "sayayinshell.moc"
#include "konsole.h"

#include <kaction.h>
#include <kactioncollection.h>
#include <kconfig.h>
#include <KDE/KConfigDialog>
#include <kedittoolbar.h>
#include <kfiledialog.h>
#include <kshortcutsdialog.h>
#include <klibloader.h>
#include <kmessagebox.h>
#include <kstandardaction.h>
#include <ktoggleaction.h>
#include <kstatusbar.h>
#include <kurl.h>
#include <klocale.h>
#include <kservice.h>

#include <QApplication>
#include <QtGui/QLayout>
#include "settings.h"



SayayinShell::SayayinShell()
    : KParts::MainWindow( ),ui(new Ui::frmPrincipal)
{
    // set the shell's ui resource file
    setXMLFile("sayayinshell_shell.rc");
  
    // then, setup our actions
    setupActions();
    setupUi();

    // this routine will find and load our Part.  it finds the Part by
    // name which is a bad idea usually.. but it's alright in this
    // case since our Part is made for this Shell
    /*
    KLibFactory *factory = KLibLoader::self()->factory("libkonsolepart");
    if (factory)
    {
        // now that the Part is loaded, we cast it to a Part to get
        // our hands on it
        m_part = static_cast<KParts::ReadWritePart *>(factory->create(this,
                                "libkonsolepart" ));

        if (m_part)
        {
            // tell the KParts::MainWindow that this is indeed the main widget
            setCentralWidget(m_part->widget());

            // and integrate the part's GUI with the shell's
            setupGUI();
        }
    }
    else
    {
        // if we couldn't find our Part, we exit since the Shell by
        // itself can't do anything useful
        KMessageBox::error(this, i18n("Could not find our Part!"));
        qApp->quit();
        // we return here, cause qApp->quit() only means "exit the
        // next time we enter the event loop...
        return;
    }
    */

    // apply the saved mainwindow settings, if any, and ask the mainwindow
    // to automatically save settings if changed: window size, toolbar
    // position, icon size, etc.
    /*
    KService::Ptr service = KService::serviceByDesktopPath
                           ("konsolepart.desktop");
			   
			    		if (service.isNull())
		{
			KMessageBox::error(this, i18n("Unable to create a factory for \"libkonsolepart\". Is Konsole installed?"));
			return;
		}
 
    if (service)
    {
      //m_part = service->createInstance<KParts::ReadWritePart>(0);
      m_part = service->createInstance<KParts::ReadOnlyPart>(this);
      if (m_part)
      {
            // tell the KParts::MainWindow that this is indeed
            // the main widget
            setCentralWidget(m_part->widget());
 
            setupGUI(ToolBar | Keys | StatusBar | Save);
 
            // and integrate the part's GUI with the shell's
            createGUI(m_part);
      }
      else
      {
          return;//return 1; 
      }
    }
    else
    {
        // if we couldn't find our Part, we exit since the Shell by
        // itself can't do anything useful
        KMessageBox::error(this, "service konsolepart.desktop not found");
        qApp->quit();
        // we return here, cause qApp->quit() only means "exit the
        // next time we enter the event loop...
        return;
    }*/
    setAutoSaveSettings();
}

SayayinShell::~SayayinShell()
{
}

void SayayinShell::load(const KUrl& url)
{
  
    m_part->openUrl( url );
}

void SayayinShell::setupActions()
{
    KStandardAction::openNew(this, SLOT(fileNew()), actionCollection());
    KStandardAction::open(this, SLOT(fileOpen()), actionCollection());

    KStandardAction::quit(qApp, SLOT(closeAllWindows()), actionCollection());
    
    KStandardAction::preferences(this, SLOT(optionsPreferences()), actionCollection());

    KToggleAction* toggleMenu = KStandardAction::showMenubar(this, SLOT(toggleMenu()), actionCollection());
    toggleMenu->setShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_M));

    createStandardStatusBarAction();
    setStandardToolBarMenuEnabled(true);

    //KStandardAction::keyBindings(this, SLOT(optionsConfigureKeys()), actionCollection());
    //KStandardAction::configureToolbars(this, SLOT(optionsConfigureToolbars()), actionCollection());
}

void SayayinShell::saveProperties(KConfigGroup & /*config*/)
{
    // the 'config' object points to the session managed
    // config file.  anything you write here will be available
    // later when this app is restored
}

void SayayinShell::readProperties(const KConfigGroup & /*config*/)
{
    // the 'config' object points to the session managed
    // config file.  this function is automatically called whenever
    // the app is being restored.  read in here whatever you wrote
    // in 'saveProperties'
}

void SayayinShell::fileNew()
{
    KMessageBox *uno= new KMessageBox;
    
    uno->about(this,QString("Hola prueba"),QString("Hola"));
    //QObjectList hola= centralWidget()->layout()->;
    
    //uno->about(this,QString::number(hola.size()),QString::number(hola.size()));
    //hola->sendInput("hola");
    // this slot is called whenever the File->New menu is selected,
    // the New shortcut is pressed (usually CTRL+N) or the New toolbar
    // button is clicked

    // About this function, the style guide (
    // http://developer.kde.org/documentation/standards/kde/style/basics/index.html )
    // says that it should open a new window if the document is _not_
    // in its initial state.  This is what we do here..
    /*if ( ! m_part->url().isEmpty() || m_part->isModified() )
    {
        (new SayayinShell)->show();
    };*/
}

void SayayinShell::optionsConfigureKeys()
{
  /*KShortcutsDialog dlg( KKeyChooser::AllActions, KKeyChooser::LetterShortcutsDisallowed, this );
  dlg.insert( actionCollection(), "sayayinshell_shell.rc" );
  dlg.insert( m_part->actionCollection(), "sayayinshell_part.rc" );
  (void) dlg.configure( true );*/
}

void SayayinShell::optionsConfigureToolbars()
{
    //saveMainWindowSettings(KGlobal::config(), autoSaveGroup());

    // use the standard toolbar editor
    /*KEditToolBar dlg(factory());
    connect(&dlg, SIGNAL(newToolbarConfig()),
            this, SLOT(applyNewToolbarConfig()));
    dlg.exec();*/
}

void SayayinShell::applyNewToolbarConfig()
{
    //applyMainWindowSettings(KGlobal::config(), autoSaveGroup());
}

void SayayinShell::fileOpen()
{
    // this slot is called whenever the File->Open menu is selected,
    // the Open shortcut is pressed (usually CTRL+O) or the Open toolbar
    // button is clicked
   /* KUrl url =
        KFileDialog::getOpenUrl( KUrl(), QString(), this );

    if (url.isEmpty() == false)
    {
        // About this function, the style guide (
        // http://developer.kde.org/documentation/standards/kde/style/basics/index.html )
        // says that it should open a new window if the document is _not_
        // in its initial state.  This is what we do here..
        if ( m_part->url().isEmpty() && ! m_part->isModified() )
        {
            // we open the file in this window...
            load( url );
        }
        else
        {
            // we open the file in a new window...
            SayayinShell* newWin = new SayayinShell;
            newWin->load( url );
            newWin->show();
        }
    }*/
}


void SayayinShell::setupUi()
{
	QWidget* centralWidget = new QWidget(this, 0);
	QWidget* consola_panel = new QWidget(this, 0);
	Konsole* partModCOnsola= new Konsole(consola_panel,new QHBoxLayout(consola_panel));
	//partModCOnsola->sendInput("ls\n");
	
	/*
	QGridLayout* grid = new QGridLayout(centralWidget);

	mRows = new QSplitter(Qt::Vertical);
	mRows->setChildrenCollapsible(false);
	grid->addWidget(mRows, 0, 0);
*/
	//QWidget* contenedor = new QWidget(this,0);
	QHBoxLayout *layout=new QHBoxLayout(centralWidget);
	
	//setCentralWidget(centralWidget);
	actionCollection()->addAssociatedWidget(centralWidget);
	ui->setupUi(this);
	ui->dockWidget_2->setWidget(consola_panel);
	
	
	QTreeWidget *treeWidget = new QTreeWidget();
	treeWidget->setColumnCount(1);
	QList<QTreeWidgetItem *> items;
	for (int i = 0; i < 10; ++i)
	    items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("item: %1").arg(i))));
	treeWidget->insertTopLevelItems(0, items);
	
	ui->dockWidget_3->setWidget(treeWidget);
	
	setCentralWidget(centralWidget);

	/*for (int i = 0; i < rows; ++i)
	{
		QSplitter* row = new QSplitter(Qt::Horizontal);
		row->setChildrenCollapsible(false);
		//mRowLayouts.push_back(row);
		//mRows->addWidget(row);
		for (int j = 0; j < columns; ++j)
		{
			Konsole* part = 0;
			if (mKonsoleParts.size() > static_cast<unsigned long>(i*columns + j))
				part = mKonsoleParts[i*columns + j];

			addPart(i, j, part);
		}
	}
	*/
//	kDebug() << "finished setting up layouts for " << mKonsoleParts.size() << " parts" << endl;
	
	//setWindowIcon(KIcon("quadkonsole4"));

	Konsole* part = new Konsole(centralWidget, layout);
	//addPart( part);
	
	
	setupGUI();

	// unused
	//statusBar()->hide();
}


Konsole* SayayinShell::addPart(Konsole* part)
{
	//QWidget* container = new QWidget(this,0);
	//mRowLayouts[row]->insertWidget(col, container);
	/*
	QBoxLayout* layout = new QBoxLayout(QBoxLayout::Down, container);
	layout->setSpacing(0);
	layout->setContentsMargins(0, 0, 0, 0);
	*/
	if (part != 0)
	{
		//part->setLayout(layout);
		//part->setParent(container);
		//container->setFocusProxy(part->widget());
	}
	else
	{
		//part = new Konsole(container, layout);
		//mKonsoleParts.push_back(part);
	}
	connect(part, SIGNAL(partCreated()), SLOT(resetLayouts()));
	actionCollection()->addAssociatedWidget(part->widget());

	return part;
}




void SayayinShell::optionsPreferences()
{
	if (KConfigDialog::showDialog("settings"))
		return;

	KConfigDialog* dialog = new KConfigDialog(this, "settings", Settings::self());
/*
	QWidget* generalSettings = new QWidget;
	Ui::prefs_base prefs_base;
	prefs_base.setupUi(generalSettings);
	dialog->addPage(generalSettings, i18n("General"), "sayayinshell");

	QWidget* shutdownSettings = new QWidget;
	Ui::prefs_shutdown prefs_shutdown;
	prefs_shutdown.setupUi(shutdownSettings);
	dialog->addPage(shutdownSettings, i18n("Shutdown"), "application-exit");
*/
	connect(dialog, SIGNAL(settingsChanged(QString)), this, SLOT(settingsChanged()));
	dialog->setAttribute(Qt::WA_DeleteOnClose);
	dialog->show();
}


void SayayinShell::settingsChanged()
{
  /*
	if (Settings::sloppyFocus() && mFilter == 0)
	{
		//mFilter = new MouseMoveFilter;
		//qApp->installEventFilter(mFilter);
	}
	else if (! Settings::sloppyFocus())
	{
		//delete mFilter;
		//mFilter = 0;
	}
	*/
}
