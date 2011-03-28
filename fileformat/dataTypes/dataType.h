#ifndef DATATYPE_H
#define DATATYPE_H

#include "../constDataPointer.h"
#include "../reporter/reporter.h"

class dataType {
public:
	friend reporter& operator<<(reporter& report, dataType d){
		d.printOn(report);
		return report;
	}
	virtual void printOn(reporter& report){
	}
	virtual QString str(){
		return "";
	}
};

#endif
