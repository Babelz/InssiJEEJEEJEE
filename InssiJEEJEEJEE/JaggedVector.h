#pragma once

#include <vector>

template <class T>
class JaggedVector
{
private:
	int width;
	int height;
	
	std::vector<std::vector<T*>> items;
public:
	JaggedVector() {

	}
	JaggedVector(int width, int height) {
		this->width = width;
		this->height = height;

		for (int i = 0; i < height; i++)
		{
			std::vector<T*> row(width);

			items.push_back(row);
		}
	}

	// TODO: ei toimi vielä.
	void resize(int newWidth, int newHeight) {
		if (newHeight < height) {
			// Rowien poisto.
		} else if (newHeight > height) {
			// Rowien lisäys.
		}

		this->height = newHeight;

		if (newWidth < width) {
			// Columeiden poisto.
		} else if (newWidth > width) {
			// Columeiden lisäys.
		}

		this->width = newWidth;
	}

	T* itemAtIndex(int y, int x) {
		return items[y][x];
	}

	void setItemAtIndex(int y, int x, T* item) {
		items[y][x] = item;
	}

	void clear() {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++)
			{
				T* item = items[i][j];

				if (item != NULL) {
					delete(item);
				}
			}
		}
	}

	int getWidth() {
		return this->width;
	}
	int getHeight() {
		return this->height;
	}

	~JaggedVector() {
		clear();
	}
};

