nums = [9, 7, 8, 1, 5, 6, 3, 4, 2]
print(nums)

for i in range(0, len(nums)):
    for j in range(1, len(nums) - i):
        if nums[j - 1] > nums[j]:
            nums[j], nums[j - 1] = nums[j - 1], nums[j]
    print(nums)
