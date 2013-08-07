/*Copyright 2013 Alejandro Velasco

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.*/
#include <QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml>
#include <iostream>
#include <functional>

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  //register types
  QQuickView view;
  view.setPersistentSceneGraph(false);
  view.setSource(QUrl("qrc:/QML/main.qml"));
  QList<QQmlError> err = view.errors(); 
  for(QQmlError e : err) {
    std::cout << e.description().toStdString();
  }
  view.setResizeMode(QQuickView::ResizeMode::SizeRootObjectToView);
  view.setClearBeforeRendering(true);
  view.show();

  //draw in opengl
  //update
  QTimer *tim = new QTimer();
  tim->setSingleShot(false);
  tim->setInterval(16);
  tim->start();
  QObject::connect(tim, &QTimer::timeout, std::function<void()>( [&]() {
    view.update();
  }) );
  return app.exec();
}
