#include <gtest/gtest.h>
#include <QSignalSpy>
#include <QApplication>
#include <QProgressBar>
#include "progressobserver.h"
#include "resourceloader.h"

//test 1 verifico che l'oggetto esista
TEST(ResourceLoaderTest, InitialState) {
    ResourceLoader loader;
    ASSERT_TRUE(true);
}

//test 2 verifica logica caricamento
TEST(ResourceLoaderTest, ProcessEmitsProgress) {
    ResourceLoader loader;
    QSignalSpy spyProgress(&loader, &ResourceLoader::progressChanged);
    QSignalSpy spyFinished(&loader, &ResourceLoader::loadingFinished);
    loader.simulateLoading();
    ASSERT_EQ(spyFinished.count(), 1);
    ASSERT_GT(spyProgress.count(), 0);
    QList<QVariant> arguments = spyProgress.takeLast();
    int lastValue = arguments.at(0).toInt();

    EXPECT_EQ(lastValue, 100);
}

//test 3 valore passa alla barra
TEST(ProgressObserverTest, UpdateValue_SetsValueOnProgressBar) {
    int argc = 0;
    char *argv[] = {nullptr};
    QApplication app(argc, argv);
    QProgressBar myBar;
    myBar.setRange(0, 100);
    myBar.setValue(0);
    ProgressObserver observer(&myBar);
    observer.updateValue(42);
    EXPECT_EQ(myBar.value(), 42);
}

//test 4 m_progressBar non crashi con nullptr
TEST(ProgressObserverTest, UpdateValue_DoesNotCrashWithNullPtr) {
    ProgressObserver observer(nullptr);
    observer.updateValue(50);
    SUCCEED();
}

