export module Stage;

import <vector>;
import <string>;
import Map;

export class Stage {
	std::string name;
	std::vector<Map> maps;
	Map* curMap;

public:
	Stage( std::string name ) : name{ name }, maps{}, curMap{} {}
};