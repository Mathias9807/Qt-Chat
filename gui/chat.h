#ifndef CHAT_H
#define CHAT_H

#include "login.h"
#include "net.h"

#include <QtGui/QTextEdit>


class Chat : public QDialog {
	Q_OBJECT

public:
	Chat(QWidget* parent = 0);

private:
	QHBoxLayout* rootLayout;

private slots:
};


#endif // CHAT_H
