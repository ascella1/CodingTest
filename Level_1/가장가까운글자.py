def solution(s):
    # 1. 딕셔너리를 하나 만든다
    # 2. s 를 enumerate 를 통해 인덱스와 알파벳(값)으로 나눈다
    # 3. 딕셔너리에 알파벳이 없다면, -1을 answer에 append한다
    # 4. 딕셔너리에 값을 추가하는데, 현재 알파벳을 키값으로 하고, 인덱스를 값으로 넣는다
    # 5. 이때 딕셔너리에 이미 알파벳이 있다면 현재 알파벳의 인덱스에서 기존에 딕셔너리에 있던 알파벳의 인덱스 값을 뺀다
    answer = []
    alp_idx = {}#딕셔너리 생성
    for idx, alp in enumerate(s):
        if alp not in alp_idx:
            answer.append(-1)
        else:
            answer.append(idx - alp_idx[alp])
        alp_idx[alp] = idx # b : 0 이런 형태를 가지게 된다
    return answer

print(solution("banana"))
