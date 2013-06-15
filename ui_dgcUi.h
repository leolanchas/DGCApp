/********************************************************************************
** Form generated from reading UI file 'dgcUi.ui'
**
** Created: Wed 18. Apr 16:30:13 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DGCUI_H
#define UI_DGCUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DgcUi
{
public:
    QGridLayout *gridLayout_5;
    QGridLayout *layout;
    QGridLayout *layoutLienzos;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *layAir;
    QFrame *line_2;
    QGridLayout *layPersp;
    QVBoxLayout *verticalLayout_4;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QLabel *LabAir;
    QLabel *LabPersp;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_4;
    QGridLayout *layFront;
    QFrame *line_5;
    QGridLayout *layLat;
    QVBoxLayout *verticalLayout_5;
    QFrame *line_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *LabFront;
    QLabel *LabLat;
    QFrame *line_3;
    QGridLayout *layoutMenu;
    QGroupBox *gbFig;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *pbDibujar;
    QComboBox *cbFigOpt;
    QPushButton *pbBorrar;
    QLineEdit *Nmerid;
    QPushButton *pbEjes;
    QLabel *label;
    QGroupBox *gbTrans;
    QGridLayout *gridLayout_4;
    QComboBox *cbTransform;
    QPushButton *pbObjColor;
    QPushButton *pbColor;
    QLabel *lbObjColor;
    QLabel *lbColor;
    QGroupBox *gbCapas;
    QHBoxLayout *horizontalLayout_6;
    QListWidget *listWidget;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QComboBox *cbShading;
    QHBoxLayout *horizontalLayout_8;
    QLabel *LightIntensity;
    QLineEdit *intensityVal;
    QHBoxLayout *horizontalLayout_9;
    QLabel *LightX;
    QLineEdit *LightXVal;
    QHBoxLayout *horizontalLayout_10;
    QLabel *LightY;
    QLineEdit *LightYVal;
    QHBoxLayout *horizontalLayout_7;
    QLabel *LightZ;
    QLineEdit *LightZVal;

    void setupUi(QDialog *DgcUi)
    {
        if (DgcUi->objectName().isEmpty())
            DgcUi->setObjectName(QString::fromUtf8("DgcUi"));
        DgcUi->resize(774, 684);
        QIcon icon;
        icon.addFile(QString::fromUtf8("figuras_geometricas.gif"), QSize(), QIcon::Normal, QIcon::Off);
        DgcUi->setWindowIcon(icon);
        gridLayout_5 = new QGridLayout(DgcUi);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        layout = new QGridLayout();
        layout->setObjectName(QString::fromUtf8("layout"));
        layoutLienzos = new QGridLayout();
        layoutLienzos->setObjectName(QString::fromUtf8("layoutLienzos"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        layAir = new QGridLayout();
        layAir->setObjectName(QString::fromUtf8("layAir"));

        horizontalLayout_3->addLayout(layAir);

        line_2 = new QFrame(DgcUi);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_2);

        layPersp = new QGridLayout();
        layPersp->setObjectName(QString::fromUtf8("layPersp"));

        horizontalLayout_3->addLayout(layPersp);


        gridLayout_3->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        line = new QFrame(DgcUi);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        LabAir = new QLabel(DgcUi);
        LabAir->setObjectName(QString::fromUtf8("LabAir"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LabAir->sizePolicy().hasHeightForWidth());
        LabAir->setSizePolicy(sizePolicy);
        LabAir->setAlignment(Qt::AlignJustify|Qt::AlignTop);

        horizontalLayout->addWidget(LabAir);

        LabPersp = new QLabel(DgcUi);
        LabPersp->setObjectName(QString::fromUtf8("LabPersp"));
        sizePolicy.setHeightForWidth(LabPersp->sizePolicy().hasHeightForWidth());
        LabPersp->setSizePolicy(sizePolicy);
        LabPersp->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout->addWidget(LabPersp);


        verticalLayout_4->addLayout(horizontalLayout);

        line_4 = new QFrame(DgcUi);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_4);


        gridLayout_3->addLayout(verticalLayout_4, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        layFront = new QGridLayout();
        layFront->setObjectName(QString::fromUtf8("layFront"));

        horizontalLayout_4->addLayout(layFront);

        line_5 = new QFrame(DgcUi);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_5);

        layLat = new QGridLayout();
        layLat->setObjectName(QString::fromUtf8("layLat"));

        horizontalLayout_4->addLayout(layLat);


        gridLayout_3->addLayout(horizontalLayout_4, 2, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        line_6 = new QFrame(DgcUi);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMinAndMaxSize);
        LabFront = new QLabel(DgcUi);
        LabFront->setObjectName(QString::fromUtf8("LabFront"));
        sizePolicy.setHeightForWidth(LabFront->sizePolicy().hasHeightForWidth());
        LabFront->setSizePolicy(sizePolicy);
        LabFront->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_2->addWidget(LabFront);

        LabLat = new QLabel(DgcUi);
        LabLat->setObjectName(QString::fromUtf8("LabLat"));
        sizePolicy.setHeightForWidth(LabLat->sizePolicy().hasHeightForWidth());
        LabLat->setSizePolicy(sizePolicy);
        LabLat->setAlignment(Qt::AlignJustify|Qt::AlignTop);

        horizontalLayout_2->addWidget(LabLat);


        verticalLayout_5->addLayout(horizontalLayout_2);


        gridLayout_3->addLayout(verticalLayout_5, 3, 0, 1, 1);


        layoutLienzos->addLayout(gridLayout_3, 0, 0, 1, 1);

        line_3 = new QFrame(DgcUi);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        layoutLienzos->addWidget(line_3, 0, 1, 1, 1);


        layout->addLayout(layoutLienzos, 0, 0, 1, 1);

        layoutMenu = new QGridLayout();
        layoutMenu->setObjectName(QString::fromUtf8("layoutMenu"));
        layoutMenu->setSizeConstraint(QLayout::SetMaximumSize);
        gbFig = new QGroupBox(DgcUi);
        gbFig->setObjectName(QString::fromUtf8("gbFig"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(gbFig->sizePolicy().hasHeightForWidth());
        gbFig->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(gbFig);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pbDibujar = new QPushButton(gbFig);
        pbDibujar->setObjectName(QString::fromUtf8("pbDibujar"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("clip-art-pencil-eraser.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbDibujar->setIcon(icon1);

        gridLayout->addWidget(pbDibujar, 3, 0, 1, 1);

        cbFigOpt = new QComboBox(gbFig);
        cbFigOpt->setObjectName(QString::fromUtf8("cbFigOpt"));
        cbFigOpt->setModelColumn(0);

        gridLayout->addWidget(cbFigOpt, 0, 0, 1, 2);

        pbBorrar = new QPushButton(gbFig);
        pbBorrar->setObjectName(QString::fromUtf8("pbBorrar"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("Eraser-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbBorrar->setIcon(icon2);

        gridLayout->addWidget(pbBorrar, 3, 1, 1, 1);

        Nmerid = new QLineEdit(gbFig);
        Nmerid->setObjectName(QString::fromUtf8("Nmerid"));
        Nmerid->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(Nmerid, 2, 0, 1, 1);

        pbEjes = new QPushButton(gbFig);
        pbEjes->setObjectName(QString::fromUtf8("pbEjes"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("ejes_transformaciones.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbEjes->setIcon(icon3);
        pbEjes->setIconSize(QSize(16, 16));

        gridLayout->addWidget(pbEjes, 1, 0, 1, 2);

        label = new QLabel(gbFig);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        layoutMenu->addWidget(gbFig, 0, 0, 1, 1);

        gbTrans = new QGroupBox(DgcUi);
        gbTrans->setObjectName(QString::fromUtf8("gbTrans"));
        sizePolicy1.setHeightForWidth(gbTrans->sizePolicy().hasHeightForWidth());
        gbTrans->setSizePolicy(sizePolicy1);
        gridLayout_4 = new QGridLayout(gbTrans);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        cbTransform = new QComboBox(gbTrans);
        cbTransform->setObjectName(QString::fromUtf8("cbTransform"));

        gridLayout_4->addWidget(cbTransform, 0, 0, 1, 1);

        pbObjColor = new QPushButton(gbTrans);
        pbObjColor->setObjectName(QString::fromUtf8("pbObjColor"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("color.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbObjColor->setIcon(icon4);

        gridLayout_4->addWidget(pbObjColor, 2, 0, 1, 1);

        pbColor = new QPushButton(gbTrans);
        pbColor->setObjectName(QString::fromUtf8("pbColor"));
        pbColor->setIcon(icon4);

        gridLayout_4->addWidget(pbColor, 1, 0, 1, 1);

        lbObjColor = new QLabel(gbTrans);
        lbObjColor->setObjectName(QString::fromUtf8("lbObjColor"));

        gridLayout_4->addWidget(lbObjColor, 2, 1, 1, 1);

        lbColor = new QLabel(gbTrans);
        lbColor->setObjectName(QString::fromUtf8("lbColor"));

        gridLayout_4->addWidget(lbColor, 1, 1, 1, 1);


        layoutMenu->addWidget(gbTrans, 1, 0, 1, 1);

        gbCapas = new QGroupBox(DgcUi);
        gbCapas->setObjectName(QString::fromUtf8("gbCapas"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(gbCapas->sizePolicy().hasHeightForWidth());
        gbCapas->setSizePolicy(sizePolicy2);
        horizontalLayout_6 = new QHBoxLayout(gbCapas);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        listWidget = new QListWidget(gbCapas);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy3);
        listWidget->setMaximumSize(QSize(212, 16777215));
        listWidget->setAcceptDrops(false);
        listWidget->setDragEnabled(true);
        listWidget->setDragDropMode(QAbstractItemView::NoDragDrop);
        listWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        listWidget->setLayoutMode(QListView::SinglePass);
        listWidget->setViewMode(QListView::ListMode);
        listWidget->setModelColumn(0);

        horizontalLayout_6->addWidget(listWidget);


        layoutMenu->addWidget(gbCapas, 3, 0, 1, 1);

        groupBox_2 = new QGroupBox(DgcUi);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        cbShading = new QComboBox(groupBox_2);
        cbShading->setObjectName(QString::fromUtf8("cbShading"));

        verticalLayout->addWidget(cbShading);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        LightIntensity = new QLabel(groupBox_2);
        LightIntensity->setObjectName(QString::fromUtf8("LightIntensity"));

        horizontalLayout_8->addWidget(LightIntensity);

        intensityVal = new QLineEdit(groupBox_2);
        intensityVal->setObjectName(QString::fromUtf8("intensityVal"));

        horizontalLayout_8->addWidget(intensityVal);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        LightX = new QLabel(groupBox_2);
        LightX->setObjectName(QString::fromUtf8("LightX"));

        horizontalLayout_9->addWidget(LightX);

        LightXVal = new QLineEdit(groupBox_2);
        LightXVal->setObjectName(QString::fromUtf8("LightXVal"));

        horizontalLayout_9->addWidget(LightXVal);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        LightY = new QLabel(groupBox_2);
        LightY->setObjectName(QString::fromUtf8("LightY"));

        horizontalLayout_10->addWidget(LightY);

        LightYVal = new QLineEdit(groupBox_2);
        LightYVal->setObjectName(QString::fromUtf8("LightYVal"));

        horizontalLayout_10->addWidget(LightYVal);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        LightZ = new QLabel(groupBox_2);
        LightZ->setObjectName(QString::fromUtf8("LightZ"));

        horizontalLayout_7->addWidget(LightZ);

        LightZVal = new QLineEdit(groupBox_2);
        LightZVal->setObjectName(QString::fromUtf8("LightZVal"));

        horizontalLayout_7->addWidget(LightZVal);


        verticalLayout->addLayout(horizontalLayout_7);


        layoutMenu->addWidget(groupBox_2, 2, 0, 1, 1);


        layout->addLayout(layoutMenu, 0, 1, 1, 1);


        gridLayout_5->addLayout(layout, 0, 0, 1, 1);


        retranslateUi(DgcUi);

        QMetaObject::connectSlotsByName(DgcUi);
    } // setupUi

    void retranslateUi(QDialog *DgcUi)
    {
        DgcUi->setWindowTitle(QApplication::translate("DgcUi", "DgcApp", 0, QApplication::UnicodeUTF8));
        LabAir->setText(QApplication::translate("DgcUi", "Aerea ( X, Z )", 0, QApplication::UnicodeUTF8));
        LabPersp->setText(QApplication::translate("DgcUi", "  Perspectiva", 0, QApplication::UnicodeUTF8));
        LabFront->setText(QApplication::translate("DgcUi", "Frontal ( X, Y )", 0, QApplication::UnicodeUTF8));
        LabLat->setText(QApplication::translate("DgcUi", "Lateral ( Z, Y )", 0, QApplication::UnicodeUTF8));
        gbFig->setTitle(QApplication::translate("DgcUi", "Figuras", 0, QApplication::UnicodeUTF8));
        pbDibujar->setText(QApplication::translate("DgcUi", "Dibujar", 0, QApplication::UnicodeUTF8));
        cbFigOpt->clear();
        cbFigOpt->insertItems(0, QStringList()
         << QApplication::translate("DgcUi", "Ninguno", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DgcUi", "Cubo", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DgcUi", "Piramide", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DgcUi", "Objeto de revoluci\303\263n", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DgcUi", "Objeto de revoluci\303\263n - Perfil", 0, QApplication::UnicodeUTF8)
        );
        pbBorrar->setText(QApplication::translate("DgcUi", "Borrar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pbEjes->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pbEjes->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        pbEjes->setText(QApplication::translate("DgcUi", "Ejes", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DgcUi", "Meridianos", 0, QApplication::UnicodeUTF8));
        gbTrans->setTitle(QApplication::translate("DgcUi", "Transformaciones", 0, QApplication::UnicodeUTF8));
        cbTransform->clear();
        cbTransform->insertItems(0, QStringList()
         << QApplication::translate("DgcUi", "Ninguna", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DgcUi", "Trasladar", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DgcUi", "Rotar", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DgcUi", "Rotar sobre su eje", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DgcUi", "Escalar", 0, QApplication::UnicodeUTF8)
        );
        pbObjColor->setText(QApplication::translate("DgcUi", "Reflection Color", 0, QApplication::UnicodeUTF8));
        pbColor->setText(QApplication::translate("DgcUi", "Object Color", 0, QApplication::UnicodeUTF8));
        lbObjColor->setText(QApplication::translate("DgcUi", "Ref. Color", 0, QApplication::UnicodeUTF8));
        lbColor->setText(QApplication::translate("DgcUi", "Obj Color", 0, QApplication::UnicodeUTF8));
        gbCapas->setTitle(QApplication::translate("DgcUi", "Capas", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("DgcUi", "Ocultacion / Sombreado", 0, QApplication::UnicodeUTF8));
        cbShading->clear();
        cbShading->insertItems(0, QStringList()
         << QApplication::translate("DgcUi", "Ninguno", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DgcUi", "Z-Buffer", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DgcUi", "Difusa sin reflexi\303\263n", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DgcUi", "Difusa con reflexi\303\263n", 0, QApplication::UnicodeUTF8)
        );
        LightIntensity->setText(QApplication::translate("DgcUi", "Intensidad", 0, QApplication::UnicodeUTF8));
        LightX->setText(QApplication::translate("DgcUi", "Posici\303\263n X ", 0, QApplication::UnicodeUTF8));
        LightY->setText(QApplication::translate("DgcUi", "Posici\303\263n Y ", 0, QApplication::UnicodeUTF8));
        LightZ->setText(QApplication::translate("DgcUi", "Posici\303\263n Z ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DgcUi: public Ui_DgcUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DGCUI_H
