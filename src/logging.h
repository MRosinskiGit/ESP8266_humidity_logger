// logging.h
#ifndef LOGGING_H
#define LOGGING_H

class LoggerClass {
	public:
		LoggerClass(int baudRate = 115200);
		void log(String str, bool newLine=true);
};


#endif
