
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

	int cnt { 0 };
	for (const auto &l : block) {
		if (l[0] == '#') { ++cnt; }
	}
	if (cnt > 1) {
		
#line 131 "index.md"

	for (int i = 1; i <= cnt; ++i) {
		int j = 0;
		for (const auto &l : block) {
			if (l[0] == '#') {
				++j;
				if (j <= i) {
					std::cout << l << '\n';
				} else {
					
#line 152 "index.md"

	int i = 0;
	while (l[i] == '#') {
		std::cout << '#';
		++i;
	}
	std::cout << " -" << l.substr(i + 1) << '\n';

#line 140 "index.md"
;
				}
			} else {
				std::cout << l << '\n';
			}
		}
		std::cout << '\n';
	}

#line 91 "index.md"
;
		continue;
	}

#line 98 "index.md"

	for (const auto &l : block) {
		std::cout << l << '\n';
	}
	std::cout << '\n';

#line 107 "index.md"

	for (const auto &l : block) {
		if (l.size() > 6 && memcmp("@" "inc(", l.c_str(), 5) == 0) {
			
#line 117 "index.md"

	std::string path { l.substr(5, l.size() - 6) };
	if (written.find(path) == written.end()) {
		written.insert(path);
		process(path);
		for (const auto &l : block) {
			std::cout << l << '\n';
		}
		std::cout << '\n';
	}

#line 110 "index.md"
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
