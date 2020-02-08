
#line 4 "index.md"

	
#line 14 "index.md"

	#include <iostream>
	#include <fstream>
	#include <string>
	#include <vector>
	#include <set>
	#include <cstring>

#line 5 "index.md"

	
#line 25 "index.md"

	std::vector<std::string> get_block(
		std::istream &in
	) {
		std::vector<std::string> block;
		
#line 69 "index.md"

	std::string line;
	while (std::getline(in, line)) {
		if (line.empty()) {
			if (block.empty()) {
				continue;
			} else {
				break;
			}
		}
		block.push_back(line);
	}

#line 30 "index.md"
;
		return block;
	}

#line 37 "index.md"

	std::set<std::string> written;

#line 43 "index.md"

	void process(const std::string &path) {
		std::ifstream in { path.c_str() };
		
#line 58 "index.md"

	std::vector<std::string> block;
	for (;;) {
		block = get_block(in);
		if (block.empty()) { break; }
		
#line 85 "index.md"

	for (const auto &l : block) {
		std::cout << l << '\n';
	}
	std::cout << '\n';

#line 94 "index.md"

	for (const auto &l : block) {
		if (l.size() > 6 && memcmp("@" "inc(", l.c_str(), 5) == 0) {
			
#line 104 "index.md"

	std::string path { l.substr(5, l.size() - 6) };
	if (written.find(path) == written.end()) {
		written.insert(path);
		process(path);
		for (const auto &l : block) {
			std::cout << l << '\n';
		}
		std::cout << '\n';
	}

#line 97 "index.md"
;
		}
	}

#line 63 "index.md"
;
	}

#line 46 "index.md"
;
	}

#line 6 "index.md"

	int main() {
		
#line 52 "index.md"

	process("index.md");

#line 8 "index.md"
;
	}
