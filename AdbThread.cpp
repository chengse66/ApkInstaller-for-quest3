//
// Created by DO on 2024/4/9.
//

#include "AdbThread.h"
#include <QDebug>

void AdbThread::run() {
    while (true) {
        while (!callbacks.empty()) {
            emit onStart();
            current = callbacks.front();
            callbacks.pop();
            current.execute();
            emit onComplete();
        }
        QThread::msleep(30);
    }
}

void AdbThread::append(const Callback &q) {
    callbacks.push(q);
}

void AdbThread::execute(const QString &q) {
    emit onProgress(q,current.callback);
}
