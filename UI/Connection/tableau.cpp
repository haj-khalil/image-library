#include "tableau.h"
#include "ui_tableau.h"

Tableau::Tableau(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tableau)
{
    ui->setupUi(this);
}

Tableau::~Tableau()
{
    delete ui;
}
