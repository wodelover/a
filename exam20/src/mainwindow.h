#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractItemModel>
#include <QStyledItemDelegate>
#include <QListView>
#include <QColor>
#include <QList>

namespace Ui {
class MainWindow;
}

class ItemDelegate : public QStyledItemDelegate
{
public:
    ItemDelegate(QObject *parent = nullptr);
};

class ListModel : public QAbstractItemModel
{

    Q_OBJECT
public:
    explicit ListModel(QObject *parent = nullptr);

    void appendColor(const QString &text);
    void removeColor(const QModelIndex &index);

public:
    QModelIndex index(int row, int column,
                              const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private :
    QList<QColor> m_colors;
};

class ListView : public QListView
{
    Q_OBJECT
public:
    explicit ListView(QWidget *parent = nullptr);
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    friend class autoTest;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAdd_clicked();

    void on_btnDelete_clicked();

private:
    Ui::MainWindow *ui;
    ListModel *m_Model;
    ItemDelegate *m_Delegate;
    ListView *m_ListView;
};

#endif // MAINWINDOW_H
