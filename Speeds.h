#ifndef SPEEDS_H
#define SPEEDS_H SPEEDS_H
#include <string>
#include "vublock.h"

///See page 163 of l207.pdf
class Speeds : public vublock {
	public:
	string name() const {
		return "Detailed Speed";
	}
	static const int TREP = 0x4;
	Speeds(iter nstart) : vublock(nstart) { Init(); }
	int size() const{
		return 2+64*Int16(0) + 2 + 128;;
	}
	void CompleteReport(reporter& report) const{
		runningIndex = 0;
		for(reporter::subblock b = report.newsub("Detailed Speed", Int16()); b(); ++b){
			report("BeginDate",readDate().str());
			ostringstream o;
			for(int k = 0; k < 60; ++k) o << IntByte() << ", ";
			report("Speeds",o.str());
		}
	}
	void BriefReport(reporter& report) const{
		if(!report.hasPlotGraph()){
			//this really requires a plotting program and stuff
			report("Speed data","omitted");
			return;
		}
		runningIndex = 0;
		int count = Int16();
		if(!count) return;
		int j = 0;
		Time date =  readDate();
		while(++j < count){
			reporter::pgptr visual(report.getPlotGraph());
			Time sdate(date);
			int daystart = date.timestamp - date.timestamp % 86400;
			int dayend = daystart + 86400;
			do {
				int difference = date.timestamp - daystart;
				for(int k = 0; k < 60; ++k) *visual << (difference + k) << " " << IntByte() << "\n";
				if(j < count) date = readDate();
			} while(++j < count && date.timestamp < dayend);
			report(sdate.datestr(),visual->str());
		}
	}

};

#endif
