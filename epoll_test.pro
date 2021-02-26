#-------------------------------------------
#定义工程目录
unix{
	CURRENT_PROJECT_PATH = $$system(pwd)
}
win32{
	CURRENT_PROJECT_PATH = .
}

#包含公共配置qmake.conf文件
!include($$(SMARTSYS_HOME)/dev/mkspecs/qmake.conf){
         error(the file $$(SMARTSYS_HOME)/dev/mkspecs/qmake.conf is not exist!!)
}
#-------------------------------------------

#-------------------------------------------
#lib 表示编译动态库，app表示编译为执行程序
TEMPLATE = app

#编译目标名
TARGET = epoll_test

#-------------------------------------------
HEADERS += 	epoll_test.h

SOURCES +=  epoll_test.cpp

#-------------------------------------------
