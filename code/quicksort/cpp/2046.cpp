#include "quicksort.h"
#include "ui_quicksort.h"

#include "mainwindow.h"


QuickSort::QuickSort(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuickSort)
{
    ui->setupUi(this);

}

QuickSort::~QuickSort()
{
    delete ui;
}
