#ifndef ANDROIDTOOLKIT_ADBTHREAD_H
#define ANDROIDTOOLKIT_ADBTHREAD_H


#include <QThread>
#include <queue>
using namespace std;
using CallbackFunc=function<void(QString)>;
///回调
struct Callback{
    function<void()> execute;
    CallbackFunc callback;
};

class AdbThread : public QThread{
    Q_OBJECT

public:
    void append(const Callback &q);
    void execute(const QString &q);

signals:
    void onStart();
    void onProgress(const QString &q,const CallbackFunc &callback);
    void onComplete();

protected:
    void run() Q_DECL_OVERRIDE;

private:
    Callback current;
    queue<Callback> callbacks;
    void HandleProcess(const QString & q);
};


#endif //ANDROIDTOOLKIT_ADBTHREAD_H
