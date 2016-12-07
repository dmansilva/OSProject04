
#define MAXPAGES 5


struct sharedmem {

  uint ref_count;
  // shared memory virtual address
  void *sharedmem_vaddr;
  // page of physical address
  void *phyaddr;
};
