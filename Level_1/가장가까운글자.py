def solution(s):
    answer = []
    for i in range(len(s)):
        if i == 0:
            answer.append(-1)
        else:
            for j in range(i):
                if s[i] == s[j]:
                    answer.append(i - j)
    return answer

