all:
	gcc -std=c++0x \
	dummymainfortravis.cpp \
	./lib/api/messages/TextSecureGroup.cpp \
	./lib/api/messages/TextSecureAttachment.cpp \
	./lib/api/push/TextSecureAddress.cpp 
	
