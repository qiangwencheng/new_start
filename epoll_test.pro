#-------------------------------------------
#���幤��Ŀ¼
unix{
	CURRENT_PROJECT_PATH = $$system(pwd)
}
win32{
	CURRENT_PROJECT_PATH = .
}

#������������qmake.conf�ļ�
!include($$(SMARTSYS_HOME)/dev/mkspecs/qmake.conf){
         error(the file $$(SMARTSYS_HOME)/dev/mkspecs/qmake.conf is not exist!!)
}
#-------------------------------------------

#-------------------------------------------
#lib ��ʾ���붯̬�⣬app��ʾ����Ϊִ�г���
TEMPLATE = app

#����Ŀ����
TARGET = epoll_test

#-------------------------------------------
HEADERS += 	epoll_test.h

SOURCES +=  epoll_test.cpp

#-------------------------------------------
