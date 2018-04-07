#include <iostream>
#include <string>

struct Hash
{
	using Int = std::int64_t;
	Int value;
	Hash(const std::string& v)
	{
		auto h = std::hash<std::string>{};
		value = h(v);
	}
};

using MyMap = std::map<std::int64_t, std::string>;

struct HashMap
{
	std::string at(const std::string &key)
	{
		Hash h{key};
		auto myHash = h.value;
		//return _map.at(myHash);

		auto it = _map.find(myHash);
		std::pair<std::int64_t, std::string> obj = *it;

		return obj.second;
	}

	void put(const std::string & key, const std::string & data)
	{
		Hash h{key};
		auto myHash = h.value;
		_map[myHash] = data;
	}

	bool check(std::string) const noexcept
	{
		Hash h{key};
		auto myHash = h.value;
		return _map.find(myHash) != _map.end();
	}

	Mymap _map;
};

int main()
{
//zamienic std::String na dowolny typ danych
}