#include <string>

#ifndef ai_H
#define ai_H

class AI {
	private:
		int hullstrength;
		int shipSpeed = 10;
		int relation = 0;
		
		struct position {
			int x;
			int y;
			int w;
			int h;
			int angle;
			char* shipfile;
		};
		
		position test[2] = {{0, 0, 0, 0, 0, "n"}, {0, 0, 0, 0, 0, "n"}} ;
		
		
		
	public:
		void createship(int AIID, int x, int y, int w, int h, int angle, char* ship);
	
		void setSpeed(int val, int AIID);
		
		void setPosX(int val, int AIID);
		
		void setPosY(int val, int AIID);
		
		position getPositions(int AIID) {return test[AIID];};
		
		void AIControl(int AIID, char dir);
		
		
};

#endif
