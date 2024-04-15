#include "FileHandler.h"
#include <QFileDialog>

FileHandler::FileHandler(QObject *parent) : QObject(parent)
{
    fileDialog = new QFileDialog();
}

QString FileHandler::saveFileDialog(const QString &defaultPath, const QString &filter)
{
    QString selectedFile = fileDialog->getSaveFileName(nullptr, tr("Save File"), defaultPath, filter);
    return selectedFile;
}
