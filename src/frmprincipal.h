#ifndef FRMPRINCIPAL_H
#define FRMPRINCIPAL_H

#include <QtGui/QMainWindow>
#include "confbasedatos.h"
#include "confsettings.h"

namespace Ui {
    class frmPrincipal;
}

class frmPrincipal : public QMainWindow {
    Q_OBJECT
public:

    frmPrincipal(QWidget *parent = 0);
    ~frmPrincipal();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::frmPrincipal *ui;
};

#endif // FRMPRINCIPAL_H
