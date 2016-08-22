#ifndef BROWSER_H
#define BROWSER_H

#include <QMainWindow>

namespace Ui {
class Browser;
}

class Browser : public QMainWindow
{
    Q_OBJECT

public:
    explicit Browser(QWidget *parent = 0);
    ~Browser();
    void keyPressEvent(QKeyEvent*);

private slots:
    void on_lineEdit_editingFinished();
private:
    Ui::Browser *ui;
};

#endif // BROWSER_H
