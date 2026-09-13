class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        unique_elements = set()
        for num in nums:
            if num not in unique_elements:
                unique_elements.add(num)
            else:
                return True
        return False
         