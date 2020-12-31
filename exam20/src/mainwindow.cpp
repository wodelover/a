#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   m_ListView=new ListView(ui->widget);
   m_Model=new ListModel(m_ListView);
   m_ListView->setModel(m_Model);
   connect(m_ListView, &ListView::clicked, this, [this]() {
       ui->btnDelete->setEnabled(true);
   });
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAdd_clicked()
{
    QString &&colorText = ui->comboBox->currentText();
    m_Model->appendColor(colorText);
}

void MainWindow::on_btnDelete_clicked()
{
    auto index = m_ListView->currentIndex();
    ui->btnDelete->setEnabled(false);
    m_Model->removeColor(index);
}

ListView::ListView(QWidget *parent)
    :QListView(parent)
{

}



void ListModel::appendColor(const QString &text)
{
    QColor color(text);
    if (color.isValid()) {
        beginResetModel();
        m_colors.append(color);
        endResetModel();
    }
}

void ListModel::removeColor(const QModelIndex &index)
{
    if (!index.isValid())
        return;
    beginResetModel();
    m_colors.removeAt(index.row());
    endResetModel();
}

QModelIndex ListModel::index(int row, int column, const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    if (row < 0 || column < 0)
        return QModelIndex();
    return createIndex(row, column);
}

QModelIndex ListModel::parent(const QModelIndex &child) const
{
    Q_UNUSED(child)
    return QModelIndex();
}

int ListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_colors.size();
}

int ListModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 1;
}

QVariant ListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int row = index.row();
    switch (role) {
    case Qt::DisplayRole:
        return m_colors.at(row).name();
    case Qt::BackgroundRole:
        return m_colors.at(row);
    }
    return QVariant();
}
ListModel::ListModel(QObject *parent):
    QAbstractItemModel(parent)
{

}
