#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QCommandLineParser>

#include <KDBusAddons/KDBusService>

#include <iostream>

#include "accountmanager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addPositionalArgument("token", "For OAUTH2 use");

    parser.process(QCoreApplication::arguments());
    auto positionals = parser.positionalArguments();

    AccountManager acm;
    if (argc == 0 || (argc > 1 && positionals.size() != 1)) {
        std::cout << "Invalid options, see usage" << '\n';
        parser.showHelp(-1);
    } else if (argc == 2) {
        Q_EMIT acm.AddAuthToken(positionals[0]); // Wait until event loop
    }

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    KDBusService service(KDBusService::StartupOption::Unique);
    QObject::connect(&service, &KDBusService::activateRequested,
                     [&parser, &acm](const QStringList& arguments, const QString&) {
        parser.process(arguments);
        if (parser.positionalArguments().size() == 1)
            Q_EMIT acm.AddAuthToken(parser.positionalArguments()[0]);

    });
    return app.exec();
}
