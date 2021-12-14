
#ifndef INC_3DBODY_3DBODY_INCLUDE_ALGORITHMS_COUNTONE_H_
#define INC_3DBODY_3DBODY_INCLUDE_ALGORITHMS_COUNTONE_H_

#include <bitset>
#include "util/Log.h"

namespace gf {

inline unsigned int countOneInUnsignedInt(unsigned int in) {
  unsigned int c = 0;
  for (c = 0; in; ++c) {
	in &= (in - 1);
  }
  return c;
}

inline unsigned int Nearst2(unsigned int cap) {
  int n = cap - 1;
  n |= n >> 1;
  n |= n >> 2;
  n |= n >> 4;
  n |= n >> 8;
  n |= n >> 16;
  return n + 1;
}

inline unsigned int getMinOne(unsigned int in) {
  if (in==INT_MAX) {
	GF_CORE_ERROR("This container has been full, please create another container!");
	return INT_MAX;
  }
  auto t = std::bitset<32>(in);
  if (!t.any()) {
	return 0;
  }
  for (int i = 0; i < 32; ++i) {
	if (t[i]==0)return i;
  }
}

inline void updateContainer(unsigned int &c) {
  if (c==INT_MAX) {
	GF_CORE_ERROR("This container has been full, please create another container!");
	return;
  }
  auto t = std::bitset<32>(c);
  if (!t.any()) {
	c = 1;
	return;
  }
  for (int i = 0; i < 32; ++i) {
	if (t[i]==0) {
	  t[i].flip();
	  c = t.to_ulong();
	  return;
	}
  }
}

class MyContainer {
 public:

  static unsigned int getAvailablePositionId() { return count_; }

  static unsigned int getTotalRegistered() { return totalRegistered_; }

  static unsigned int getContainerLayout() { return container_; }

  static unsigned int registerToContainer() {
	if (noUnregistered) {
	  unsigned int id = count_;
	  if (count_==0) {
		count_++;
		container_ = 1;
		totalRegistered_++;
		return id;
	  }
	  count_++;
	  container_ |= Nearst2(container_);
	  totalRegistered_++;
	  return id;
	} else {
	  if (count_==0) {
		container_ |= 1;
		count_ = getMinOne(container_);
		totalRegistered_++;
		return 0;
	  }
	  unsigned int id = count_;
	  updateContainer(container_);
	  count_ = getMinOne(container_);
	  totalRegistered_++;
	  return id;
	}
  }

  static void deregisterToContainer(unsigned int idx) {
	if (container_==0) {
	  GF_CORE_ERROR("You never registered to container!");
	  return;
	}
	if (noUnregistered) {
	  noUnregistered = false;
	  if (idx==0) {
		if ((container_%2)!=1) {
		  GF_CORE_ERROR("Current ID: {} has been de-registered! Please do not redo this operation.", idx);
		  return;
		}
		count_ = 0;
		container_ &= (container_ - 1);
		totalRegistered_--;
		return;
	  } else {
		int          k = ~(1 << (idx - 1));
		unsigned int t = container_ & k;
		if (container_==t) {
		  GF_CORE_ERROR("Current ID: {} has been de-registered! Please do not redo this operation.", idx);
		  return;
		}
		container_ = t;
		count_     = idx;
		totalRegistered_--;
		return;
	  }
	} else {
	  if (idx==0) {
		if ((container_%2)!=1) {
		  GF_CORE_ERROR("Current ID: {} has been de-registered! Please do not redo this operation.", idx);
		  return;
		}
		count_ = 0;
		container_ &= (container_ - 1);
		totalRegistered_--;
		return;
	  } else {
		int          k = ~(1 << (idx - 1));
		unsigned int t = container_ & k;
		if (container_==t) {
		  GF_CORE_ERROR("Current ID: {} has been de-registered! Please do not redo this operation.", idx);
		  return;
		}
		container_ = t;
		count_     = idx < count_ ? idx : count_;
		totalRegistered_--;
		return;
	  }
	}

  }

 private:
  static unsigned int count_;
  static unsigned int totalRegistered_;
  static unsigned int container_;
  static bool         noUnregistered;

};

}

#endif //INC_3DBODY_3DBODY_INCLUDE_ALGORITHMS_COUNTONE_H_
