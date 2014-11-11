#-------------------------------------------------
#
# Project created by QtCreator 2014-10-20T20:25:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia multimediawidgets
lessThan(QT_MAJOR_VERSION, 5): QT += phonon
TARGET = new360
TEMPLATE = app


SOURCES += main.cpp\
    src/commom/staticbutton.cpp \
    src/commom/dynamicbutton.cpp \
    src/commom/dynamicwidget.cpp \
    src/commom/dynamicscaledwidget.cpp \
    src/commom/safebuttonwidget.cpp \
    src/commom/speedoutbutton.cpp \
    src/commom/speedoutbuttonwidget.cpp \
    src/commom/animbuttonwidget.cpp \
    src/commom/animbuttongroupwidget.cpp \
    src/commom/toptabwidget.cpp \
    src/test/mainwidget.cpp \
    src/main/mainbottomwidget.cpp \
    src/main/maintopwidget.cpp \
    src/commom/basestylewidget.cpp \
    src/commom/sysbuttongroup.cpp \
    src/commom/numanimwidget.cpp \
    src/commom/numbersanimwidget.cpp \
    src/main/common/scorewidget.cpp \
    src/main/common/buttonlabel.cpp \
    src/main/common/backgroundbutton.cpp \
    src/main/top/mainscorewidget.cpp \
    src/main/top/userwidget.cpp \
    src/main/top/topbottomwidget.cpp \
    src/main/bottom/mainbottomfirstwidget.cpp \
    src/main/bottom/mainexaminewidget.cpp \
    src/main/mainwindow.cpp \
    src/main/common/shadowwidget.cpp \
    src/commom/wenliwidget.cpp \
    src/safe/safewidget.cpp \
    src/safe/common/scanbuttonwidget.cpp \
    src/commom/statictextbutton.cpp \
    src/safe/common/safescanbottom.cpp \
    src/safe/safetopwidget.cpp \
    src/safe/safebottomwidget.cpp \
    src/commom/wenlibackwidget.cpp \
    src/commom/stackstatuswidget.cpp \
    src/clean/cleanwidget.cpp \
    src/youhua/youhuawidget.cpp \
    src/clean/common/cleanscanbottom.cpp \
    src/clean/common/cleandynamicbuttonwidget.cpp \
    src/youhua/common/youhuabutton.cpp \
    src/youhua/common/youhuascanbottom.cpp \
    src/main/common/opacitywidget.cpp \
    src/main/common/videowidget.cpp

HEADERS  += \
    src/commom/staticbutton.h \
    src/commom/dynamicbutton.h \
    src/commom/dynamicwidget.h \
    src/commom/dynamicscaledwidget.h \
    src/commom/safebuttonwidget.h \
    src/commom/common.h \
    src/commom/speedoutbutton.h \
    src/commom/speedoutbuttonwidget.h \
    src/commom/animbuttonwidget.h \
    src/commom/animbuttongroupwidget.h \
    src/commom/toptabwidget.h \
    src/test/mainwidget.h \
    src/main/mainbottomwidget.h \
    src/main/maintopwidget.h \
    src/commom/basestylewidget.h \
    src/commom/sysbuttongroup.h \
    src/commom/numanimwidget.h \
    src/commom/numbersanimwidget.h \
    src/main/common/scorewidget.h \
    src/main/common/buttonlabel.h \
    src/commom/threebutton.h \
    src/main/common/backgroundbutton.h \
    src/main/top/mainscorewidget.h \
    src/main/top/userwidget.h \
    src/main/top/topbottomwidget.h \
    src/main/bottom/mainbottomfirstwidget.h \
    src/main/bottom/mainexaminewidget.h \
    src/main/mainwindow.h \
    src/main/common/shadowwidget.h \
    src/commom/wenliwidget.h \
    src/safe/safewidget.h \
    src/safe/common/scanbuttonwidget.h \
    src/commom/statictextbutton.h \
    src/safe/common/safescanbottom.h \
    src/safe/safetopwidget.h \
    src/safe/safebottomwidget.h \
    src/commom/myhelper.h \
    src/commom/wenlibackwidget.h \
    src/commom/stackstatuswidget.h \
    src/clean/cleanwidget.h \
    src/youhua/youhuawidget.h \
    src/clean/common/cleanscanbottom.h \
    src/clean/common/cleandynamicbuttonwidget.h \
    src/youhua/common/youhuabutton.h \
    src/youhua/common/youhuascanbottom.h \
    src/main/common/opacitywidget.h \
    src/main/common/videowidget.h

RESOURCES += \
    resource/360.qrc

#复制视频文件
win32{
    COPY = copy /y
    MKDIR = mkdir
}else{
    COPY = cp
    MKDIR = mkdir -p
}

FILES_COPY_SRC = resource/video/360SafeVideo.wmv


!equals(_PRO_FILE_PWD_, OUT_PWD) {
    for(f, FILES_COPY_SRC){
        orig_file = $$_PRO_FILE_PWD_/$$f
        dist_file = $$OUT_PWD/$$f
        dist = $$dirname(dist_file)
        win32:dist = $$replace(dist, /, \\)
        win32:orig_file = $$replace(orig_file, /, \\)
        !exists($$dist):system($$MKDIR $$dist)
        !exists($$dist_file):system($$COPY $$orig_file $$dist)
    }
}
