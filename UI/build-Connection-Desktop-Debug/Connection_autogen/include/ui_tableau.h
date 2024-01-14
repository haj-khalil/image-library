/********************************************************************************
** Form generated from reading UI file 'tableau.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEAU_H
#define UI_TABLEAU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Tableau
{
public:
    QTableWidget *Descripteurs;

    void setupUi(QDialog *Tableau)
    {
        if (Tableau->objectName().isEmpty())
            Tableau->setObjectName(QString::fromUtf8("Tableau"));
        Tableau->resize(813, 427);
        Descripteurs = new QTableWidget(Tableau);
        if (Descripteurs->columnCount() < 4)
            Descripteurs->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Descripteurs->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        Descripteurs->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        Descripteurs->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        Descripteurs->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        Descripteurs->setObjectName(QString::fromUtf8("Descripteurs"));
        Descripteurs->setGeometry(QRect(30, 30, 711, 361));

        retranslateUi(Tableau);

        QMetaObject::connectSlotsByName(Tableau);
    } // setupUi

    void retranslateUi(QDialog *Tableau)
    {
        Tableau->setWindowTitle(QCoreApplication::translate("Tableau", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = Descripteurs->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Tableau", "Nom d'image", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = Descripteurs->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Tableau", "Image name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = Descripteurs->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Tableau", "Titre", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = Descripteurs->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Tableau", "Source", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tableau: public Ui_Tableau {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEAU_H
