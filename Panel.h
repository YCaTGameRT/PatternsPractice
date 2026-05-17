#ifndef _PANEL_H_
#define _PANEL_H_

#include <vector>
#include <memory>
#include "Frames.h"

class Panel {
public:
	void AddFrame(const Frames& frame) {
		frames.push_back(std::make_unique<Frames>(frame));
	}

	bool TryPlaceToy(const Toys& toy, int frameIndex) {
		if (frameIndex >= 0 && frameIndex < frames.size()) {
			if (frames[frameIndex]->IsPassable(toy)) {
				frames.erase(frames.begin() + frameIndex);
				return true;
			}
		}
		return false;
	}

	int GetFramesCount() const { return frames.size(); }

	const Frames& GetFrame(int index) const {
		return *frames[index];
	}

private:
	std::vector<std::unique_ptr<Frames>> frames;
};

#endif