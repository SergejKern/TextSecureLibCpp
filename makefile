all:
	gcc -std=c++0x \
	./lib/api/messages/TextSecureGroup.cpp \
	./lib/api/messages/TextSecureAttachment.cpp \
	./lib/api/push/TextSecureAddress.cpp
