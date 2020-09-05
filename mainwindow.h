#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include "bitmap.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnOpenBitmap_clicked();

    void on_btnOpenOverlay_clicked();

    void on_btnSaveBitmap_clicked();

    void on_btnGenerateOverlaid_clicked();

private:
    bool openFileDialog(QString &filePath);
    bool saveFileDialog(QString &filepath);
    //bool openBitmap(QString filePath, BITMAP &bitmap);
    void setGraphicsView(BITMAP &bitmap, QGraphicsView *qGraphicsView);
    void generateOverlaidBitmap();
    void showErrorMessage(QString errorMessage);
    void enableGenerateButton();
    void enableSaveButton();
    BITMAP *bmpOriginal = nullptr;
    BITMAP *bmpOverlay = nullptr;
    BITMAP *bmpOverlaid = nullptr;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
