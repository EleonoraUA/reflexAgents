
#ifndef AGENT__
#define AGENT__

#include <string>
using std::string;

// -----------------------------------------------------------
//				class Agent
// -----------------------------------------------------------
class Environment;
class Agent
{
public:
	Agent():bump_(false), dirty_(false) {}
	
	enum ActionType { actUP, actDOWN,  actLEFT, actRIGHT, actSUCK, actIDLE };
	static ActionType act[];

	virtual void Perceive(const Environment &env);
	virtual ActionType Think();
protected:
	bool bump_,
		 dirty_;
};

string ActionStr(Agent::ActionType);

#endif
