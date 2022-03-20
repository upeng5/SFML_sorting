#ifndef SORT_SETTINGS_H
#define SORT_SETTINGS_H

struct SortSettings {
	float start_pos = 1.6f;
	float margin = 2.f;
	float increment = 0;
	SortSettings() {}
	SortSettings(float increment) : increment(increment) {}
};

#endif