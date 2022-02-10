#ifndef HITABLELISTH
#define HITABLELISTH
#include "Hitable.h"

#include <vector>

class HitableList :public Hitable
{
public:
	HitableList(){}
	void AddHitableObject(Hitable* addItem);
	void RemoveHitableObject(Hitable* removeItem);
	void RemoveHitableObject(int index);
	int GetItemSize();
	virtual bool Hit(const Ray& r, float minT, float maxT, HitRecord& rec)const override;

protected:
	std::vector<Hitable*> m_hitableObjectsList;
	int list_size = 0;
};


#endif
