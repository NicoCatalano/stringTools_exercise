#ifndef STRINGTOOLS_H
#define STRINGTOOLS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class StringTools; }
QT_END_NAMESPACE

class StringTools : public QMainWindow
{
    Q_OBJECT

public:
    StringTools(QWidget *parent = nullptr);
    ~StringTools();

private:
    QString toCamelCase(const QString& s);
    Ui::StringTools *ui;

private slots:
    void reversePressed();
    void capitalizePressed();
    void camelCasePressed();
    void clearPressed();
    void closeApp();
};
#endif // STRINGTOOLS_H
