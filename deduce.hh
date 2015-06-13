#pragma once
#include <algorithm>
#include <type_traits>

template<typename BidirIt>
void 
shift(BidirIt first, BidirIt mid, BidirIt last)
{
	std::reverse(first, mid);
	std::reverse(mid, last);
	std::reverse(first, last);
}

template<typename FuncT, typename BidirIt>
void
deduce_helper(FuncT&& weight, BidirIt first, BidirIt last)
{
	auto root = first++;
	if(first == last)
		return;
	auto mid = first;
	while(static_cast<long long>((weight(mid) - weight(root)) * (weight(first) - weight(root))) > 0 && mid != last)
		++mid;
	if(mid == last)
		return;
	deduce_helper(weight, first, mid);		
	deduce_helper(weight, mid, last);
	shift(first, mid, last);		
}
/**
 * \brief 根据树的中序遍历和后序遍历求前序遍历
 * \param weight 接收指向后序遍历序列的迭代器，返回该迭代器所指元素在中序遍历中的位置
 * \param first end 后序遍历区间，左闭右开
 * \note 结果储存在[first, last)中
 */
template<typename FuncT, typename BidirIt>
void
deducePreorder(FuncT&& weight, BidirIt first, BidirIt last)
{
	std::reverse(first, last);
	deduce_helper(weight, first, last);	
}

/**
 * \brief 根据树的中序遍历和前序遍历求后序遍历
 * \param weight 接收指向前序遍历序列的迭代器，返回该迭代器所指元素在中序遍历中的位置
 * \param first end 前序遍历区间，左闭右开
 * \note 结果储存在[first, last)中
 */
template<typename FuncT, typename BidirIt>
void
deducePostorder(FuncT&& weight, BidirIt first, BidirIt last)
{
	deduce_helper(weight, first, last);
	std::reverse(first, last);
}
