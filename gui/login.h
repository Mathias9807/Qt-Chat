#ifndef LOGIN_H
#define LOGIN_H

#include <QtGui/QDialog>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QMessageBox>

#include "net.h"


class Login : public QDialog {
	Q_OBJECT

public:
	Login(QWidget* parent = 0);

private:
	QVBoxLayout* rootLayout;

private slots:
	void connectAction();
};


#endif // LOGIN_H
