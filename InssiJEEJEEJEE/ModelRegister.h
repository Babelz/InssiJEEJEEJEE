#pragma once
#include <vector>
#include "TileModel.h"
class ModelRegister
{
private:
	std::vector<TileModel*> models;
public:
	ModelRegister();

	void registerModel(TileModel* const model);
	TileModel* getModelWithId(int id);

	~ModelRegister();
};

