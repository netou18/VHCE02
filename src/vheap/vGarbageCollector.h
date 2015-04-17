#ifndef SRC_VHEAP_VGARBAGECOLLECTOR_H_
#define SRC_VHEAP_VGARBAGECOLLECTOR_H_

class vGarbageCollector {
private:
	static void* run(void* var);
	static void wait();
public:
	vGarbageCollector();
	~vGarbageCollector();
};

#endif /* SRC_VHEAP_VGARBAGECOLLECTOR_H_ */
