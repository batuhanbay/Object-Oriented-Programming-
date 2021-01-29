#pragma once
class Valve
{
public:
	Valve();
	~Valve();
	void open_valve();
	void close_valve();
	bool getSatus()const;
private:
	bool valve;
};