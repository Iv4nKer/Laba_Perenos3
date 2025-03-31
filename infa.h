#include <iostream>
#include <string>
namespace TVR {
	class tvr {
		std::string _name;
		std::string _color;
		int _cost;
	public:
		tvr() = default;
		tvr(std::string name, std::string color, int cost);
		std::string name();
		std::string color();
		int cost();
		friend std::ostream& operator << (std::ostream & out, const tvr& f);
		friend std::istream& operator >> (std::istream & in, tvr& f);
		void setName(const std::string& name) { _name = name; }
		void setColor(const std::string& color) { _color = color; }
		void setCost(int cost) { _cost = cost; }
	};
	std::ostream& operator << (std::ostream & out, const tvr& f);
	std::istream& operator >> (std::istream & in, tvr& f);
	tvr * load(int & count);
	tvr * create(int & count);
	void save(tvr *arr, int count);
	void add(tvr **arr, int *count);
	void del(tvr *arr, int *count);
	void edit(tvr *arr, int count);
	void search(tvr *arr, int count);
	void show(tvr *arr, int count);
}