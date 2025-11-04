# Project 4 - HashTable

Project description can be found [in the repo](Project4_HashTable.pdf)

Place your complexity analysis below.

---

For all: (best case/avg case: O(1), worst: O(n)
1. insert
   usually requires 1 or a few probes to find an empty
   bucket. worst case it probes all buckets.

2. remove
   likewise remove probes to locate key. on average it is 
   constant, but worst case all buckets need checked.

3. contains
   uses same probing logic as insert and remove. as long as
   load factor is low, time is constant.

4. get
   again, getting value typically needs a single probe, but 
   worst case is linear.
   
5. operator[]
   as long as load factor is below the 0.5 threshold, avg case
   is constant. 
