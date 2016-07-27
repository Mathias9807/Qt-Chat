#include <QtGui/QApplication>
#include <iostream>

#include "login.h"

bool hasArgument(const char* p, int argc, char* argv[]) {
	for (int i = 0; i < argc; i++) {
		int j = 0;
		bool areEqual = true;
		while (p[j] && argv[i][j] && areEqual) {
			if (p[j] != argv[i][j])
				areEqual = false;
			j++;
		}
		if (areEqual) return true;
	}
	return false;
}

int main(int argc, char* argv[]) {
	netMain();

	if (hasArgument("--server", argc, argv)) {
		srvMain();

		return 0;
	}

	QApplication a(argc, argv);

	Login l;
	l.show();

	return a.exec();
}

