#include <vector>
#include <string>
#include <array>
#include <list>
#include <iostream>
#include <stdexcept>

template<typename Iter_1, typename Iter_2>
Iter_2 my_copy(Iter_1 f1, Iter_1 e1, Iter_2 f2) 
{
for(Iter_1 p = f1; p != e1; ++p)
    *f2++ = *p;
return f2;
}

template<typename C>
void print_elements(const C& c, const std::string& s = "")
{
std::cout << s << '\t';
for(auto& a : c)
std::cout << a << ' ';
std::cout << '\n';
}

template<typename C>
void Increase_value(C& c, int n = 1)
{
for(auto& a : c)
a += n;
}

int main()
try {
	constexpr int size = 10;
	int arr[size];
	for (int i = 0; i < size; ++i) arr[i] = i;
	print_elements(arr, "array[10]: ");
	std::cout << "\n";
	
	std::array<int, size> ai;
	std::copy(arr, arr + size, ai.begin());
	print_elements(ai, "std::list: ");
	
	std::vector<int> vi(size);
	std::copy(arr, arr + size, vi.begin());
	print_elements(vi, "std::vector: ");
	
	std::list<int> li(size);
	std::copy(arr, arr + size, li.begin());
	print_elements(li, "std::list: ");
	
	std::cout << '\n';
	
	
	std::array<int, size> ai2 = ai;
	std::vector<int> vi2 = vi;
	std::list<int> li2 = li;
	print_elements(ai2, "array cpoy: ");
	print_elements(vi2, "vector copy: ");
	print_elements(li2, "list copy: ");
	
	Increase_value(ai2, 2);
	Increase_value(vi2, 3);
	Increase_value(li2, 5);
	print_elements(ai2, "array +2: ");
	print_elements(vi2, "vector +3: ");
	print_elements(li2, "list +5: ");
	
	
	my_copy(ai2.begin(), ai2.end(), vi2.begin());
	my_copy(li2.begin(), li2.end(), ai2.begin());
	print_elements(ai2, "array cop: ");
	print_elements(vi2, "vector cop: ");
	print_elements(li2, "list cop: ");
	
	
	
	
}
catch(std::exception& e)
{
std::cerr << "Exception: " << e.what() << '\n';
return 1;
}

catch(...)
{
std::cerr << "Unknown exeotion\n";
return 2;
}



	
