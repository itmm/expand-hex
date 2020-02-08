# Automatically combine hex documents

```
@Def(file: expand-hex.cpp)
	@put(includes)
	@put(globals)
	int main() {
		@put(main);
	}
@End(file: expand-hex.cpp)
```

```
@def(includes)
	#include <iostream>
	#include <fstream>
	#include <string>
	#include <vector>
	#include <set>
	#include <cstring>
@end(includes)
```

```
@def(globals)
	std::vector<std::string> get_block(
		std::istream &in
	) {
		std::vector<std::string> block;
		@put(get block);
		return block;
	}
@end(globals)
```

```
@add(globals)
	std::set<std::string> written;
@end(globals)
```

```
@add(globals)
	void process(const std::string &path) {
		std::ifstream in { path.c_str() };
		@put(process);
	}
@end(globals)
```

```
@def(main)
	process("index.md");
@end(main)
```

```
@def(process)
	std::vector<std::string> block;
	for (;;) {
		block = get_block(in);
		if (block.empty()) { break; }
		@put(process block);
	}
@end(process)
```

```
@def(get block)
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
@end(get block)
```

```
@def(process block)
	for (const auto &l : block) {
		std::cout << l << '\n';
	}
	std::cout << '\n';
@end(process block)
```

```
@add(process block)
	for (const auto &l : block) {
		if (l.size() > 6 && memcmp("@" "inc(", l.c_str(), 5) == 0) {
			@put(handle include);
		}
	}
@end(process block)
```

```
@def(handle include)
	std::string path { l.substr(5, l.size() - 6) };
	if (written.find(path) == written.end()) {
		written.insert(path);
		process(path);
		for (const auto &l : block) {
			std::cout << l << '\n';
		}
		std::cout << '\n';
	}
@end(handle include)
```

