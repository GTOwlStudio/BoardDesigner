#pragma once
class GUIObject
{
public:
	GUIObject() {};
	virtual ~GUIObject() {}

	virtual void updateLogic() = 0;

	 

};

