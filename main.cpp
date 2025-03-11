#include <iostream>
#include "pixel.h"
#include <vector>
#include <fstream>
#include <string>

void average_colors(std::vector<Pixel> &pixel_list) {
	int size = pixel_list.size();
	float r_avg = 0.0;
	float g_avg = 0.0;
	float b_avg = 0.0;
	for (int i = 0; i < size; i++) {
		r_avg += pixel_list[i].r;
		b_avg += pixel_list[i].b;
		g_avg += pixel_list[i].g;
	}
	r_avg = r_avg / size;
	g_avg = g_avg / size;
	b_avg = b_avg / size;

	std::cout << "Average R: " << r_avg << std::endl;
	std::cout << "Average G: " << g_avg << std::endl;
	std::cout << "Average B: " << b_avg << std::endl;
}

void flip_vertically(std::vector<Pixel> &pixel_list) {
	int max_y = 255;

	for (int i = 0; i < pixel_list.size(); ++i) {
		pixel_list[i].y = max_y - pixel_list[i].y;
	}
}









int main( int argc, char *argv[]) {

	std::string filename = argv[1];
	std::vector<Pixel> pixel_list;
	std::ifstream file;
	file.open(filename.c_str(), std::ios::in);
	if(file.is_open()) {


		std::string line;
		while (std::getline(file, line))
		{
			Pixel pixel;
			int start = 0;
			int end = line.find(",");
			pixel.x = std::stoi(line.substr(start, end - start));
			start = end + 1;
			end = line.find(",", start);
			pixel.y = std::stoi(line.substr(start, end - start));
			start = end + 1;

			end = line.find(",", start);
			pixel.r = std::stof(line.substr(start, end - start));
			start = end + 1;

			end = line.find(",", start);
			pixel.g = std::stof(line.substr(start, end - start));
			start = end + 1;

			pixel.b = std::stof(line.substr(start));

			pixel_list.push_back(pixel);
		}
	file.close();		
	}
	average_colors(pixel_list);
	flip_vertically(pixel_list);
	
	std::ofstream output_file("flipped.dat");
	for (int i = 0; i < pixel_list.size(); ++i) 
	{
		const Pixel &p = pixel_list[i]; 
		output_file << p.x << "," << p.y << "," << p.r << "," << p.g << "," << p.b << std::endl;
	}
	return 0;




}
