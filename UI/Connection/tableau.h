#ifndef TABLEAU_H
#define TABLEAU_H

#include <QDialog>

namespace Ui {
class Tableau;
}

class Tableau : public QDialog
{
    Q_OBJECT

public:
    explicit Tableau(QWidget *parent = nullptr);
    ~Tableau();
    Ui::Tableau *ui;

};

#endif // TABLEAU_H
