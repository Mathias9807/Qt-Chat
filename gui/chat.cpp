#include "chat.h"

QVBoxLayout* layout0;
QHBoxLayout* layout1;
QTextEdit* txtClients;
QTextEdit* txtHistory;
QLineEdit* linMessage;

Chat::Chat(QWidget* parent) : QDialog(parent) {
	this->setWindowTitle("Chat");

	rootLayout = new QHBoxLayout(this);
	rootLayout->addLayout(layout0 = new QVBoxLayout(NULL));

	rootLayout->addWidget(txtClients = new QTextEdit(NULL));
	txtClients->setReadOnly(true);
	txtClients->setFixedWidth(100);

	layout0->addWidget(txtHistory = new QTextEdit(NULL));
	txtHistory->setReadOnly(true);

	layout0->addLayout(layout1 = new QHBoxLayout(NULL));

	layout1->addWidget(linMessage = new QLineEdit(NULL));
	layout1->addWidget(new QPushButton("Send", NULL));
}

