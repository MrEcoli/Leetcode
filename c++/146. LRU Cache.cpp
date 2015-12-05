class LRUCache{
public:
	LRUCache(int capacity) {
		this->cap = capacity;
		this->cur = 0;
	}

	int get(int key) {
		int ret = -1;
		if (map.find(key) != map.end()){
			ret = map[key];
			recentlyuse(key);
		}
		return ret;
	}

	void set(int key, int value) {
		auto iter = map.find(key);

		if (iter != map.end()){
			iter->second = value;
			recentlyuse(key);
		}
		else{
			if (this->cur == this->cap){
				int rm = used.back();
				used.pop_back();
				map.erase(rm);
				positions.erase(rm);

				map[key] = value;

				used.push_front(key);
				positions[key] = used.begin();
			}
			else{
				cur++;
				map[key] = value;
				used.push_front(key);
				positions[key] = used.begin();
			}

		}


	}

private:
	int cap;
	int cur;
	unordered_map<int, int> map;
	unordered_map<int, list<int>::iterator> positions;
	list<int> used;

	void recentlyuse(int key){
		auto iter = positions[key];
		used.erase(iter);
		used.push_front(key);
		positions[key] = used.begin();
		
	}
};