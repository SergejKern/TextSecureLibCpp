all:
	gcc -std=c++0x -c \
	./lib/api/messages/TextSecureGroup.cpp \
	./lib/api/messages/TextSecureAttachment.cpp \
	./lib/api/push/TextSecureAddress.cpp \
	-o textsecurelibcpp.o
	ar rcs libtextsecure.o textsecurelibcpp.o
