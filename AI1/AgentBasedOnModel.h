#pragma once 
#include <vector>
#include <algorithm>

class Agent;

class AgentBasedOnModel : public Agent {
private:
	Agent::ActionType way;
	vector<vector<int>> map;
	vector<int> dirt;
	vector<int> dirt_ind;

	int steps = 0;
	int posx;
	int posy;
	int n = 5;
	int x[4] = { -1, 1, 0, 0 };
	int y[4] = { 0, 0, -1, 1 };
	int* state;
public:
	AgentBasedOnModel() : Agent() {
		state = new int[4]{ 0 };
		way = ActionType(rand() % 4);

		dirt.resize(4);
		map.resize(Environment::MAZE_SIZE);
		/*for (int i = 0; i < map.size(); i++)
		{
			vector <int> row;
			for (int j = 0; j < Environment::MAZE_SIZE; j++)
			{
				row.push_back(2);
			}
			map.push_back(row);
		}*/

		for (int i = 0; i < map.size(); i++)
			map[i].resize(Environment::MAZE_SIZE);

		/*for (int i = 0; i < map.size(); i++)
			for (int j = 0; j < map[i].size(); j++)
				map[i][j] = 2;*/
	}

	~AgentBasedOnModel() {
		delete[] state;
	}

	ActionType Think() override
	{
		if (dirty_)
			return actSUCK;

		AgentBasedOnModel::BuildMap();
		if (steps < 200) {
			steps++;
			/*for (int i = 0; i < map.size(); i++) {
				for (int j = 0; j < map[i].size(); j++)
					cout << map[i][j];
				cout << endl;
			}*/
			if (!bump_) {
				if (n == 2 + rand() % 6)
					way = ActionType(rand() % 4);
				return way;
			}
			else {
				way = ActionType(rand() % 4);
			}
		}
		else {
			dirt.clear();
			dirt_ind.clear();
			

			//string act[] = {"actLeft"};
			for (int i = 0; i < 4; i++) {
				//cout << posx + x[i] << " " << posy + y[i];
				//cout << map[posx + x[i]][posy + y[i]] << " state: " << state[i] << endl;
				if (map[posx + x[i]][posy + y[i]] != 2) {
					dirt.push_back(state[i]);
					dirt_ind.push_back(i);
				}
			}
			//auto maxim = std::max(dirt.begin(), dirt.end(), [](const std::pair<int, int> &left, const std::pair<int, int> &right) {
			//	return left.second < right.second;
			//});
			if (*max_element(std::begin(dirt), std::end(dirt)) == 0) {
				int ind = rand() % dirt_ind.size();
				return static_cast<ActionType>(ActionType(dirt_ind[ind]));
			}
			for (int i = 0; i < 4; i++) {
				if (state[i] == *max_element(std::begin(dirt), std::end(dirt))) {
					return static_cast<ActionType>(ActionType(i));
				}
			}
			/*cout << "MAX: " << *maxim << endl;
			cout << "----------------------------------" << endl;*/

			/*float maxim = max(max(state[0], state[1]), max(state[2], state[3]));
			for (int i = 0; i < 4; i++) {
				if (map[posx + x[i]][posy + y[i]] == 2) {
					continue;
				}
				if (state[i] == maxim) {
					return static_cast<ActionType>(ActionType(i));
				}
			}*/
			//return static_cast<ActionType>(5);
			//way = ActionType(rand() % 4);
			//return static_cast<ActionType>(way);
		}
	}

	void AgentBasedOnModel::Perceive(const Environment &env) override
	{
		Agent::Perceive(env);
		posx = env.GetAgentX();
		posy = env.GetAgentY();

		state[0] = env.DirtAmount(env.GetAgentX() - 1, env.GetAgentY());
		state[1] = env.DirtAmount(env.GetAgentX() + 1, env.GetAgentY());
		state[2] = env.DirtAmount(env.GetAgentX(), env.GetAgentY() - 1);
		state[3] = env.DirtAmount(env.GetAgentX(), env.GetAgentY() + 1);
	}

	void AgentBasedOnModel::BuildMap() {
		map[posx][posy] = 1;
		for (int i = 0; i < 4; i++) {
			map[posx + x[i]][posy + y[i]] = state[i] == -1 ? 2 : 1;
		}
		/*if (state[0] == -1) {
			map[posx - 1][posy] = 2;
		}
		else {
			map[posx - 1][posy] = 1;
		}
		if (state[1] == -1) {
			map[posx + 1][posy] = 2;
		}
		else {
			map[posx + 1][posy] = 1;
		}
		if (state[2] == -1) {
			map[posx][posy - 1] = 2;
		}
		else {
			map[posx][posy - 1] = 1;
		}
		if (state[3] == -1) {
			map[posx][posy + 1] = 2;
		}
		else {
			map[posx][posy + 1] = 1;
		}*/
	}
};