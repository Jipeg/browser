#include "browser.h"
#include "ui_browser.h"
#include <QKeyEvent>
#include <QDebug>
Browser::Browser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Browser)
{
    ui->setupUi(this);
    ui->lineEdit->setText(ui->webView->url().toString());

}

Browser::~Browser()
{
    delete ui;
}

void Browser::keyPressEvent(QKeyEvent *e){
    if(e->modifiers()==Qt::ControlModifier)
        switch(e->key()){
        case 'W':
            ui->lineEdit->show();
            ui->lineEdit->setFocus();
            break;
        case '=':
            ui->webView->setZoomFactor(ui->webView->zoomFactor()+0.1);
            break;
        case '-':
            ui->webView->setZoomFactor(ui->webView->zoomFactor()-0.1);
            break;
        case 'Q':
            QApplication::exit();
            break;
        default:
            break;
        }
}


void Browser::on_lineEdit_editingFinished()
{
    QUrl u;
    u.setUrl(ui->lineEdit->text());
    ui->webView->setUrl(u);
    ui->lineEdit->hide();
    ui->webView->setFocus();
}
