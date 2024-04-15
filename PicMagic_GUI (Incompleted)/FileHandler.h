#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QObject>
#include <QFileDialog>

class FileHandler : public QObject
{
    Q_OBJECT
public:
    explicit FileHandler(QObject *parent = nullptr);

    Q_INVOKABLE QString saveFileDialog(const QString &defaultPath, const QString &filter);

private:
    QFileDialog* fileDialog; // Declared as QFileDialog*
};

#endif // FILEHANDLER_H
