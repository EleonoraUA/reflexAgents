#pragma once

class Environment;


class SimpleReflexAgent : public Agent {
private:
	Environment::Location _location;
	Agent::ActionType way;
	int n;

public:
	SimpleReflexAgent(): Agent() {
		n = 5;
		way = ActionType(rand() % 4);
	}
	ActionType Think() override 
	{
		if (dirty_) {
			return actSUCK;
		}
		
		if (!bump_) {
			if (n == 2 + rand() % 6)
				way = ActionType(rand() % 4);
			return way;
		}
		else {
			way = ActionType(rand() % 4);
		}
	}

	void SimpleReflexAgent::Perceive(const Environment &env) override
	{
		Agent::Perceive(env);
		_location = env.GetAgentLocation();
	}
};