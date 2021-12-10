#include "stringtools.h"
#include "ui_stringtools.h"
#include <QRegularExpression>
#include <QShortcut>
#include <bits/stdc++.h>

StringTools::StringTools(QWidget *parent): QMainWindow(parent), ui(new Ui::StringTools){
    //init UI
    ui->setupUi(this);

    //connecting button to actions
    connect(ui->reverseButton, SIGNAL(released()),this, SLOT(reversePressed()));
    connect(ui->capitalizeButton, SIGNAL(released()),this, SLOT(capitalizePressed()));
    connect(ui->camelCaseButton, SIGNAL(released()),this, SLOT(camelCasePressed()));
    connect(ui->clearButton, SIGNAL(released()),this, SLOT(clearPressed()));

    //binding shortcuts
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_1), this, SLOT(reversePressed()));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_2), this, SLOT(capitalizePressed()));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_3), this, SLOT(camelCasePressed()));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_0), this, SLOT(clearPressed()));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), this, SLOT(closeApp()));

    //set focus on inputbox by default
    ui->inputBox->setFocusPolicy(Qt::StrongFocus);
    ui->inputBox->setFocus();
}


StringTools::~StringTools(){
    delete ui;
}

void StringTools::reversePressed(){
    QString inputText = ui->inputBox->text();

    std::reverse(inputText.begin(), inputText.end());

    ui->inputBox->setText(inputText);
}

void StringTools::capitalizePressed(){
    QString capitalized = ui->inputBox->text().toUpper();
    ui->inputBox->setText(capitalized);
}

QString StringTools::toCamelCase(const QString& s)
{
    QStringList parts = s.split(' ', QString::SkipEmptyParts);
    for (int i = 0; i < parts.size(); ++i)
        parts[i].replace(0, 1, parts[i][0].toUpper());

    return parts.join("");
}

void StringTools::camelCasePressed(){
    QString inputText = ui->inputBox->text();
;
    ui->inputBox->setText(toCamelCase(inputText));
}
void StringTools::clearPressed(){
    ui->inputBox->setText(QString(""));
}
void StringTools::closeApp(){
    QCoreApplication::quit();
}


