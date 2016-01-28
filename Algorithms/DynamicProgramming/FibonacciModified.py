args = [int(x) for x in input().split()]
nums = args[0:2]
n = args[2]
for i in range(2, n):
    nums.append(nums[i-1] ** 2 + nums[i-2])
print(nums[n-1])
