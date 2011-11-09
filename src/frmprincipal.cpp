#include "frmprincipal.h"
#include "ui_frmprincipal.h"
#include <QMessageBox>

frmPrincipal::frmPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::frmPrincipal)
{
    ui->setupUi(this);
    confBaseDatos *uno = new confBaseDatos("/home/jonathan/Proyectos/NaivivSymfony/nuevoProyecto");
    //uno->traverse
   // QMessageBox::information(this,"", (uno->())?"True":"False");
}

frmPrincipal::~frmPrincipal()
{
    delete ui;
}

void frmPrincipal::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
