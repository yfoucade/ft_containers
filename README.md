todo:  
- [x] refactor vector::reserve() to try to double capacity.
- [ ] is it necessary to call member destructors in assignment operator of pair ?
- [ ] deallocate and delete nodes in erase(iterator) and erase(iterator, iterator)
- [x]	vector: reserve should only allocate the requested amount.
- [x]	vector: shift should not have to call reserve, only shift. It is the 
		responsibility of the calling function to check that there is enough space.
- [x]	vector: create a function check_len(size_type n) that will check that there
		is enough _capacity to add n elements. Otherwise decide size to reserve.
- [x]	assign from iterators: do not reallocate if _capacity is sufficient.