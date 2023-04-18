#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <CListModel.h>
#include <FilterProxyModel.h>
#include <QQmlContext>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    CListModel *listmodel = new CListModel;
    listmodel->addData("Naveendra Kumar");
    listmodel->addData("Suresh Raina");
    listmodel->addData("Mahendra Singh Dhoni");
    listmodel->addData("Virat Kohli");
    listmodel->addData("Kane Williamson");
    listmodel->addData("ABD");
    listmodel->addData("Eion Morgan");
    listmodel->addData("Kumara Sangarkara");
    listmodel->addData("Mahela jayavardhane");
    listmodel->addData("Pspk");

    //for filter model
    FilterProxyModel *filtermodel=new FilterProxyModel;
    filtermodel->setSourceModel(listmodel);
    filtermodel->setFilterRole(NameRole);
    filtermodel->setSortRole(NameRole);

    QQmlApplicationEngine engine;

   engine.rootContext()->setContextProperty("filterModel",filtermodel);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
