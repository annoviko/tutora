#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "DictionaryManager.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->TableDictionary->setColumnCount(2);

    QList<DictionaryEntry> container = DictionaryManager().GetDictionary();
    for (int i = 0; i < container.size(); i++) {
        ui->TableDictionary->insertRow(i);
        ui->TableDictionary->setItem(i, 0, new QTableWidgetItem(container[i].GetWord()));
        ui->TableDictionary->setItem(i, 1, new QTableWidgetItem(container[i].GetTranslation().GetTranslation()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ButtonInsert_clicked()
{
    DictionaryManager().InsertWord(ui->LineKey->text(), ui->LineValue->text());
}
