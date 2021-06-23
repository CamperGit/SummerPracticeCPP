QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Message/release/ -lMessage
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Message/debug/ -lMessage

INCLUDEPATH += $$PWD/../Message
DEPENDPATH += $$PWD/../Message

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../MessageFilter/release/ -lMessageFilter
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../MessageFilter/debug/ -lMessageFilter

INCLUDEPATH += $$PWD/../MessageFilter
DEPENDPATH += $$PWD/../MessageFilter

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../User/release/ -lUser
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../User/debug/ -lUser

INCLUDEPATH += $$PWD/../User
DEPENDPATH += $$PWD/../User
