
#ifndef SRC_VHEAP_DEFRAG_H_
#define SRC_VHEAP_DEFRAG_H_

class Defrag {
private:
	static void* run(void* var);
	static void wait();
public:
	Defrag();
	~Defrag();
};

#endif /* SRC_VHEAP_DEFRAG_H_ */
