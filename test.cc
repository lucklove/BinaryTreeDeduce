#include "deduce.hh"
#include <cassert>

void
test_prededuce(const std::string& mid, std::string post, const std::string& expect_result)
{
	deducePreorder([&](auto it) {
		return mid.find(*it);
	}, post.begin(), post.end());
	assert(post == expect_result);
}

void
test_postdeduce(const std::string& mid, std::string pre, const std::string& expect_result)
{
	deducePostorder([&](auto it) {
		return mid.find(*it);
	}, pre.begin(), pre.end());
	assert(pre == expect_result);
}

int
main()
{
	test_prededuce("012345678", "013427685", "521043867");
	test_postdeduce("012345678", "521043867", "013427685");
	test_postdeduce("DBGEACHF", "ABDEGCFH", "DGEBHFCA");
}
