#include "login.h"
#include "chat.h"

#include <QTimer>

QLabel* lblLogin;
QLineEdit* linName;
QLineEdit* linIP;
QLineEdit* linPort;
QPushButton* btnConnect;

Login::Login(QWidget* parent) : QDialog(parent) {
	this->setWindowTitle("Login");

	rootLayout = new QVBoxLayout(this);

	QHBoxLayout* h2Layout = new QHBoxLayout(NULL);
	h2Layout->addWidget(new QLabel("Username: ", this));
	h2Layout->addWidget(linName = new QLineEdit(this));
	rootLayout->addLayout(h2Layout);

	QHBoxLayout* h1Layout = new QHBoxLayout(NULL);
	h1Layout->addWidget(new QLabel("IP: ", this));
	h1Layout->addWidget(linIP = new QLineEdit(this));
	h1Layout->addWidget(new QLabel(":", this));
	linIP->setText("localhost");
	h1Layout->addWidget(linPort = new QLineEdit(this));
	linPort->setText("63636");
	linPort->setMaxLength(5);
	rootLayout->addLayout(h1Layout);

	rootLayout->addWidget(btnConnect = new QPushButton("Connect"));
	connect(btnConnect, SIGNAL(clicked()), this, SLOT(connectAction()));
}

void Login::connectAction() {
	char ip[linIP->text().length()] = {0};
	strcat(ip, linIP->text().toAscii().data());
	int port = atoi(linPort->text().toAscii().data());
	char name[linName->text().length()] = {0};
	strcat(name, linName->text().toAscii().data());

	QString str = linIP->text() + ":" + linPort->text();
	if (clnConnect(ip, port, name)) {
		close();

		Chat* c = new Chat(NULL);
		c->show();
	}else {
		QMessageBox::about(this, "Connection failed!", str);
	}
}

