#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int elemento=0;
    int fila=ui->spinBox->text().toInt();
    int columna=ui->spinBox_2->text().toInt();
    int** matriz = new int*[fila];
    for(int i=0;i<fila;i++){
        matriz[i]=new int[columna];
    }

    for(int f=0;f<fila;f++){
        for(int c=0;c<columna;c++){
            elemento++;
            matriz[f][c]=elemento;
        }
    }

    ui->tableWidget->setRowCount(fila);
    ui->tableWidget->setColumnCount(columna);
    ui->tableWidget_2->setRowCount(fila);
    ui->tableWidget_2->setColumnCount(columna);

    for(int f=0;f<fila;f++){
        for(int c=0;c<columna;c++){
            ui->tableWidget->setItem(f, c, new QTableWidgetItem(QString::number(matriz[f][c])));
        }
    }
    for(int f=0;f<fila;f++){
        for(int c=0;c<columna;c++){
            ui->tableWidget_2->setItem(f, c, new QTableWidgetItem(QString::number(matriz[f][c])));
        }
    }
}


void MainWindow::on_pushbutton_2_clicked()
{
    int** matriz = new int*[ui->tableWidget->rowCount()];
    for(int i=0;i<ui->tableWidget->rowCount();i++){
        matriz[i]=new int[ui->tableWidget->columnCount()];
    }

    for(int f=0;f<ui->tableWidget->rowCount();f++){
        for(int c=0;c<ui->tableWidget->columnCount();c++){
            matriz[f][c]=ui->tableWidget->item(f,c)->text().toInt()+ui->tableWidget->item(f,c)->text().toInt();
        }
    }

    ui->tableWidget_3->setRowCount(ui->tableWidget->rowCount());
    ui->tableWidget_3->setColumnCount(ui->tableWidget->columnCount());
    for(int f=0;f<ui->tableWidget->rowCount();f++){
        for(int c=0;c<ui->tableWidget->columnCount();c++){
            ui->tableWidget_3->setItem(f, c, new QTableWidgetItem(QString::number(matriz[f][c])));
        }
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    int** matriz = new int*[ui->tableWidget->rowCount()];
    for(int i=0;i<ui->tableWidget->rowCount();i++){
        matriz[i]=new int[ui->tableWidget->columnCount()];
    }

    for(int f=0;f<ui->tableWidget->rowCount();f++){
        for(int c=0;c<ui->tableWidget->columnCount();c++){
            matriz[f][c]=ui->tableWidget->item(f,c)->text().toInt()-ui->tableWidget->item(f,c)->text().toInt();
        }
    }

    ui->tableWidget_3->setRowCount(ui->tableWidget->rowCount());
    ui->tableWidget_3->setColumnCount(ui->tableWidget->columnCount());
    for(int f=0;f<ui->tableWidget->rowCount();f++){
        for(int c=0;c<ui->tableWidget->columnCount();c++){
            ui->tableWidget_3->setItem(f, c, new QTableWidgetItem(QString::number(matriz[f][c])));
        }
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    if(ui->tableWidget->columnCount()==ui->tableWidget_2->rowCount()){
        int** matriz = new int*[ui->tableWidget->rowCount()];
        for(int i=0;i<ui->tableWidget->rowCount();i++){
            matriz[i]=new int[ui->tableWidget->columnCount()];
        }

        for(int f=0;f<ui->tableWidget->rowCount();f++){
            for(int c=0;c<ui->tableWidget->columnCount();c++){
                matriz[f][c]=0;
                for(int i=0;i<ui->tableWidget->columnCount();i++){
                    matriz[f][c]+=ui->tableWidget->item(f,i)->text().toInt()*ui->tableWidget->item(i,c)->text().toInt();
                }
            }
        }

        ui->tableWidget_3->setRowCount(ui->tableWidget->rowCount());
        ui->tableWidget_3->setColumnCount(ui->tableWidget->columnCount());
        for(int f=0;f<ui->tableWidget->rowCount();f++){
            for(int c=0;c<ui->tableWidget->columnCount();c++){
                ui->tableWidget_3->setItem(f, c, new QTableWidgetItem(QString::number(matriz[f][c])));
            }
        }
    }else{
        mensaje.setWindowTitle("Mensaje");
        mensaje.setText("Las matrizes no se pueden multiplicar.");
        mensaje.exec();
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    int elemento=0;
    int fila=ui->spinBox_3->text().toInt();
    int columna=ui->spinBox_4->text().toInt();
    int** matriz = new int*[fila];
    for(int i=0;i<fila;i++){
        matriz[i]=new int[columna];
    }

    for(int f=0;f<fila;f++){
        for(int c=0;c<columna;c++){
            elemento++;
            matriz[f][c]=elemento;
        }
    }

    ui->tableWidget_4->setRowCount(fila);
    ui->tableWidget_4->setColumnCount(columna);
    for(int f=0;f<fila;f++){
        for(int c=0;c<columna;c++){
            ui->tableWidget_4->setItem(f, c, new QTableWidgetItem(QString::number(matriz[f][c])));
        }
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    int numero=ui->lineEdit->text().toInt();
    bool existe=false;

    for(int f=0;f<ui->tableWidget_4->rowCount();f++){
        for(int c=0;c<ui->tableWidget_4->columnCount();c++){
            if(numero==ui->tableWidget_4->item(f,c)->text().toInt()){
                mensaje.setWindowTitle("Mensaje");
                mensaje.setText("El elemento esta en la fila: "+QString::number(f)+" columna: "+QString::number(c));
                mensaje.exec();
                existe=true;
                break;
            }
        }
    }

    if(!existe){
        mensaje.setWindowTitle("Mensaje");
        mensaje.setText("El elemento no existe en la matriz.");
        mensaje.exec();
    }
}


void MainWindow::on_pushButton_7_clicked()
{
    int elemento=0;
    int fila=ui->spinBox_5->text().toInt();
    int columna=ui->spinBox_6->text().toInt();
    int** matriz = new int*[fila];
    for(int i=0;i<fila;i++){
        matriz[i]=new int[columna];
    }

    for(int f=0;f<fila;f++){
        for(int c=0;c<columna;c++){
            elemento++;
            matriz[f][c]=elemento;
        }
    }

    ui->tableWidget_5->setRowCount(fila);
    ui->tableWidget_5->setColumnCount(columna);
    for(int f=0;f<fila;f++){
        for(int c=0;c<columna;c++){
            ui->tableWidget_5->setItem(f, c, new QTableWidgetItem(QString::number(matriz[f][c])));
        }
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    int** matriz=new int*[ui->tableWidget_5->columnCount()];
    for(int i=0;i<ui->tableWidget_5->columnCount();i++){
        matriz[i]=new int[ui->tableWidget_5->rowCount()];
    }

    for(int f=0;f<ui->tableWidget_5->rowCount();f++){
        for(int c=0;c<ui->tableWidget_5->columnCount();c++){
            matriz[c][f]=ui->tableWidget_5->item(f,c)->text().toInt();
        }
    }

    ui->tableWidget_6->setRowCount(ui->tableWidget_5->columnCount());
    ui->tableWidget_6->setColumnCount(ui->tableWidget_5->rowCount());
    for(int f=0;f<ui->tableWidget_5->columnCount();f++){
        for(int c=0;c<ui->tableWidget_5->rowCount();c++){
            ui->tableWidget_6->setItem(f, c, new QTableWidgetItem(QString::number(matriz[f][c])));
        }
    }
}


void MainWindow::on_pushButton_9_clicked()
{
    int elemento=0;
    int fila=ui->spinBox_7->text().toInt();
    int columna=ui->spinBox_7->text().toInt();
    int** matriz = new int*[fila];
    for(int i=0;i<fila;i++){
        matriz[i]=new int[columna];
    }

    for(int f=0;f<fila;f++){
        for(int c=0;c<columna;c++){
            elemento++;
            matriz[f][c]=elemento;
        }
    }

    ui->tableWidget_7->setRowCount(fila);
    ui->tableWidget_7->setColumnCount(columna);
    for(int f=0;f<fila;f++){
        for(int c=0;c<columna;c++){
            ui->tableWidget_7->setItem(f, c, new QTableWidgetItem(QString::number(matriz[f][c])));
        }
    }
}


void MainWindow::on_pushButton_10_clicked()
{
    int** matriz=new int*[ui->tableWidget_7->rowCount()];
    for(int i=0;i<ui->tableWidget_7->rowCount();i++){
        matriz[i]=new int[ui->tableWidget_7->columnCount()];
    }

    int cambiof=ui->tableWidget_7->rowCount(), cambioc=0;
    for(int f=0;f<ui->tableWidget_7->rowCount();f++){
        for(int c=0;c<ui->tableWidget_7->columnCount();c++){
            cambiof--;
            matriz[f][c]=ui->tableWidget_7->item(cambiof,cambioc)->text().toInt();
        }
        cambiof=ui->tableWidget_7->rowCount();
        cambioc++;
    }

    ui->tableWidget_8->setRowCount(ui->tableWidget_7->rowCount());
    ui->tableWidget_8->setColumnCount(ui->tableWidget_7->columnCount());
    for(int f=0;f<ui->tableWidget_7->rowCount();f++){
        for(int c=0;c<ui->tableWidget_7->columnCount();c++){
            ui->tableWidget_8->setItem(f, c, new QTableWidgetItem(QString::number(matriz[f][c])));
        }
    }
}

