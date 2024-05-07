nums = [3,1,2,3]

"""

"""

def solution(nums):
    answer = 0
    
    len_of_max_pocketmon = len(nums) / 2
    remove_duplicate = list(set(nums))
    
    if len(remove_duplicate) < len_of_max_pocketmon:
        answer = len(remove_duplicate)
    else:
        answer = len_of_max_pocketmon
    
    return answer


print(int(solution(nums)))