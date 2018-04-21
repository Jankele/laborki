#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>

struct Ingredient
{
	std::string skladnik;
	int ilosc;
};

struct Recipe
{
    std::string keyword;
    std::string title;
};


struct Cookbook
{
  void addRecipe(std::string &title, Recipe& recipe, std::string& keyword)
  {
  	Recipe r;
  	r.keyword = keyword;
  	r.title = title;
  }

  Recipes findRecipe(const std::string& keyword)
  {

  }

  Recipe at(const std::size_t &index)
  {

  }
private:
	std::set<Recipe> cb;
	std::set<Recipe> cb2;
};

int main()
{

}