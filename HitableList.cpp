#include "HitableList.h"

void HitableList::AddHitableObject(Hitable* addItem) {
	m_hitableObjectsList.push_back(addItem);
}

void HitableList::RemoveHitableObject(Hitable* removeItem) {
	for (std::vector<Hitable*>::iterator iter = m_hitableObjectsList.begin(); iter != m_hitableObjectsList.end(); ++iter) {
		if (*iter == removeItem) {
			iter = m_hitableObjectsList.erase(iter);
			break;
		}
	}
}

void HitableList::RemoveHitableObject(int index) {

}

int HitableList::GetItemSize() {
	return (int)m_hitableObjectsList.size();
}

//检查当前hitable list，找到最近hit的位置
bool HitableList::Hit(const Ray& r, float minT, float maxT, HitRecord& rec)const
{
	HitRecord tempRec;
	bool hitAnything = false;
	double closestHitDistance = maxT;
	for (int i = 0; i < list_size; i++)
	{
		//实现遮挡剔除
		if (m_hitableObjectsList[i]->Hit(r, minT, maxT, tempRec))
		{
			hitAnything = true;
			closestHitDistance = tempRec.m_paramT;
			rec = tempRec;
		}
	}
	return hitAnything;
}