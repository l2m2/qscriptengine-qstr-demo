#include <QCoreApplication>
#include <QtScript>
#include <QtCore>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QScriptEngine engine;
    QTranslator translator;
    bool ok = translator.load(QCoreApplication::applicationDirPath() + "/qstr-demo_zhcn.qm");
    qDebug() << "load qm: " << ok;
    a.installTranslator(&translator);

    qDebug() << QObject::tr("Fuck you!");

    engine.installTranslatorFunctions();
    QString fileName(":/demo.js");
    QFile file(":/demo.js");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream stream(&file);
    QString contents = stream.readAll();
    file.close();
    engine.evaluate(contents, fileName);

    return a.exec();
}
