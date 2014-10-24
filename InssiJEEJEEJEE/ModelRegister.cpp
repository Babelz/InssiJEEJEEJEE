#include "ModelRegister.h"

ModelRegister::ModelRegister() {
}

void ModelRegister::registerModel(TileModel* const model) {
	models.push_back(model);

}
TileModel* ModelRegister::getModelWithId(int id) {
	for (int i = 0; i < models.size(); i++) {
		if (models[i]->getId() == id) {
			return models[i];
		}
	}

	return 0;
}

ModelRegister::~ModelRegister() {
	for (int i = 0; i < models.size(); i++) {
		delete(models[i]);
	}
}
