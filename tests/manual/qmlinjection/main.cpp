// Copyright (C) 2024 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#include <QtCore/QDir>
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlContext>
#include <QtQml/QQmlEngine>
#include <QtQuick/QQuickView>

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  QQuickView viewer;

  // The following are needed to make examples run without having to install the
  // module in desktop environments.
#ifdef Q_OS_WIN
  QString extraImportPath(QStringLiteral("%1/../../../%2"));
#else
  QString extraImportPath(QStringLiteral("%1/../../%2"));
#endif
  viewer.engine()->addImportPath(extraImportPath.arg(
      QGuiApplication::applicationDirPath(), QString::fromLatin1("qml")));
  QObject::connect(viewer.engine(), &QQmlEngine::quit, &viewer,
                   &QWindow::close);

  viewer.setTitle(QStringLiteral("QML graph injection"));
  viewer.setSource(QUrl("qrc:/qml/qmlinjection/main.qml"));
  viewer.setResizeMode(QQuickView::SizeRootObjectToView);
  viewer.show();

  return app.exec();
}
